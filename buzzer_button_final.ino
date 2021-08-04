int ButtonValue = 0;

int led = 11;

int Button = 8;

void setup(){

pinMode(button, INPUT)

pinMode(led, OUTPUT)
}

void loop(){

ButtonValue = digitalRead(button);

 if(ButtonValue! = 0){
	digitalWrite(led, HIGH);
 }
 else{
	digitalWrite(led, LOW);
 }
}	
