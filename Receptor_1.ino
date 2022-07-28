/*Receptor 1*/
/*el que recibe la "A"*/

#include <IRremote.hpp>                       //Librería para IR
int RECV = 11;                            //Pin KY022 a PIN11 Digital  
IRrecv irrecv(11);                   //Se reciben paquetes remotos IR por medio del objeto irrecv
decode_results results;                    // decoficación de los paquetes enviados por ky-005 
void setup() {
  Serial.begin(9600);                     //Iniciando puerto serial en 9600 bauds
  irrecv.enableIRIn();                    // Habilita la recepción de datos
}
void loop() {
  if ((irrecv.decode(&results))==01000001) {          // Cuando se recibe una A
    Serial.println(results.value,HEX);   // impresión de los valores recibidos en formato hexadecimal
    irrecv.resume();                      // Después de recibir, se debe llamar a este para restablecer el receptor y prepararlo para recibir otro código
  }
  delay (100);                            // espera para el siguiente valor
} 
