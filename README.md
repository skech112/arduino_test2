# arduino_test2

1번 문항 

         1 - 공학도로서 창의성을 발휘할 수 있도록 한다.

         2 - 팀과 협업하고 잘 소통할 수 있는 기초를 다진다.
         
         3 - 아두이노를 활용하여 IoT 관련 생활에 유용한 제품을 만들 수 있다.
         
         4 - 사물 인터넷을 스마트폰 앱으로 무선 제어 할 수 있다.
         
         5 - 로봇을 스마트폰으로 구동하고 원하는 위치로 제어할 수 있다.



2번 문항 : 집의 전등에 아두이노를 통해 연결하려면 릴레이를 추가하여 아두이노 5v로 220v등을 제어해야한다. 

```c
    int relay = 7
    void setup() {
    Serial.begin(9600);
    pinMode(relay, OUTPUT);
    }
 
    void loop() {
 
    if (Serial.available() > 0) {
    
     String m = Serial.readStringUntil('\n');
         if (m == "on") {
       digitalWrite(relay, HIGH);
     } else if (m == "off") {
       digitalWrite(relay, LOW);
     }
   }
 }
```

위의 코드는 릴레이에 7번핀으로 5v 신호를 보내려는 코드이다. 릴레이가 2핀이라 가정하고 아두이노의 GND, 신호선(7번핀)을 맞게 연결해준다.
그리고 릴레이의 반대편에는 전구와 그 220v선을 릴레이, 콘센트에 연결해준다.
그 후 Server와 통신하려면 위의 코드에서 처럼 Serial통신을 통해서 연결해줘야한다. Server쪽으로 와서는

```processing
import processing.net.*;
import processing.serial.*;
Server s;
 Client c;
 Serial p;
 void setup() {
   s = new Server(this, 123);
   p = new Serial(this, "COM11", 9600);
 }
 String msg="hi";
 void draw() {
   c = s.available();
   if (c!=null) {
    
     String m = c.readString();
     if (m.indexOf("GET /")==0) {
       c.write("HTTP/1.1 200 OK\r\n\r\n");
       c.write(msg);
     }
     if (m.indexOf("PUT /")==0) {
       int n = m.indexOf("\r\n\r\n")+4; // on-off 위치
       m = m.substring(n); // on-off 잘라 내는 위치   //
       m += '\n';           // 표시할 문자
       p.write(m); // 시리얼 포트로 on-off 보내기 
       print(m);
     }
   }
   if (p.available()>0) { // 시리얼 데이터 읽기
     String m = p.readStringUntil('\n');
     if (m!=null)  msg = m;
     print(msg);
   }
 }
```

Serial통신을 통해 Sensing, 즉 아두이노 부분과 데이터를 주고 받을 수 있게 만들어준다. 위 처럼 Processing코드를 통해 연결해준다.

이제 목적은 스마트폰에서 버튼을 눌러 켜고 꺼야하므로 App의 측면에서 Client가 되어 Server와 무선으로 정보를 주고 받을 수 있도록 한다.


![image](https://github.com/naengku3/arduino_test2/assets/127822478/fdffcb65-6dfa-4c3e-b864-73332e5b182f)


위의 이미지처럼 앱인벤터를 사용해서 ON이라고 적힌 버튼1을 클릭하면 무선통신인 WIFE를 통해 "on"이라는 텍스트를 보내고,

버튼2를 클릭하면 마찬가지로 WIFE를 통해 "off"라는 텍스트를 Server측으로 보낸다. 이때 앱인벤터의 Components에 Web을 추가해주고 WIFE IPv4와

포트를 지정해줘서 연결해준다. 그러면 이제 스마트폰 APP을 통해 Client측에서 Server측으로 데이터를 주고 받을 수 있게 되었다.

이제 위를 모두 종합하면 핸드폰 App을 통해 Client 환경에서 무선통신인 WIFE를 통해 Server로 on/off 데이터를 보내고,

Server에서 받아서 Processing 코드로 Serial 통신을 통해 Sensing부분 즉, 아두이노로 데이터를 보내준다.

그리고 그 보내준 데이터를 통해 제어문으로 전등을 끄고 켠다.


3번 문항 ~ 5번 문항 각각 깃헙에 파일을 통해서 코드와 앱인벤터 환경을 스크린샷찍은 것을 제출하였습니다. 감사합니다.


