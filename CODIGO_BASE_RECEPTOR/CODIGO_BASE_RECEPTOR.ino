
/*CONDICIONES
-IMPULSADA POR CORRIENTE DE LENOVO
-SIN CONRRIENTE ALTERNA
-ARDUINO MEGA

FUNCIONA A LA PERFECCION.*/
#include <IRremote.h>                       //Librería para IR
int recibe = 11;                            //Pin KY022 a PIN11 Digital  
IRrecv irrecv(recibe);                   //Se reciben paquetes remotos IR por medio del objeto irrecv
decode_results results;                    // decoficación de los paquetes enviados por ky-005 
void setup() {
  Serial.begin(9600);                     //Iniciando puerto serial en 9600 bauds
  irrecv.enableIRIn();                    // Habilita la recepción de datos
}
void loop() {
  if (irrecv.decode(&results)) {          // Cuando se recibe un código, la información se almacena en "resultados".
    Serial.println(results.value, HEX);   // impresión de los valores recibidos en formato hexadecimal
    irrecv.resume();                      // Después de recibir, se debe llamar a este para restablecer el receptor y prepararlo para recibir otro código
  }
  delay (100);                            // espera para el siguiente valor
}
