#include <Arduino.h>

void setup() {
 // Inicializar comunicación serial con el monitor serial
Serial.begin(9600);
 // Inicializar la comunicación serial para enviar datos
Serial2.begin(9600);
}


void loop() {
 
if (Serial2.available()) {
  // Leer los datos recibidos por serialRX
 
  char receivedChar = Serial2.read();

  // Mostrar los datos recibidos en el monitor serial
  Serial.write(receivedChar);
}




if (Serial.available()) {
 
  // Leer los datos disponibles en el monitor serial
  char receivedChar1 = Serial.read();
  
  // Enviar los datos recibidos por el monitor serial a través de serialTX
  Serial2.write(receivedChar1);
}
}
