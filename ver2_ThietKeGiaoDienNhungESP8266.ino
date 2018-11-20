// Them thu vien

#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <DHT.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
WiFiUDP u;
NTPClient n(u,"0.asia.pool.ntp.org", 7 * 3600);
#include "index.h"

// Pin
// Su dung cam bien DHT11
#define DHTTYPE DHT22
#define DHTPIN D1
#define output_pin D5
#define output_pin1 D6
int tus=0, temp = 0, humi = 0;
String trangthai = "OFF", tuss="-1";

int gioHienTai=-1, phutHienTai=-1;
int gioHenBatDen=-1, phutHenBatDen=-1, gioHenTatDen=-1, phutHenTatDen=-1;
int gioHenBatBom=-1, phutHenBatBom=-1,gioHenTatBom=-1, phutHenTatBom=-1;

// Thiet lap DHT
DHT dht(DHTPIN, DHTTYPE);

// Thong so WiFi nha ban
//const char* ssid = "R&D WORKSHOP";
//const char* password = "174238hqv";
const char* ssid = "Mechanical HQV";
const char* password = "174238HQV";
//const char* ssid = "Ank";
//const char* password = "1234567890";
//const char* ssid = "Đỗ Huy Có Dấu";
//const char* password = "12345678910111213";
//const char* ssid = "mynet";
//const char* password = "honganh1997";
//const char* ssid = "Nhu Hai";
//const char* password = "88888888";
//const char* ssid = "Quynh Duong";
//const char* password = "0985820470";
//const char* ssid = "KhongWifi";
//const char* password = "hue00111";

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
  server.on("/giobatden", giobatden);
  server.on("/phutbatden", phutbatden);
  server.on("/giotatden", giotatden);
  server.on("/phuttatden", phuttatden);
   server.on("/giobatbom", giobatbom);
  server.on("/phutbatbom", phutbatbom);
  server.on("/giotatbom", giotatbom);
  server.on("/phuttatbom", phuttatbom);
  server.on("/ledCheckStatus", ledCheckStatus);
  server.on("/bomCheckStatus", bomCheckStatus);
  // Khoi dong server
  server.begin();
  Serial.println("Khoi dong Server");

  // In ra dia chi IP
  Serial.println(WiFi.localIP());
  
 
}
void loop(void){
  server.handleClient();          //Handle client requests
  n.update();
  String time = n.getFormattedTime();
  gioHienTai = (time.substring(0, 2)).toInt();
  phutHienTai = (time.substring(3, 5)).toInt();

// điều khiển đèn
  if(gioHenBatDen >= 0)
  {
       if((gioHenBatDen == gioHienTai))
       {
           if((phutHenBatDen == phutHienTai))
           {
                 digitalWrite(output_pin, 1);
                 
                 //gioHenBatDen = phutHenBatDen = -1;
           }
       }
  }
  if(gioHenTatDen >= 0)
  {
       if((gioHenTatDen == gioHienTai))
       {
           if((phutHenTatDen == phutHienTai))
           {
                 digitalWrite(output_pin, 0);
                 //gioHenTatDen = phutHenTatDen = -1;
           }
       }
  }

//điều khiển bơm
  if(gioHenBatBom >= 0)
  {
       if((gioHenBatBom == gioHienTai))
       {
           if((phutHenBatBom == phutHienTai))
           {
                 digitalWrite(output_pin1, 1);
                 //gioHenBatBom = phutHenBatBom = -1;
           }
       }
  }

  if(gioHenTatBom >= 0)
  {
       if((gioHenTatBom == gioHienTai))
       {
           if((phutHenTatBom == phutHienTai))
           {
                 digitalWrite(output_pin1, 0);
                 //gioHenTatBom = phutHenTatBom = -1;
           }
       }
  }

  
//  
//  Serial.println("=========================");
//  Serial.printf("Gio hien tai: ");
//     Serial.println(gioHienTai);
//     Serial.printf("Phut hien tai: ");
//     Serial.println(phutHienTai);
//  Serial.printf("Gio bat hen den: ");
//     Serial.println(gioHenBatDen);
//      Serial.printf("Phut bat hen den: ");
//     Serial.println(phutHenBatDen);
//     Serial.printf("Gio tat hen den: ");
//     Serial.println(gioHenTatDen);
//      Serial.printf("Phut tat hen den: ");
//     Serial.println(phutHenTatDen);
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

void giobatden()
{
  Serial.println(gioHenBatDen);
  server.send(200, "text/plane", String(gioHenBatDen));
}
void phutbatden()
{
  server.send(200, "text/plane", String(phutHenBatDen));
}
void giotatden()
{
  server.send(200, "text/plane", String(gioHenTatDen));
}
void phuttatden()
{
  server.send(200, "text/plane", String(phutHenTatDen));
}

void giobatbom()
{
  server.send(200, "text/plane", String(gioHenBatBom));
}
void phutbatbom()
{
  server.send(200, "text/plane", String(phutHenBatBom));
}
void giotatbom()
{
  server.send(200, "text/plane", String(gioHenTatBom));
}
void phuttatbom()
{
  server.send(200, "text/plane", String(phutHenTatBom));
}

void ledCheckStatus()
{
    tus = digitalRead(output_pin);
    if(tus== HIGH)
    {
      trangthai = "Tắt đèn";
    }
    if(tus== LOW)
    {
      trangthai = "Bật đèn";
    }
    server.send(200, "text/plane", trangthai);
}
void bomCheckStatus()
{
    tus = digitalRead(output_pin1);
    if(tus== HIGH)
    {
      trangthai = "Tắt bơm";
    }
    if(tus== LOW)
    {
      trangthai = "Bật bơm";
    }
    server.send(200, "text/plane", trangthai);
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
    tuss = server.arg("stus");
    if(tuss== "0")
    {
        gioHenTatDen = (server.arg("gio")).toInt();
        phutHenTatDen = (server.arg("phut")).toInt();
    }
    if(tuss== "1")
    {
          gioHenBatDen = (server.arg("gio")).toInt();
          phutHenBatDen = (server.arg("phut")).toInt();
    }
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
    tuss = server.arg("stus");
    if(tuss== "0")
    {
        gioHenTatBom = (server.arg("gio")).toInt();
        phutHenTatBom = (server.arg("phut")).toInt();
    }
    if(tuss== "1")
    {
          gioHenBatBom = (server.arg("gio")).toInt();
          phutHenBatBom = (server.arg("phut")).toInt();
    }
}
