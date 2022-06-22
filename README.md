# Arduino_Python_Aplicaciones de Muestreo y Datos
El proyecto se basa en una aplicacion de harwuare realizada en arduino transmitiendo los datos hacia python y en este mostrar los mismos y poder tomar desiciones de acuerdo a los valores 
## Arduino Aplicacion de Hardware
La aplicacion consiste en mostrar la distancia medida desde un sensor HC-SR04 y un sensor de temperatura y humedad DHT11 en una pantalla LCD 16x2, asimismo los valores enviarlos por el puerto serie y recogerlos con Python  
### Toma de datos y lectura en Python
Una vez ingreados los datos en Python en forme de cadena, los mismos son analizados y separados por sensor(Distancia, Humedad, Temperatura)
Se genera una ventana mediante la libreria Tkinter en la cual se mostraran los datos obtenidos

### Harwuare
Arduino Uno
Sensor HCSR04
Sensor DHT11
pantalla LCD 16x2
potenciometro 50k
portroboard
cables macho a macho 15




