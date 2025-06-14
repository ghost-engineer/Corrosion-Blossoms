#include <Servo.h>
#include <math.h>

// Servo pins
#define SERVO_X_PIN 9
#define SERVO_Y_PIN 10

Servo servoX;
Servo servoY;

// Spiral parameters
const int steps = 200; // Number of points
const float scale = 2.0; // Spiral scale
const float angleStep = 0.15; // Angle step

// Servo range (adjust for your mechanics)
const int servoMin = 20;
const int servoMax = 160;

// Map coordinates to servo angle
int mapToServo(float val, float minVal, float maxVal) {
  return map((int)val, (int)minVal, (int)maxVal, servoMin, servoMax);
}

void setup() {
  servoX.attach(SERVO_X_PIN);
  servoY.attach(SERVO_Y_PIN);
  delay(1000); // Give servos time to initialize
}

void loop() {
  float x0 = 0, y0 = 0;
  for (int i = 0; i < steps; i++) {
    // Fibonacci spiral formula
    float angle = i * angleStep;
    float radius = scale * sqrt(i);
    float x = radius * cos(angle);
    float y = radius * sin(angle);

    // Map coordinates to servo range
    int servoXpos = mapToServo(x + 50, 0, 100); // 0..100 — X range
    int servoYpos = mapToServo(y + 50, 0, 100); // 0..100 — Y range

    servoX.write(servoXpos);
    servoY.write(servoYpos);
    delay(100); // Delay for smoothness
  }
  delay(5000); // Pause before repeating
}
