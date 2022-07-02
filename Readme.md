# PIR 
[![pir-bb.png](https://i.postimg.cc/02C1wkcv/pir-bb.png)](https://postimg.cc/KR4WXy6p)
Uso de un sensor de infrarojo para detectar movimiento.

Creando una función de tipo bool, que devuelva true si el sensor detecta movimiento y false en caso contrario, activamos el led de la placa.

Para detectar movimiento se lee si el sensor devuelve true o false. En caso de ser false, se compara la diferencia de tiempo entre la ultima vez que el sensor detecto movimiento y la actual. Si la diferencia es mayor a un tiempo determinado, la funcion devuelve false.

[![pir-esquem-tico.png](https://i.postimg.cc/h4TBKbmf/pir-esquem-tico.png)](https://postimg.cc/Z0bgcNVS)