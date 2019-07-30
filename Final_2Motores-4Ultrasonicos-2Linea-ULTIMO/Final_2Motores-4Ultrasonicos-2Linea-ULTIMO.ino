#include <AFMotor.h>

//Nombre Motores
AF_DCMotor MotorD(1);
AF_DCMotor MotorI(2);

//Seteo pines UltraSonidos

//Sensor 0(Delante)
#define echoPin0 A11
#define trigPin0 A10
long distancia0, duracion0;

//Sensor 1(Izquierda)
#define echoPin1 A4
#define trigPin1 A5
long distancia1, duracion1;

//Sensor 2(Derecha)
#define echoPin2 A2
#define trigPin2 A3
long distancia2, duracion2;

//Sensor3(Atras)
#define echoPin3 A13
#define trigPin3 A12
long distancia3, duracion3;

//Seteo pines Sensores de Línea
int sl_delantero = 30;
int sl_trasero = 32;

//Definimos funciones que luego usaremos
void atras (){
  MotorI.setSpeed (255);
  MotorI.run(BACKWARD);

  MotorD.setSpeed (255);
  MotorD.run (BACKWARD);
}

void delante(){
  MotorI.setSpeed(255);
  MotorI.run (FORWARD);
  
  MotorD.setSpeed (255);
  MotorD.run (FORWARD);
}
void izquierda (){
  MotorI.run (RELEASE);
  
  MotorD.setSpeed (255);
  MotorD.run (FORWARD);
}

void derecha (){
  MotorI.setSpeed(255);
  MotorI.run (FORWARD);
  
  MotorD.run (RELEASE);
}

void setup (){
  Serial.begin(9600); //Consola Serial

  //Seteo OUTPUT Pines US
  pinMode(trigPin0, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);

  //Seteo INPUT Pines US
  pinMode(echoPin0, INPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);

  //Seteo INPUT Sensor de Linea
  pinMode (sl_delantero, INPUT);
  pinMode (sl_trasero, INPUT);

  //Pasan 5 segundos
  delay (5000);
}

void loop (){
  //Lectura Sensor delantero y lo comprueba sino comprueba el otro
  /*if (digitalRead(sl_delantero) == 0) {
    atras();
    Serial.print ("\n Atras: Blanco");
  }else if (digitalRead(sl_trasero) == 0) {
    delante();
    Serial.print ("\n Adelante: Blanco");
 }*/
 //Lectura Sensor (Adelante)
 digitalWrite(trigPin0, LOW); //Es para que luego genere un pulso limpio
 delayMicroseconds(2);
 digitalWrite(trigPin0, HIGH); //Genera un pulso por 10ms
 delayMicroseconds(10);
 digitalWrite(trigPin0, LOW);
 //Empieza Medicion de distancia
 duracion0 = pulseIn(echoPin0, HIGH);
 distancia0 = (duracion0/2) / 29.1;
 
 //Lectura Sensor (Izquierda) 
 digitalWrite(trigPin1, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin1, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin1, LOW);
 duracion1 = pulseIn(echoPin1, HIGH);
 distancia1 = (duracion1/2) / 29.1;
 
 //Lectura Sensor (Derecha) 
 digitalWrite(trigPin2, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin2, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin2, LOW);
 duracion2 = pulseIn(echoPin2, HIGH);
 distancia2 = (duracion2/2) / 29.1;

 //Lectura Sensor (Atras) 
 digitalWrite(trigPin3, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin3, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin3, LOW);
 duracion3 = pulseIn(echoPin3, HIGH);
 distancia3 = (duracion3/2) / 29.1;

 Serial.print("\n 0:");
 Serial.print (distancia0);
 Serial.print("\n 1:");
 Serial.print (distancia1);
 Serial.print("\n 2:");
 Serial.print (distancia2);
 Serial.print("\n 3:");
 Serial.print (distancia3);
 
 if (distancia0<=120){
  delante();
  
  }else if (distancia1<=120){
    derecha();
    
    }else if (distancia2<=120){
      izquierda();
      
      }else if (distancia3<=120){
        derecha();
        derecha();
        
      }else {
        izquierda ();
        delante ();
      }
}
