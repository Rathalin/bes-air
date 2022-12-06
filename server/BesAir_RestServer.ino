#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_CAP1188.h>

// Replace with your network credentials
const char* ssid = "Rathalin";
const char* password = "Wurmloch";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// stores the content of the index.html file we want the webserver to send
extern const char index_html[] PROGMEM;

void setup() {
  Serial.print("Starting...");
  // Serial port for debugging purposes
  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    request->send_P(200, "text/html", "Use the /api endpoint");
  });

  // API
  server.on("/api/start", HTTP_POST, [](AsyncWebServerRequest* request) {
    Serial.println("Starting Besn");
    request->send(200);
  });

  server.on("/api/stop", HTTP_POST, [](AsyncWebServerRequest* request) {
    Serial.println("Stoping Besn");
    request->send(200);
  });

  // Start server
  server.begin();
}

void loop() {
}

const char index_html[] PROGMEM = R"(
<!DOCTYPE HTML><html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      body {
        font-family: 'sans-serif';
        background-color: #1e1e1e;
        color: white;
      }
    </style>
  </head>
  <body>
    <h2>ESP32 Server</h2>
    <div class="container">
      <div class="row">
        <div id="sensor0" class="col-sm card rounded">S0</div>
        <div id="sensor1" class="col-sm card rounded">S1</div>
        <div id="sensor2" class="col-sm card rounded">S2</div>
        <div id="sensor3" class="col-sm card rounded">S3</div>
        <div id="sensor4" class="col-sm card rounded">S4</div>
        <div id="sensor5" class="col-sm card rounded">S5</div>
        <div id="sensor6" class="col-sm card rounded">S6</div>
        <div id="sensor7" class="col-sm card rounded">S7</div>      
      </div>
    </div>
  </body>
  <script>
    console.log('Joooo')
  </script>
</html>)";
