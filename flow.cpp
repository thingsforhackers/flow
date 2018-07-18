#include <Arduino.h>
#include <EEPROM.h>
#include <SPI.h>
#include <GD2.h>

//BM Handles
static const byte TEMP_GRAPH_BM_HANDLE = 0;

static const uint16_t TEMP_GRAPH_BM_WIDTH = 480;
static const uint16_t TEMP_GRAPH_BM_HEIGHT = 272;
static const uint32_t TEMP_GRAPH_BM_ADDR = 0;
static const uint32_t TEMP_GRAPH_BM_SIZE = (uint32_t)TEMP_GRAPH_BM_WIDTH * (uint32_t)TEMP_GRAPH_BM_HEIGHT * 1L; // 1 == ARGB2

static const uint8_t ARGB2_BLUE  = 0xC0 | 0x03;
static const uint8_t ARGB2_GREEN = 0xC0 | 0x0C;
static const uint8_t ARGB2_RED   = 0xC0 | 0x30;
static const uint8_t ARGB2_WHITE = 0xC0 | 0x3F;

static void
create_tmp_bm(void) {
  GD.BitmapHandle(TEMP_GRAPH_BM_HANDLE);
  GD.BitmapSource(TEMP_GRAPH_BM_ADDR);
  GD.BitmapSize(NEAREST, BORDER, BORDER, TEMP_GRAPH_BM_WIDTH, TEMP_GRAPH_BM_HEIGHT);
  GD.BitmapLayout(ARGB2, TEMP_GRAPH_BM_WIDTH, TEMP_GRAPH_BM_HEIGHT);
  for (uint32_t i = 0; i < TEMP_GRAPH_BM_SIZE; i++)
    GD.wr(i, ARGB2_RED);
}

void 
setup() {
  Serial.begin(57600);
  GD.begin(); 
  create_tmp_bm();
  Serial.println(TEMP_GRAPH_BM_SIZE);
}

void 
loop() {
  GD.ClearColorRGB(0);
  GD.Clear();
  GD.Begin(BITMAPS);
  GD.Vertex2ii(0, 0, TEMP_GRAPH_BM_HANDLE);
  GD.swap();
}