typedef enum {SELECCION, CEROG, DOSG, CUATROG, CINCOG, SEISG, SIETEG, OCHOG, NUEVEG, CEROL, DOSL, CUATROL, CINCOL} Estados; //Declaramos los estados de máquina, E0 s la condicion inicial y los E1 y E2 según digrama.
Estados SECUENCIA = SELECCION; // Establecemos se ubique estado inicial
bool L;  //Pin2
bool G;  //Pin3
bool D;  //pin4
bool C; //pin5
bool Z; //pin6


void setup() { // Declaramos los pines de entrada y salida.
  Serial.begin(9600); //Inicializar puerto serial
  pinMode(2, INPUT); //L
  pinMode(3, INPUT);  //G
  pinMode(4, INPUT); //D
  pinMode(5, INPUT);  //C
  pinMode(6, INPUT);  //Z
  pinMode(7, OUTPUT); //La
  pinMode(8, OUTPUT); //Go
  pinMode(9, OUTPUT); //Ca

}
void loop() {
  L = digitalRead(2); // Leemos el valor digital del sensor S1
  Serial.print(L); /// Lo imprimimos en monitor serie
  G = digitalRead(3); // Lo mismo para el resto de la entradas.
  Serial.print(G);
  D = digitalRead(4); // Leemos el valor digital del sensor S1
  Serial.print(D); /// Lo imprimimos en monitor serie
  C = digitalRead(5); // Lo mismo para el resto de la entradas.
  Serial.print(C);
  Z = digitalRead(6); // Lo mismo para el resto de la entradas.
  Serial.println(Z);


  switch (SECUENCIA) { // utilizamos la estructura switch case para una máquina de estados.
    case SELECCION:     // Aqui se realiza lo que queremos mientras estemos ese estado
      if (L == HIGH) {
        SECUENCIA = CEROL; // Se va a estado E5 si ponemos 5 pesos
      }
      else if (G == HIGH) {
        SECUENCIA = CEROG;
      }
      else {
        SECUENCIA = SELECCION;
      }
      Serial.println("¿QUE DESEA COMPRAR?");
      delay(1000);   // De lo contrario que permanezca en ese estado (E0)
      break;


    case CEROL:     // Aqui se realiza lo que queremos mientras estemos ese estado
      if (Z == HIGH) {
        SECUENCIA = SELECCION;
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        Serial.println("entredando lapiz, 4 pesos cambio");
      }
      else if (D == HIGH) {
        SECUENCIA = DOSL;
      }
      else if (C == HIGH) {
        SECUENCIA = CINCOL;
      }
      else {
        SECUENCIA = CEROL;
      }
      break;

    case DOSL:
      if (D == HIGH)
      {
        SECUENCIA = CUATROL;
      }
      else if (C == HIGH) {
        SECUENCIA = SELECCION;
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        Serial.println("entredando lapiz, 1 peso cambio");
      }
      else if (Z == HIGH) {
        SECUENCIA = SELECCION;
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        Serial.println("entredando lapiz, 6 pesoS cambio");
      }
      else {
        SECUENCIA = DOSL;
      }
      break;
    case CUATROL:
      if (D == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        Serial.println("entredando lapiz, SIN CAMBIO");
      }
      else if (C == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        Serial.println("entredando lapiz, 3 pesos cambio");
      }
      else if (Z == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        Serial.println("entredando lapiz, 8 pesos cambio");
      }
      else {
        SECUENCIA = CUATROL;
      }
      break;
    case CINCOL:
      if (D == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        Serial.println("entredando lapiz, 1 peso cambio");
      }
      else if (C == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        Serial.println("entredando lapiz, 4 pesos cambio");
      }
      else if (Z == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        Serial.println("entredando lapiz, 9 pesos cambio");
      }
      else {
        SECUENCIA = CINCOL;
      }
      break;

    case CEROG:
      if (D == HIGH)
      {
        SECUENCIA = DOSG;
      }
      else if (C == HIGH)
      {
        SECUENCIA = CINCOG;
      }
      else if (Z == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        Serial.println("entredando  goma, sin cambio");
      }
      else {
        SECUENCIA = CEROG;
      }
      break;

    case DOSG:
      if (D == HIGH)
      {
        SECUENCIA = CUATROG;
      }
      else if (C == HIGH)
      {
        SECUENCIA = SIETEG;
      }
      else if (Z == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        Serial.println("entredando  goma,2 pesos cambio");
      }
      else {
        SECUENCIA = DOSG;
      }
      break;

    case CUATROG:
      if (D == HIGH)
      {
        SECUENCIA = SEISG;
      }
      else if (C == HIGH)
      {
        SECUENCIA = NUEVEG;
      }
      else if (Z == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        Serial.println("entredando  goma, 4 pesos cambio");
      }
      else {
        SECUENCIA = CEROG;
      }
      break;

    case SEISG:
      if (D == HIGH)
      {
        SECUENCIA = OCHOG;
      }
      else if (C == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        Serial.println("entredando  goma, 1 peso cambio");
      }
      else if (Z == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        Serial.println("entredando  goma, 6 pesos cambio");
      }
      else {
        SECUENCIA = SEISG;
      }
      break;

    case OCHOG:
      if (D == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        Serial.println("entredando  goma, sin cambio");
      }

      else if (C == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        Serial.println("entredando  goma, 3 pesos cambio");
      }

      else if (Z == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        Serial.println("entredando  goma, 8 pesos cambio");
      }
      else {
        SECUENCIA = OCHOG;
      }
      break;

    case CINCOG:
      if (D == HIGH)
      {
        SECUENCIA = SIETEG;
      }

      else if (C == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        Serial.println("entredando  goma, sin cambio");
      }

      else if (Z == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        Serial.println("entredando  goma, 5 pesos cambio");
      }
      else {
        SECUENCIA = CINCOG;
      }
      break;

    case SIETEG:
      if (D == HIGH)
      {
        SECUENCIA = NUEVEG;
      }

      else if (C == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        Serial.println("entredando  goma, 2 pesos cambio");
      }

      else if (Z == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        Serial.println("entredando  goma, 7 pesos cambio");
      }
      else {
        SECUENCIA = SIETEG;
      }
      break;

    case NUEVEG:
      if (D == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        Serial.println("entredando  goma, 1 peso cambio");
      }
      else if (C == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        Serial.println("entredando  goma, 4 pesos cambio");
      }

      else if (Z == HIGH)
      {
        SECUENCIA = SELECCION;
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        Serial.println("entredando  goma, 9 pesos cambio");
      }
      else {
        SECUENCIA = NUEVEG;
      }
      break;

  }
}
