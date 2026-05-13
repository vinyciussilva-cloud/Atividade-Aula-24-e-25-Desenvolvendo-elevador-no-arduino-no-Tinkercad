<div align="center">

# 🏢 Elevador Inteligente
### Simulação com Arduino UNO · Tinkercad

<br>

![Arduino](https://img.shields.io/badge/Arduino-UNO-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Tinkercad](https://img.shields.io/badge/Tinkercad-Simulação-FF6D00?style=for-the-badge&logo=autodesk&logoColor=white)
![Language](https://img.shields.io/badge/Linguagem-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Status](https://img.shields.io/badge/Status-Concluído-2ea44f?style=for-the-badge)

<br>

> Simulação de um sistema de elevador inteligente com **6 andares** desenvolvida em Arduino UNO no Tinkercad.
> Expansão do projeto original de 3 andares com amis dificuldades, atendendo ao cenário de ampliação de um prédio comercial imposto.

</div>

---

## 📋 Sobre o Projeto

Uma construtora ampliou um prédio comercial que anteriormente possuía apenas **3 andares**. Após a reforma, o edifício passou a ter **6 andares**, exigindo a modernização completa do sistema de elevador.

O desafio foi expandir o projeto original de forma modular e organizada, mantendo a mesma lógica de controle e adicionando novos componentes ao circuito. O sistema simula com fidelidade o comportamento real de um elevador:

- O elevador **parte sempre do 1º andar** (LED verde aceso por padrão)
- Ao pressionar um botão, o andar atual **apaga** e o solicitado **acende**
- Um delay de `800ms` simula o **tempo de deslocamento** entre andares
- A variável `andarAtual` **rastreia o estado** e evita chamadas redundantes

---

## 🗂 Estrutura do Repositório

```
📁 elevador-arduino/
│
├── 🖼  Print_do_Design.png              — screenshot do circuito no Tinkercad
├── 📄 Código_Fonte_Comentado.ino       — código principal comentado
├── 📄 Explicacao_Logica_Elevador.pdf   — documentação da lógica de expansão
└── 📄 README.md                        — este arquivo
```
---

## 🔌 Mapeamento de Pinos

| Andar | Função    | Pino LED | Pino Botão | Cor do LED   |
|:-----:|-----------|:--------:|:----------:|:------------:|
| 1º    | Térreo    | 3        | 2          | 🟢 Verde     |
| 2º    | —         | 5        | 4          | 🔴 Vermelho  |
| 3º    | —         | 7        | 6          | 🟡 Amarelo   |
| 4º    | —         | 9        | 8          | ⚫ Cinza     |
| 5º    | —         | 11       | 10         | 🔵 Azul      |
| 6º    | Cobertura | 13       | 12         | 🟤 Marrom    |

---

## 🧰 Lista de Componentes

| Componente            | Qtd. | Função                              |
|-----------------------|:----:|-------------------------------------|
| Arduino UNO           | 1    | Microcontrolador principal          |
| LED 5mm               | 6    | Indicador visual do andar atual     |
| Botão push-button     | 6    | Chamada do elevador por andar       |
| Resistor 220 Ω        | 6    | Proteção dos LEDs contra sobrecarga |
| Resistor 10 kΩ        | 6    | Pull-down dos botões                |
| Protoboard 830 pontos | 1    | Montagem e organização do circuito  |
| Cabos jumper          | ~20  | Conexões entre Arduino e protoboard |

---

## 💡 Lógica do Código

### Inicialização

O elevador parte do **1º andar** assim que o Arduino é ligado — sem nenhuma interação necessária.

```cpp
void setup() {
  // configura todos os pinos...

  // LED do 1º andar já nasce aceso
  digitalWrite(ledVerde, HIGH);
}
```

### Chamada de Andar

Ao pressionar qualquer botão, o sistema executa três etapas:

```
[Botão pressionado] → apagarTodos() → delay(800ms) → acender LED do destino
```

```cpp
if (digitalRead(botaoVermelho) == HIGH && andarAtual != 2) {
  apagarTodos();                    // apaga o andar atual
  delay(800);                       // simula o deslocamento
  digitalWrite(ledVermelho, HIGH);  // acende o destino
  andarAtual = 2;                   // atualiza o estado
}
```

### Função `apagarTodos()`

Centraliza o reset visual — todos os LEDs vão a `LOW` de uma vez, garantindo que nunca haja dois andares acesos simultaneamente.

```cpp
void apagarTodos() {
  digitalWrite(ledVerde,    LOW);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo,  LOW);
  digitalWrite(ledCinza,    LOW);
  digitalWrite(ledAzul,     LOW);
  digitalWrite(ledMarrom,   LOW);
}
```

### Variável de Estado

A condição `andarAtual != X` impede que o elevador "viaje" para o andar em que já se encontra, evitando piscadas desnecessárias no LED.

---

## 📐 Diagrama de Funcionamento

```
BOOT
 │
 └─► LED Verde (Andar 1) = ON          ← estado inicial
          │
          ▼
     [ loop() ]
          │
          ├─ botão pressionado? ──NÃO──► aguarda...
          │
          └─ SIM
               │
               ├─ é o andar atual? ──SIM──► ignora
               │
               └─ NÃO
                    │
                    ├─ apagarTodos()
                    ├─ delay(800ms)
                    ├─ acende LED destino
                    └─ atualiza andarAtual
                              │
                              └─► volta ao [ loop() ]
```

---

## 🎯 Objetivos de Aprendizagem

A atividade praticou os seguintes conceitos:

- ✅ Lógica de programação e variáveis de estado
- ✅ Estruturas condicionais (`if / else`)
- ✅ Manipulação de entradas e saídas digitais (`digitalRead` / `digitalWrite`)
- ✅ Uso de `delay()` para simular tempo real
- ✅ Organização modular de código com funções
- ✅ Automação e simulação de sistemas embarcados
- ✅ Raciocínio lógico aplicado à IoT

---

## 🏫 Informações da Atividade

| Campo       | Detalhe                                |
|-------------|----------------------------------------|
| Instituição | SENAI "A. Jacob Lafer"                 |
| Curso       | Técnico em Desenvolvimento de Sistemas |
| Disciplina  | IoT com Arduino e Tinkercad            |
| Atividade   | Aulas 24 e 25 — Elevador no Tinkercad  |
| Plataforma  | Tinkercad (Autodesk)                   |

---

<div align="center">

Feito por **[@vinycius.art](https://github.com/VinyciusXZ)**

</div>
