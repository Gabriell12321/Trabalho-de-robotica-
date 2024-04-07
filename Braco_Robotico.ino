/*********************************************/
/* Projeto - Braço Robótico                  */
/* Abaixo um exemplo de código controlará o  */
/* braço robótico utilizando a placa joystick*/
/* shield. A seleção do servomotor a ser     */
/* controlado é feita através dos botões A,  */
/* B, C e D. O movimento da base e da garra  */
/* do braço é feito através do movimento do  */
/* joystick na direçao do eixo x e dos       */
/* servomotores das laterais do braço é feito*/
/* movendo o joystick no eixo y.             */
/*********************************************/
/* Inclui a biblioteca Servo.                */
#include <Servo.h>
/* Definição das portas dos botões.          */
#define btA 2
#define btB 3
#define btC 4
#define btD 5

/* Váriáveis auxiliares.                     */
int potA0, potA1, incremento = 1;
char escolha;

/* Definindo o ângulo inicial dos servos.    */
int angBase = 90;
int angDir = 90;
int angEsq = 90;
int angGuarra = 90;

/* Criando objetos de controle dos servos.   */
Servo servo_9;
Servo servo_10;
Servo servo_11;
Servo servo_12;

void setup() {
  /* Configurando o modo de operação das     */
  /* portas dos botões ativando o resistor   */
  /* interno do Arduino.                     */
  pinMode(btA, INPUT_PULLUP);
  pinMode(btB, INPUT_PULLUP);
  pinMode(btC, INPUT_PULLUP);
  pinMode(btD, INPUT_PULLUP);
  /* Definindo as portas dos servos.         */
  servo_9.attach(9);
  servo_10.attach(10);
  servo_11.attach(11);
  servo_12.attach(12);
  /* Posiciona os servos no angulo inicial.  */
  servo_9.write(angBase);
  servo_10.write(angDir);
  servo_11.write(angEsq);
  servo_12.write(angGuarra);
}
void loop() {
  /* Guarda os valores analógicos dos        */
  /* potenciômetros do joystick.             */
  potA0 = analogRead(A0);
  potA1 = analogRead(A1);
  /* Se for pressionado o botão A.           */
  if (digitalRead(btA) == 0) {
    /* Defina a escolha como A.              */
    escolha = 'A';
  }
  /* Se for pressionado o botão B.           */
  if (digitalRead(btB) == 0) {
    /* Defina a escolha como B.              */
    escolha = 'B';
  }
  /* Se for pressionado o botão C.           */
  if (digitalRead(btC) == 0) {
    /* Defina a escolha como C.              */
    escolha = 'C';
  }
  /* Se for pressionado o botão D.           */
  if (digitalRead(btD) == 0) {
    /* Defina a escolha como D.              */
    escolha = 'D';
  }
  /* Após um botão ser pressionado, entrará  */
  /* em um dos quatro modos de operação (A,  */
  /* B, C e D).                              */
  switch (escolha) {
    /* Caso a escolha for A.                 */
    case 'A':
      /* Se o joystick for deslocado para a  */
      /* esquerda e o ângulo do servo da     */
      /* garra for menor que 100°, abrirá a  */
      /* garra.                              */
      if (potA0 > 700 && angGuarra < 100) {
        /* Posiciona o servo no ângulo atual */
        servo_12.write(angGuarra);
        /* Incrementa o valor do ângulo.     */
        angGuarra = angGuarra + incremento;
        /* Aguarda 50 milissegundos para     */
        /* atualizar o ângulo.               */
        delay(50);
      }
      /* Se o joystick for deslocado para a  */
      /* direita e o ângulo do servo da      */
      /* garra for maior que 60°, fechará a  */
      /* garra.                              */
      if (potA0 < 300 && angGuarra > 60) {
        /* Posiciona o servo no ângulo atual.*/
        servo_12.write(angGuarra);
        /* Decrementa o valor do ângulo.     */
        angGuarra = angGuarra - incremento;
        /* Aguarda 50 milissegundos para     */
        /* atualizar o ângulo.               */
        delay(50);
      }
      /* Final desse caso.                   */
      break;
    /* Caso a escolha for B.                 */
    case 'B':
      /* Se o joystick for deslocado para    */
      /* frente e o ângulo do servo da       */
      /* direita for menor que 180°,         */
      /* abaixará o braço.                   */
      if (potA1 > 700 && angDir < 180) {
        /* Posiciona o servo no ângulo atual.*/
        servo_10.write(angDir);
        /* Incrementa o valor do ângulo.     */
        angDir = angDir + incremento;
        /* Aguarda 50 milissegundos para     */
        /* atualizar o ângulo.               */
        delay(50);
      }
      /* Se o joystick for deslocado para    */
      /* trás e o ângulo do servo da direita */
      /* for maior que 50º, levantará o braço.*/ 
      if (potA1 < 300 && angDir > 50) {
        /* Posiciona o servo no ângulo atual.*/
        servo_10.write(angDir);
        /* Decrementa o valor do ângulo.     */
        angDir = angDir - incremento;
        /* Aguarda 50 milissegundos para     */
        /* atualizar o ângulo.               */
        delay(50);
      }
      /* Final desse caso.                   */
      break;
    /* Caso a escolha for C.                 */
    case 'C':
      /* Se o joystick for deslocado para a  */
      /* direita e o ângulo do servo da base */
      /* for menor que 180°, o braço girará  */
      /* no sentido horário.                 */
      if (potA0 < 300 && angBase < 180) {
        /* Posiciona o servo no ângulo atual.*/
        servo_9.write(angBase);
        /* Incrementa o valor do ângulo.     */
        angBase = angBase + incremento;
        /* Aguarda 50 milissegundos para    */
        /* atualizar o ângulo.              */
        delay(50);
      }
      /* Se o joystick for deslocado para a  */
      /* esquerda e o ângulo do servo da     */
      /* base for maior que 0°, o braço      */
      /* girará no sentido anti-horário.     */
      if (potA0 > 700 && angBase > 0) {
        /* Posiciona o servo no ângulo atual.*/
        servo_9.write(angBase);
        /* Decrementa o valor do ângulo.     */
        angBase = angBase - incremento;
        /* Aguarda 50 milissegundos para     */
        /* atualizar o ângulo.               */
        delay(50);
      }
      /* Final desse caso.                   */
      break;
    /* Caso a escolha for D.                 */
    case 'D':
      /* Se o joystick for deslocado para    */
      /* frente e o ângulo do servo da       */
      /* esquerda for menor que 180°,        */
      /* levantará o antebraço.              */
      if (potA1 > 700 && angEsq < 180) {
        /* Posiciona o servo no ângulo atual.*/
        servo_11.write(angEsq);
        /* Incrementa o valor do ângulo.     */
        angEsq = angEsq + incremento;
        /* Aguarda 50 milissegundos para     */
        /* atualizar o ângulo.               */
        delay(50);
      }
      /* Se o joystick for deslocado para    */
      /* trás e o ângulo do servo da         */
      /* esquerda for maior que 90°,         */
      /* abaixará o antebraço.               */
      if (potA1 < 300 && angEsq > 90) {
        /* Posiciona o servo no ângulo atual.*/
        servo_11.write(angEsq);
        /* Decrementa o valor do ângulo.     */
        angEsq = angEsq - incremento;
        /* Aguarda 50 milissegundos para     */
        /* atualizar o ângulo.               */
        delay(50);
      }
      /* Final desse caso.                   */
      break;
  }
}
