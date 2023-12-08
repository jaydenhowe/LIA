/* In this program the goal is to create an obstacle avoidance for the robot car. */ 

# include <Servo.h>     // includes the servo library

#define Ltrack A2      //defines pin A2 as Ltrack
#define Mtrack A1      //defines pin A1 as Mtrack
#define Rtrack A0       //defines pin A0 as Rtrack
#define trig 13        //defines pin 13 as trig
#define echo 12         //defines pin 12 as echo
#define servo 10        //defines pin 10 as servo

float DIST;             //floats value DIST
Servo myservo;          //creates servo object to control servo motor

void forward(int x){  /* creates function to have left motors and right motors moving in the 
same direction (forward) at the same speed*/

    digitalWrite(7, 1); 
    analogWrite(5, x); 
    digitalWrite(8, 1); 
    analogWrite(6, x); 
} 
void backwards(int x){   /* creates function to have left motors and right motors moving in the 
same direction (backwards) at the same speed*/
  
    digitalWrite(7, 0); 
    analogWrite(5, x); 
    digitalWrite(8, 0); 
    analogWrite(6, x); 
} 
void left(int x){     /* creates function to have left motors going backwards and right motors
going forward at the same speed*/
  
    digitalWrite(7, 1); 
    analogWrite(5, x); 
    digitalWrite(8, 0); 
    analogWrite(6, x); 
} 
void right(int x){   /* creates function to have left motors going forward and right motors
going backwards at the same speed*/
  
    digitalWrite(7, 0); 
    analogWrite(5, x); 
    digitalWrite(8, 1); 
    analogWrite(6, x); 
} 
void leftforward(int x){   /* creates function to have left and right motors going forward but
having the left motor going half the speed*/
  
    digitalWrite(7, 1); 
    analogWrite(5, x); 
    digitalWrite(8, 1); 
    analogWrite(6, x/2); 
} 
void rightforward(int x){  /* creates function to have left and right motors going forward but
having the right motor going half the speed*/
  
    digitalWrite(7, 1); 
    analogWrite(5, x/2); 
    digitalWrite(8, 1); 
    analogWrite(6, x); 
}

void leftbackward(int x){    /* creates function to have left and right motors going backwards but
having the left motor going half the speed*/
  
    digitalWrite(7, 0); 
    analogWrite(5, x); 
    digitalWrite(8, 0); 
    analogWrite(6, x/2); 
} 
void rightbackward(int x){    /* creates function to have left and right motors going backwards but
having the right motor going half the speed*/
  
    digitalWrite(7, 0); 
    analogWrite(5, x/2); 
    digitalWrite(8, 0); 
    analogWrite(6, x); 
} 
void stopit(){     /* creates function to stop the car by having both motors at 0 speed */
  
    digitalWrite(7, 0); 
    analogWrite(5, 0); 
    digitalWrite(8, 0); 
    analogWrite(6, 0); 
}
void checkdist(){              //creates function to check distance with the ultrasonic

  digitalWrite(trig, LOW);        //writes pin 9 to LOW
  delayMicroseconds(2);        //delays it by 2 microseconds       
  digitalWrite(trig, HIGH);        //writes pin 9 to HIGH
  delayMicroseconds(20);        //delays it by 20 microseconds
  digitalWrite(trig, LOW);        //writes pin 9 to LOW
  float duration = pulseIn(echo, HIGH);         // floats "duration" and sets pin 13 to HIGH
  DIST = (duration/58);                     //writes equation for the distance by dividing the duration by 58
  return(int)DIST;                         //returns the value of DIST
}

int startpos = 90;           //sets the angle of the servo (90°) to startpos
int leftpos = 170;          //sets the angle of the servo (170°) to leftpos
int rightpos = 5;           //sets the angle of the servo (5°) to rightpos


void setup() { 

  // put your setup code here, to run once:           
    pinMode(5, OUTPUT);     //sets pin 5 as an output
    pinMode(8, OUTPUT);     //sets pin 8 as an output
    pinMode(6, OUTPUT);     //sets pin 6 as an output
    pinMode(7, OUTPUT);     //sets pin 7 as an output
    pinMode(3, OUTPUT);     //sets pin 3 as an output
    digitalWrite(3, 1);      //turns on the motor
   pinMode(Ltrack, INPUT);    //sets Ltrack (A2) as an input
  pinMode(Mtrack, INPUT);     //sets Mtrack (A1) as an input
  pinMode(Rtrack, INPUT);     //sets Rtrack (A0) as an input
  pinMode(trig, OUTPUT);      //sets trig (13) as an output
  pinMode(echo, INPUT);       //sets echo (12) as an input
  myservo.attach(servo);      //attaches pin 10 to the servo

} 

void loop() {
  // put your main code here, to run repeatedly:

  int Lsensor = analogRead(Ltrack);    // reads the value from Ltrack and sets it to integer Lsensor
  int Msensor = analogRead(Mtrack);    // reads the value from Mtrack and sets it to integer Msensor    
  int Rsensor = analogRead(Rtrack);    // reads the value from Rtrack and sets it to integer Rsensor

if (Lsensor, Msensor, Rsensor >= 1000) {  //creates if command for if the robot isn't touching the ground
    stopit();        // calls the function "stopit"
    delay(100);      // delays it by 100 milliseconds
  } else {           //creates else command for if it is touching the ground

checkdist();         // calls the function "checkdist"
if (DIST <=20) {     //creates if command for if the robot is too close to an object
  stopit();          // calls the function "stopit"
  delay(1000);             // delays it by 1 second
  myservo.write(leftpos);    // moves the servo to the left position  
  delay(1000);               //delays it by 1 second
  checkdist();               // calls the function "checkdist"
if (DIST <=20) {             //creates if command for if the robot is too close to an object
  myservo.write(rightpos);    //moves the servo to the right position
  delay(1000);                //delays it by 1 second
  checkdist();                // calls the function "checkdist"
if (DIST <=20) {              //creates if command for if the robot is too close to an object
  backwards(100);             //calls the function "backwards"
  delay(1000);               //delays it by 1 second
  left(100);                  //calls the function "left"
  delay(550);                 //delays it by 550 milliseconds
  myservo.write(startpos);     //moves the servo to the starting position
  delay(1000);                 //delays it by 1 second
  forward(150);                //calls the function "forward"
} else {                       //creates else command for if the robot isn't close to an object
  myservo.write(startpos);
  delay(1000);
  right(100);
  delay(500);
}
} else {                      //creates else command for if the robot isn't close to an object
  myservo.write(startpos);     //moves the servo to the starting position
  delay(1000);                //delays it by 1 second
  left(100);                  //calls the function "left"
  delay(500);                 //delays it by 550 milliseconds
}
} else {                     //creates else command for if the robot isn't close to an object
  forward(100);             //calls the function "forward"
}
  }
}     





