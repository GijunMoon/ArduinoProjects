//20181110, GijunMoon
//이 주석은 남겨주세요
//피에조 부저와 버튼, 초음파를 이용한 악기만들기 (소형화)

const int buttonPin = 7;    // 버튼을 7번 핀에 연결합니다.
const int piezoPin =  8;      // 부저를 8번 핀에 연결합니다.


int buttonState = 0; // 버튼의 현재 상태를 저장합니다.      

int echoPin = 12; //초음파센서의 핀 번호를 설정합니다.
int trigPin = 13;

float duration;
int amp = 0;

void setup() {
  Serial.begin(9600);

  pinMode(piezoPin, OUTPUT);      // 부저를 출력으로 설정합니다.
 
  pinMode(buttonPin, INPUT);     // 버튼을 입력으로 설정합니다.

  // trig를 출력모드로 설정, echo를 입력모드로 설정
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop(){

   digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  // 초음파를 보낸다. 다 보내면 echo가 HIGH 상태로 대기하게 된다.
  
  duration = pulseIn(echoPin, HIGH); // echoPin 이 HIGH를 유지한 시간을 저장 한다.

 changeNote(duration, amp);
}

//거리에 따라 음 높이를 변화시키는 함수
void changeNote(float time, int amp) {

  if((duration >0) && (duration < 400)) {            //거리가 0이상 400이하면
    for(long i = 0; i < 1000000; i=i+2552) {         //도
    digitalWrite(piezoPin,1);
    delayMicroseconds(amp);
    digitalWrite(piezoPin,0);
    delayMicroseconds(2*1911 - amp);
    }
  } else if(duration < 800 ){                       //거리가 800이하면
    for(long i = 0; i < 1000000; i=i+2552) {        //레
      digitalWrite(piezoPin,1);
      delayMicroseconds(amp);
      digitalWrite(piezoPin,0);
      delayMicroseconds(2*1702 - amp);
     }
  } else if(duration < 1200) {                     //거리가 1200이하면
    for(long i = 0; i < 1000000; i=i+2552) {       //미
      digitalWrite(piezoPin,1);
      delayMicroseconds(amp);
      digitalWrite(piezoPin,0);
      delayMicroseconds(2*1517 - amp);
     }
  } else if (duration < 1600) {                    //거리가 1600이하면
    for(long i = 0; i < 1000000; i=i+2552) {       //파
      digitalWrite(piezoPin,1);
      delayMicroseconds(amp);
      digitalWrite(piezoPin,0);
      delayMicroseconds(2*1431 - amp);
     }
  } else if (duration < 2000) {                    //거리가 2000이하면
    for(long i = 0; i < 1000000; i=i+2552) {       //솔
      digitalWrite(piezoPin,1);
      delayMicroseconds(amp);
      digitalWrite(piezoPin,0);
      delayMicroseconds(2 * 1276 - amp);
     }
  } else if (duration < 2400) {                   //거리가 2400이하면
    for(long i = 0; i < 1000000; i=i+2552) {      //라
      digitalWrite(piezoPin,1);
      delayMicroseconds(amp);
      digitalWrite(piezoPin,0);
      delayMicroseconds(2*1137 - amp);
     }
  } else if (duration < 2800) {                   //거리가 2800이하면
    for(long i = 0; i < 1000000; i=i+2552) {      //시
      digitalWrite(piezoPin,1);
      delayMicroseconds(amp);
      digitalWrite(piezoPin,0);
      delayMicroseconds(2*1012 - amp);
     } 
  } else if (duration < 3200) {                   //거리가 2300이하면
    for(long i = 0; i < 1000000; i=i+2552) {      //도
      digitalWrite(piezoPin,1);
      delayMicroseconds(amp);
      digitalWrite(piezoPin,0);
      delayMicroseconds(2*995 - amp);
     }
  } 
}
