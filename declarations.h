#include <Encoder.h>
#include "Arduino.h"
#include "pinout_config.h"

// Declaración de encoders
Encoder knobL(LVOL_B, LVOL_A);
Encoder knobR(RVOL_B, RVOL_A);

// Valor actual de posición de cada encoder
long currentPositionL;
long currentPositionR;

// Asigna tecla "Enter" para boton start
 char returnKey = KEY_RETURN; 

// Tiempo de retraso en ms para resp. de botones
#define DELAY    5
