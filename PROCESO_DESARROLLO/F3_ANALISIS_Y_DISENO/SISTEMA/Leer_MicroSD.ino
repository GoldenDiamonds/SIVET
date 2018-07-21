/*
 *        *** SIVET ***
 * Sistema Verificador de Tomates
 *            v2.0
 *          /06/06/18
 *         Licence MIT
 */
#include <SD.h>

File myFile;

void setup()
{
  Serial.begin(9600);
  Serial.print("Iniciando SD ...");
  if (!SD.begin(4)) {
    Serial.println("No se pudo inicializar");
    return;
  }
  Serial.println("inicialización exitosa");
 
  //myFile = SD.open("Esquema_Cableado.txt");//abrimos  el archivo 
  myFile = SD.open("prueba.txt");//abrimos  el archivo 
  if (myFile) {
    //Serial.println("Esquema_Cableado.txt:");
    Serial.println("prueba.txt:");
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close(); //cerramos el archivo
  } else {
    Serial.println("Error al abrir el archivo");
  }
}

void loop()
{
  
}
