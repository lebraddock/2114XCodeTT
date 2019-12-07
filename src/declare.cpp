#include "main.h"
#include "chassisLib.h"

chassisStandard drive(-6,-7,10,9,3, 4.0768, 9.8634,.429,20,20); //chassisLib declare
pros::Controller master (pros::E_CONTROLLER_MASTER);

pros::Motor intake1(2, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor intake2(1, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor tilter(8, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor lift(3, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::ADIDigitalIn liftSense('b');

pros::ADIAnalogIn lineSense('a');


pros::ADIAnalogIn intakeSense('d');

pros::ADIUltrasonic leftUltra('e', 'f');
pros::ADIUltrasonic rightUltra('g', 'h');

int startPos = 1;
int finalPos = 560;
int midPos = 340;

int restPos = 5;
int lowTower = 366;
int highTower = 470;

double tkp = .22; //.35;  .22
double atkp = .22;
double tki = .0014; //.0012
double atki = .0014;

bool tray = true;
bool intakeBool = true;
bool trayBool = false;
int trayTime = 0;
int ttarget = startPos;
 	bool liftDown = true;

  int autoNum = 1;

int signchk(double number)
{
  if(number > 0)
  return 1;
  else
  return -1;
}

bool isCube()
{
  if(lineSense.get_value() < 2000)
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
