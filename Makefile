ARDUINO_DIR = $(ARDUINO_IDE)
BOARD_TAG = uno
ARDUINO_PORT = /dev/ttyUSB0
ARDUINO_LIBS = SPI/src EEPROM/src Gameduino2
AVR_TOOLS_PATH = $(HOME)/opt/avr/bin
ARDUINO_ETC_PATH = $(ARDUINO_DIR)/hardware/tools/avr/etc/
ARDUINO_OPT_LIB_PATH=libs
include Arduino.mk
