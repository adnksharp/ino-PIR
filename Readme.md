# PIR 
[![pir-bb.png](https://i.postimg.cc/02C1wkcv/pir-bb.png)](https://postimg.cc/KR4WXy6p)

Uso de un sensor de infrarojo para detectar movimiento.

## Hardware y software necesarios
- Placa de desarrollo Arduino.
- Sensor de infrarojo PIR.
- [Arduino IDE](https://www.arduino.cc/en/software) o [Arduino CLI](https://arduino.github.io/arduino-cli/0.23/installation/).

## Funcionamiento
### Variables
- ```pir```: pin digital del sensor de infrarojo.
- ```led```: pin digital del LED integrado.
- ```Delay```: tiempo de espera para el sensor de infrarojo en milisegundos.
- ```Go```: variable que indica cuando el sensor detecta movimiento.
- ```out```, ```state``` y ```cache```: variables para almacenar el valor del sensor y el valor anterior.

### Funcionamiento
Dentro de unafunción ```PIR```, se realiza una lectura del sensor de infrarojo:

- La variable ```out``` almacena el valor de ```cache```.

- Si la lectura actual del sensor es un ```1```, se indica que el sensor detectó movimiento, de ser así, ```out``` se pone en ```1``` y ```state``` en ```0```.

- Si la lectura actual del sensor es un ```0```:
    - Se revisa si el valor de ```state``` es **0**. Esto indica que el sensor acaba de detectar movimiento, de ser así, ```Go``` almacena el tiempo actual.
    - Se revisa si han pasado ```Delay``` milisegundos desde el momento en que el sensor detectó movimiento. Si es así, ```out``` se pone en ```0```.
    - Después de revisar lo anterior, el valor de ```state``` se pone en ```0``` para evitar que el valor de ```Go``` se actualice.
- El valor de ```cache``` se actualiza con el valor de ```out```.
- La función ```PIR``` devuelve el valor de ```out```.

Dentro del funcionamiento del microcontrolador, ```led``` se pone en ```PIR()``` (**0** o **1**) usando la función ```digitalWrite```.
