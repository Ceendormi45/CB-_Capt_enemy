
#include <IRremote.h>      //Librería para IR

IRsend irsend;            //Se transmitirán paquetes remotos IR por medio de la variable irsend,
int RECV = 10;
IRrecv irrecv(10);        //Se reciben paquetes remotos IR por medio del objeto irrecv
decode_results results;   // decoficación de los paquetes enviados por ky-005

/*Emisor 1*/

void setup()
{
  Serial.begin(9600);                   //Iniciando puerto serial en 9600 bauds
  irrecv.enableIRIn();                    // Habilita la recepción de datos
}

void loop() {

 emisor1();
receptor2();
}
void emisor1(){

  irsend.sendNEC(0x00000001, 32);     //se enviara un "A" un mensaje de 8bits
 // Serial.println("send");            
  delay(1000);                 
  }

/*Receptor 1*/
/*el que recibe la "A"*/

void receptor2(){
  if ((irrecv.decode(&results))==0x00000001) {        // Cuando se recibe una U
    Serial.println(results.value, HEX);   // impresión de los valores recibidos en formato hexadecimal
    irrecv.resume();                      // Después de recibir, se debe llamar a este para restablecer el receptor y prepararlo para recibir otro código
  }
  delay (100);                            // espera para el siguiente valor
}
