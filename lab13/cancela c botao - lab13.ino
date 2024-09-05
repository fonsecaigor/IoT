#include <Servo.h>

Servo servo9; // CRIA UM OBJETO DO TIPO SERVO9
int botao = 2;
int valorBotao;
int estadoAnteriorBotao = LOW; // Armazena o estado anterior do botão
unsigned long tempoUltimaLeitura = 0; // Armazena o tempo da última leitura
const unsigned long debounceDelay = 50; // Tempo de debounce (50ms)

void setup()
{
  servo9.attach(9); // ASSOCIA O PINO DIGITAL 9 AO OBJETO DO TIPO SERVO
  pinMode(botao, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int leituraBotao = digitalRead(botao);
  
  // Verifica se o botão mudou de estado (debounce)
  if (leituraBotao != estadoAnteriorBotao) {
    tempoUltimaLeitura = millis(); // Atualiza o tempo da última mudança
  }
  
  // Verifica se o tempo de debounce passou
  if ((millis() - tempoUltimaLeitura) > debounceDelay) {
    // Se o botão está pressionado e o estado mudou
    if (leituraBotao != valorBotao) {
      valorBotao = leituraBotao;
      
      if (valorBotao == HIGH) {
        servo9.write(90); // Posiciona o servo em 90 graus
        Serial.println("Cancela Levantada");
      } else {
        servo9.write(0); // Posiciona o servo em 0 graus
        Serial.println("Cancela Baixada");
      }
    }
  }

  estadoAnteriorBotao = leituraBotao; // Atualiza o estado anterior do botão
}
