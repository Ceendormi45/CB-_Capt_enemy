#include <IRremote.h>      //Librería para IR

IRsend irsend;            //Se transmitirán paquetes remotos IR por medio de la variable irsend,
int RECV = 10;
IRrecv irrecv(10);        //Se reciben paquetes remotos IR por medio del objeto irrecv
decode_results results;   // decoficación de los paquetes enviados por ky-005

/*Emisor 1*/

void setup()
{
 
  Serial.begin(9600);                   //Iniciando puerto serial en 9600 bauds
  irrecv.enableIRIn();
}

void loop() {

  
 receptor2();
 emisor1();

}

/*Receptor 2*/


void receptor2(){
  if ((irrecv.decode(&results))==1) {        // Cuando se recibe un 1
    Serial.println(results.value, HEX);   // impresión de los valores recibidos en formato hexadecimal lo traduce en 2
    irrecv.resume();                      // Después de recibir, se debe llamar a este para restablecer el receptor y prepararlo para recibir otro código
  }
  delay (1000);                            // espera para el siguiente valor
}

//emisor1
void emisor1(){

  irsend.sendNEC(0x00000002, 32);     //se enviara un no se sabe
  Serial.println("send");            //se imprimirá "send" como confirmación
  delay(1000);                 //esperaremos 100ms
  
  }
/*conseguir 4 protoboards pequenos*/
