#include "main.h"
#ifdef __USE_FIVE_ // main control

#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include "lwip/netdb.h"
#include "lwip/dns.h"

#define WEB_SERVER "strapg.atwebpages.com"
#define WEB_PORT    "80"
#define WEB_URL    "strapg.atwebpages.com/receive.php"


#define postReq  "POST /receive.php HTTP/1.1\r\nHost:strapg.atwebpages.com\r\nContent-Length: %d\r\nContent-Type:application/json\r\n\r\n %s"

char reqBuffer[1024];

void http_post_task(void){
    struct addrinfo sockPrep = {
        .ai_family = AF_INET,
        .ai_socktype = SOCK_STREAM,
    };
    struct addrinfo *response;
    struct in_addr *addr;
    int s, r;
    char resp[512];
    http_handle = xEventGroupCreate();
    while(1){
        xEventGroupWaitBits(http_handle, CONNECTED_BIT, false, true, portMAX_DELAY);
        printf("Wait Complete\n");
        int err = getaddrinfo(WEB_SERVER, WEB_PORT, &sockPrep, &response);
        if( err!=0 || response == NULL){
            printf("DNS LOOKUP FAILED: err: %d and response: %p\n", err, response);
            vTaskDelay(100/portTICK_PERIOD_MS);
            continue;
        }
        addr = &((struct sockaddr_in *)response->ai_addr)->sin_addr;
        printf("IP: %s\n", inet_ntoa(addr));

        //Create a client socket handle.
        s = socket(response-> ai_family, response -> ai_socktype, 0);

        //Connect to the server.
        if(connect(s, response -> ai_addr, response -> ai_addrlen) != 0){
            printf("Connection failed\n");
            close(s);
            freeaddrinfo(response);
            vTaskDelay(1000/portTICK_PERIOD_MS);
            continue;
        }
        printf("Connected! \n");
        freeaddrinfo(response);

        char *str = "{ \"data\" : {\"Gyan Ki Baat\": \"Tum Chutiye Ho.\"} }\r\n";
        snprintf(reqBuffer, strlen(postReq)+100, postReq, strlen(str),  str);
        printf(" %s/n", reqBuffer);

        if(write(s, reqBuffer, strlen(reqBuffer)) < 0){
            close(s);
            vTaskDelay(1000/portTICK_PERIOD_MS);
            continue;
        }

        printf("Request Sent Successfully.");

        //Response Timeout.
        struct timeval receive_timeout;
        receive_timeout.tv_sec = 5;
        receive_timeout.tv_usec = 0;

        if(setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, &receive_timeout, sizeof(receive_timeout) ) < 0){
            printf("Error in receive");
            close(s);
            vTaskDelay(1000/portTICK_PERIOD_MS);
            continue;
        }
        do{
            bzero(resp, sizeof(resp));
            r = read(s, resp, sizeof(resp)-1);
            for(int i = 0; i < r; i++){
                putchar(resp[i]);
            }
        }while(r > 0);
        close(s);
        for(int countdown = 10; countdown >= 0; countdown--) {
            printf("%d... ", countdown);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
        printf("Starting again!\n");


    }


}


void app_main(){
    nvs_flash_init();
    esp_event_loop_init(wifi_http_req_handler, NULL);
    ESP_ERROR_CHECK(wifi_setup());
    
    xTaskCreate(http_post_task, "http_post_task", 4096, NULL, 5, NULL);
}

#endif  //main control