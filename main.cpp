#include <Arduino.h>
#include <BleKeyboard.h>

#define PAUSE 13
#define SKIP 12
#define REWIND 14
BleKeyboard bleKeyboard("Amogh's ESP32 Controller", "UCI", 100);

void setup() {
  Serial.begin(115200);
  pinMode(PAUSE, INPUT_PULLUP); 
  pinMode(SKIP, INPUT_PULLUP);
  pinMode(REWIND, INPUT_PULLUP);
  bleKeyboard.begin();
  Serial.println("Starting BLE work!");
  
  Serial.println("BLE Keyboard is now advertising. Check your phone!");
}

void loop() {
  if(bleKeyboard.isConnected()) {
    
    if (digitalRead(PAUSE) == 0) {
      Serial.println("Sending Play/Pause...");
      
      bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);

     
      while(digitalRead(PAUSE) == 0) {
        delay(10); 
      }
    }

    if (digitalRead(SKIP) == 0) {
      Serial.println("Sending skip...");
      
      bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);

      while(digitalRead(SKIP) == 0) {
        delay(10); 
      }
    }

    if (digitalRead(REWIND) == 0) {
      Serial.println("Sending Rewind...");
      
      bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);

     
      while(digitalRead(REWIND) == 0) {
        delay(10); 
      }
    }
      
      // 4. Small debounce delay after release
      delay(100); 
      //Serial.println("Button released, ready for next press.");
    }
  }

