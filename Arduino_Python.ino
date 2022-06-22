
  //Inicializamos el lcd
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Incluimos librería
#include <DHT.h>
#include <DHT_U.h>
 

// Inicializamos el sensor DHT11
DHT dht(7, DHT11);

//Se declaran los pines para el sensor
int const TRIG = 9;
int const ECHO = 8;

//Variables de calculo
float distancia;
float tiempo;

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  //Activación del pin como salida: para el pulso ultrasónico
  pinMode(TRIG, OUTPUT); 
  //Activación del pin como entrada: tiempo del rebote del ultrasonido
  pinMode(ECHO, INPUT); 
   // Comenzamos el sensor DHT
  dht.begin();
}

void loop(){
  digitalWrite(TRIG,LOW); 
  delayMicroseconds(5);
  //Envío del pulso ultrasónico
  digitalWrite(TRIG, HIGH); 
  delayMicroseconds(10);

  //Obtenemos el tiempo de rebote
  tiempo = pulseIn(ECHO, HIGH); 

  //Calculamos la distancia
  distancia= tiempo / 2 / 29.1;
   
   delay(2000);
 
  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();
  // Leemos la temperatura en grados Fahreheit
  float f = dht.readTemperature(true);
 
  // Comprobamos si ha habido algún error en la lectura
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;}

    // Calcular el índice de calor en Fahreheit
  float hif = dht.computeHeatIndex(f, h);
  // Calcular el índice de calor en grados centígrados
  float hic = dht.computeHeatIndex(t, h, false);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.println("distancia");
  lcd.setCursor(10,0);
  lcd.println(distancia);
  lcd.setCursor(13,0);
  lcd.println("cm");
  lcd.setCursor(0,1);
  lcd.println("Temp:");
  lcd.setCursor(6,1);
  lcd.println(t);
  lcd.setCursor(8,1);
  lcd.println("c");
  lcd.setCursor(10,1);
  lcd.println(h);
  lcd.setCursor(12,1);
  lcd.println("%");
  Serial.println("Distancia: "+String (distancia,2)+","+ "Temp: "+String (t)+","+"Hum: "+String (hic));
  
  
  delay(500);
  
  }
