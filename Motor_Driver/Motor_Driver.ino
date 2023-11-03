// TB6612FNG Driver Board Sample board
//
// Author: Ben Taylor
// University of Sheffield
// Date: September 2021

//
const int pinAI1 = 7;       // Pin allocation for AI1
const int pinAI2 = 8;       // Pin allocation for AI2
const int pinPWM = 5;       // Pin allocation for the PWM pin
const int pinStandBy = 9;   // Pin allocation for the standby pin
const int potPin = 0;      // Pin allocation for the potentiometer


boolean AI1 = 0;            // AI1 pin value
boolean AI2 = 0;            // AI2 pin value
boolean standBy = 0;        // standBy pin Value

boolean rotDirect = 0;      // Rotation direction variable
unsigned char pwmValue = 0; // PWM value to be written to the output

void setup()
{
  // Assign the digital I/O pin directions
  pinMode(potPin, INPUT);
  pinMode(pinAI1, OUTPUT);
  pinMode(pinAI2, OUTPUT);
  pinMode(pinPWM, OUTPUT);
  pinMode(pinStandBy, OUTPUT);


  //Initialize the serial port
  Serial.begin(9600);

  // Drive the standby pin high to enable the output
  standBy = true;
  digitalWrite(pinStandBy, standBy);

  // Set Initial values for AI1 and AI2 control function pins
  AI1 = true;
  AI2 = false;

  // set an initial value for the PWM value
  pwmValue = 100;
}

void loop() {

  float potReading = analogRead(potPin);

  if (potReading >= 512) {
    AI1 = true;
    AI2 = false;
    pwmValue = map(potReading, 512, 1023, 0, 255);
  }
  else {
    AI1 = false;
    AI2 = true;
    pwmValue = map(potReading, 0, 511, 255, 0);
  }

  // Write the AI1 and AI2 values to the configuration pins
  digitalWrite(pinAI1, AI1);
  digitalWrite(pinAI2, AI2);

  // Write the pwnValue to the PWM pin
  analogWrite(pinPWM, pwmValue);

  // Display the board variable status to the Serial Monitor
  Serial.print("ADC Values: ");
  Serial.print(potReading);
  Serial.print(", PWM Value: ");
  Serial.print(pwmValue);
  Serial.print(", AI1: ");
  Serial.print(AI1);
  Serial.print(", AI2: ");
  Serial.print(AI2);
  Serial.print(", Standby: ");
  Serial.println(standBy);
  Serial.print("\r\n");

  delay(100);
}
