// BOTÕES
int botaoVerde = 2;
int botaoVermelho = 4;
int botaoAmarelo = 6;
int botaoCinza = 8;
int botaoAzul = 10;
int botaoMarrom = 12;

// LEDS
int ledVerde = 3;
int ledVermelho = 5;
int ledAmarelo = 7;
int ledCinza = 9;
int ledAzul = 11;
int ledMarrom = 13;

void setup()
{
  // BOTÕES
  pinMode(botaoVerde, INPUT);
  pinMode(botaoVermelho, INPUT);
  pinMode(botaoAmarelo, INPUT);
  pinMode(botaoCinza, INPUT);
  pinMode(botaoAzul, INPUT);
  pinMode(botaoMarrom, INPUT);

  // LEDS
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledCinza, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledMarrom, OUTPUT);
}

void loop()
{
  // LED VERDE
  if (digitalRead(botaoVerde) == LOW)
  {
    apagarTodos();
    delay(200);
    digitalWrite(ledVerde, HIGH);
    delay(5000);
    digitalWrite(ledVerde, LOW);
  }

  // LED VERMELHO
  if (digitalRead(botaoVermelho) == LOW)
  {
    apagarTodos();
    delay(200);
    digitalWrite(ledVermelho, HIGH);
    delay(5000);
    digitalWrite(ledVermelho, LOW);
  }

  // LED AMARELO
  if (digitalRead(botaoAmarelo) == LOW)
  {
    apagarTodos();
    delay(200);
    digitalWrite(ledAmarelo, HIGH);
    delay(5000);
    digitalWrite(ledAmarelo, LOW);
  }

  // LED CINZA
  if (digitalRead(botaoCinza) == LOW)
  {
    apagarTodos();
    delay(200);
    digitalWrite(ledCinza, HIGH);
    delay(5000);
    digitalWrite(ledCinza, LOW);
  }

  // LED AZUL
  if (digitalRead(botaoAzul) == LOW)
  {
    apagarTodos();
    delay(200);
    digitalWrite(ledAzul, HIGH);
    delay(5000);
    digitalWrite(ledAzul, LOW);
  }

  // MARROM
  if (digitalRead(botaoMarrom) == LOW)
  {
    apagarTodos();
    delay(200);
    digitalWrite(ledMarrom, HIGH);
    delay(5000);
    digitalWrite(ledMarrom, LOW);
  }
}

// FUNÇÃO PARA APAGAR TODOS OS LEDS
void apagarTodos()
{
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledCinza, LOW);
  digitalWrite(ledAzul, LOW);
  digitalWrite(ledMarrom, LOW);
}
