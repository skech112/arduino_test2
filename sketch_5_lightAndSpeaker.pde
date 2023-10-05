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
