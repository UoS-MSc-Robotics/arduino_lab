// This Example code is for use with the Controlling a Standard Servomotor exercise
//

// Include the servo library to allow for connection and control of servo motors
#include <Servo.h>

// define the macro pinServo1 as 9, to use for connecting the servo to pin 9
#define pinServo1 9

#define potPin A0

// Declare a servo motor class variable servo 1
Servo servo1;

// -------------------------------------
// Setup function
void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);

  // "attach"  servo 1 to the defined pin
  servo1.attach(pinServo1);

  // set the neutral, centre, position for the servo
  servo1.write(90);

  // Alternte command for setting the neutral position
  //servo1.writeMicroseconds(1500);

  // wait until the servo has moved into position, (1000ms is more time than needed)
  delay(1000);
}

// -------------------------------------
// Loop Function
void loop() {

  // read the value of the potentiometer
  int potValue = analogRead(potPin);

  // map the potentiometer value to a range of -150 to 150
  int potAngle = map(potValue, 0, 1023, -150, 150);

  // map the servo value to a range of 0 to 180
  int servoAngle = map(potAngle, -150, 150, 0, 180);

  // print the pot angle and servo angle to the serial monitor
  int servodebugAngle = map(potAngle, -150, 150, -90, 90);

  Serial.print("Potentiometer Angle: ");
  Serial.print(potAngle*-1);
  Serial.print(", Servo Angle: ");
  Serial.println(servodebugAngle*-1);
  Serial.print("\r\n");
  delay(100);


  // use PWM to control the servo position
  servo1.write(servoAngle);
}
