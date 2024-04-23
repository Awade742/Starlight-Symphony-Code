#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip(34, 6); 

int sensorPin = A0;
int sensorReading;

float normalNoise;
boolean musicStart = false;

uint32_t stars = strip.Color(162, 225, 242);
uint32_t night = strip.Color(0, 0, 0);

void setup() {
  Serial.begin(9600);
  
  pinMode(sensorPin, INPUT);

  strip.begin();
  strip.clear();
  strip.show();

  // sound sensor calibration
  float sum = 0;
  delay(1000);
  for (int i = 0; i < 100; i++){
    sensorReading = analogRead(sensorPin);
    sum += sensorReading;
    delay(20);
  }
  // register the music starting
  if (sensorReading >= 100 && sensorReading != normalNoise){
    musicStart = true;
  }

  normalNoise = sum/100;
  Serial.println(normalNoise);
  delay(3000);

}

void loop() {
  sensorReading = analogRead(sensorPin);
  Serial.println(sensorReading);

  if (musicStart == false){
    delay(200);
    musicLights(stars, night);
    musicStart = !musicStart;
  }
}

void musicLights(uint32_t c1, uint32_t c2){
  // this is for Brahms Lullaby btw. it's in 3/4 time (huzzah!)
  firstNote(c1, 2); // lu
    delay(250);                 // I just like delays they're convenient ok
  secondNote(c1, c2, 2); //lla
    delay(250);
  thirdNote(c1); // by
    delay(500);
  firstNote(c1, 2); // and
    delay(250);
  secondNote(c1, c2, 2); // good
    delay(250);
  thirdNote(c1); // night
    delay(600);
  firstNote(c1, 2); // with
    delay(250);
  secondNote(c1, c2, 2); // ro
    delay(250);
  thirdNote(c1); // ses
    delay(500);
  firstNote(c1, 2); // bed
    delay(250);                
  secondNote(c1, c2, 2); // light
    delay(250);
  firstNote(c1, 2); 
    delay(250);                 
  secondNote(c1, c2, 2); 
    delay(250);
  thirdNote(c1); 
    delay(500);
  firstNote(c1, 2); 
    delay(250);
  secondNote(c1, c2, 2); 
    delay(250);
  thirdNote(c1); 
    delay(600);
  firstNote(c1, 2); 
    delay(250);
  secondNote(c1, c2, 2); 
    delay(250);
  thirdNote(c1); 
    delay(500);
  firstNote(c1, 2); 
    delay(250);                
  secondNote(c1, c2, 2); 
    delay(250); 
  thirdNote(c1);
    delay(500);
  firstNote(c1, 2); 
    delay(250);                 
  secondNote(c1, c2, 2); 
    delay(250);
  thirdNote(c1); 
    delay(500);
  firstNote(c1, 2); 
    delay(250);
  secondNote(c1, c2, 2); 
    delay(250);
  thirdNote(c1); 
    delay(600);
  firstNote(c1, 2); 
    delay(250);
  secondNote(c1, c2, 2); 
    delay(250);
  thirdNote(c1); 
    delay(500);
  firstNote(c1, 2); 
    delay(250);                
  secondNote(c1, c2, 2); 
    delay(250); 
  thirdNote(c1);
    delay(500);
  fourthNote(c1, 100);
    delay(500);
  fourthNote(c1, 255);
    delay(1000);
  fourthNote(c1, 100);
    delay(500);
  fourthNote(c1, 200);
    delay(500);
  fourthNote(c1, 150);
    delay(1000);
  fourthNote(c1, 100);
    delay(1000);
  fourthNote(c1, 50);
    delay(1000);

  strip.clear();
  strip.show();
}

void firstNote(uint32_t c, int num){
  strip.clear();
  strip.show();
  for(int index = 0; index < strip.numPixels(); index++){
    if (index % num == 0){
      strip.setPixelColor(index, c);
    }
  }
  strip.show();
}

void secondNote(uint32_t c1, uint32_t c2, int num){
  strip.clear();
  strip.show();
  for (int index = 0; index < strip.numPixels(); index++){
    if (index % num == 0){
      strip.setPixelColor(index, c2);
    }
    else {
      strip.setPixelColor(index, c1);
    }
  }
  strip.show();
}

void thirdNote(uint32_t c1){
  strip.clear();
  strip.show();
  for (int index = 0; index < strip.numPixels(); index++){
    strip.setPixelColor(index, c1);
  }
  strip.show();
}

void fourthNote(uint32_t c1, int brightness){
  strip.clear();
  strip.show();
  for(int index = 0; index < strip.numPixels(); index++){
    strip.setPixelColor(index, c1);
    strip.setBrightness(brightness);
  }
  strip.show();
}







