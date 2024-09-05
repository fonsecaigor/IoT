int piezzo = 12;
int tmp = A0;
int thresholdTemp1 = 30;
int thresholdTemp2 = 90; 

bool messageDisplayed = false;  

void setup() {
  pinMode(piezzo, OUTPUT);
  pinMode(tmp, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(tmp);
  float voltage = sensorValue * (5.0 / 1023.0); 
  
  float temperatureC = (voltage - 0.5) * 100.0;
  
  Serial.print("Temperatura: ");
  Serial.print(temperatureC);
  Serial.println(" *C");

  if (temperatureC >= thresholdTemp1 && !messageDisplayed) {
    Serial.println("Temperatura chegou a 30°C");
    messageDisplayed = true;
  }

  if (temperatureC >= thresholdTemp2) {
    tone(piezzo, 1500); 
  } else {
    noTone(piezzo);
  }

  delay(1000);
}