/*

  O sensor de som capta o barulho do ambiente e o Arduino classifica
  essa leitura em três faixas, acendendo um LED para cada uma delas.
  As leituras também são enviadas para o Serial Monitor, para que a
  turma possa registrar os dados e transformá-los em gráfico depois.

  Autor: Eduardo Domingues
  Licença: CC BY 4.0
*/

// ---------------------------------------------------------------
// Pinos
// ---------------------------------------------------------------
const int PINO_SENSOR   = A0;
const int PINO_VERDE    = 11;
const int PINO_AMARELO  = 12;
const int PINO_VERMELHO = 13;

// ---------------------------------------------------------------
// Limiares de classificação
//
// ATENÇÃO: estes dois valores precisam ser ajustados pela turma.
// Eles funcionam como referência inicial, mas cada sala, cada
// sensor e cada posição na mesa produzem leituras diferentes.
// Faça a calibração antes de confiar no semáforo.
// ---------------------------------------------------------------
int limiteBaixo = 300;   // abaixo disso o ambiente é considerado silencioso
int limiteAlto  = 600;   // acima disso o ruído é considerado excessivo

// Intervalo entre uma leitura e outra, em milissegundos
const int INTERVALO = 200;

void setup() {
  Serial.begin(9600);

  pinMode(PINO_VERDE, OUTPUT);
  pinMode(PINO_AMARELO, OUTPUT);
  pinMode(PINO_VERMELHO, OUTPUT);

  Serial.println("Semaforo do Silencio iniciado");
  Serial.println("Leitura | Faixa");
}

void loop() {
  int leitura = analogRead(PINO_SENSOR);

  apagarTodos();

  if (leitura < limiteBaixo) {
    digitalWrite(PINO_VERDE, HIGH);
    registrar(leitura, "silencio");
  } else if (leitura < limiteAlto) {
    digitalWrite(PINO_AMARELO, HIGH);
    registrar(leitura, "conversa produtiva");
  } else {
    digitalWrite(PINO_VERMELHO, HIGH);
    registrar(leitura, "ruido excessivo");
  }

  delay(INTERVALO);
}

// ---------------------------------------------------------------
// Apaga os três LEDs antes de decidir qual deve acender.
// Sem isso, dois LEDs poderiam ficar acesos ao mesmo tempo.
// ---------------------------------------------------------------
void apagarTodos() {
  digitalWrite(PINO_VERDE, LOW);
  digitalWrite(PINO_AMARELO, LOW);
  digitalWrite(PINO_VERMELHO, LOW);
}

// ---------------------------------------------------------------
// Envia a leitura para o Serial Monitor junto com a faixa.
// ---------------------------------------------------------------
void registrar(int valor, String faixa) {
  Serial.print(valor);
  Serial.print(" | ");
  Serial.println(faixa);
}
