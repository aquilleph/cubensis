//
// Created by Aquilla Sherrock on 5/28/15.
//

#ifndef CUBENSIS_MOTOR_H
#define CUBENSIS_MOTOR_H

#include "../lib/hardware/arduino/avr/variants/standard/pins_arduino.h"
#include "util.h"
#include "itvec.h"
#include "Servo.h"

#define MOTOR1_PIN 3
#define MOTOR2_PIN 5
#define MOTOR3_PIN 6
#define MOTOR4_PIN 9

#define THROTTLE_PIN A3
#define THROTTLE_MIN 10
#define THROTTLE_MAX 125
#define THROTTLE_KILL 10
#define MOTOR_START_THROTTLE1 10
#define MOTOR_START_THROTTLE2 20



class Motor
{
public:
    Motor(uint8_t pin);
    void init();
    int set();
    int set(int);
    int getThrottle();
    void kill(bool=true);
    static int getThrottlePinValue();

private:
    Servo servo;
    uint8_t servoPin;
    int throttle;
    static int throttlePinValue;
    static bool killed;

    bool is_kill;
};


#endif //CUBENSIS_MOTOR_H
