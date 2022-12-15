#include <ArduinoBLE.h>
#include <Adafruit_NeoPixel.h>

/* definitions of sensors pins */
#define LEDALARM 12     // WS2812B LED
#define BUZZER 11       // Buzzer
#define PIR A6          // PIR Sensor
#define BUTTON A6       // Button

/* globales variables */
uint32_t cpt = 0;
uint32_t activation_state = 1;

/* object and services definition */
BLEService customService("19b10000-e8f2-537e-4f6c-d104768a1214");
BLEUnsignedIntCharacteristic nb_detected("19b10001-e8f2-537e-4f6c-d104768a1214", BLERead | BLENotify);
BLEUnsignedIntCharacteristic activation("19b10002-e8f2-537e-4f6c-d104768a1214", BLERead | BLENotify | BLEWrite);
BLEUnsignedIntCharacteristic pin_code("19b10003-e8f2-537e-4f6c-d104768a1214", BLERead | BLENotify | BLEWrite);
Adafruit_NeoPixel led_alarm = Adafruit_NeoPixel(8, LEDALARM, NEO_GRB + NEO_KHZ800);

void runBuzzer() {
  cpt++;
  led_alarm.fill(led_alarm.Color(255,0,0), 0, 8);
  led_alarm.show();
  for (int rep=0; rep<5; rep++) {
    for (int freq=1400; freq<=1600; freq++) {
      tone(BUZZER, freq);
      delay(5);
    }
  }
  tone(BUZZER, 0);
}

void stopBuzzer() {
  led_alarm.clear();
  led_alarm.show();
  noTone(BUZZER);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Start alarm");

  pinMode(BUTTON, INPUT);
  pinMode(PIR, INPUT);
  
  pinMode(BUZZER, OUTPUT);
  tone(BUZZER, 0);

  led_alarm.begin();
  led_alarm.clear();
  led_alarm.show();
  led_alarm.setBrightness(5);

  // Bluetooth
  BLE.begin();                                      // start bluetooth
  BLE.setLocalName("Detection alarm");              // set device name
  BLE.setAdvertisedService(customService);          // set advertised service UUID
  customService.addCharacteristic(nb_detected);     // add the characteristics to the service
  customService.addCharacteristic(activation);
  customService.addCharacteristic(pin_code);
  BLE.addService(customService);                    // add service
  BLE.setConnectable(true);                         // define possibility to connect to this device
  BLE.advertise();                                  // start advertising
}

void loop()
{
  BLEDevice central = BLE.central();      // listen for connection by others devices

  if(central)                             // if a device is connected to the system
  {
    led_alarm.fill(led_alarm.Color(0,0,255), 0, 8);
    led_alarm.show();
    nb_detected.writeValue(cpt);
    // Gérer l'envoie de juste une data
    //cpt = 0;
    if(activation.written()) {            // if received data
      activation_state = activation.value();
      if(activation_state == 0) {         // long bip if disabled
        tone(BUZZER, 1000);
        delay(200);
        tone(BUZZER, 0);
      }
      else {                              // 2 bip if enabled
        tone(BUZZER, 659);
        delay(200);
        tone(BUZZER, 0);
        delay(50);
        tone(BUZZER, 659);
        delay(200);
        tone(BUZZER, 0);
      }
    }
  }
  else if(activation_state == 1) {        // if alarm is enabled
    if(digitalRead(PIR) || digitalRead(BUTTON))
      runBuzzer();
    else
      stopBuzzer();
  }
}
