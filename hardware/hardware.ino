const int ledPin = 13;       // LED 1 pin
const int ledPin1 = 11;      // LED 2 pin
const int fanPin = 12;       // Fan pin
const int gasSensorPin = A0; // MQ2/MQ135 analog pin
const int tempSensorPin = A1;  // Temperature sensor analog pin (LM35)

int smokeThreshold = 400;    // Calibrate this value
bool smokeDetected = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(fanPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Handle incoming serial commands
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "LED1_ON") {
      digitalWrite(ledPin, HIGH);
    } 
    else if (command == "LED1_OFF") {
      digitalWrite(ledPin, LOW);
    } 
    else if (command == "LED2_ON") {
      digitalWrite(ledPin1, HIGH);
    } 
    else if (command == "LED2_OFF") {
      digitalWrite(ledPin1, LOW);
    } 
    else if (command == "FAN_ON") {
      digitalWrite(fanPin, HIGH);
    } 
    else if (command == "FAN_OFF") {
      digitalWrite(fanPin, LOW);
    }
  }

  // Read temperature sensor (LM35)
  int tempRaw = analogRead(tempSensorPin);
  float voltage = tempRaw * (5.0 / 1023.0);
  float temperatureC = voltage * 100.0;

  // Send temperature reading over Serial
  Serial.print("TEMP:");
  Serial.println(temperatureC);

  // Smoke detection logic
  int gasValue = analogRead(gasSensorPin);

  if (gasValue > smokeThreshold && !smokeDetected) {
    Serial.println("SMOKE_ALERT");
    smokeDetected = true;
  } 
  else if (gasValue <= smokeThreshold && smokeDetected) {
    Serial.println("CLEAR");
    smokeDetected = false;
  }

  delay(500); // Stabilize readings and reduce serial noise
}
