int x = D2; //led1 العمود
int x1= D5; //led2 البوابه
/////////////////////
int x2= D3; //led3  البيت الدور الاول
int x4=D4;  //led5 البيت الدور التاني
/////////////////////
int x3= D6; //led4  ريلي

#include <Servo.h>
Servo motor;

#include <ESP8266WiFi.h>

const char* ssid="sa";
const char* password = "123456781";


IPAddress ip(192,168,43,35);
IPAddress subnet(255,255,255,0);
IPAddress gate(192,168,43,1);



#include <ESP8266WebServer.h>
ESP8266WebServer server(80);



bool led1 =LOW;
bool led2 =LOW;
bool led3 =LOW;
bool led4 =LOW;
bool led5 =LOW;
void setup() {
  // put your setup code here, to run once:
 
  pinMode(x1,OUTPUT);
  
  motor.attach(D5);
  motor.write(160);
  pinMode(x,OUTPUT);
  //
  pinMode(x2,OUTPUT);
  //
  pinMode(x3,OUTPUT);
  //
  pinMode(x4,OUTPUT);

  WiFi.config(ip,gate,subnet);
  WiFi.begin(ssid,password);

  Serial.begin(9600);

  while(WiFi.status() != WL_CONNECTED){ 
      Serial.print(".");
      delay(10);
      
      
    }

  Serial.println();
  Serial.println(WiFi.localIP());


  server.on("/",Connect);
  server.on("/led1off",Connect_off);
  server.on("/led1on",Connect_on);
  server.onNotFound(notFound);
  server.begin();
  Serial.println("done");
  ////////////////////////////////////////////
  server.on("/",Connect2);
  server.on("/led2off2",Connect_off2);
  server.on("/led2on2",Connect_on2);
  server.onNotFound(notFound2);
  server.begin();
  Serial.println("done");
////////////////////////////////////////////////
  server.on("/",Connect3);
  server.on("/led3off3",Connect_off3);
  server.on("/led3on3",Connect_on3);
  server.onNotFound(notFound3);
  server.begin();
  Serial.println("done");
  ///////////////////////////////////////////
  server.on("/",Connect4);
  server.on("/led4off4",Connect_off4);
  server.on("/led4on4",Connect_on4);
  server.onNotFound(notFound4);
  server.begin();
  Serial.println("done");
////////////////////////////////////////////
  server.on("/",Connect5);
  server.on("/led5off5",Connect_off5);
  server.on("/led5on5",Connect_on5);
  server.onNotFound(notFound5);
  server.begin();
  Serial.println("done");
}

void notFound(){
  server.send(404, "text/plain", "Not found");
}
void Connect_on(){                                
  led1=HIGH;                                     
  server.send(200,"text/html",CodeHtml(led1));    
}                                                 
void Connect_off(){                               
  led1=LOW;                                       
  server.send(200,"text/html",CodeHtml(led1));    
  }                                               
void Connect(){                                   
 // led1=LOW;                                     
  server.send(200,"text/html",CodeHtml(led1));    
}                                                

//////////////////////////////////////////////////                                                  
void notFound2(){
  server.send(404, "text/plain", "Not found2");
}
void Connect_on2(){                                
  led2=HIGH;                                      
  server.send(200,"text/html",CodeHtml(led2));    
}                                                
void Connect_off2(){                               
  led2=LOW;                                       
  server.send(200,"text/html",CodeHtml(led2));   
  }                                               
void Connect2(){                                   
 // led2=LOW;                                     
  server.send(200,"text/html",CodeHtml(led2)); 
}   
///////////////////////////////////////////////////
void notFound3(){
  server.send(404, "text/plain", "Not found3");
}
void Connect_on3(){                                
  led3=HIGH;                                      
  server.send(200,"text/html",CodeHtml(led3));    
}                                                
void Connect_off3(){                               
  led3=LOW;                                       
  server.send(200,"text/html",CodeHtml(led3));   
  }                                               
void Connect3(){                                   
 // led3=LOW;                                     
  server.send(200,"text/html",CodeHtml(led3));  
  }
  ////////////////////////////////////////////////////
void notFound4(){
  server.send(404, "text/plain", "Not found4");
}
void Connect_on4(){                                
  led4=HIGH;                                      
  server.send(200,"text/html",CodeHtml(led4));    
}                                                
void Connect_off4(){                               
  led4=LOW;                                       
  server.send(200,"text/html",CodeHtml(led4));   
  }                                               
void Connect4(){                                   
 // led4=LOW;                                     
  server.send(200,"text/html",CodeHtml(led4));  
  }
////////////////////////////////////////////////////////
void notFound5(){
  server.send(404, "text/plain", "Not found5");
}
void Connect_on5(){                                
  led5=HIGH;                                      
  server.send(200,"text/html",CodeHtml(led5));    
}                                                
void Connect_off5(){                               
  led5=LOW;                                       
  server.send(200,"text/html",CodeHtml(led5));   
  }                                               
