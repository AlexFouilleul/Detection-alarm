/*macro definitions of PIR motion sensor pin and LED pin*/
#define PIR 12          // PIR Sensor
#define RED 22          // Red LED
#define BLUE 24         // Blue LED
#define GREEN 23        // Green LED
#define BUZZER 11       // Buzzer

char notes[] = "ccggaagffeeddcc ";
int beats[] = {1,1,1,1,1,1,2,1,1,1,1,1,1,2,4};
int tempo = 300;

int cpt = 0;

void play(char note, int duration)
{
  char names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'c'};
  int freq[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956};
  for(int i=0; i<8; i++)
  {
    if(names[i] == note)
    {
      for(long i=0; i<duration*1000L; i+=freq[i]*2)
      {
        digitalWrite(BUZZER, HIGH);
        delay(freq[i]);
        digitalWrite(BUZZER, LOW);
        delay(freq[i]);
      }
    }
  }
}

void runBuzzer()
{  
  digitalWrite(RED, LOW);  
  Serial.println("Moving people detected");

  tone(BUZZER, 440);
  delay(3000);
} 

void stopBuzzer()
{
    digitalWrite(RED, HIGH); 
    //digitalWrite(BUZZER, LOW);
    noTone(BUZZER);
    Serial.println("Watching");
}
 
void setup()
{
    pinMode(PIR, INPUT);
    Serial.begin(9600); 
    Serial.println("Start alarm");  

    //pinMode(BUZZER, OUTPUT);
    //noTone(BUZZER);
    //digitalWrite(BUZZER, LOW);
    
    pinMode(RED, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    digitalWrite(RED, HIGH);
    digitalWrite(BLUE, HIGH);
    digitalWrite(GREEN, HIGH);
}
 
void loop()
{
  Serial.println("Moving people detected");
  if(digitalRead(PIR))          // if it detects the moving people
  {
      runBuzzer();
      cpt++;
  }
  else
  {
      stopBuzzer();
  }
  //delay(200);
}
