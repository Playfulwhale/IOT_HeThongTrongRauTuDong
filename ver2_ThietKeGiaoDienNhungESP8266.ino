// Them thu vien

#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <DHT.h>
#include "index.h"

// Pin
// Su dung cam bien DHT11
#define DHTTYPE DHT22
#define DHTPIN D1
#define output_pin D8
#define output_pin1 D7
int tus=0, temp = 0, humi = 0;
String trangthai = "OFF";
// Thiet lap DHT
DHT dht(DHTPIN, DHTTYPE);

// Thong so WiFi nha ban
//const char* ssid = "R&D WORKSHOP";
//const char* password = "174238hqv";
//const char* ssid = "Ank";
//const char* password = "1234567890";
//const char* ssid = "mynet";
//const char* password = "honganh1997";
//const char* ssid = "Nhu Hai";
//const char* password = "88888888";
const char* ssid = "Quynh Duong";
const char* password = "0985820470";

// Tao server
ESP8266WebServer server(80);

void setup() {

// Khai bao GPIO5
  pinMode(output_pin, OUTPUT);
   pinMode(output_pin1, OUTPUT);
   digitalWrite(output_pin1, 0);
  digitalWrite(output_pin, 0);
  // Mo Serial
  Serial.begin(115200);
  delay(10);

  // Khoi tao DHT
  dht.begin();

  // Ket noi toi mang WiFi
  Serial.print("Ket noi toi mang ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Da ket noi WiFi");
  
  server.on("/", handleRoot);
  server.on("/temp", temperature);
  server.on("/humi", humidity);
  server.on("/led", ledControl);
  server.on("/led1", ledControl1);
  server.on("/bom", bomControl);
  server.on("/bom1", bomControl1);
  // Khoi dong server
  server.begin();
  Serial.println("Khoi dong Server");

  // In ra dia chi IP
  Serial.println(WiFi.localIP());
  
 
}
void loop(void){
  server.handleClient();          //Handle client requests
}

void handleRoot()
{
  String s = MAIN_page; //Doc trang HTML
  server.send(200, "text/html", s); // Gui HTML den client
}

void temperature()
{
  temp = dht.readTemperature();
  server.send(200, "text/plane", String(temp));
}

void humidity()
{
  humi = dht.readHumidity();
  server.send(200, "text/plane", String(humi));
}
void ledControl()
{
    tus = digitalRead(output_pin);
    if(tus== LOW)
    {
      trangthai = "Tắt đèn";
      digitalWrite(output_pin, 1);
    }
    if(tus== HIGH)
    {
      trangthai = "Bật đèn";
      digitalWrite(output_pin, 0);
    }
    server.send(200, "text/plane", trangthai);
}
void ledControl1()
{
    String tuss = server.arg("stus");
    Serial.println(tuss);
    if(tuss== "1")
    {
      trangthai = "Bật đèn";
      digitalWrite(output_pin, 1);
    }
    if(tuss== "0")
    {
      trangthai = "Tắt đèn";
      digitalWrite(output_pin, 0);
    }
    server.send(200, "text/plane", trangthai);
}
void bomControl()
{
    tus = digitalRead(output_pin1);
    if(tus== LOW)
    {
      trangthai = "Tắt bơm";
      digitalWrite(output_pin1, 1);
    }
    if(tus== HIGH)
    {
      trangthai = "Bật bơm";
      digitalWrite(output_pin1, 0);
    }
    server.send(200, "text/plane", trangthai);
}
void bomControl1()
{
    String tuss = server.arg("stus");
    Serial.println(tuss);
    if(tuss== "1")
    {
      trangthai = "OFF";
      digitalWrite(output_pin1, 1);
    }
    if(tuss== "0")
    {
      trangthai = "ON";
      digitalWrite(output_pin1, 0);
    }
    server.send(200, "text/plane", trangthai);
}
