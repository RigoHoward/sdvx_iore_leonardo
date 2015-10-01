// Cambiar números de los dos pines tienen capacidad de interrupcion
// Rendimiento Aceptable: un sólo pin tiene capacidad de interrupción
// Bajo Rendimiento: ninguno de los pines tiene capacidad de interrupción
// *NO usar pines con función de LED integrado*

// Pines para fases de encoders 
// Arduino Leonardo tiene 4 (3, 2, 1, 0) pines con capacidad de interrupción
#define LVOL_A 0
#define LVOL_B 1
#define RVOL_A 2
#define RVOL_B 3

// Pines para botones
#define BT_START 4
#define BT_A 5
#define BT_B 6
#define BT_C 7
#define BT_D 8
#define BT_FXL 9
#define BT_FXR 10
