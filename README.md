# Smart_Home_automation-ESP32-AP-mode-
ESP32-based Smart Home Automation system using WiFi Access Point mode. Control 4 appliances via a responsive web interface without internet or external router.

# ESP32 Smart Home – WiFi Relay Control (AP Mode) --->>>(4 switch Home_automation)

	This project demonstrates a 
	**Smart Home control system using ESP32** in 
	**Access Point (AP) mode**.  
	Users can connect directly to the ESP32 WiFi network and control 
	**4 electrical appliances (relays)** through a 
	**mobile-friendly web interface** without requiring an external router or internet connection.

---

## 🚀 Features

	- ESP32 runs as **WiFi Access Point**
	- Control **4 appliances** using relays
	- **Responsive Web UI** (mobile & desktop friendly)
	- Real-time **ON/OFF status indication**
	- Simple and lightweight **WebServer (port 80)**
	- No cloud, no internet required
	- Ideal for **local smart home automation**

---

## 🔧 Hardware Requirements

	- ESP32 Development Board
	- 4-Channel Relay Module (Active LOW)
	- Electrical appliances (Bulb, Fan, etc.)
	- Jumper wires
	- Power supply

---

## Relay Configuration

	| Relay | GPIO Pin | Appliance |
	|------|---------|-----------|
	| R1   | GPIO 23 | Back Light |
	| R2   | GPIO 19 | Front Light |
	| R3   | GPIO 18 | Blue Ceiling Light |
	| R4   | GPIO 5  | Fan |

	> Relays are **Active LOW**, so `LOW = ON` and `HIGH = OFF`.

---

##  WiFi Access Point Details

	| Parameter | Value |
	|---------|------|
	| SSID | `Smart_Home_chavan` |
	| Password | `987654321` |       we can change password in programm
	| IP Address | `192.168.4.1` |
	| Port | `80` |

---

## 📱 How It Works

	1. ESP32 creates its own WiFi network (AP mode)
	2. User connects phone/laptop to ESP32 WiFi
	3. Open browser and go to:
 		http://192.168.4.1
	4. Control appliances using web buttons
	5. Button color indicates ON/OFF status

---

## 🖥️ Web Interface

- Green button → ON
- Red button → OFF
- Emoji icons for easy identification
- Fully responsive UI

---

## 🧪 Libraries Used

- `WiFi.h`
- `WebServer.h`

(Pre-installed with ESP32 board package)

---

## 🔌 Upload Instructions

1. Install **ESP32 Board Support** in Arduino IDE
2. Select correct ESP32 board and COM port
3. Upload the code
4. Open Serial Monitor at **115200 baud**
5. Note the AP IP address
6. Connect to ESP32 WiFi and control devices

---

## 📌 Applications

- Home automation
- Mini smart switch board
- Hostel / PG automation
- IoT learning project
- Embedded systems portfolio project

---

## 🧑‍💻 Author

**Roshan P Chavan**  
Electronics & Telecommunication Engineer  
Embedded Systems Enthusiast

---

## ⭐ Support
If you like this project:
- ⭐ Star the repository  
- 🍴 Fork it  
- 🛠️ Improve it  

Happy Coding! 🚀


