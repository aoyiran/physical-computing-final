
#include <SparkButton.h>
#include "Particle.h"
#include "neopixel.h"
SparkButton b = SparkButton();
SYSTEM_MODE(AUTOMATIC);


#define PIXEL_PIN D2
#define PIXEL_COUNT 59
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int ledPin = D2;
int knockSensor = 0;               
byte val = 0;
int statePin = LOW;
int THRESHOLD = 50;

String lightSignal;

void setup() {
  strip.begin();
  strip.show(); 
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);
  Spark.function("twitter",twitter); //function for twitter notification
  b.begin();
}


void loop() {
    val = analogRead(knockSensor);     
  if (val >= THRESHOLD) {
    colorWipe(strip.Color(255, 255, 255), 150); 
    colorWipe(strip.Color(0, 0, 0), 150); 
    Serial.println("NOISY!");
  }
         delay(1000);
  }
  
  int twitter(String args){
    colorWipe(strip.Color(255, 255, 255), 150); 
    colorWipe(strip.Color(0, 0, 0), 150); 
    Serial.println("TRASH!");
  }
      

void colorWipe(uint32_t color, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, color);
      strip.show();
      delay(10);
  }
}
