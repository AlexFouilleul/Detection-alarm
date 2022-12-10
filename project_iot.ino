#include <Adafruit_NeoPixel.h>
#include <ArduinoBLE.h>

/* definitions of sensors pins */
#define PIR 12          // PIR Sensor
#define RED 22          // Red LED
#define BLUE 24         // Blue LED
#define GREEN 23        // Green LED
#define BUZZER 11       // Buzzer
#define LED_RGB A6      // WS2812 LED

/* globales variables */
int cpt = 0;
int NB_LED = 5;

/* object and services definition */
//Adafruit_NeoPixel led_alarm = Adafruit_NeoPixel(NB_LED, LED_RGB, NEO_GRB + NEO_KHZ800);
BLEService customService("19b10000-e8f2-537e-4f6c-d104768a1214");                           // Service Bluetooth Arduino
BLEUnsignedIntCharacteristic test("19b10001-e8f2-537e-4f6c-d104768a1214", BLERead | BLENotify);

void runBuzzer()
{ 
  cpt++;
  digitalWrite(RED, LOW); 
  for(int rep=0; rep<5; rep++)
  {
    for(int freq=1400; freq<=1600; freq++)
    {
      tone(BUZZER, freq);
      delay(5);
    }
  }
  tone(BUZZER, 0);
} 

void stopBuzzer()
{
    digitalWrite(RED, HIGH); 
    noTone(BUZZER);
}
 
void setup()
{
    // PIR sensor
    pinMode(PIR, INPUT);

    // Serial communication
    Serial.begin(9600); 
    Serial.println("Start alarm");  

    // Buzzer
    pinMode(BUZZER, OUTPUT);
    tone(BUZZER, 0);
    
    // Bluetooth
    if (!BLE.begin())
    {
      Serial.println("Failed.");
      while(1);
    }
    BLE.setLocalName("Alarm");                    // set device name
    BLE.setAdvertisedService(customService);      // set advertised service UUID
    customService.addCharacteristic(test);        // add the characteristic to the service
    BLE.addService(customService);                // add service
    BLE.setConnectable(true);                     // define possibility to connect to this device
    BLE.advertise();                              // start advertising

    // LED
    pinMode(RED, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    digitalWrite(RED, HIGH);
    digitalWrite(BLUE, HIGH);
    digitalWrite(GREEN, HIGH);
}
 
void loop()
{
  BLEDevice central = BLE.central();      // listen for connection by others devices

  if(digitalRead(PIR))                    // if it detects the moving people
  {
      runBuzzer();
  }
  else
  {
      stopBuzzer();
  }
}
