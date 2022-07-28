/*CODIGO BASE PARA EMISOR

CONDICIONESñ
-COMPUTADORE DELL
-CONECTADA A CORRIENTE ALTERNA
-ARDUINO UNO
FUNCIONA A LA PERFECCION*/

#include <IRremote.h>       //Librería para IR

IRsend irsend;            //Se transmitirán paquetes remotos IR por medio de la variable irsend,
                          //automáticamente utiliza el pin3 como salida para que el LED envié el paquete de datos
int b = 11;               //Push button en el pin 11
int valor;                //Variable para el valor ALTO/BAJO del push button

void setup()
{
  Serial.begin(9600);                   //Iniciando puerto serial en 9600 bauds
  pinMode(b, OUTPUT);                   //declaración del push button como salida
}

void loop() {
  valor = digitalRead(b);               //El valor guardara el estado del push button HIGH/LOW
  if (valor == HIGH) {                  //En caso de que sea pulsado el push button..
    irsend.sendNEC(0x00000001, 32);     //se enviara un paquete de 32 bits por el protocolo NEC
    Serial.println("send");            //se imprimirá "send" como confirmación
    delay(100);                         //esperaremos 100ms
  }
}
