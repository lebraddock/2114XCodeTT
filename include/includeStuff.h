#ifndef includeStuff
#define includeStuff
#include "main.h"
#include "chassisLib.h"

extern chassisStandard drive;
extern pros::Controller master;
extern pros::Motor intake1;
extern pros::Motor intake2;
extern pros::Motor tilter;
extern pros::Motor lift;
extern pros::ADIDigitalIn liftSense;
extern pros::ADIDigitalIn lineSense;
extern pros::ADIDigitalIn rightClick;
extern pros::ADIDigitalIn leftClick;
extern pros::ADIDigitalIn intakeSense;

extern double tkp;
extern double tki;

extern int startPos;
extern int finalPos;
extern int restPos;
extern int lowTower;
extern int highTower;
extern int signchk(double num);
extern bool isCube();
extern bool isIntake();
extern int autoNum;

extern bool tray;
extern int ttarget;
extern bool liftDown;
extern void intakeThing();
#endif
