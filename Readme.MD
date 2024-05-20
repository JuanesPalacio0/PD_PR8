# Comunicación Serial Doble con ESP32

Este programa demuestra cómo establecer una comunicación bidireccional entre el ESP32 y otro dispositivo utilizando dos interfaces seriales: `Serial` y `Serial2`. `Serial` se utiliza para comunicarse con el monitor serial del ordenador, mientras que `Serial2` se utiliza para comunicarse con otro dispositivo serial.

## Código

```cpp
#include <Arduino.h>

void setup() {
    // Inicializar comunicación serial con el monitor serial
    Serial.begin(9600);
    // Inicializar la comunicación serial para enviar datos
    Serial2.begin(9600);
}

void loop() {
    if (Serial2.available()) {
        // Leer los datos recibidos por Serial2
        char receivedChar = Serial2.read();
        // Mostrar los datos recibidos en el monitor serial
        Serial.write(receivedChar);
    }

    if (Serial.available()) {
        // Leer los datos disponibles en el monitor serial
        char receivedChar1 = Serial.read();
        // Enviar los datos recibidos por el monitor serial a través de Serial2
        Serial2.write(receivedChar1);
    }
}

### Objetivo 
El objetivo de este programa es permitir la transmisión de datos entre el monitor serial del ordenador y otro dispositivo serial conectado al ESP32, utilizando dos puertos seriales distintos (Serial y Serial2).

### Funcionamiento
** Inicialización en setup():**

1. Serial.begin(9600): Configura la velocidad de transmisión del puerto serial para la comunicación con el monitor serial del ordenador.
2. Serial2.begin(9600): Configura la velocidad de transmisión del puerto serial para la comunicación con otro dispositivo.
Comunicación en loop():

Recepción desde Serial2 y envío a Serial:
Se verifica si hay datos disponibles en Serial2 utilizando Serial2.available().
Si hay datos disponibles, se leen con Serial2.read().
Los datos recibidos se envían al monitor serial utilizando Serial.write().
Recepción desde Serial y envío a Serial2:
Se verifica si hay datos disponibles en Serial utilizando Serial.available().
Si hay datos disponibles, se leen con Serial.read().
Los datos recibidos se envían al dispositivo conectado a Serial2 utilizando Serial2.write().

**Explicación de las Funciones Clave**
- Serial.begin(9600): Inicializa la comunicación serial con el monitor serial del ordenador a una velocidad de 9600 baudios.
- Serial2.begin(9600): Inicializa la comunicación serial con otro dispositivo a una velocidad de 9600 baudios.
- Serial2.available(): Verifica si hay datos disponibles para leer desde Serial2.
- Serial2.read(): Lee un byte de datos desde Serial2.
- Serial.write(receivedChar): Envía un byte de datos al monitor serial del ordenador.
- Serial.available(): Verifica si hay datos disponibles para leer desde Serial.
- Serial.read(): Lee un byte de datos desde Serial.
- Serial2.write(receivedChar1): Envía un byte de datos al dispositivo conectado a Serial2.

**Uso Práctico**
Este programa es útil para aplicaciones que requieren la interacción con múltiples dispositivos seriales, como la comunicación con sensores, módulos de radio o dispositivos de almacenamiento. Al usar Serial para el monitor serial y Serial2 para otro dispositivo, se puede monitorear y controlar la comunicación de manera efectiva.

Este programa ilustra cómo utilizar múltiples interfaces seriales en el ESP32 para gestionar comunicaciones simultáneas, lo cual es esencial para el desarrollo de aplicaciones de IoT y sistemas embebidos avanzados.