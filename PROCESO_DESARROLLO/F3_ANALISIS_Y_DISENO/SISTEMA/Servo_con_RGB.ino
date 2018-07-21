/*
 *        *** SIVET ***
 * Sistema Verificador de Tomates
 *            v1.1
 *            /07/04/18
 *            Licence MIT
 */
const int s0 = 8;  
const int s1 = 9;  
const int s2 = 12;  
const int s3 = 11;  
const int out = 10;   
// LED pins connected to Arduino
int redLed = 2;  
int greenLed = 3;  
int blueLed = 4;
// Variables 
int rojo = 0;
int verde = 0;
int azul = 0;
 
// Incluímos la librería para poder controlar el servo
#include <Servo.h>
 
// Declaramos la variable para controlar el servo
Servo servoMotor;

void setup(){  
  Serial.begin(9600); 
  pinMode(s0,OUTPUT);  
  pinMode(s1,OUTPUT);  
  pinMode(s2,OUTPUT);  
  pinMode(s3,OUTPUT);  
  pinMode(out,INPUT);   
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,HIGH);  
  pinMode(redLed, OUTPUT);  
  pinMode(greenLed, OUTPUT);  
  pinMode(blueLed, OUTPUT); 

  //Servo
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 6
  servoMotor.attach(6);
 
  // Inicializamos al ángulo 0 el servomotor
  servoMotor.write(0);
}  

   
void loop(){  
  color(); 
  Serial.print("ROJO ");  
  Serial.print(rojo, DEC);  
  Serial.print("  VERDE ");  
  Serial.print(verde, DEC);  
  Serial.print("  AZUL ");  
  Serial.print(azul, DEC);  

  if (rojo < azul && verde > azul && rojo < 120) 
  {  
   Serial.println("   Rojo");    
   digitalWrite(redLed, HIGH); // Turn RED LED ON 
   digitalWrite(greenLed, LOW);  
   digitalWrite(blueLed, LOW); 
  }   
  else if (azul < rojo && azul < verde && verde < rojo)  
  {  
   Serial.println("   Azul");  
   digitalWrite(blueLed, HIGH); // Turn BLUE LED ON  
   digitalWrite(redLed, LOW);  
   digitalWrite(greenLed, LOW);      
  }  

  else if (rojo > verde && azul > verde )  
  {  
   Serial.println("   Verde");
   digitalWrite(redLed, LOW);  
   digitalWrite(greenLed, HIGH); // Turn GREEN LED ON 
   digitalWrite(blueLed, LOW);       
  }  
  else{
  Serial.println("  ");  
  }
  delay(2000); 
  digitalWrite(redLed, LOW);  
  digitalWrite(greenLed, LOW);  
  digitalWrite(blueLed, LOW);

  //Servo
  // Vamos a tener dos bucles uno para mover en sentido positivo y otro en sentido negativo
  // Para el sentido positivo
  for (int i = 0; i <= 180; i++)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    // Hacemos una pausa de 25ms
    delay(25);
  }
 
  // Para el sentido negativo
  for (int i = 179; i > 0; i--)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    // Hacemos una pausa de 25ms
    delay(25);
  }
 }  
    
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);   
  rojo = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);   
  azul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);    
  verde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}
