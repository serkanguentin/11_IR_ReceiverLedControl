#include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>

const int firstLightPin = 8; 
const int secondLightPin = 12; 

void setup() {
    pinMode(firstLightPin, OUTPUT);
    pinMode(secondLightPin, OUTPUT);
    
    Serial.begin(115200);
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
    if (IrReceiver.decode()) {
        if (IrReceiver.decodedIRData.protocol != UNKNOWN) {
            switch(IrReceiver.decodedIRData.command) {
                case 12:
                   digitalWrite(secondLightPin, LOW);
                    digitalWrite(firstLightPin, HIGH);
                    delay(1000); 
                    
                    break;
                case 24:
                digitalWrite(firstLightPin, LOW); 
                    digitalWrite(secondLightPin, HIGH); 
                    delay(1000); 
                   break;
                default:
                   break;
            }
        }
        IrReceiver.resume();
      } 
}