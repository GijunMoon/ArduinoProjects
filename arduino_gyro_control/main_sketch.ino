#include <Wire.h>
#include <MPU6050.h>
#include <Servo.h>

MPU6050 mpu;
Servo servoX;
Servo servoY;

int16_t ax, ay, az;
int16_t gx, gy, gz;

// 모터의 최대 및 최소 각도
const int servoX_min_angle = 0; // X축 모터 최소 각도
const int servoX_max_angle = 180; // X축 모터 최대 각도
const int servoY_min_angle = 0; // Y축 모터 최소 각도
const int servoY_max_angle = 180; // Y축 모터 최대 각도

// 자이로센서에서 읽은 각도 값의 범위
const int16_t gyroX_min = -17000; // X축 자이로센서 최소 값
const int16_t gyroX_max = 17000; // X축 자이로센서 최대 값
const int16_t gyroY_min = -17000; // Y축 자이로센서 최소 값
const int16_t gyroY_max = 17000; // Y축 자이로센서 최대 값

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  servoX.attach(8); // X축 모터에 연결된 핀 번호
  servoY.attach(7); // Y축 모터에 연결된 핀 번호
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // X축 모터 제어
  int servoX_angle = map(gx, gyroX_min, gyroX_max, servoX_min_angle, servoX_max_angle);
  servoX.write(constrain(servoX_angle, servoX_min_angle, servoX_max_angle));

  // Y축 모터 제어
  int servoY_angle = map(gy, gyroY_min, gyroY_max, servoY_min_angle, servoY_max_angle);
  servoY.write(constrain(servoY_angle, servoY_min_angle, servoY_max_angle));

  delay(20);
}
