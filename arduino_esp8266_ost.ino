#include "SoftwareSerial.h"
String ssid ="theperfectstorm";

String password="9661458227";

SoftwareSerial esp(2, 3);// RX, TX

String data;

String server = "www.theperfectstorm.co.in"; // www.example.com

String uri = "/quality.php";// our example is /esppost.php

int ppm = analogRead(A0);//sensor pin



String temp ,hum;

void setup() {

pinMode (A0, INPUT);

esp.begin(9600);

Serial.begin(9600);

reset();

connectWifi();

}

//reset the esp8266 module

void reset() {

esp.println("AT+RST");

delay(1000);

if(esp.find("OK") ) Serial.println("Module Reset");

}

//connect to your wifi network

void connectWifi() {

String cmd = "AT+CWJAP=\"" +ssid+"\",\"" + password + "\""+"\r\n\r\n";
delay(1000);

esp.println(cmd);

delay(4000);

if(esp.find("OK")) {

Serial.println("Connected!");

}

else {

connectWifi();

Serial.println("Cannot connect to wifi"); }

}

void loop () {


// convert the bit data to string form



data = "ppm=" + String(ppm);// data sent must be under this form //name1=value1&name2=value2.
Serial.println(data);
delay(1000);
httppost();

delay(1000);

}

void httppost () {

esp.println("AT+CIPSTART=\"TCP\",\"" + server + "\",80");//start a TCP connection.

if( esp.find("OK")) {

Serial.println("TCP connection ready");

} delay(1000);

String postRequest =

"GET " + uri + " HTTP/1.0\r\n" +

"Host: " + server + "\r\n" +

"Accept: *" + "/" + "*\r\n" +

"Content-Length: " +  data.length() + "\r\n" +
"User-Agent: ESP8266_HTTP_Client\r\n"+
"Connection: keep-alive\r\n"+



"Content-Type: application/x-www-form-urlencoded\r\n" +

"\r\n" + data;

String sendCmd = "AT+CIPSEND=";//determine the number of caracters to be sent.
delay(200);
esp.print(sendCmd);
delay(300);

esp.println(postRequest.length() );

delay(500);

if(esp.find(">")) { Serial.println("Sending.."); esp.print(postRequest);

if( esp.find("SEND OK")) { Serial.println("Packet sent");

while (esp.available()) {

String tmpResp = esp.readString();

Serial.println(tmpResp);

}

// close the connection

esp.println("AT+CIPCLOSE");

}

}}
