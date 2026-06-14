/*
 * Automatic Valve Opening Using IoT — Bluetooth Version
 * -------------------------------------------------------
 * Mini Project — Dept. of ECE, AMC Engineering College
 * VTU, Belagavi | 2023-24
 *
 * Description:
 *   Extended version with HC-05 Bluetooth module support.
 *   - Sends real-time soil moisture data to paired smartphone
 *   - Accepts manual control commands over Bluetooth:
 *       Send '1' → Force relay ON  (open valve)
 *       Send '0' → Force relay OFF (close valve)
 *   - Auto-controls relay based on moisture threshold (< 30%)
 *
 * Pin Configuration:
 *   Relay Module     → Arduino Pin 2
 *   Soil Sensor      → Arduino Pin A0
 *   HC-05 TX         → Arduino Pin 0 (RX)
 *   HC-05 RX         → Arduino Pin 1 (TX)
 * -------------------------------------------------------
 */

const int relayEnable  = 2;     // Relay control pin
const int sensorPin    = A0;    // Soil moisture sensor
const int thresholdMax = 800;   // Sensor reading at max dryness
const int thresholdMin = 400;   // Sensor reading at max wetness

void setup() {
  pinMode(relayEnable, OUTPUT);
  pinMode(sensorPin, INPUT);

  // Initialize Serial for Bluetooth communication (HC-05)
  Serial.begin(9600);
  Serial.println("=== Soil Moisture Monitoring System (BT Mode) ===");
  delay(1000);
}

void loop() {
  // Read and map sensor value to moisture percentage
  int sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue, thresholdMin, thresholdMax, 0, 100);
  sensorValue = constrain(sensorValue, 0, 100);

  // Transmit moisture data over Bluetooth to paired device
  Serial.print("Moisture: ");
  Serial.print(sensorValue);
  Serial.println("%");

  // ── Manual Override via Bluetooth Commands ──
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == '1') {
      digitalWrite(relayEnable, LOW);   // Activate relay → Open valve
      Serial.println("Manual: Relay ON → Valve OPEN");
    } else if (command == '0') {
      digitalWrite(relayEnable, HIGH);  // Deactivate relay → Close valve
      Serial.println("Manual: Relay OFF → Valve CLOSED");
    }
  }

  // ── Automatic Control Based on Moisture Level ──
  if (sensorValue < 30) {
    // Soil is dry — activate relay to open solenoid valve
    digitalWrite(relayEnable, LOW);
    Serial.println("Auto: Relay ON → Valve OPEN (moisture < 30%)");
  } else {
    // Soil moisture is sufficient — deactivate relay
    digitalWrite(relayEnable, HIGH);
    Serial.println("Auto: Relay OFF → Valve CLOSED");
  }

  Serial.println("--------------------------------");
  delay(1000);  // 1-second interval between readings
}
