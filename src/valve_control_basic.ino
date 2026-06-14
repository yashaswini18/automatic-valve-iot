/*
 * Automatic Valve Opening Using IoT
 * ----------------------------------------------------
 * Mini Project — Dept. of ECE, AMC Engineering College
 * VTU, Belagavi | 2023-24
 *
 * Description:
 *   Reads soil moisture from an analog sensor.
 *   Maps the reading to a percentage (0–100%).
 *   Activates a relay (and solenoid valve) when
 *   moisture drops below 40% (dry soil threshold).
 *
 * Pin Configuration:
 *   Relay Module  → Arduino Pin 2
 *   Soil Sensor   → Arduino Pin A0
 * ----------------------------------------------------
 */

const int relayEnable  = 2;     // Relay control pin
const int sensorPin    = A0;    // Soil moisture sensor analog pin
const int thresholdMax = 800;   // Sensor value = very dry soil
const int thresholdMin = 300;   // Sensor value = very wet soil

void setup() {
  pinMode(relayEnable, OUTPUT);
  pinMode(sensorPin, INPUT);

  Serial.begin(9600);
  Serial.println("=== Soil Moisture Monitoring System ===");
  delay(1000);
}

void loop() {
  // Read raw analog value from sensor (0–1023)
  int sensorValue = analogRead(sensorPin);

  // Map raw value to moisture percentage (0% = dry, 100% = wet)
  sensorValue = map(sensorValue, thresholdMin, thresholdMax, 100, 0);

  // Keep within valid range
  sensorValue = constrain(sensorValue, 0, 100);

  // Print to Serial Monitor
  Serial.print("Moisture: ");
  Serial.print(sensorValue);
  Serial.println("%");

  // Control relay based on moisture level
  if (sensorValue < 40) {
    // Soil is dry — open valve
    digitalWrite(relayEnable, LOW);
    Serial.println("Status: Relay ON  → Valve OPEN (irrigating)");
  } else {
    // Soil is adequately moist — close valve
    digitalWrite(relayEnable, HIGH);
    Serial.println("Status: Relay OFF → Valve CLOSED");
  }

  Serial.println("-------------------------------");
  delay(1000);  // Wait 1 second before next reading
}
