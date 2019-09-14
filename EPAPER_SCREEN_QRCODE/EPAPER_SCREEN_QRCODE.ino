#include <GxEPD.h>
#include <GxGDE0213B1/GxGDE0213B1.h>      // 2.13" b/w

// FreeFonts from Adafruit_GFX
#include <Fonts/Picopixel.h>
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
// for SPI pin definitions see e.g.:
// C:\Users\xxx\Documents\Arduino\hardware\espressif\esp32\variants\lolin32\pins_arduino.h
GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16); // arbitrary selection of 17, 16
GxEPD_Class display(io, /*RST=*/ 16, /*BUSY=*/ 4); // arbitrary selection of (16), 4
//static const unsigned char wifiicon[] = {B00000000, B00000000, B00000000, B00000000, B00000111, B11100000, B00011111, B11111000, B00111111, B11111100, B01100000, B00000110, B11000011, B11000011, B10001111, B11110001, B00011000, B00011000, B00110000, B00001100, B00100011, B11000100, B00000111, B11100000, B00001100, B00110000, B00001000, B00010000, B00000001, B10000000, B00000001, B10000000}; //16*16
//static const unsigned char floppyicon[] = {B11000000, B00001000, B11000000, B01101100, B11000000, B01101110, B11000000, B01101111, B11000000, B01101111, B11000000, B00001111, B11000000, B00001111, B11111111, B11111111, B10000000, B00000011, B10111111, B11111011, B10000000, B00000011, B10111111, B11111011, B10000000, B00000011, B10111111, B11111011, B10000000, B00000011, B11111111, B11111111}; //16*16
//static const unsigned char erroricon[] = {B00000001, B10000000, B00000011, B11000000, B00000010, B01000000, B00000110, B01100000, B00000110, B01100000, B00001101, B10110000, B00001001, B10010000, B00011001, B10011000, B00010001, B10001000, B00110001, B10001100, B00100001, B10000100, B01100000, B00000110, B01000001, B10000010, B11000001, B10000011, B10000000, B00000001, B11111111, B11111111}; //16*16
//static const unsigned char intrologo[] = {B00111001, B10011100, B01110011, B11001110, B11100110, B01100111, B11001100, B00110011, B10011001, B10011001, B00110011, B11001100, B01100110, B01100110, B11001100, B00110011, B11001100, B00110011, B01100110, B01100110, B00110011, B11001100, B10011001, B10011001, B11001100, B00110011, B11100110, B01100111, B01110011, B11001110, B00111001, B10011100}; //16*16
//static const unsigned char copyright[] = {B00000111, B11100000, B00011111, B11111000, B00111000, B00011100, B01100011, B11000110, B01100111, B11100110, B11001100, B00110011, B11011000, B00000011, B11011000, B00000011, B11011000, B00000011, B11011000, B00000011, B11001100, B00110011, B01100111, B11100110, B01100011, B11000110, B00111000, B00011100, B00011111, B11111000, B00000111, B11100000}; //16*16
//static const unsigned char pointer[] = {B00000000, B00011000, B00011000, B00111100, B00111100, B01111110, B01111110, B11111111}; //8*8
//static const unsigned char passround[] = {B00000011, B11000000, B00001111, B11110000, B00001111, B11110000, B00000111, B11100000, B01100011, B11000110, B01110000, B00001110, B11111001, B10011111, B11111011, B11011111, B11111011, B11011111, B11111001, B10011111, B01110000, B00001110, B01100011, B11000110, B00000111, B11100000, B00001111, B11110000, B00001111, B11110000, B00000011, B11000000}; //16*16
//static const unsigned char passlow[] = {B00000011, B11000000, B00001111, B11110000, B00011100, B00111000, B00110000, B00001100, B01100000, B00000110, B01100000, B00000110, B11000000, B00000011, B11000000, B00000011, B11000000, B00000011, B11000000, B00000011, B01100000, B00000110, B01100000, B00000110, B00110000, B00001100, B00011100, B00111000, B00001111, B11110000, B00000011, B11000000}; //16*16
//static const unsigned char tick[] = {B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, B00000000, B00001111, B00000000, B00111100, B00000000, B01110000, B00000000, B11100000, B11000001, B11000000, B11100011, B10000000, B01110111, B00000000, B00111110, B00000000, B00011100, B00000000, B00001000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000}; //16*16
//static const unsigned char left[] = {B00000001, B00000011, B00000111, B00001110, B00011110, B00111100, B01111100, B11111000, B11111000, B01111100, B00111100, B00011110, B00001110, B00000111, B00000011, B00000001};//8*16
//static const unsigned char right[] = {B10000000, B11000000, B11100000, B01110000, B01111000, B00111100, B00111110, B00011111, B00011111, B00111110, B00111100, B01111000, B01110000, B11100000, B11000000, B10000000};//8*16
//static const unsigned char music[] = {B00000000, B00001111, B00000000, B11111111, B00001111, B11110001, B00001111, B00000001, B00001000, B00001111, B00001000, B11110001, B00001111, B00000001, B00001000, B00000001, B00001000, B00000001, B00001000, B00000001, B00001000, B00000001, B00001000, B00001111, B00001000, B00011111, B01111000, B00001110, B11111000, B00000000, B01110000, B00000000}; //16*16
//static const unsigned char notes[] = {B01111111, B11111110, B01000000, B00000010, B01000111, B11100010, B01000000, B00000010, B01000000, B00000010, B01011111, B11111010, B01000000, B00000010, B01011111, B11111010, B01000000, B00000010, B01011111, B11111010, B01000000, B00000010, B01011111, B11111010, B01000000, B00000010, B01011111, B10000010, B01000000, B00000010, B01111111, B11111110}; //16*16
//static const unsigned char edit[] = {B00000000, B00010000, B00000000, B00111000, B00000000, B01001100, B00000000, B10000110, B00000001, B00000100, B00000010, B00001000, B00000100, B00010000, B00001000, B00100000, B00010000, B01000000, B00100000, B10000000, B01000001, B00000000, B01100010, B00000000, B01110100, B00000000, B01111000, B00000000, B00000000, B00000000, B11111111, B11111111}; //16*16
//static const unsigned char wifiLocked[] = {B00000111, B11100000, B00001111, B11110000, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000, B00111111, B11111100, B00100000, B00000100, B00100001, B10000100, B00100001, B10000100, B00100001, B10000100, B00100001, B10000100, B00100001, B10000100, B00100000, B00000100, B00111111, B11111100, B00000000, B00000000}; //16*16
//static const unsigned char wifiOpen[] = {B00000111, B00000000, B00001111, B10000000, B00011001, B10000000, B00011001, B10000000, B00011001, B10000000, B00011000, B00000000, B00111111, B11111100, B00100000, B00000100, B00101000, B00010100, B00100110, B01100100, B00100001, B10000100, B00100110, B01100100, B00101000, B00010100, B00100000, B00000100, B00111111, B11111100, B00000000, B00000000}; //16*16
//static const unsigned char timeicon[] = {B00001111, B11110000, B00111100, B00111100, B01010001, B10001010, B01100001, B10000110, B01100001, B10000110, B11000001, B10000011, B10000001, B10000001, B10000001, B10000001, B10000001, B11000001, B10000000, B11100001, B11000000, B01100011, B11000000, B00000011, B01100000, B00000110, B01010000, B00001010, B00111100, B00111100, B00001111, B11110000}; //16*16
//static const unsigned char soundicon[] = {B00001000, B00000100, B00100100, B00010010, B10010010, B11010010, B11001001, B11101001, B11101001, B11001001, B11010010, B10010010, B00010010, B00100100, B00000100, B00001000}; //8*16
//static const unsigned char rtcsyncIcon[] = {B00000000, B00000000, B00000011, B11100000, B11111000, B00011000, B00011000, B10000100, B00011000, B10000100, B00101000, B10000010, B01001000, B10000001, B01000000, B10000001, B01000000, B10000001, B01000000, B01000001, B01000000, B00100001, B00100000, B00010010, B00100000, B00000010, B00010000, B00000100, B00001100, B00011000, B00000011, B11100000}; //16*16
//static const unsigned char disconnectIcon[] = {B00000000, B00000000, B00000000, B00000010, B00000111, B11100100, B00011111, B11111000, B00011111, B11111000, B01100000, B00100110, B11000011, B11000011, B10001111, B10010001, B00011001, B00011000, B00110010, B00001100, B00100100, B11000100, B00001001, B11100000, B00010000, B00110000, B00100000, B00010000, B01000001, B10000000, B00000001, B10000000}; //16*16

