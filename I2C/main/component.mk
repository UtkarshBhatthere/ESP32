#
# Main component makefile.
#
# This Makefile can be left empty. By default, it will take the sources in the 
# src/ directory, compile them and link them into lib(subdirectory_name).a 
# in the build directory. This behaviour is entirely configurable,
# please read the ESP-IDF documents if you need to do this.
#

COMPONENT_ADD_INCLUDEDIRS="/home/utkarshbhatt/esp/projects/I2C/main/MPU6050"

COMPONENT_ADD_INCLUDEDIRS="/home/utkarshbhatt/esp/projects/I2C/main/I2Cdev"

COMPONENT_ADD_INCLUDEDIRS="/home/utkarshbhatt/esp/projects/I2C/main/custom"
COMPONENT_ADD_LDFLAGS= -lstdc++ -l$(COMPONENT_NAME)
