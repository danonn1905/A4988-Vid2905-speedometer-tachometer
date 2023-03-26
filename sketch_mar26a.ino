//   1 July 2022   Rev.1 adds include of Wire.h                -jkl
// Adds support for a4988 driver for VID2905 stepper motor. Provides Tachometer reading.
//   12 November 2022       by jkl
////////////////////////////////////////////////////////////////////////////////////////////
// Скетч для работы на Ардуино Mega2560 PRO mini 
// Либо отдельным пином сигнала от Тахо get OBD data(OBD_RPM) изучаю код написания
// Либо отдельным пином сигнала от SPD  get OBD data(OBD_SPD). изучаю код написания
// Считывается информация с кода данных OBD1 getOBDdata подключение считывания с 
 tachStepper.moveTo((long)(map(getOBDdata(OBD_RPM), 0, MAX_RPM_RANGE, 1, STEPS_PER_REVOLUTION * uSteps * 2)));
(OBD_SPD) 
// При запуске скетча задействовать режим тест стрелок с последуюшем вкл в рабочий режим 


// Установка выводов
const int dirPin = 28;
const int stepPin = 26;
const int en = 30;          // задействовать .
const int stepsperevolution = 300;
const int dirPin1 = 50;
const int stepPin1 = 48;
const int en1 = 47;         // задействовать .
const int stepsperevolution1 = 300;
// подключаем библиотеку
#include <AccelStepper.h>

// модифицирован для шагового двигателя и контроллера тахометра
AccelStepper tachStepper(AccelStepper::DRIVER, stepPin, dirPin); // works for a4988 (Bipolar, constant current, step/direction driver)
const long STEPS_PER_REVOLUTION = 315;     // for the VID2905 stepper
// Set this value based on a4988 configuration.
// 1 = full step, 2 = 1/2 step, 4 = 1/4 step, 8 = 1/8 step
const int uSteps = 2;   // micro step rate
const int MAX_RPM_RANGE = 7000;      // Maximum RPM range to display for your car

// модифицирован для шагового двигателя и контроллера спидометр
AccelStepper spdStepper(AccelStepper::DRIVER, stepPin, dirPin);  // works for a4988 (Bipolar, constant current, step/direction driver)
const long STEPS_PER_REVOLUTION1 = 315;     // for the VID2905 stepper
// Set this value based on a4988 configuration.
// 1 = full step, 2 = 1/2 step, 4 = 1/4 step, 8 = 1/8 step
const int uSteps1 = 2;   // micro step rate
const int MAX_RPM_RANGE1 = 7000;      // Maximum RPM range to display for your car

void setup() {
 
  tachStepper.setMaxSpeed(250 * uSteps);         // these valuses seem to work for VID2905
  tachStepper.setAcceleration(250 * uSteps);
  tachStepper.runToNewPosition(-300 * uSteps);   // move to zero position
  tachStepper.runToNewPosition(10 * uSteps);     // now move needle almost to zero  -- tach is ready to use.
  delay(1000);
 
  spdStepper.setMaxSpeed(250 * uSteps);          // these valuses seem to work for VID2905
  spdStepper.setAcceleration(250 * uSteps);
  spdStepper.runToNewPosition(-300 * uSteps);    // move to zero position
  spdStepper.setCurrentPosition(0);              // set as 0 rpm reference
  spdStepper.runToNewPosition(10 * uSteps);      // now move needle almost to zero  -- tach is ready to use.
  delay(1000);
} // END VOID SETUP.

void loop(void) {

 // код для  tachStepper
 // код для  spdStepper

   }
   tachStepper.run();
   spdStepper.run();
  }
 }