static const unsigned char sdicon[] = {B00000111, B11110000, B00000101, B01011000, B00001101, B01011000, B00011111, B11111000, B00011111, B11111000, B00011111, B11111000, B00001111, B11111000, B00001111, B11111000, B00011111, B11111000, B00010001, B00011000, B00010111, B01101000, B00010001, B01101000, B00011101, B01101000, B00010001, B00011000, B00011111, B11111000, B00011111, B11111000}; //16*16
static const unsigned char bluetoothicon[] = {B00000000, B00000000, B00000001, B10000000, B00000001, B01000000, B00000001, B00100000, B00001001, B00010000, B00000101, B00100000, B00000011, B01000000, B00000001, B10000000, B00000001, B10000000, B00000011, B01000000, B00000101, B00100000, B00001001, B00010000, B00000001, B00100000, B00000001, B01000000, B00000001, B10000000, B00000000, B00000000}; //16*16
static const unsigned char sleepicon[] = {B00000111, B11000000, B00011111, B11110000, B00111110, B00011000, B01111000, B00000000, B01111000, B00000000, B11110001, B11100000, B11100000, B00100000, B11100000, B01000000, B11100000, B10000000, B11100001, B00000000, B11110001, B11100000, B01110000, B00000000, B01111000, B00000000, B00111110, B00011000, B00011111, B11110000, B00000111, B11000000}; //16*16
static const unsigned char uparrow[] = {B00000001, B10000000, B00000001, B10000000, B00000011, B11000000, B00000011, B11000000, B00000011, B11000000, B00000111, B11100000, B00001111, B11110000, B00001111, B11110000, B00011111, B11111000, B00011111, B11111000, B00111111, B11111100, B00111111, B11111100, B01111111, B11111110, B01111110, B01111110, B11111000, B00011111, B11100000, B00000111}; //16*16
static const unsigned char downarrow[] = {B11100000, B00000111, B11111000, B00011111, B01111110, B01111110, B01111111, B11111110, B01111111, B11111110, B00111111, B11111100, B00011111, B11111000, B00011111, B11111000, B00001111, B11110000, B00001111, B11110000, B00000111, B11100000, B00000111, B11100000, B00000011, B11000000, B00000011, B11000000, B00000001, B10000000, B00000001, B10000000}; //16*16
#define FS_NO_GLOBALS
#include "FS.h"
#include "SPIFFS.h"
#define FORMAT_SPIFFS_IF_FAILED true
char* FILENAME = "disp.txt";
String TEXT_SPIFFS = "<disp title=\"NO DATA\">NO data available</disp>";
String TEXT_SD = "";
String currentText = "";
#define LED_BUILTIN 22  //Blink pin 
#define BTN_UP GPIO_NUM_33
#define BTN_DOWN GPIO_NUM_32
#define LED GPIO_NUM_25
RTC_DATA_ATTR int bootCount = 0;
RTC_DATA_ATTR String QRszoveg = "";
RTC_DATA_ATTR String Etitle = "";
RTC_DATA_ATTR String Eline1 = "";
RTC_DATA_ATTR String Eline2 = "";
RTC_DATA_ATTR String Eline3 = "";
RTC_DATA_ATTR String Eline4 = "";
RTC_DATA_ATTR String Eline5 = "";
int MAXPAGE = 0;
long lastPress = 0;
long lastup = 0;
long lastdown = 0;
bool up = false;
bool down = false;

