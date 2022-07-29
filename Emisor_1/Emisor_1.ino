/*Emisor 1*/

#include <IRremote.h>      //Librería para IR

IRsend irsend;            //Se transmitirán paquetes remotos IR por medio de la variable irsend,
                          //automáticamente utiliza el pin3 como salida para que el LED envié el paquete de datos
//int b = 11;               //Push button en el pin 11
//int valor;                //Variable para el valor ALTO/BAJO del push button

void setup()
{
  Serial.begin(9600);                   //Iniciando puerto serial en 9600 bauds
//  pinMode(b, OUTPUT);                   //declaración del push button como salida
}

void loop() {
  
    irsend.sendNEC(0x00000001, 8);     //se enviara un "A" un mensaje de 8bits
    Serial.println("send");            //se imprimirá "send" como confirmación
     delay(1000);                 //esperaremos 100ms
  
}
