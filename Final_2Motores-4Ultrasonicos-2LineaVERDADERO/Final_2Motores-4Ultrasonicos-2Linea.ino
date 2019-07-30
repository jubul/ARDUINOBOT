#include <AFMotor.h>
//Nombre Motores
AF_DCMotor MotorD(1);
AF_DCMotor MotorI(2);

//Seteo pines UltraSonidos
//Sensor 0(Delante)
#define echoPin0 A11
#define trigPin0 A10
long distance0, duration0;

//Sensor 1(Izquierda)
#define echoPin1 A4
#define trigPin1 A5
long distance1=0, duration1=0;

int cont=0;

//Sensor 2(Derecha)
#define echoPin2 A2
#define trigPin2 A3
long distance2=0, duration2=0;

//Sensor3(Atras)
#define echoPin3 A12
#define trigPin3 A13
long distance3=0, duration3=0;

 //Seteo pines sensores de Línea
 int sl_trasero = 30;
 int sl_delantero = 32;

 //Definimos funciones que luego usaremos
 void atras ();
 void delante();
 void lejos();
 void izquierda ();
 void derecha ();
 
  
void setup () {
  Serial.begin(9600); //Consola Serial
  
  //Seteo I/O Pines US
  pinMode(trigPin0, OUTPUT);
  pinMode(echoPin0, INPUT);
  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  
  //Seteo I/O Sensor de Linea
  pinMode (sl_delantero, INPUT);
  pinMode (sl_trasero, INPUT);
  
  //Desbloqueo Motores
  MotorI.run(RELEASE);
  MotorD.run(RELEASE);
  
  //Pasan 4 segundos
  delay (4000);
}

void loop (){
  
   //--------------------------SENSOR DE LINEA------------------------------------------
//Lectura Sensor delantero y lo comprueba 
  /*if (digitalRead(sl_delantero) == 0) {
  atras(255);
  Serial.print("                                                         ATRAS(255)\n");
  Serial.print ("\n Adelante: Blanco");
 }

//Lectura Sensor trasero y lo comprueba
 if (digitalRead(sl_trasero) == 0) {
  delante(255);
  Serial.print("                                                         ADELANTE(255)\n");
  Serial.print ("\n Atras: Blanco");
 }*/
  derecha(200);

  // -------------------------------------------------------------------------------------
  
 //----------------------------------SENSOR ULTRASONICO------------------------------------
 digitalWrite(trigPin0, LOW);
 digitalWrite(trigPin0, HIGH);
 digitalWrite(trigPin0, LOW);
  //Empieza Medicion de distancia
 duration0 = pulseIn(echoPin0, HIGH);
 distance0 = (duration0/2) / 29.1;

  if (distance0<=100) {
      delante(255);
  }

 digitalWrite(trigPin1, LOW);
 digitalWrite(trigPin1, HIGH);
 digitalWrite(trigPin1, LOW); 
 duration1 = pulseIn(echoPin1, HIGH);
 distance1 = (duration1/2) / 29.1;
 
  if (distance1<=100) {
    izquierda(255);
    Serial.print("                                               IZQUIERDA(255)\n");
  }

 digitalWrite(trigPin2, LOW);
 digitalWrite(trigPin2, HIGH);
 digitalWrite(trigPin2, LOW);
 duration2 = pulseIn(echoPin2, HIGH);
 distance2 = (duration2/2) / 29.1;
 
  if (distance2<=100) {
    derecha(255);
    Serial.print("                                                DERECHA(255)\n");
  }   

 digitalWrite(trigPin3, LOW);
 digitalWrite(trigPin3, HIGH);
 digitalWrite(trigPin3, LOW);
 duration3 = pulseIn(echoPin3, HIGH);
 distance3 = (duration3/2) / 29.1;
 
  if (distance3<=100) {
    derecha(255);
    derecha(255);
  }

 }
 //Funciones motores (Para reducir codigo)
 void delante(byte veloc){
  MotorI.run(FORWARD);
  MotorI.setSpeed(veloc);

  MotorD.run(FORWARD);
  MotorD.setSpeed(veloc);  
       
 }  
 
 void izquierda (byte veloc) {
  MotorI.run(RELEASE);
  
  MotorD.setSpeed(veloc);  
  MotorD.run(FORWARD);

    }
    
void derecha (byte veloc) {
  MotorI.setSpeed(veloc);
  MotorI.run(FORWARD);
  
  MotorD.run(RELEASE);
     
}

void atras (byte veloc) {
  MotorI.run(BACKWARD);
  MotorI.setSpeed(veloc);
  
  MotorD.run(BACKWARD);
  MotorD.setSpeed(veloc); 
     }
 
void parar(){
  MotorI.run (RELEASE);
  MotorD.run (RELEASE);
 }