int freq = 5000;
int ledChannel = 0;
int resolution = 8;

bool LEDON = false;

#include "qrcode.h"

bool BLUERUN = false;

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;

String serialBuffer = "";
String blueBuffer = "";

int lastCMD = 0;

uint64_t sleeptime = UINT64_C(3600 * 1000000);

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");

  ++bootCount;
  Serial.println("Boot number: " + String(bootCount));

  pinMode(BTN_UP, INPUT);
  pinMode(BTN_DOWN, INPUT);
  pinMode(LED, OUTPUT);
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED, ledChannel);
  //ledcWrite(ledChannel, 100);
  //delay(40);
  ledcWrite(ledChannel, 0);
  if (!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED)) {
    Serial.println("SPIFFS Mount Failed");
  }
  display.init(115200); // enable diagnostic output on Serial
  Serial.println("setup done");
  display.setRotation(3);
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);

  Serial.print("H:");
  Serial.print(display.height());
  Serial.print(" W:");
  Serial.println(display.width());

  Serial.println("Welcome!");
  Serial.println("\tQR=");
  Serial.println("\tTT=");
  Serial.println("\tT1=");
  Serial.println("\tT2=");
  Serial.println("\tT3=");
  Serial.println("\tT4=");
  Serial.println("\tT5=");
  Serial.println("\tSV");
  Serial.println("\tRR");

  initFull(false);
  //display.update();
}
void initFull(bool must) {
  ledcWrite(ledChannel, 100);
  esp_sleep_wakeup_cause_t wakeup_reason;
  if (QRszoveg.length() == 0 && !must) {
    loadInfo();
  }
  int val = analogRead(34);
  int bat = map(val, 1024, 2750, 1000, 2500) * 2;
  display.setFont(NULL);
  display.setTextSize(3);
  display.setCursor(0, 0);
  display.println(Etitle);
  display.setFont(NULL);
  display.setTextSize(1);
  display.setCursor(108, 110);
  display.print(String(bat) + "mV");
  display.drawRect(106, 106, 42, 16, GxEPD_BLACK);
  display.fillRect(148, 110, 2, 8, GxEPD_BLACK);
  display.setTextSize(2);
  display.setCursor(106, 24);
  display.print(Eline1.substring(0, 12));
  display.setCursor(106, 40);
  display.print(Eline2.substring(0, 12));
  display.setCursor(106, 56);
  display.print(Eline3.substring(0, 12));
  display.setCursor(106, 72);
  display.print(Eline4.substring(0, 12));
  display.setCursor(106, 88);
  display.print(Eline5.substring(0, 12));
  if(BLUERUN){
    display.drawBitmap(bluetoothicon, 156, 106, 16, 16, GxEPD_BLACK);
  }
  drawQR(QRszoveg);
  wakeup_reason = esp_sleep_get_wakeup_cause();
  if (wakeup_reason == ESP_SLEEP_WAKEUP_EXT0 && bootCount % 4 != 0 && !must) {
    //Can continue, memory survived
    display.updateWindow(0, 0, 249, 121);
  } else {
    //Have to reinit and redraw display
    //welcome();
    display.update();
  }
  ledcWrite(ledChannel, 0);
}
void drawQR(String text) {
  char __text[text.length()+1];
  text.toCharArray(__text, text.length()+1);
  QRCode qrcode;
  uint8_t qrcodeData[qrcode_getBufferSize(8)];
  //"BEGIN:VCARD\nVERSION:3.0\nN:Daniel;Nemeth;;;\nFN:Nemeth Daniel\nORG:ndtech.hu\nEMAIL:ndaniel@ndtech.hu\nURL:https://ndtech.hu\nEND:VCARD"
  Serial.println("QRDRAW:>>" + String(__text) + "<<");
  Serial.println("QRDRAW_ORIG:>>" + text + "<<");
  qrcode_initText(&qrcode, qrcodeData, 8, 0, __text);
  for (uint8_t y = 0; y < qrcode.size; y++) {
    // Each horizontal module
    for (uint8_t x = 0; x < qrcode.size; x++) {
      display.drawPixel(2 + 2 * x, 24 + 2 * y, qrcode_getModule(&qrcode, x, y) ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawPixel(2 + 2 * x, 24 + 2 * y + 1, qrcode_getModule(&qrcode, x, y) ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawPixel(2 + 2 * x + 1, 24 + 2 * y, qrcode_getModule(&qrcode, x, y) ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawPixel(2 + 2 * x + 1, 24 + 2 * y + 1, qrcode_getModule(&qrcode, x, y) ? GxEPD_BLACK : GxEPD_WHITE);
    }
  }
}
void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param) {
  if (event == ESP_SPP_SRV_OPEN_EVT) {
    Serial.println("BLUETOOTH Client Connected");
    SerialBT.println("Welcome!");
    SerialBT.println("\tQR=");
    SerialBT.println("\tTT=");
    SerialBT.println("\tT1=");
    SerialBT.println("\tT2=");
    SerialBT.println("\tT3=");
    SerialBT.println("\tT4=");
    SerialBT.println("\tT5=");
    SerialBT.println("\tSV");
    SerialBT.println("\tRR");
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  checkSerial();
  if (millis() - lastPress > 90000) {
    //WAKEUP -> 32
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_32, 0);
    display.drawBitmap(sleepicon, 234, 106, 16, 16, GxEPD_BLACK);
    display.fillRect(156, 106, 16, 16, GxEPD_WHITE);
    display.updateWindow(0, 0, 249, 121);
    Serial.println("SLEEP...");
    delay(100);
    esp_sleep_enable_timer_wakeup(sleeptime);
    esp_deep_sleep_start();
  }
  if ((!up) != digitalRead(BTN_UP)) {
    up = !up;
    lastPress = millis();
    if (up == true)lastup = millis();
    else {
      Serial.print("UP TIME: ");
      Serial.println(millis() - lastup);
      long t = millis() - lastup;
      if (t >= 250 && t <= 750) {
        //SHORT PRESS

      } else if (t > 750 && !BLUERUN) {
        //LONG PRESS
        BLUERUN = true;
        SerialBT.begin("ESP32"); //Bluetooth device name
        SerialBT.register_callback(callback);
        display.drawBitmap(bluetoothicon, 156, 106, 16, 16, GxEPD_BLACK);
        display.updateWindow(0, 0, 249, 121);
      }
    }
  }
  if ((!down) != digitalRead(BTN_DOWN)) {
    down = !down;
    lastPress = millis();
    if (down == true)lastdown = millis();
    else {
      Serial.print("DOWN TIME: ");
      Serial.println(millis() - lastdown);
      long t = millis() - lastdown;
      if (t >= 250 && t <= 750) {
        //SHORT PRESS

      } else if (t > 750) {
        //LONG PRESS
        LEDON = !LEDON;
        if (LEDON) {
          ledcWrite(ledChannel, 200);
        } else {
          ledcWrite(ledChannel, 0);
        }
      }
    }
  }
}
void checkSerial() {
  if (Serial.available()) {
    lastPress = millis();
    while (Serial.available()) {
      char c = char(Serial.read());
      if (c == '\n') {
        processCommand(serialBuffer);
        serialBuffer = "";
      }else if(c != '\r'){
        serialBuffer += c;
      }
    }
  }
  if (SerialBT.available()) {
    lastPress = millis();
    while (SerialBT.available()) {
     char c = char(SerialBT.read());
      if (c == '\n') {
        processCommand(blueBuffer);
        blueBuffer = "";
      }else if(c != '\r'){
        blueBuffer += c;
      }
    }
  }
}
void processCommand(String cmd) {
  //QR=/TT=/T1=/T2=/T3=/T4=/T5=/SV/RR
  if (cmd.startsWith("SV") && cmd.length() < 4) {
    //SAVE
    String TEXT_FULL = "QR=" + QRszoveg + "\nTT=" + Etitle + "\nT1=" + Eline1 + "\nT2=" + Eline2+ "\nT3=" + Eline3+ "\nT4=" + Eline4+ "\nT5=" + Eline5 + "\n";
    fs::File f = SPIFFS.open("/qr.txt", "w");
    if (!f) {
      Serial.println("ERROR OPENING FILE FOR WRITE");
      return;
    }
    f.print(TEXT_FULL);
    f.close();
    display.fillScreen(GxEPD_WHITE);
    initFull(true);
    lastCMD = 0;
  }else if(cmd.startsWith("RR")){
    display.fillScreen(GxEPD_WHITE);
    initFull(true);
    lastCMD = 1;
  }else if(cmd.startsWith("QR=")){
    QRszoveg = cmd.substring(3);
    lastCMD = 2;
    //Serial.println("QR=" + QRszoveg);
  }else if(cmd.startsWith("TT=")){
    Etitle = cmd.substring(3,16);
    lastCMD = 3;
  }else if(cmd.startsWith("T1=")){
    Eline1 = cmd.substring(3,15);
    lastCMD = 3;
  }else if(cmd.startsWith("T2=")){
    Eline2 = cmd.substring(3,15);
    lastCMD = 3;
  }else if(cmd.startsWith("T3=")){
    Eline3 = cmd.substring(3,15);
    lastCMD = 3;
  }else if(cmd.startsWith("T4=")){
    Eline4 = cmd.substring(3,15);
    lastCMD = 3;
  }else if(cmd.startsWith("T5=")){
    Eline5 = cmd.substring(3,15);
    lastCMD = 3;
  }else{
    if(lastCMD == 2){
      QRszoveg += "\n" + cmd;
      //Serial.println("QR=" + QRszoveg);
    }
  }
}
void loadInfo() {
  if (SPIFFS.exists("/qr.txt")) {
    TEXT_SPIFFS = "";
    fs::File f = SPIFFS.open("/qr.txt", "r");
    if (f) {
      String line = "";
      while (f.available()) {
        char c = f.read();
        if (c == '\n') {
          processCommand(line);
          line = "";
          TEXT_SPIFFS += "\n";
        }else if (c != '\r') {
          TEXT_SPIFFS += c;
          line += c;
        }
      }
    }
    f.close();

    Serial.println("SPIFFS - INFO: " + TEXT_SPIFFS);
  } else {
    Serial.println("SPIFFS - No file with name: " + String(FILENAME));
  }
}
