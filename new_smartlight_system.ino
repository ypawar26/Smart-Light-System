#include<SoftwareSerial.h>
SoftwareSerial espSerial(0, 1);
String str;

int buttonValue = 0;

int buzzer = 11;

int button = 8;

int ldr = A5;

int ir = 13; //A0

int led = 2;

void setup() 
{
  Serial.begin (115200);
  espSerial.begin(115200);
  
  pinMode (ldr,INPUT);
  
  pinMode (ir,INPUT);
  
  pinMode(button, INPUT);

  pinMode(buzzer, OUTPUT);

  pinMode (led,OUTPUT);
 }
void loop() 
{
  
  buttonValue = digitalRead(button);

 if(buttonValue != 0){
  digitalWrite(buzzer, HIGH);
  Serial.println('ON');
 }
 else{
  digitalWrite(buzzer, LOW);
  Serial.println('OFF'); 
 }
 
 int statusSensor = digitalRead(ir);

      if (statusSensor == 1)
      {
        digitalWrite(led, LOW);
      }
      else
      {
        digitalWrite(led, HIGH);
        }

  Serial.println(analogRead(A5));
  int ldrStatus = analogRead (ldr);
    if (ldrStatus <=500)
     {
       
       digitalWrite(led, HIGH);
       analogWrite(led,255/5);
       Serial.println('ON');
       
        //if (analogRead(A0)<300)       // IR 1 CODE    
          //     {
            //    digitalWrite(led,HIGH);
              //  analogWrite(led,255);       
                //delay(1000);// micro second
                //Serial.println('ON');
               //} 
            //else 
              //  {
               //   digitalWrite(led,HIGH);
                //  analogWrite(led,255/5);
                 // Serial.println('ON');
               // }
       
     }else 
       {
         
         digitalWrite(led, LOW);
         Serial.println('OFF');
      }
      
      

}
