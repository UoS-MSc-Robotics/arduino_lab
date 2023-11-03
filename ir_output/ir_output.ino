int irSensorPin = 1;    // Analog input pin that sensor is attached to
int irReading = 0;      // variable to store the value read
int avg_number = 50;

void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(irSensorPin, INPUT);
}


void loop(void) {

  float DistReading = 0;
  for (int n = 0; n < avg_number; n++) {
    DistReading += (float)analogRead(irSensorPin);
  }
  DistReading /= (float)avg_number;

  Serial.print("Uncalibrated distance = ");
  Serial.print(DistReading);
  Serial.println("cm");
  Serial.print("\r\n");
}
