import processing.serial.*;
Serial p;
void setup(){
  p = new Serial(this, "COM11", 9600);
}
String m="";
void draw(){
  if(p.available()>0){
    m = p.readStringUntil('\n');
    if(m!=null){
      print(m);
      if(m.indexOf('1')==0) background(0,255,0);
      if(m.indexOf('2')==0) background(0,0,0);
    }
  }
}
