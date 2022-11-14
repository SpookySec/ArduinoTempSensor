#include <DHT.h>
#include <MD_Parola.h>
#include <LiquidCrystal.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>

const uint16_t WAIT_TIME = 1000;

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define DHT_TYPE DHT11

#define CLK_PIN   11
#define DATA_PIN  13
#define CS_PIN    12
#define DHT_PIN   7

MD_Parola display = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
DHT sensor = DHT(DHT_PIN, DHT_TYPE);
String load = "0";

void setup(void) {
  display.begin();
  sensor.begin();

  delay(2000);
}

void loop(void) {
  float temp = sensor.readTemperature();

  if (isnan(temp)) {
    // display.displayClear();
    display.print("Error!");
    delay(5000);
    return;
  }

  // display.displayClear();
  display.print(String(temp) + "C");
  // display.print("C");

  delay(500);
}