#include "main.h"
#include "includeStuff.h"
#include "chassisLib.h"
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
*/

void intakeThing()
{
	intake1.move(127);
	intake2.move(127);
	pros::delay(250);
	lift.move(127);
	pros::delay(55);
	intake1.move(-127);
	intake2.move(-127);
	pros::delay(240);
	intake1.move(0);
	intake2.move(0);
}
void liftControl (void * param)
{
	bool liftDown = true;

	while(true)
	{
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
    {
      intake1.move(127);
      intake2.move(127);
    }
    else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
    {
			if(lift.get_position() > 100)
			{
				intake1.move(-80);
				intake2.move(-80);
			}
			else{
      intake1.move(-127);
      intake2.move(-127);
			}
    }
    else
    {
      intake1.move(0);
      intake2.move(0);
    }
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
			{
					if(isCube() == true)
						intakeThing();
					lift.move_absolute(highTower, 100);
					liftDown = false;
					pros::delay(300);
				}
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT))
				{
					if(isCube() == true)
						intakeThing();
					lift.move_absolute(lowTower, 100);
					liftDown = false;
					pros::delay(300);
				}
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
			{
				while(liftSense.get_value() != 1)
				{
					lift.move(-120);
				}
				lift.move(0);
				liftDown = true;
				lift.tare_position();
			}
		if(liftDown == true && lift.get_position() < 15)
		{
			lift.move(-10);
		}
		pros::lcd::print(0, "pos : %d", lineSense.get_value());


		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B) && tray == true)
		{
			ttarget = finalPos;//tray
			tray = false;
			pros::delay(300);
		}
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B) && tray == false)
		{
			ttarget = startPos;//tray
			tray = true;
			pros::delay(300);
		}
		pros::delay(20);
	}

}

void setIntakeIPS(int velocity)
{
	float rpm = velocity * (3.1415 * 1.25 * 1.25);
	intake1.move_velocity(rpm);
	intake2.move_velocity(rpm);
}


void opcontrol() {

int terror;
int ttotalError = 0;
int tpower;
int tsign = 1;
int tlastSign = 1;

drive.resetLeftEncoder();
drive.resetRightEncoder();

	pros::Task task1 (liftControl, (void*)"PROS", TASK_PRIORITY_DEFAULT,
                TASK_STACK_DEPTH_DEFAULT, "Lift and Intake Control");
	while (true) {
		pros::lcd::print(1, "test %f", .2);
		drive.tankDrive(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
		pros::lcd::print(2, "lpos : %f", drive.getLeftEncoder());
    pros::lcd::print(3, "rpos : %f", drive.getRightEncoder());

		int avgDrive = drive.getLeftVelocity();

//TRAY// ur mom is a tray hahahahahahahaha


		//tilter pi loop
		terror = ttarget - tilter.get_position();
		ttotalError += terror;
		tsign = signchk(terror);
		if(tsign != tlastSign)
			ttotalError = 0;
		tlastSign = tsign;
		tpower = terror * tkp + tki * ttotalError;
		if(terror > 320)
			tpower = 127;
		tilter.move(tpower);
		//tilter pi loop ^^^^


//LIFT//


		pros::delay(20);
	}
}
