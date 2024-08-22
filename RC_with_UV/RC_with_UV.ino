#include <AFMotor.h>
#define MOTOR1_PIN1 3
#define MOTOR1_PIN2 4
#define MOTOR2_PIN1 5
#define MOTOR2_PIN2 6
#define UV_LED_PIN 7
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
char command; 
void setup() {
  Serial.begin(9600);
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);
  pinMode(UV_LED_PIN, OUTPUT);
  motor1.setSpeed(0);
  motor2.setSpeed(0);
}
void loop() 
  if (Serial.available()) {
    command = Serial.read(); 
    switch (command) {
      case 'F':  
        moveForward();
        break;
      case 'B':  
        moveBackward();
        break;
      case 'L':  
        turnLeft();
        break;
      case 'R':  
        turnRight();
        break;
      case 'S':  
        stop();
        break;
      case 'U': 
        digitalWrite(UV_LED_PIN, HIGH);
        break;
      case 'D':  
        digitalWrite(UV_LED_PIN, LOW);
        break;
      default:
        break;
    }
  }
}
void moveForward() {
  motor1.setSpeed(255);  
  motor2.setSpeed(255);  
  motor1.forward();     
  motor2.forward();     
}
void moveBackward() {
  motor1.setSpeed(255);  
  motor2.setSpeed(255);  
  motor1.backward();    
  motor2.backward();    
}
void turnLeft() {
  motor1.setSpeed(255);  
  motor2.setSpeed(255);  
  motor1.backward();   
  motor2.forward();    
}
void turnRight() {
  motor1.setSpeed(255);  
  motor2.setSpeed(255);  
  motor1.forward();     
  motor2.backward();  
}
void stop() {
  motor1.setSpeed(0);   
  motor2.setSpeed(0);   
}

