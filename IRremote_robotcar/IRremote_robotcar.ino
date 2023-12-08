/* the goal of this program is to control the movement of the robot car with an IR Remote*/

# include <IRremote.h>          //includes the IR remote library

int myState;               //sets myState as an integer
int motspeed = 10;         //sets motspeed as an integer = to 10

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
void upspeed() {                     //creates function to increase the speed of the car
  motspeed = motspeed + 25;
  myState = 0;
}
void downspeed() {                  //creates function to decrease the speed of the car
  motspeed = motspeed - 25;
  myState = 0;
}

int IR_REC = 9;             //sets pin 9 to integer IR_REC
#define key1 22             //defines Key1 as #22
#define key2 25             //defines Key2 as #25
#define key3 13             //defines Key3 as #13
#define key4 12             //defines Key4 as #12
#define key5 24             //defines Key5 as #24
#define key6 94             //defines Key6 as #94
#define key7 8             //defines Key7 as #8
#define key8 28            //defines Key8 as #28
#define key9 90             //defines Key9 as #90
#define key0 82             //defines Key0 as #82
#define uparrow 70             //defines uparrow as #70
#define downarrow 21             //defines downarrow as #21
#define leftarrow 68             //defines leftarrow as #68
#define rightarrow 67             //defines rightarrow as #67
#define ok 64             //defines ok as #64
#define star 74             //defines star as #74
#define hashtag 66             //defines hashtag as #66

void setup() { 
  // put your setup code here, to run once: 
    pinMode(5, OUTPUT);     //sets pin 5 as an output
    pinMode(8, OUTPUT);     //sets pin 8 as an output
    pinMode(6, OUTPUT);     //sets pin 6 as an output
    pinMode(7, OUTPUT);     //sets pin 7 as an output
    pinMode(3, OUTPUT);     //sets pin 3 as an output
    digitalWrite(3, 1);      //turns on the motor 
    IrReceiver.begin(IR_REC, ENABLE_LED_FEEDBACK);      //starts the IR_REC pin to enable feedback

} 

void loop() { 
  // put your main code here, to run repeatedly: 
    if (IrReceiver.decode()) {                             //decodes the IR receiver
    const int myState = IrReceiver.decodedIRData.command;      //sets the IR data to myState
    IrReceiver.resume();                                     //resumes the receiver

if (myState == uparrow) {      //creates if command for if certain key is pressed do X
  forward(motspeed);           //calls the function "forward"
} 
if (myState == ok) {      //creates if command for if certain key is pressed do X
  stopit();                   //calls the function "stopit"
} 
if (myState == downarrow) {      //creates if command for if certain key is pressed do X
  backwards(motspeed);           //calls the function "backwards"
} 
if (myState == leftarrow) {      //creates if command for if certain key is pressed do X
  left(motspeed);                //calls the function "left"
}
if (myState == rightarrow) {      //creates if command for if certain key is pressed do X
  right(motspeed);                //calls the function "right"
}
if (myState == key1) {      //creates if command for if certain key is pressed do X
  leftforward(motspeed);          //calls the function "leftforward"
}
if (myState == key3) {      //creates if command for if certain key is pressed do X
  rightforward(motspeed);         //calls the function "rightforward"
}
if (myState == star) {      //creates if command for if certain key is pressed do X
  upspeed();                      //calls the function "upspeed"
}
if (myState == hashtag) {      //creates if command for if certain key is pressed do X
  downspeed();                   //calls the function "downspeed"
} 
  } 

   }



