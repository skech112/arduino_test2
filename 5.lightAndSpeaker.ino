void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
}
void loop() {
  
  String values[] = {"1", "2", "3", "4", "5", "6", "7", "8"};

  if (Serial.available() > 0) {
    
    String m = Serial.readStringUntil('\n');
        if (m == "on") {
      digitalWrite(7, HIGH);
    } else if (m == "off") {
      digitalWrite(7, LOW);
    } else {
      int frequency = 0;
      // 문자열을 정수로 변환하여 주파수 설정
      int value = m.toInt();
      switch (value) {
        case 1:
          frequency = 261; // 도
          break;
        case 2:
          frequency = 293; // 레
          break;
        case 3:
          frequency = 329; // 미
          break;
        case 4:
          frequency = 349; // 파
          break;
        case 5:
          frequency = 392; // 솔
          break;
        case 6:
          frequency = 440; // 라
          break;
        case 7:
          frequency = 493; // 시
          break;
        case 8:
          frequency = 523; // 높은 도
          break;
        default:
          // 유효하지 않은 입력 처리
          break;
      }

      if (frequency > 0) {
        tone(4, frequency, 500); // 주파수 설정
      }
    }
  }
}