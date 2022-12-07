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
int detected = 0;           // 0 = False, 1 = True

void play(char note, int duration)
{
  char names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'c'};
  int tones[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956};
  for(int i=0; i<8; i++)
  {
    if(names[i] == note)
    {
      for(long i=0; i<duration*1000L; i+=tones[i]*2)
      {
        digitalWrite(BUZZER, HIGH);
        delay(tones[i]);
        digitalWrite(BUZZER, LOW);
        delay(tones[i]);
      }
    }
  }
}

void runBuzzer()
{  
  digitalWrite(RED, HIGH);  
  Serial.println("Moving people detected");
  for(int i=0; i<15; i++)   
  {  
    if (notes[i] == ' ')  
    {  
      delay(beats[i]*tempo);      // rest  
    }  
    else  
    {  
      play(notes[i], beats[i]*tempo);  
    }  
    delay(tempo/2);         // pause between notes  
  }  
} 

void stopBuzzer()
{
    digitalWrite(RED, HIGH); 
    digitalWrite(BUZZER, LOW);
    Serial.println("Watching");
}
 
void setup()
{
    pinMode(PIR, INPUT);
    Serial.begin(9600);   
    
    pinMode(RED, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    digitalWrite(RED, HIGH);
    digitalWrite(BLUE, HIGH);
    digitalWrite(GREEN, HIGH);
}
 
void loop()
{
    if(digitalRead(PIR))          // if it detects the moving people
    {
        runBuzzer();
        cpt++;
    }
    else
    {
        stopBuzzer();
    }
 
 delay(200);
}
