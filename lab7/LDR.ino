int led = 10;
int ldrsensor = A0;
int  ldrvalue = 0;

void setup(){
  pinMode(led, OUTPUT);
  pinMode(ldrsensor, INPUT);
  Serial.begin(9600);
}

void loop(){
  ldrvalue = analogRead(ldrsensor);
  Serial.println(ldrvalue);
  
  if ((ldrvalue) < 500 ){
  	digitalWrite(led, HIGH);
  }
   else{
     digitalWrite(led, LOW);
   }
}