# automatic-valve-iot
IoT-based automatic solenoid valve control using Arduino, soil moisture sensor, and Bluetooth — VTU Mini Project 2023-24
# 🌱 Automatic Valve Opening Using IoT & Machine Learning

> Mini Project — Bachelor of Engineering (Electronics & Communication Engineering)  
> **AMC Engineering College, Bengaluru** | Visvesvaraya Technological University | 2023–24

---

## 📌 Project Overview

An intelligent, automated irrigation system that uses **IoT sensors**, an **Arduino Uno microcontroller**, and **machine learning** to control a solenoid valve based on real-time soil moisture data. The system eliminates manual irrigation, conserves water, and enables remote monitoring via Bluetooth.

---

## 👥 Team

| Name | USN |
|---|---|
| Yashaswini R | 1AM21EC101 |
| Syed Yousuff Masood | 1AM21EC090 |
| Mohammed Fuzail | 1AM21EC105 |

**Guide:** Dr. Rashmi R Deshpande, Associate Professor, Dept. of ECE, AMCEC

---

## 🔧 Hardware Components

| Component | Purpose |
|---|---|
| Arduino Uno | Central microcontroller — processes sensor data, controls relay & Bluetooth |
| Soil Moisture Sensor | Reads analog soil moisture level (0–1023) |
| Relay Module | Switches the solenoid valve ON/OFF based on Arduino signal |
| Solenoid Valve | Physically controls water flow |
| HC-05 Bluetooth Module | Wireless communication — sends data & receives commands from smartphone |
| Breadboard | Prototyping and connections |
| Power Supply (7–12V) | Powers Arduino and all modules |

---

## 🖥️ Software & Libraries

| Tool / Library | Purpose |
|---|---|
| Arduino IDE | Writing and uploading code to Arduino |
| `WiFi.h` | Wi-Fi connectivity |
| `HTTPClient.h` | HTTP/HTTPS communication |
| `DHT.h` | Temperature & humidity sensor data |
| `Adafruit_Sensor.h` | Sensor integration support |
| Blynk | IoT dashboard — mobile app & web UI for monitoring |

---

## 🏗️ System Architecture

```
Power Supply
     │
     ▼
Sensor Unit (Soil Moisture Sensor)
     │
     ▼
Microcontroller Unit (Arduino Uno)
     │
     ├──► Control Unit
     │         │
     │         ▼
     │    Valve Actuator (Relay Module)
     │         │
     │         ▼
     │    Water Valve (Solenoid Valve)
     │         │
     │         ▼
     │    Field Area
     │
     └──► User Interface (Bluetooth / Web Dashboard)
```

---

## ⚙️ How It Works

1. The **soil moisture sensor** continuously reads the moisture level of the soil.
2. The **Arduino Uno** maps the raw analog reading (0–1023) to a percentage (0–100%).
3. If moisture falls **below 40%** (dry soil), the relay is triggered → solenoid valve **opens** → irrigation starts.
4. When moisture rises **above 40%**, the relay deactivates → valve **closes** → irrigation stops.
5. Real-time moisture data is sent over **Bluetooth (HC-05)** to a paired smartphone for remote monitoring.
6. Users can also manually send `'1'` (relay ON) or `'0'` (relay OFF) commands via Bluetooth.

---

## 📁 Repository Structure

```
automatic-valve-iot/
├── README.md
├── src/
│   ├── valve_control_basic.ino       # Core soil moisture + relay control
│   └── valve_control_bluetooth.ino   # Extended version with HC-05 Bluetooth
├── docs/
│   ├── project_report.md             # Full project documentation
│   └── wiring_reference.md           # Pin connections & wiring guide
├── hardware/
│   └── components_list.md            # Hardware BOM with specs
└── ml/
    └── ml_overview.md                # Machine learning approach overview
```

---

## 🚀 Getting Started

### 1. Clone the Repository
```bash
git clone https://github.com/<your-username>/automatic-valve-iot.git
cd automatic-valve-iot
```

### 2. Install Arduino IDE
Download from: https://www.arduino.cc/en/software

### 3. Install Required Libraries
In Arduino IDE → **Sketch → Include Library → Manage Libraries**, install:
- `DHT sensor library` by Adafruit
- `Adafruit Unified Sensor`
- `BlynkSimpleEsp8266` (if using ESP8266 Wi-Fi)

### 4. Upload the Code
- Open `src/valve_control_basic.ino` (or the Bluetooth version)
- Select Board: **Arduino Uno**
- Select the correct COM port
- Click **Upload**

### 5. Wiring
See [`docs/wiring_reference.md`](docs/wiring_reference.md) for full pin connections.

---

## 📊 Results

- ✅ Automated irrigation triggered at soil moisture < 40%
- ✅ Real-time moisture readings transmitted over Bluetooth
- ✅ Manual override via Bluetooth commands (`'1'` / `'0'`)
- ✅ Reduced water wastage through threshold-based control
- ✅ Scalable design — adaptable to different crops and field sizes

---

## 🔮 Future Enhancements

- Integrate **ESP8266/ESP32** for Wi-Fi and cloud connectivity (replace Bluetooth)
- Add **weather API integration** to factor in rainfall forecasts
- Implement **ML model** (trained on historical soil + weather data) for predictive irrigation
- Build a **web dashboard** using Flask for remote monitoring
- Add **multiple sensor zones** for large-scale field deployment

---

## 📚 References

1. Vij A. et al., *"IoT and Machine Learning Approaches for Automation of Farm Irrigation System"*
2. Abo-Zahhad M.M., *"IoT-based Automated Irrigation Management System using Soil Moisture Data and Weather Forecasting Adopting Machine Learning"*, Sohag University, Egypt
3. Obaideen K. et al., *"An Overview of Smart Irrigation Systems Using IoT"*

---

## 📄 License

This project was developed as an academic mini project at AMC Engineering College, Bengaluru (VTU, 2023–24).  
Free to use for educational and research purposes.
