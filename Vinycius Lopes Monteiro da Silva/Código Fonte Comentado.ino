// =============================================
// ELEVADOR - 6 ANDARES
// =============================================

// Pinos dos botões (andares 1 a 6)
int botoes[] = {2, 4, 6, 8, 10, 12};

// Pinos dos LEDs (andares 1 a 6)
int leds[]   = {3, 5, 7, 9, 11, 13};

const int numAndares = 6;
int andarAtual = 0;        // começa no andar 1 (índice 0)
bool emMovimento = false;  // trava enquanto o elevador se move

void setup() {
  for (int i = 0; i < numAndares; i++) {
    pinMode(botoes[i], INPUT_PULLUP);
    pinMode(leds[i], OUTPUT);
  }

  // Inicia no andar 1 com LED 1 aceso
  apagarTodos();
  digitalWrite(leds[andarAtual], HIGH);
}

void loop() {
  // Ignora botões enquanto o elevador estiver se movendo
  if (emMovimento) return;

  for (int i = 0; i < numAndares; i++) {
    if (digitalRead(botoes[i]) == LOW) {
      delay(50); // debounce: aguarda estabilizar

      // Confirma que ainda está pressionado
      if (digitalRead(botoes[i]) == LOW) {
        moverElevador(i);

        // Espera soltar o botão antes de continuar
        while (digitalRead(botoes[i]) == LOW);
        delay(100);
      }
    }
  }
}

// Move o elevador do andar atual até o destino, acendendo cada LED no caminho
void moverElevador(int destino) {
  if (destino == andarAtual) return; // já está no andar destino

  emMovimento = true;

  if (destino > andarAtual) {
    // Subindo: acende cada LED do andar atual até o destino
    for (int i = andarAtual + 1; i <= destino; i++) {
      apagarTodos();
      digitalWrite(leds[i], HIGH);
      delay(800); // tempo de "viagem" entre andares
    }
  } else {
    // Descendo: acende cada LED do andar atual até o destino
    for (int i = andarAtual - 1; i >= destino; i--) {
      apagarTodos();
      digitalWrite(leds[i], HIGH);
      delay(800);
    }
  }

  andarAtual = destino; // atualiza posição final
  emMovimento = false;

  // LED do andar destino permanece aceso
}

// Apaga todos os LEDs
void apagarTodos() {
  for (int i = 0; i < numAndares; i++) {
    digitalWrite(leds[i], LOW);
  }
}
