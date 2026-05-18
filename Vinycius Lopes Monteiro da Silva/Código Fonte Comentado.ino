// BOTÕES
const int botaoVerde = 2;     // Andar 1
const int botaoVermelho = 4;  // Andar 2
const int botaoAmarelo = 6;   // Andar 3
const int botaoCinza = 8;     // Andar 4
const int botaoAzul = 10;     // Andar 5
const int botaoMarrom = 12;   // Andar 6

// LEDS
const int ledVerde = 3;       // Andar 1
const int ledVermelho = 5;    // Andar 2
const int ledAmarelo = 7;     // Andar 3
const int ledCinza = 9;       // Andar 4
const int ledAzul = 11;       // Andar 5
const int ledMarrom = 13;     // Andar 6

// Variáveis de controle de tempo
unsigned long tempoInicio = 0;
const long tempoEspera = 5000; // 5 segundos por andar
bool elevadorEmUso = false;
int andarDestino = 0;

void setup() {
  // BOTÕES (com INPUT_PULLUP para não precisar de resistores externos)
  pinMode(botaoVerde, INPUT_PULLUP);
  pinMode(botaoVermelho, INPUT_PULLUP);
  pinMode(botaoAmarelo, INPUT_PULLUP);
  pinMode(botaoCinza, INPUT_PULLUP);
  pinMode(botaoAzul, INPUT_PULLUP);
  pinMode(botaoMarrom, INPUT_PULLUP);

  // LEDS
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledCinza, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledMarrom, OUTPUT);
  
  apagarTodos();
}

void loop() {
  // Se o elevador não estiver em movimento, lê os botões
  if (!elevadorEmUso) {
    if (digitalRead(botaoVerde) == LOW) { iniciarAndar(ledVerde); }
    else if (digitalRead(botaoVermelho) == LOW) { iniciarAndar(ledVermelho); }
    else if (digitalRead(botaoAmarelo) == LOW) { iniciarAndar(ledAmarelo); }
    else if (digitalRead(botaoCinza) == LOW) { iniciarAndar(ledCinza); }
    else if (digitalRead(botaoAzul) == LOW) { iniciarAndar(ledAzul); }
    else if (digitalRead(botaoMarrom) == LOW) { iniciarAndar(ledMarrom); }
  }

  // Se estiver em movimento, conta o tempo sem travar o Arduino
  if (elevadorEmUso) {
    if (millis() - tempoInicio >= tempoEspera) {
      digitalWrite(andarDestino, LOW); // Desliga o led do andar
      elevadorEmUso = false;           // Libera o elevador para a próxima chamada
    }
  }
}

// Função para iniciar a viagem
void iniciarAndar(int ledAndar) {
  apagarTodos();                 // Limpa painel
  andarDestino = ledAndar;       // Memoriza o andar que deve acender
  digitalWrite(andarDestino, HIGH); // Liga o led do andar
  tempoInicio = millis();        // Zera o cronômetro
  elevadorEmUso = true;          // Trava o elevador neste estado
}

// FUNÇÃO PARA APAGAR TODOS OS LEDS
void apagarTodos() {
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledCinza, LOW);
  digitalWrite(ledAzul, LOW);
  digitalWrite(ledMarrom, LOW);
}
