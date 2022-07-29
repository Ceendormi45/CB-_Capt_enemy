#include <IRremote.h>      //Librería para IR

IRsend irsend;            //Se transmitirán paquetes remotos IR por medio de la variable irsend,
int RECV = 10;
IRrecv irrecv(10);        //Se reciben paquetes remotos IR por medio del objeto irrecv
decode_results results;   // decoficación de los paquetes enviados por ky-005

/*main*/
void setup()
{
 
  Serial.begin(9600);                   //Iniciando puerto serial en 9600 bauds
  irrecv.enableIRIn();
}

void loop() {

  
 receptor1();
 emisor2();

}

/*Receptor 1*/
/*el que recibe la "A"*/

void receptor1(){
  if ((irrecv.decode(&results))==1) {        // Cuando se recibe una U
    Serial.println(results.value, HEX);   // impresión de los valores recibidos en formato hexadecimal
    irrecv.resume();                      // Después de recibir, se debe llamar a este para restablecer el receptor y prepararlo para recibir otro código
  }
  delay (1000);                            // espera para el siguiente valor
}

//emisor 2
void emisor2(){

  irsend.sendNEC(0x00000002, 32);     //se enviara un "A" un mensaje de 8bits
  Serial.println("send");            //se imprimirá "send" como confirmación
  delay(1000);                 //esperaremos 100ms
  
  }
