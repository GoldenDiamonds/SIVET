#include <SD.h>
 
//const int chipSelect = 4;
 
void setup()
{
 
   
  //Comprobamos si esta disponible la MicroSD
  if (!SD.begin(4)) {
    return;
    //Detenemos la ejecución en el caso de que tengamo sproblemas con la MicroSD 
  }
}
 
void loop()
{
  // Creamos el String para almacenar lo que vayamos a mandar al archivo
  String dataString = "";
  // Nos aseguramos que el chipselect de ethernet esta en salida
  //para evitar problemas.
  //pinMode(10, OUTPUT);
   
 
    int color = 25;
    //Guardamos el color en un string
    dataString += String(color);
    dataString += ";";
    
  //Abrimos el archivo datalog.csv
  File dataFile = SD.open("InfoSensores.csv", FILE_WRITE);
 
  // Si el archivo se ha abierto correctamente
  if (dataFile) {
    //almacenamos el string en elarchivo
    dataFile.println(dataString);
    dataFile.close();
  }  
  delay(500);
}
