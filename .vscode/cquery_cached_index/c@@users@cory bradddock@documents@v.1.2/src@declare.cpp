#include "main.h"
#include "chassisLib.h"

chassisStandard drive(-6,-7,10,9,3, 4.0768, 9.8634,.429,20,20); //chassisLib declare
pros::Controller master (pros::E_CONTROLLER_MASTER);

pros::Motor intake1(3, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor intake2(4, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor tilter(8, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor lift(1, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::ADIDigitalIn liftSense('a');

pros::ADIAnalogIn lineSense('b');

pros::ADIDigitalIn rightClick('c');
pros::ADIDigitalIn leftClick('d');
pros::ADIAnalogIn intakeSense('h');

int startPos = 1;
int finalPos = 563;

int restPos = 5;
int lowTower = 350;
int highTower = 470;

double tkp = .2;
double tki = .0015;

bool tray = true;
int ttarget = startPos;
 	bool liftDown = true;

  int autoNum = 5;

int signchk(double number)
{
  if(number > 0)
  return 1;
  else
  return -1;
}

bool isCube()
{
  if(lineSense.get_value() < 400)
    return true;
  else
    return false;
}

bool isIntake()
{
  if(intakeSense.get_value() < 2700)
    return true;
  else
    return false;
}
