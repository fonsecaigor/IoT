int pir = 10;
int led = 2;

void setup() {
  pinMode(pir, INPUT);  
  pinMode(led, OUTPUT); 
  Serial.begin(9600);   
}

void loop() {
  int pirState = digitalRead(pir);  

  if (pirState == HIGH) {  
    Serial.println("Movimento detectado!");  
    digitalWrite(led, HIGH);  
    delay(500);  
    digitalWrite(led, LOW);  
    delay(500);  
  } else {
    digitalWrite(led, LOW);  
  }
}