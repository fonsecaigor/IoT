unsigned long tempo_ciclo_padrao = 10000;
unsigned long tempo_mudanca = 3000;       
unsigned long tempo_ultima_mudanca = 0;   

const int buttonPin = 5;
const int vermelhoPin = 12;
const int amareloPin = 10;
const int verdePin = 8;
int buttonState = 0;                      

bool ligado = true;                       

void setup() {
  Serial.begin(9600);                     
  pinMode(buttonPin, INPUT);
  pinMode(vermelhoPin, OUTPUT);
  pinMode(amareloPin, OUTPUT);
  pinMode(verdePin, OUTPUT);
}

void ligar() {
  Serial.println("Ligado");
  digitalWrite(vermelhoPin, LOW);
  digitalWrite(amareloPin, LOW);
  digitalWrite(verdePin, HIGH);
}

void desligar() {
  Serial.println("Desligado");
  digitalWrite(vermelhoPin, HIGH);
  digitalWrite(amareloPin, LOW);
  digitalWrite(verdePin, LOW);
}

void mudando() {
  Serial.println("Mudando");   
  digitalWrite(vermelhoPin, LOW);
  digitalWrite(amareloPin, HIGH);
  digitalWrite(verdePin, LOW);
  delay(tempo_mudanca);                   
  ligado = !ligado;                       
  tempo_ultima_mudanca = millis();        
}

void loop() {
  unsigned long tempo_atual = millis();   
  buttonState = digitalRead(buttonPin);   
  
  
  if (tempo_atual - tempo_ultima_mudanca >= tempo_ciclo_padrao || buttonState == LOW) {
    mudando();                            
  }
  
  if (ligado) {
    ligar();                              
  } else {
    desligar();                           
  }

  delay(100);                             
}