void Connect5(){                                   
 // led5=LOW;                                     
  server.send(200,"text/html",CodeHtml(led5));  
  }
/////////////////////////////////////////////////////////
  String CodeHtml(bool led){
      String html;
      html = "<!DOCTYPE html> \
<html>\
    <head>\
        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\
        <title>LED Control</title>\
        <style>\
            html {\
                font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;\
            }\
            body{margin-top: 50px;} \
            h1 {color: #444444;margin: 50px auto 30px;}\ 
            h3 {color: #444444;margin-bottom: 50px;}\
            .button {\
                display: block;width: 80px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;\
            }\
            .button-on {background-color: #1abc9c;}\
            .button-on:active {background-color: #16a085;}\
            .button-off {background-color: #34495e;}\
            .button-off:active {background-color: #2c3e50;}\
            p {font-size: 14px;color: #888;margin-bottom: 10px;}\
        </style>\
    </head>\
    <body>\
        <h1>Smart Home Project Server</h1>\n<h3>Creative Team</h3>\
  ";
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(led){                                                                                       
      html +="<p>LED1 Status: ON</p><a class=\"button button-off\" href=\"/led1off\">Electric Column:   OFF</a>\n";}  
    else{                                                                                          
      html +="<p>LED1 Status: OFF</p><a class=\"button button-on\" href=\"/led1on\">Electric Column:   ON</a>\n";}  
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      if(led2){                                                                                       
      html +="<p>LED2 Status: ON</p><a class=\"button button-off\" href=\"/led2off2\">House Gate:   OFF</a>\n";}  
    else{                                                                                          
      html +="<p>LED2 Status: OFF</p><a class=\"button button-on\" href=\"/led2on2\">House Gate:   ON</a>\n";}    
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
    if(led3){                                                                                       
      html +="<p>LED3 Status: ON</p><a class=\"button button-off\" href=\"/led3off3\">First Floor light:    OFF</a>\n";}  
    else{                                                                                          
      html +="<p>LED3 Status: OFF</p><a class=\"button button-on\" href=\"/led3on3\">First Floor light:     ON</a>\n";}  
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
      if(led4){                                                                                       
      html +="<p>LED4 Status: ON</p><a class=\"button button-off\" href=\"/led4off4\">Search light:    OFF</a>\n";}  
    else{                                                                                          
      html +="<p>LED4 Status: OFF</p><a class=\"button button-on\" href=\"/led4on4\">Search light:     ON</a>\n";}  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
      if(led5){                                                                                       
      html +="<p>LED5 Status: ON</p><a class=\"button button-off\" href=\"/led5off5\">Second Floor light:    OFF</a>\n";}  
    else{                                                                                          
      html +="<p>LED5 Status: OFF</p><a class=\"button button-on\" href=\"/led5on5\">Second Floor light:     ON</a>\n";}  
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    html +="</body>\n";
    html +="</html>\n";

      return html;
     
}

void loop() {
  // put your main code here, to run repeatedly:

//////////////////////////////////////////////
server.handleClient();  
if(led1)
{digitalWrite(x, HIGH);}
else
{digitalWrite(x, LOW);}
//////////////////////////////////////////////
server.handleClient(); 
if(led2)
{digitalWrite(x1, HIGH);
motor.write(160);
delay(300);
motor.write(150);
delay(300);
motor.write(140);
delay(300);
motor.write(130);
delay(300);
motor.write(120);
delay(300);
motor.write(110);
delay(300);
motor.write(100);
delay(300);
motor.write(90);
delay(300);
motor.write(80);
delay(300);
motor.write(70);
delay(300);
motor.write(60);
delay(300);
motor.write(50);
delay(300);
motor.write(40);
delay(300);
motor.write(30);
delay(300);
motor.write(20);
delay(300);
motor.write(10);
delay(300);
motor.write(0);
delay(3000);
motor.write(10);
delay(300);
motor.write(20);
delay(300);
motor.write(30);
delay(300);
motor.write(40);
delay(300);
motor.write(50);
delay(300);
motor.write(60);
delay(300);
motor.write(70);
delay(300);
motor.write(80);
delay(300);
motor.write(90);
delay(300);
motor.write(100);
delay(300);
motor.write(110);
delay(300);
motor.write(120);
delay(300);
motor.write(130);
delay(300);
motor.write(140);
delay(300);
motor.write(150);
delay(300);
motor.write(160);
delay(3000);}
else
{digitalWrite(x1, LOW);}
//////////////////////////////////////////////////
server.handleClient();  
if(led3)
{digitalWrite(x2, HIGH);}
else
{digitalWrite(x2, LOW);}
/////////////////////////////////////////////////
server.handleClient();  
if(led4)
{digitalWrite(x3, HIGH);}
else
{digitalWrite(x3, LOW);}
////////////////////////////////////////////////
server.handleClient();  
if(led5)
{digitalWrite(x4, HIGH);}
else
{digitalWrite(x4, LOW);}
  
  
}
