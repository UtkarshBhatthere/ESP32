deps_config := \
	/home/utkarshbhatt/esp/esp-idf/components/app_trace/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/aws_iot/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/bt/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/driver/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/esp32/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/esp_adc_cal/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/esp_http_client/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/ethernet/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/fatfs/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/freertos/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/heap/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/http_server/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/libsodium/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/log/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/lwip/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/mbedtls/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/mdns/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/openssl/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/pthread/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/spi_flash/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/spiffs/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/tcpip_adapter/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/vfs/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/components/wear_levelling/Kconfig \
	/home/utkarshbhatt/esp/esp-idf/Kconfig.compiler \
	/home/utkarshbhatt/esp/esp-idf/components/bootloader/Kconfig.projbuild \
	/home/utkarshbhatt/esp/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/utkarshbhatt/esp/esp-idf/components/partition_table/Kconfig.projbuild \
	/home/utkarshbhatt/esp/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
