typedef enum {REPOSO,B,C,S} Estados; 
Estados SECUENCIA = REPOSO; // Establecemos se ubique estado inicial
bool FA;  //Pin2
bool FB;  //Pin3 
bool FC;  //pin4
bool A; //pin5
bool P; //pin6
 

void setup(){  // Declaramos los pines de entrada y salida.
Serial.begin(9600); //Inicializar puerto serial
pinMode(2, INPUT); //FA
pinMode(3, INPUT);  //FB
pinMode(4, INPUT); //FC
pinMode(5, INPUT);  //A 
pinMode(6, INPUT);  //P
pinMode(7, OUTPUT); //KA1
pinMode(8, OUTPUT); //KA2 
pinMode(9, OUTPUT); //KA3
pinMode(10, OUTPUT); //KA4


 

}
void loop(){
FA = digitalRead(2); // Leemos el valor digital del sensor S1
Serial.println(FA); /// Lo imprimimos en monitor serie 
FB = digitalRead(3); // Lo mismo para el resto de la entradas.
Serial.println(FB);
FC = digitalRead(4); // Leemos el valor digital del sensor S1
Serial.println(FC); /// Lo imprimimos en monitor serie 
A = digitalRead(5); // Lo mismo para el resto de la entradas.
Serial.println(A);
P = digitalRead(6); // Lo mismo para el resto de la entradas.
Serial.println(P);


switch(SECUENCIA){ // utilizamos la estructura switch case para una máquina de estados.
case REPOSO:     // Aqui se realiza lo que queremos mientras estemos ese estado
    if(FA == LOW && FB == LOW && FC == LOW && A == HIGH )
    {SECUENCIA = B;}  
    else{SECUENCIA = REPOSO;
       Serial.println("ESPERANDO ARRANQUE");
     digitalWrite(7, LOW);
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW);
         delay(1000);}   // De lo contrario que permanezca en ese estado (E0)
  break;
 

case B:     // Aqui se realiza lo que queremos mientras estemos ese estado
    if(P == HIGH){
     digitalWrite(7, LOW);
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW);
    Serial.println("PARO");}
  else if (FA == HIGH){ SECUENCIA = B;}            
  else if (FA == HIGH && FB == HIGH)
  {SECUENCIA = C;} 
  else { SECUENCIA = B;}
  digitalWrite(7, HIGH);
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW);
    Serial.println("ENCENDIENDO TALADRO");
     delay(1000);
  break;
  
case C:
  if(P == HIGH){
     digitalWrite(7, LOW);
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW);
     Serial.println("PARO");}
  else if (FA == HIGH && FB == HIGH && FC == HIGH)
  {SECUENCIA=S;}
  else {SECUENCIA = C;}
    Serial.println("LLENANDO");
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    delay(1000);             
  break;
                  
case S:
  if(P == HIGH){
     digitalWrite(7, LOW);
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW);
    Serial.println("PARO");}                
  else if (FA == HIGH && FB == LOW && FC == LOW)                
  {
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }
    else if (FA == LOW && FB == LOW && FC == LOW) 
    {
     digitalWrite(7, LOW);
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW);
    Serial.println("GRACIAS POR TALADRAR");
      delay(1000);
      SECUENCIA=REPOSO;
    }
    else {SECUENCIA = S;}
       digitalWrite(7, LOW);
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW);
    Serial.println("TERMINADO... REGRESANDO A EDO INICIAL");
   delay(5000);
     break;                  
}}
