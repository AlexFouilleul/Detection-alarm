#include <ArduinoBLE.h>

/* definitions of sensors pins */
#define PIR 12          // PIR Sensor
#define RED 22          // Red LED
#define BLUE 24         // Blue LED
#define GREEN 23        // Green LED
#define BUZZER 11       // Buzzer
#define LED_RGB A6      // WS2812 LED

/* globales variables */
uint32_t cpt = 0;
uint32_t activation_state = 0

/* object and services definition */
BLEService customService("19b10000-e8f2-537e-4f6c-d104768a1214");                           // Service Bluetooth Arduino
BLEUnsignedIntCharacteristic nb_detected("19b10001-e8f2-537e-4f6c-d104768a1214", BLERead | BLENotify);
BLEUnsignedIntCharacteristic activation("19b10002-e8f2-537e-4f6c-d104768a1214", BLERead | BLENotify | BLEWrite);

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
    // Serial communication
    Serial.begin(9600); 
    Serial.println("Start alarm");
    
    // PIR sensor
    pinMode(PIR, INPUT);

    // Buzzer
    pinMode(BUZZER, OUTPUT);
    tone(BUZZER, 0);
    
    // Bluetooth
    BLE.begin();                                      // start bluetooth
    BLE.setLocalName("Detection alarm");              // set device name
    BLE.setAdvertisedService(customService);          // set advertised service UUID
    customService.addCharacteristic(nb_detected);     // add the characteristics to the service
    customService.addCharacteristic(activation);
    BLE.addService(customService);                    // add service
    BLE.setConnectable(true);                         // define possibility to connect to this device
    BLE.advertise();                                  // start advertising

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

  if(central)                             // if a device is connected to the system
  {
    digitalWrite(BLUE, LOW); 
    nb_detected.writeValue(cpt);
    // Gérer l'activation/désactivation de l'alarme
    // Gérer l'envoie de juste une data
    //cpt = 0;
  }
  else
  {
    digitalWrite(BLUE, HIGH); 
    if(digitalRead(PIR))                    // if it detects the moving people
    {
      runBuzzer();
    }
    else
    {
      stopBuzzer();
    }
  }

  
}
