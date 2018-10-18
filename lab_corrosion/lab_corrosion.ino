// Institution: Queensland University of Technology
// Author: Andrew Collison
// Supervisour: Assoc Prof. Geoffery Will
/* The driving code for an arduino motor driver and data logger
 *  used to raise and lower corrosion samples out of a solution
 *  to control and monitor the corrosion rate of various samples
 *  in a lab based environment
 */

//set motor pins
int d1 = 2;
int d2 = 3;
int motor_speed = 9;

int dir; // Motor direction 
int spd;; // Motor Speed           
int sample_pos = 0; // 0 = sample raised. 1= sample lowerd

const unsigned long SECOND = 1000;
const unsigned long MINUTE = 60*SECOND;
const unsigned long HOUR = 3600*SECOND;


void motor_control(int dir, int spd){
  if(dir == 0){ // Set forward direction
    digitalWrite(d1, HIGH);
    digitalWrite(d2, LOW);
    analogWrite(motor_speed, spd);
    } 
   if(dir == 1){ // Set reverse direction
    digitalWrite(d1, LOW);
    digitalWrite(d2, HIGH);
    analogWrite(motor_speed, spd);
    }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(motor_speed, OUTPUT);

  // Raise Arm to neutral position
  motor_control(1, 255);
  
  // Test Raise and Lower
  motor_control(0, 255);
  delay(5000);
  motor_control(1, 255);
  delay(5000);   
}

void loop() {
  // put your main code here, to run repeatedly:  
  while(1){
    // Motor Down
    motor_control(0, 255); // Check the direction
    delay(5000);   
    // Hold Down: 15 minutes
    delay(15*MINUTE);
    // Motor Raise
    motor_control(1, 255);
    delay(5000);
    // Hold up: 6 hours  
    delay(6*HOURS);
    // Repeat the cycle   
  }
}
