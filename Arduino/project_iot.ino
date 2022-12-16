#include <ArduinoBLE.h>
#include <Adafruit_NeoPixel.h>

/* definitions of sensors pins */
#define LEDALARM 12                                     // WS2812B LED
#define BUZZER 11                                       // Buzzer
#define PIR A6                                          // PIR Sensor
#define BUTTON A6                                       // Button

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
  for(int rep=0; rep<5; rep++) {
    for(int freq=1400; freq<=1600; freq++) {
      tone(BUZZER, freq);
      led_alarm.setBrightness((int)map(freq, 1400, 1600, 1, 20));
      led_alarm.show();
      delay(5);
    }
  }
  tone(BUZZER, 0);
}

void stopBuzzer() {
  led_alarm.clear();
  led_alarm.show();
  led_alarm.setBrightness(10);
  noTone(BUZZER);
}

void setAlarmState() {
  nb_detected.writeValue(cpt);
  if(activation.written()) {                            // if data received 
    activation_state = activation.value();
    if(activation_state == 0) {                         // long bip if disabled
      tone(BUZZER, 1000, 200);
      delay(250);
      tone(BUZZER, 1000, 200);
    }
    else                                                // 2 bip if enabled
      tone(BUZZER, 1000, 500);
  }
  led_alarm.fill(led_alarm.Color(0,0,255), 0, 8);       // if disabled = full blue led, if enabled = extremity led red
  if(activation_state == 1) {
    led_alarm.setPixelColor(0, led_alarm.Color(255,0,0));
    led_alarm.setPixelColor(1, led_alarm.Color(255,0,0));
    led_alarm.setPixelColor(6, led_alarm.Color(255,0,0));
    led_alarm.setPixelColor(7, led_alarm.Color(255,0,0));
  }
  led_alarm.show();
}

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(PIR, INPUT);
  pinMode(BUZZER, OUTPUT);
  tone(BUZZER, 0);

  led_alarm.begin();
  led_alarm.clear();
  led_alarm.show();
  led_alarm.setBrightness(10);

  BLE.begin();                                          // start bluetooth
  BLE.setLocalName("Detection alarm");                  // set device name
  BLE.setAdvertisedService(customService);              // set advertised service UUID
  customService.addCharacteristic(nb_detected);         // add the characteristics to the service
  customService.addCharacteristic(activation);
  customService.addCharacteristic(pin_code);
  BLE.addService(customService);                        // add service
  BLE.setConnectable(true);                             // define possibility to connect to this device
  BLE.advertise();                                      // start advertising
}

void loop()
{
  BLEDevice central = BLE.central();                    // listen for connection by others devices

  if(central) {                                         // if device is connected to the system
    setAlarmState();
    // Gérer l'envoie de juste une data
    //cpt = 0;
  }
  else if(activation_state == 1) {
    if(digitalRead(PIR) || digitalRead(BUTTON))
      runBuzzer();
    else
      stopBuzzer();
  }
  else
    stopBuzzer();
}
