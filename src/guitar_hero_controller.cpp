#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  11, 0, /** 11 = QUANTIDADE DE BOTÕES */
  false, false, false,
  false, false, false,
  false, true, /** { throttle: true } para habilitar a alavanca(WAMMY)  */
  false, false, false);

/** CONFIGURE AQUI OS PINOS DO SEU ARDUINO */
#define VERDE 2
#define VERMELHO 3
#define AMARELO 4
#define AZUL 5
#define LARANJA 6
#define PALHETA_UP 7
#define PALHETA_DOWN 8
#define RIGHT 10
#define LEFT 16
#define SELECT 15
#define START 14
#define WAMMY A3

#define tempoDebounce 0 /** 0 = ZERO DELAY */

bool estadoAnt[10];
unsigned long debounce[10];

void setup() {
  pinMode(VERDE, INPUT_PULLUP);
  pinMode(VERMELHO, INPUT_PULLUP);
  pinMode(AMARELO, INPUT_PULLUP);
  pinMode(AZUL, INPUT_PULLUP);
  pinMode(LARANJA, INPUT_PULLUP);
  pinMode(PALHETA_UP, INPUT_PULLUP);
  pinMode(PALHETA_DOWN, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(SELECT, INPUT_PULLUP);
  pinMode(START, INPUT_PULLUP);
  
  Joystick.begin(true);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(WAMMY));
  Joystick.setThrottle(map(analogRead(WAMMY), 0, 1024, 0, 256));
  
  bool estado;
  if ((millis() - debounce[0]) > tempoDebounce) {
      estado = digitalRead(VERDE);
      if (estado != estadoAnt[0]) {
         Joystick.setButton(0, !estado);
         //Serial.print(estado);
         //Serial.println("u");
         debounce[0] = millis();
      }
      estadoAnt[0] = estado;
  }
  if ((millis() - debounce[1]) > tempoDebounce) {
      estado = digitalRead(VERMELHO);
      if (estado != estadoAnt[1]) {
         Joystick.setButton(1, !estado);
         debounce[1] = millis();
      }
      estadoAnt[1] = estado;
  }
  if ((millis() - debounce[2]) > tempoDebounce) {
      estado = digitalRead(AMARELO);
      if (estado != estadoAnt[2]) {
         Joystick.setButton(2, !estado);
         debounce[2] = millis();
      }
      estadoAnt[2] = estado;
  }
  if ((millis() - debounce[3]) > tempoDebounce) {
      estado = digitalRead(AZUL);
      if (estado != estadoAnt[3]) {
         Joystick.setButton(3, !estado);
         debounce[3] = millis();
      }
      estadoAnt[3] = estado;
  }
  if ((millis() - debounce[4]) > tempoDebounce) {
      estado = digitalRead(LARANJA);
      if (estado != estadoAnt[4]) {
         Joystick.setButton(4, !estado);
         debounce[4] = millis();
      }
      estadoAnt[4] = estado;
  }
  if ((millis() - debounce[5]) > tempoDebounce) {
      estado = digitalRead(PALHETA_UP);
      if (estado != estadoAnt[5]) {
         Joystick.setButton(5, !estado);
         debounce[5] = millis();
      }
      estadoAnt[5] = estado;
  }
  if ((millis() - debounce[6]) > tempoDebounce) {
      estado = digitalRead(PALHETA_DOWN);
      if (estado != estadoAnt[6]) {
         Joystick.setButton(6, !estado);
         debounce[6] = millis();
      }
      estadoAnt[6] = estado;
  }
  if ((millis() - debounce[7]) > tempoDebounce) {
      estado = digitalRead(RIGHT);
      if (estado != estadoAnt[7]) {
         Joystick.setButton(7, !estado);
         debounce[7] = millis();
      }
      estadoAnt[7] = estado;
  }
  if ((millis() - debounce[8]) > tempoDebounce) {
      estado = digitalRead(LEFT);
      if (estado != estadoAnt[8]) {
         Joystick.setButton(8, !estado);
         debounce[8] = millis();
      }
      estadoAnt[8] = estado;
  }
  if ((millis() - debounce[9]) > tempoDebounce) {
      estado = digitalRead(SELECT);
      if (estado != estadoAnt[9]) {
         Joystick.setButton(9, !estado);
         debounce[9] = millis();
      }
      estadoAnt[9] = estado;
  }
  if ((millis() - debounce[10]) > tempoDebounce) {
      estado = digitalRead(START);
      if (estado != estadoAnt[10]) {
         Joystick.setButton(10, !estado);
         debounce[10] = millis();
      }
      estadoAnt[10] = estado;
  }
}