#include "main.h"
#include "includeStuff.h"

void printScreen(int num)
{
if(num == 1)
{
pros::lcd::print(0, "RED");
pros::lcd::print(1, "Big Stack");
pros::lcd::print(2, "Stack 8");
}
if(num == 2)
{
pros::lcd::print(0, "RED");
pros::lcd::print(1, "Collect");
pros::lcd::print(2, "Collect no score");
}
if(num == 3)
{
pros::lcd::print(0, "BLUE");
pros::lcd::print(1, "Big Stack");
pros::lcd::print(2, "Stack 8");
}
if(num == 4)
{
pros::lcd::print(0, "BLUE");
pros::lcd::print(1, "Collect");
pros::lcd::print(2, "Collect no score");
}
if(num == 5)
{
pros::lcd::print(0, "SKILLS");
pros::lcd::print(1, "SKILLS");
pros::lcd::print(2, "SKILLS");
}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	tilter.tare_position();
	lift.tare_position();
	lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	pros::lcd::initialize();

	intake1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
intake2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);



}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
		bool lcdBool = true;
	while(lcdBool)
	{

while(lcdBool)
{
if(pros::lcd::read_buttons() == LCD_BTN_RIGHT || rightClick.get_value() == 1)
{
	if(autoNum == 5)
	autoNum = 1;
	else
	autoNum++;
	pros::delay(300);
}
if(pros::lcd::read_buttons() == LCD_BTN_LEFT || leftClick.get_value() == 1)
{
	if(autoNum == 1)
	autoNum = 5;
	else
	autoNum--;
	pros::delay(300);
}
if(pros::lcd::read_buttons() == LCD_BTN_CENTER)
{
	lcdBool = false;
	pros::delay(300);
}
 printScreen(autoNum);
pros::delay(20);
}
pros::lcd::print(5, "////////////////////////");
pros::lcd::print(6, "//AUTONOMOUS SELECTED!//");
pros::lcd::print(7, "////////////////////////");
	}
}
