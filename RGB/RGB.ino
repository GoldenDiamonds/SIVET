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
