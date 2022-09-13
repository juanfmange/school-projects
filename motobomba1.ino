typedef enum {SB, LLENADO, VACIADO} Estados; //Declaramos los estados de máquina, E0 s la condicion inicial y los E1 y E2 según digrama. 
Estados SECUENCIA = SB; // Establecemos se ubique estado inicial
bool A;  //Pin2
bool P;  //Pin3 
bool S2;	//pin4
bool S1;	//pin5

 

void setup(){  // Declaramos los pines de entrada y salida.
Serial.begin(9600); //Inicializar puerto serial
pinMode(2, INPUT); //A
pinMode(3, INPUT);  //P
pinMode(4, INPUT); //S1
pinMode(5, INPUT);	//S2	
pinMode(6, OUTPUT);	//M1
pinMode(7, OUTPUT);	//M2

 

}
void loop(){
A = digitalRead(2); // Leemos el valor digital del sensor S1
Serial.println(A); /// Lo imprimimos en monitor serie 
P = digitalRead(3); // Lo mismo para el resto de la entradas.
Serial.println(P);
S2 = digitalRead(4); // Leemos el valor digital del sensor S1
Serial.println(S2); /// Lo imprimimos en monitor serie 
S1 = digitalRead(5); // Lo mismo para el resto de la entradas.
Serial.println(S1);
 


switch(SECUENCIA){ // utilizamos la estructura switch case para una máquina de estados.
case SB:     // Aqui se realiza lo que queremos mientras estemos ese estado
    if(A == HIGH && S2 == LOW && S1 == HIGH || A == HIGH && S2 == LOW && S1 == LOW){SECUENCIA = LLENADO;}  // Se va a estado E5 si ponemos 5 pesos
    else if (A == HIGH && S1 == HIGH && S2 == HIGH){SECUENCIA = VACIADO;}
    else{SECUENCIA = SB;}
       Serial.println("ESPERANDO SECUENCIA");
    digitalWrite(6, LOW);  // Bomba suministro apagada
    digitalWrite(7, LOW);  // Bomba desague apagada
    delay(1000);   // De lo contrario que permanezca en ese estado (E0)
  break;
 

case LLENADO:     // Aqui se realiza lo que queremos mientras estemos ese estado
    if(S1 == HIGH && S2 == HIGH){SECUENCIA = VACIADO;
       digitalWrite(6,LOW);
       digitalWrite(7,LOW);                          
       delay(3000);}  // Se va a estado E5 si ponemos 5 pesos
  else if (P == HIGH){ SECUENCIA = SB;}  
  else{SECUENCIA = LLENADO;}
    Serial.println("LLENANDO");
     digitalWrite(6,HIGH);
     digitalWrite(7,LOW);  //Bomba APAGADA
     delay(1000);   
  break;
  
case VACIADO:
  if (S1 == LOW && S2 == LOW)
  {
    SECUENCIA = LLENADO;}
  else if (P == HIGH){SECUENCIA=SB;}
  else {SECUENCIA = VACIADO;
    Serial.println("VACIANDO"); 
   digitalWrite(6,LOW);
   digitalWrite(7,LOW);
  }
  break;
}}
