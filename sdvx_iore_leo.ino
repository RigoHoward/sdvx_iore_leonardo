/* Sound Voltex controller para Arduino Leonardo
setup conformado con 2 encoders rotatorios de 400ppr 
y 7 botones) 
Autor: Rigo Howard
Usa libreria para Rotary Encoders de pjrc.com*/

#include <Encoder.h>
#include "declarations.h"
#include "pinout_config.h"

void setup() {
  // Inicializa valores y posición de encoders
  currentPositionL = 0;
  knobL.write(0);  
  currentPositionR = 0;
  knobR.write(0);
  // Inicia funcionalidad de mouse
  Mouse.begin();
 
  // Prepara pines para botones
  pinMode(BT_START, INPUT_PULLUP);
  pinMode(BT_A,     INPUT_PULLUP);
  pinMode(BT_B,     INPUT_PULLUP);
  pinMode(BT_C,     INPUT_PULLUP);
  pinMode(BT_D,     INPUT_PULLUP);
  pinMode(BT_FXL,   INPUT_PULLUP);
  pinMode(BT_FXR,   INPUT_PULLUP);
  // Inicia funcionalidad de teclado
  Keyboard.begin();  
}

void loop() {
// Se lee valor de mov. encoder izq.
 long newPositionL = knobL.read();

// Se detecta un cambio de posición en encoder izq.
 if (newPositionL != currentPositionL) { 
   Mouse.move(0, newPositionL / 2, 0); // mueve mouse izq. o der. en relación a la dirección del giro
 }
 // Almacena posición actual de encoder
 currentPositionL = newPositionL;
 // Reinicia valores para próxima lectura
 knobL.write(0);
 newPositionL = 0;

// Se lee valor de mov. encoder der.
 long newPositionR = knobR.read();
// Se detecta un cambio de posición en encoder der. 
 if (newPositionR != currentPositionR) { 
  Mouse.move(newPositionR / 2, 0, 0); // mueve mouse arriba o abajo en relación a la dirección del giro
 }
 // Almacena posición actual de encoder
 currentPositionR = newPositionR; 
 // Reinicia valores par próxima lectura
 knobR.write(0);
 newPositionR = 0;
 
 // Manejo de pulsación de botones
 // BT Start
  static char old_START = LOW;
  char this_START = digitalRead(BT_START);
  if (this_START == LOW && old_START == HIGH)
    Keyboard.press(returnKey);

  if (this_START == HIGH && old_START == LOW)
    Keyboard.release(returnKey);
  old_START = this_START;

 // BT A
  static char old_BTA = LOW;
  char this_BTA = digitalRead(BT_A);
  if (this_BTA == LOW && old_BTA == HIGH)
    Keyboard.press('s');

  if (this_BTA == HIGH && old_BTA == LOW)
    Keyboard.release('s');
  old_BTA = this_BTA;

 // BT B
  static char old_BTB = LOW;
  char this_BTB = digitalRead(BT_B);
  if (this_BTB == LOW && old_BTB == HIGH)
    Keyboard.press('d');

  if (this_BTB == HIGH && old_BTB == LOW)
    Keyboard.release('d');
  old_BTB = this_BTB;

 // BT C
  static char old_BTC = LOW;
  char this_BTC = digitalRead(BT_C);
  if (this_BTC == LOW && old_BTC == HIGH)
    Keyboard.press('j');

  if (this_BTC == HIGH && old_BTC == LOW)
    Keyboard.release('j');
  old_BTC = this_BTC;

 // BT D
  static char old_BTD = LOW;
  char this_BTD = digitalRead(BT_D);
  if (this_BTD == LOW && old_BTD == HIGH)
    Keyboard.press('k');

 if (this_BTD == HIGH && old_BTD == LOW)
    Keyboard.release('k');
  old_BTD = this_BTD;

 // BT FXL
  static char old_FXL = LOW;
  char this_FXL = digitalRead(BT_FXL);
  if (this_FXL == LOW && old_FXL == HIGH)
    Keyboard.press('c');

  if (this_FXL == HIGH && old_FXL == LOW)
    Keyboard.release('c');
  old_FXL = this_FXL;

 // BT FXR
  static char old_FXR = LOW;
  char this_FXR = digitalRead(BT_FXR);
  if (this_FXR == LOW && old_FXR == HIGH)
    Keyboard.press('n');

  if (this_FXR == HIGH && old_FXR == LOW)
    Keyboard.release('n');
  old_FXR = this_FXR;

// Retraso en pulsación evitar registrar doble registro
 delay(DELAY);

}
