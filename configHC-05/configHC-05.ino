
#include <SoftwareSerial.h>

SoftwareSerial BT1(10, 11); // 10-RX | 11-TX

void setup() {

    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);

    digitalWrite(9, HIGH);

    delay(500);

    Serial.begin(9600);

    Serial.println("Levantando el modulo HC-05");

    digitalWrite(8, HIGH);
    
    Serial.println("Listo para recibir comandos AT");

    BT1.begin(38400); // Si no responde con un OK cambiar la velocidad por una de las siguientes 9600, 19200, 57600 o 115200
}

void loop() {

    if (BT1.available()) {

        Serial.write( BT1.read());

    }


    if (Serial.available()) {

        BT1.write( Serial.read());

    }
    
}