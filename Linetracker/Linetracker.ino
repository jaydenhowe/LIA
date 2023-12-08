/* the goal of this program is to create a line follower with the sensor on the bottom of the car.
we want it to follow the line until it can't and then have it search for a different line or go back 
onto the same one*/

#define Ltrack A2      //defines pin A2 as Ltrack
#define Mtrack A1      //defines pin A1 as Mtrack
#define Rtrack A0       //defines pin A0 as Rtrack

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
} 

void loop() { 
  // put your main code here, to run repeatedly: 
    
  int Lsensor = analogRead(Ltrack);    // reads the value from Ltrack and sets it to integer Lsensor
  int Msensor = analogRead(Mtrack);    // reads the value from Mtrack and sets it to integer Msensor    
  int Rsensor = analogRead(Rtrack);    // reads the value from Rtrack and sets it to integer Rsensor

if (Msensor >= 150 && Msensor <=800)  {      // creates if command for if the middle sensor is reading between 150 and 800
     forward(80);                            //calls the function "forward"
      delay(100);                            //delays it by 100 milliseconds

  } else if (Lsensor, Msensor, Rsensor >= 1000) {    //creates if command for if the robot isn't touching the ground
    stopit();                                        //calls the function "stopit"
    delay(100);                                      //delays it by 100 milliseconds
    
  } else if (Lsensor >= 150 && Lsensor <= 800) {     //creates if command for if the left sensor is reading between 150 and 800
    left(60);                                        //calls the function "left"
    delay(100);                                      //delays it by 100 milliseconds
     
  } else if (Rsensor >= 150 && Rsensor <= 800) {     //creates if command for if the right sensor is reading between 150 and 800
    right(60);                                       //calls the function "right"
    delay(100);                                      //delays it by 100 milliseconds

  }   else if (Msensor, Rsensor, Lsensor >= 0 && Msensor, Rsensor, Lsensor <= 80) {   /*creates if command for if the robot is touching the ground 
  but the sensors are reading between 0 and 80 */
   right(100);                                       //calls the function "right"
  }  
}


