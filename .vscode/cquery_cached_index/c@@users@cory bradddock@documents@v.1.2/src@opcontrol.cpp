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

	intakeBool = false;
	pros::delay(20);
	intake1.move(-127);
	intake2.move(-127);
	pros::delay(10);
	lift.move(127);
	intake1.move(-127);
	intake2.move(-127);
	pros::delay(180);
	intake1.move(0);
	intake2.move(0);
	intakeBool = true;
}
void trayIntake()
{
	while(pros::millis() < trayTime && master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) != 1)
	{
		float num = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)+master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y)/2;
		intake1.move(num);
		intake2.move(num);pros::delay(20);
	}
}

void intakeControl(void * param)
{
	while(true)
	{
		while(intakeBool == true)
		{
		if(trayBool == true)
			{
				trayIntake();
				trayBool = false;
			}
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
		{
			intake1.move(127);
			intake2.move(127);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
			if(lift.get_position() > 400)
			{
				intake1.move(-80);
				intake2.move(-80);
			}
			else if(lift.get_position() > 100)
			{
				intake1.move(-60);
				intake2.move(-60);
			}

			else{
			intake1.move(-127);
			intake2.move(-127);

		}
		}
		else if(ttarget == startPos && lift.get_position() > 75 && isCube())
		{
			intake1.move(0);
			intake2.move(0);
		}
		else if(ttarget == startPos && lift.get_position() < 75 && isCube())
		{
			intake1.move(10);
			intake2.move(10);
		}
		else
		{
			intake1.move(0);
			intake2.move(0);
		}
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_X))
		{
			int timeOut = pros::millis() + 700;
			intake1.move(-70);
			intake2.move(-70);
		  while(!(isIntake()) && pros::millis() < timeOut)
		  {
		    pros::delay(20);
		  }
			pros::delay(50);
			intake1.move(0);
			intake2.move(0);
		}
		pros::delay(20);
	}
	pros::delay(20);
	}
}
void liftControl (void * param)
{
	bool liftDown = true;

	while(true)
	{

		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
			{
					ttarget = startPos;//tray
					tray = true;
					if(tilter.get_position() > 30)
						pros::delay(500);
					if(isCube() == true  && lift.get_position() < 50)
						intakeThing();
					lift.move_absolute(highTower, 127);
					liftDown = false;
					pros::delay(300);
				}
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT))
				{
					ttarget = startPos;//tray
					tray = true;
					if(tilter.get_position() > 30)
						pros::delay(500);
					if(isCube() == true && lift.get_position() < 50)
						intakeThing();
					lift.move_absolute(lowTower, 127);
					liftDown = false;
					pros::delay(300);
				}
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
			{
				while(liftSense.get_value() != 1)
				{
					lift.move(-127);
				}
				lift.move(0);
				liftDown = true;
				lift.tare_position();
			}

		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && ttarget == startPos)
		{
			ttarget = midPos;//tray

			pros::delay(300);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && ttarget == midPos)
		{
			ttarget = startPos;//tray
			tray = true;
			pros::delay(300);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B) && tray == true)
		{
			intakeBool = false;
			int timeOut = pros::millis() + 700;

		  while(!(isIntake()) && pros::millis() < timeOut)
		  {
				intake1.move(-70);
				intake2.move(-70);
		    pros::delay(20);
		  }
			pros::delay(50);
			intake1.move(0);
			intake2.move(0);
			intakeBool = true;
			ttarget = finalPos;//tray
			tray = false;
			pros::delay(300);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B) && tray == false)
		{
			ttarget = startPos;//tray
			tray = true;
			trayTime = pros::millis() + 3000;
			trayBool = true;
			pros::delay(300);
		}
		if(liftDown == true && lift.get_position() < 15)
		{
			lift.move(-10);
		}
		pros::lcd::print(0, "pos : %f", tilter.get_position());



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

if(autoNum == 5)
{
	while(liftSense.get_value() != 1)
	{
		lift.move(-127);
		pros::delay(20);
	}
	lift.move(0);
	lift.tare_position();
intake1.move(-127);
intake2.move(-127);
pros::delay(140);
intake1.move(0);
intake2.move(0);
pros::delay(100);
intake1.move(127);
intake2.move(127);
pros::delay(300);
int timeOut = pros::millis() + 700;

while(!(isIntake()) && pros::millis() < timeOut)
{
	intake1.move(-70);
	intake2.move(-70);
	pros::delay(20);
}
pros::delay(50);
intake1.move(0);
intake2.move(0);
lift.move_absolute(lowTower, 127);
liftDown = false;
drive.driveForward(18, 40, 70);
intake1.move(-80);
intake2.move(-80);
pros::delay(500);
intake1.move(0);
intake2.move(0);
//drive.driveBackward(16, 40, 70);
drive.setLeftVelocity(-23.8);
drive.setRightVelocity(-27.86);
while(liftSense.get_value() != 1)
{
	lift.move(-127);
	pros::delay(20);
}
lift.move(0);
liftDown = true;
lift.tare_position();
pros::delay(400);
drive.setLeftDrive(0);
drive.setRightDrive(0);



}

	pros::Task task1 (liftControl, (void*)"PROS", TASK_PRIORITY_DEFAULT,
                TASK_STACK_DEPTH_DEFAULT, "Lift and Intake Control");
	pros::Task task2 (intakeControl, (void*)"PROS", TASK_PRIORITY_DEFAULT,
                TASK_STACK_DEPTH_DEFAULT, "Lift and Intake Control");

 //if everthing dies delete this :)

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
		//if(ttotalError > 20000)
		//	ttotalError = 20000;
		tsign = signchk(terror);
		if(tsign != tlastSign)
			ttotalError = 0;
		tlastSign = tsign;
		tpower = terror * tkp + tki * ttotalError;
		if(terror > 220) //320
			tpower = 127;
		if(tpower < -127)
			tpower = -127;
	 if(terror > 80 && ttarget == midPos)
				tpower = 127;
		/*if(tpower > 0 && tpower < 20)
			tpower = 20;
		if(tpower < 0 && tpower > -20)
			tpower = -20;*/
//		if(terror < 10 && terror > -10 && ttarget != startPos)
	//		tpower = 0;
		tilter.move(tpower);
		//tilter pi loop ^^^^


//LIFT//


		pros::delay(20);
	}
}
