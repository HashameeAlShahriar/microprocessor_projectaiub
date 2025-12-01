// A toy car who just avoid the obj.
#include <AFMotor.h>
#include <Servo.h>

// Motors
AF_DCMotor motor1(1);  // M1
AF_DCMotor motor2(2);  // M2
AF_DCMotor motor3(3);  // M3
AF_DCMotor motor4(4);  // M4

// Ultrasonic pins
#define trigPin A0
#define echoPin A1

// Servo motor
Servo myServo;
#define servoPin 9  //D9

void setup() {
  Serial.begin(9600);

  //speeds(0–255)
  motor1.setSpeed(150);  //++100
  motor2.setSpeed(150);
  motor3.setSpeed(150);
  motor4.setSpeed(150);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //servo Motor setup
  myServo.attach(servoPin);
  myServo.write(90);
  delay(500);
  Serial.println("Setup complete. Servo centered.");
}


//sensor
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration *0.034/2;
}
void moveForward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}


void moveBackward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

//turn++speed
void turnLeft() {
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

  delay(1000);

  stopMotors();
  delay(200);

  //Reset
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor3.setSpeed(150);
  motor4.setSpeed(150);
}

void turnRight() {
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  //aditya:bg->a+di+tto;
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

  delay(1000);

  stopMotors();
  delay(200);
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor3.setSpeed(150);
  motor4.setSpeed(150);
}
void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void loop() {
  int distance = getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 20) {
    stopMotors();
    delay(300);

    Serial.println("Obstacle detected. Reversing...");
    moveBackward();
    delay(500);
    stopMotors();
    delay(300);
    myServo.write(0);
    delay(700);
    int leftDist = getDistance();
    Serial.print("Left distance: ");
    Serial.println(leftDist);

    // Scan right
    myServo.write(180);
    delay(700);
    int rightDist = getDistance();
    Serial.print("Right distance: ");
    Serial.println(rightDist);

    //backTocenter
    myServo.write(90);
    delay(500);

    // Decide
    if (leftDist > rightDist) {
      Serial.println("Turning left...");
      turnLeft();
    } else {
      Serial.println("Turning right...");
      turnRight();
    }
  } else {
    moveForward();
  }

  delay(100);  //main loop delay
}
// Must have to install the AFMotor [amk keo ata boleni]


