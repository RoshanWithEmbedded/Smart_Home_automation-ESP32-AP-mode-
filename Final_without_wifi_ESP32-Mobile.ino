#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

/* ===== AP DETAILS ===== */
const char* ap_ssid = "Smart_Home_chavan";
const char* ap_pass = "987654321";

/* ===== RELAY PINS ===== */
#define R1 23   // Back Light
#define R2 19   // Front Light
#define R3 18   // Blue Ceiling Light
#define R4 5    // Fan

bool s1=false, s2=false, s3=false, s4=false;

/* ===== HTML PAGE GENERATOR ===== */
String mainPage() {
  String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>ESP32 Smart Home</title>
<style>
body {
  margin: 0;
  height: 100vh;
  background: #0f172a;
  display: flex;
  justify-content: center;
  align-items: center;
  font-family: Arial;
  color: white;
}
.container {
  width: 100%;
  max-width: 420px;
  padding: 20px;
  text-align: center;
}
button {
  width: 100%;
  padding: 18px;
  font-size: 20px;
  margin: 12px 0;
  border-radius: 12px;
  border: none;
  cursor: pointer;
  color: white;
}
.on { background: #22c55e; }
.off { background: #ef4444; }
</style>
</head>
<body>
<div class="container">
<h2>ESP32 Smart Home</h2>

<button class="%C1%" onclick="location.href='/r1'">
  &#128161; Back Light : %S1%
</button>

<button class="%C2%" onclick="location.href='/r2'">
  &#128262; Front Light : %S2%
</button>

<button class="%C3%" onclick="location.href='/r3'">
  &#128309; Blue Ceiling Light : %S3%
</button>

<button class="%C4%" onclick="location.href='/r4'">
  &#128736; Fan : %S4%
</button>

</div>
</body>
</html>
)rawliteral";

  page.replace("%S1%", s1 ? "ON" : "OFF");
  page.replace("%S2%", s2 ? "ON" : "OFF");
  page.replace("%S3%", s3 ? "ON" : "OFF");
  page.replace("%S4%", s4 ? "ON" : "OFF");

  page.replace("%C1%", s1 ? "on" : "off");
  page.replace("%C2%", s2 ? "on" : "off");
  page.replace("%C3%", s3 ? "on" : "off");
  page.replace("%C4%", s4 ? "on" : "off");

  return page;
}

void setup() {
  Serial.begin(115200);

  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);

  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  digitalWrite(R4, HIGH);

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ap_ssid, ap_pass);

  Serial.print("ESP32 AP IP: ");
  Serial.println(WiFi.softAPIP()); // 192.168.4.1

  server.on("/", []() {
    server.send(200, "text/html", mainPage());
  });

  server.on("/r1", []() { s1=!s1; digitalWrite(R1, s1?LOW:HIGH); server.sendHeader("Location","/"); server.send(303); });
  server.on("/r2", []() { s2=!s2; digitalWrite(R2, s2?LOW:HIGH); server.sendHeader("Location","/"); server.send(303); });
  server.on("/r3", []() { s3=!s3; digitalWrite(R3, s3?LOW:HIGH); server.sendHeader("Location","/"); server.send(303); });
  server.on("/r4", []() { s4=!s4; digitalWrite(R4, s4?LOW:HIGH); server.sendHeader("Location","/"); server.send(303); });

  server.begin();
}

void loop() {
  server.handleClient();
}
