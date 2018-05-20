 /*
  * Sistema Verificador de Tomates
  * Creado por equipo 4 UTCV
  */
// Incluímos la librería para poder controlar el servo
#include <Servo.h>
 
// Declaramos la variable para controlar el servo
Servo servoMotor;
 
void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 13
  servoMotor.attach(13);
 
  // Inicializamos al ángulo 0 el servomotor
  servoMotor.write(0);
}
 
void loop() {
 
  // Vamos a tener dos bucles uno para mover en sentido positivo y otro en sentido negativo
  // Para el sentido positivo
  for (int i = 0; i <= 180; i++)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    // Hacemos una pausa de 25ms
    delay(25);
    // Se ralentiza antes de girar al sentido contrario para evita que cambie de dirección bruscamente
    if(i>150&&i<180)
    delay(50);
    /*Para ver en qué posición va
    *Serial.println(i);
    */
  }
 
  // Para el sentido negativo
  for (int i = 179; i > 0; i--)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    // Hacemos una pausa de 25ms
    delay(25);
    // Se ralentiza antes de girar al sentido contrario para evita que cambie de dirección bruscamente
    if(i>1&&i<30)
    delay(50);
    /*Para ver en que posición va
    *Serial.println(i);
    */
  }
}
