#ifndef chassisLib
#define chassisLib
#include "main.h"
#include <vector>

class chassisStandard
{
  private:
    int leftMotor1;
    int leftMotor2;
    int rightMotor1;
    int rightMotor2;
    int gearing;
    double gearRatio;
    double chassisWidth;
    double wheelDiameter;
    double angleTarget;
    double driveTarget;
    double maxVelocity;
    double maxAcceleration;
  public:
  //4 motor drive constructor
  chassisStandard(int l1, int l2, int r1, int r2, int g, double wD, double cW, double gR, double mV, double mA)
  {
    //leftMotor1
    if(l1 < 0)
    {
      leftMotor1 = l1 * -1;
      pros::c::motor_set_reversed(leftMotor1, true);
    }
    else
    {
      leftMotor1 = l1;
      pros::c::motor_set_reversed(leftMotor1, false);
    }
    //leftMotor2
    if(l2 < 0)
    {
      leftMotor2 = l2 * -1;
      pros::c::motor_set_reversed(leftMotor2, true);
    }
    else
    {
      leftMotor2 = l2;
      pros::c::motor_set_reversed(leftMotor2, false);
    }
    //rightMotor1
    if(r1 < 0)
    {
      rightMotor1 = r1 * -1;
      pros::c::motor_set_reversed(rightMotor1, true);
    }
    else
    {
      rightMotor1 = r1;
      pros::c::motor_set_reversed(rightMotor1, false);
    }
    //rightMotor2
    if(r2 < 0)
    {
      rightMotor2 = r2 * -1;
      pros::c::motor_set_reversed(rightMotor2, true);
    }
    else
    {
      rightMotor2 = r2;
      pros::c::motor_set_reversed(rightMotor2, false);
    }


    gearing = g;
    gearRatio = gR;
    wheelDiameter = wD;
    chassisWidth = cW;
    maxVelocity = mV;
    maxAcceleration = mA;
    //gearset 1 = 100rpm
    //gearset 2 = 200rpm
    //gearset 3 = 600rpm
    if(gearing == 1)
    {
    pros::c::motor_set_gearing(leftMotor1, pros::E_MOTOR_GEARSET_36);
    pros::c::motor_set_gearing(leftMotor2, pros::E_MOTOR_GEARSET_36);
    pros::c::motor_set_gearing(rightMotor1, pros::E_MOTOR_GEARSET_36);
    pros::c::motor_set_gearing(rightMotor2, pros::E_MOTOR_GEARSET_36);
    }
    if(gearing == 2)
    {
    pros::c::motor_set_gearing(leftMotor1, pros::E_MOTOR_GEARSET_18);
    pros::c::motor_set_gearing(leftMotor2, pros::E_MOTOR_GEARSET_18);
    pros::c::motor_set_gearing(rightMotor1, pros::E_MOTOR_GEARSET_18);
    pros::c::motor_set_gearing(rightMotor2, pros::E_MOTOR_GEARSET_18);
    }
    if(gearing == 3)
    {
    pros::c::motor_set_gearing(leftMotor1, pros::E_MOTOR_GEARSET_06);
    pros::c::motor_set_gearing(leftMotor2, pros::E_MOTOR_GEARSET_06);
    pros::c::motor_set_gearing(rightMotor1, pros::E_MOTOR_GEARSET_06);
    pros::c::motor_set_gearing(rightMotor2, pros::E_MOTOR_GEARSET_06);
    }
    pros::c::motor_set_encoder_units(leftMotor1, pros::E_MOTOR_ENCODER_DEGREES);
    pros::c::motor_set_encoder_units(leftMotor2, pros::E_MOTOR_ENCODER_DEGREES);
    pros::c::motor_set_encoder_units(rightMotor1, pros::E_MOTOR_ENCODER_DEGREES);
    pros::c::motor_set_encoder_units(rightMotor2, pros::E_MOTOR_ENCODER_DEGREES);
  }






//////////////////////////////////////////////////
//////////////////////////////////////////////////
///////////////Driver Controll////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////

  //tank drive for driver controll
  void tankDrive(int leftPower, int rightPower)
  {
    if(leftPower < 6 && leftPower > -6)
      leftPower = 0;
    if(rightPower < 6 && rightPower > -6)
      rightPower = 0;
    if(leftPower > 100)
      leftPower = 127;
    if(leftPower < -100)
      leftPower = -127;
    if(rightPower > 100)
      rightPower = 127;
    if(rightPower < -100)
      rightPower = -127;
    setLeftDrive(leftPower);
    setRightDrive(rightPower);
  }

  //arcade drive for driver controll
  void arcadeDrive(int y, int x)
  {
    setLeftDrive(y + x);
    setRightDrive(y - x);
  }







  //helper function to check sign
  int checkSign(int num)
  {
    if(num > 0)
      return 1;
    else if(num < 0)
      return -1;
    else
      return 0;
  }



//////////////////////////////////////////////////
//////////////////////////////////////////////////
/////////////Set Functions////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////

  //set drive functions
  void setLeftDrive(int power)
  {
    if(power > 127)
      power = 127;
    if(power < -127)
      power = -127;
    pros::c::motor_move(leftMotor1, power);
    pros::c::motor_move(leftMotor2, power);
  }
  void setRightDrive(int power)
  {
    if(power > 127)
      power = 127;
    if(power < -127)
      power = -127;
    pros::c::motor_move(rightMotor1, power);
    pros::c::motor_move(rightMotor2, power);
  }

  //set linear velocity of drive
  void setLeftVelocity(double inps)
  {
    double rpm = inps / (3.1415 * wheelDiameter) * 60;
    rpm = rpm / gearRatio;
    pros::c::motor_move_velocity(leftMotor1, rpm);
    pros::c::motor_move_velocity(leftMotor2, rpm);
  }
  double getLeftVelocity()
  {
    double rpm = pros::c::motor_get_actual_velocity(leftMotor1) + pros::c::motor_get_actual_velocity(leftMotor2) / 2;
    rpm = rpm * gearRatio;
    return (rpm * 3.1315 * wheelDiameter / ( 60));
  }
  void setRightVelocity(double inps)
  {
    double rpm = inps / (3.1415 * wheelDiameter) * 60;
    rpm = rpm / gearRatio;
    pros::c::motor_move_velocity(rightMotor1, rpm);
    pros::c::motor_move_velocity(rightMotor2, rpm);
  }
  double getRightVelocity()
  {
    double rpm = pros::c::motor_get_actual_velocity(rightMotor1) + pros::c::motor_get_actual_velocity(rightMotor2)/2;
    rpm = rpm * gearRatio;
    return (rpm * 3.1315 * wheelDiameter / ( 60));
  }
  //stahp
  void stopDriveMotors()
  {
    setLeftDrive(0);
    setRightDrive(0);
  }

  void stopDriveVelocity()
  {
    setLeftVelocity(0);
    setRightVelocity(0);
  }

  //get average encoder values
  double getLeftEncoder()
  {
    return (pros::c::motor_get_position(leftMotor1) + pros::c::motor_get_position(leftMotor2)) / 2;
  }
  double getRightEncoder()
  {
    return (pros::c::motor_get_position(rightMotor1) + pros::c::motor_get_position(rightMotor2)) / 2;
  }

  double getLeftInches()
  {
    return getLeftEncoder() / 360 * 3.1415 * wheelDiameter * gearRatio;
  }
  double getRightInches()
  {
    return getRightEncoder() / 360 * 3.1415 * wheelDiameter * gearRatio;
  }
  //reset encoder values
  void resetLeftEncoder()
  {
    pros::c::motor_tare_position(leftMotor1);
    pros::c::motor_tare_position(leftMotor2);
  }
  void resetRightEncoder()
  {
    pros::c::motor_tare_position(rightMotor1);
    pros::c::motor_tare_position(rightMotor2);
  }

  //////////////////////////////////////////////////
  //////////////////////////////////////////////////
  ///////////Standard Drive Functions///////////////
  //////////////////////////////////////////////////
  //////////////////////////////////////////////////

  //10ms loops opopopopop


  double KP = 1.3; //.3
  double kp = 1; //4
  double kd = 1.5; //1.2
  double kv = 2.3; //.4
  double ka = 1.2; //.38
  double lError;
  double lPreviousError;
  double rError;
  double rPreviousError;

  double calculateAccelerationTriangleTime(double velocity, double acceleration)
  {
    return velocity / acceleration;
  }
  double calculateAccelerationTriangleDistance( double velocity, double acceleration)
  {
    return calculateAccelerationTriangleTime(velocity, acceleration) * velocity * .5;
  }



  /////Drive Forward with a motion profile////////




  void driveForward(double inches, double velocity, double acceleration)
  {
    //////////////////Create the motion profile///////////////////////////
    int condition = 0;
    int n = 0;
    if(inches > calculateAccelerationTriangleDistance(velocity, acceleration) * 2) //determain if it is trapezoidal or a triangular profile
      {
    condition = 0;
      }
    else
      condition = 1;

    if(condition == 0) //if trapezoidal
    {
      double boxDistance = inches - (calculateAccelerationTriangleDistance(velocity, acceleration) * 2);
      double boxTime = boxDistance / velocity;
      double accelerationTime = calculateAccelerationTriangleTime(velocity, acceleration);
      n = (int)((accelerationTime * 2 + boxTime) * 100);
    }
    else
    {
      double triangleTarget = inches / 2;
      double triangleTime = sqrt(2 * triangleTarget / acceleration);
      n = (int)(triangleTime * 200);
    }


    double driveArray[n]; //where the path would be stored
    double positionArray[n];
    double accelerationArray[n];
    int totalPosition = 0;

    if(condition == 0) //create trapezoidal path
    {
      double boxDistance = inches - (calculateAccelerationTriangleDistance(velocity, acceleration) * 2);
      int boxTime = (int)((boxDistance / velocity) * 100);
      int accelerationTime = (int)(calculateAccelerationTriangleTime(velocity, acceleration) * 100);
      for(int i = 0; i < accelerationTime; i++)
      {
        driveArray[i] = (i /100.0) * acceleration;
        totalPosition = totalPosition + driveArray[i] * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = acceleration;
      }
      for(int i = (int)accelerationTime; i < accelerationTime + boxTime; i++)
      {
        driveArray[i] = velocity;
        totalPosition = velocity * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = 0;
      }
      double count = .01;
      for(int i = accelerationTime + boxTime; i < n; i++)
      {
        driveArray[i] = velocity - (count * acceleration);
        count = count + .01;
        totalPosition = totalPosition + driveArray[i] * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = -1 * acceleration;
      }
    }
    else // create triangular path
    {
      double triangleTarget = inches / 2;
      int triangleTime = (int)(sqrt(2 * triangleTarget / acceleration) * 100);
      for(int i = 0; i < n / 2; i++)
      {
        driveArray[i] = (i /100.0) * acceleration;
        totalPosition = totalPosition + driveArray[i] * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = acceleration;
      }

      for(int i = n/2; i < n; i++)
      {
        driveArray[i] = driveArray[i - 1] - acceleration * (1.0/100);
        totalPosition = totalPosition + driveArray[i] * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = -1 * acceleration;
      }
    }

    ////////////Follow Motion Path///////////////

    double degrees = inches * 360 / (3.1415 * wheelDiameter * gearRatio);
    int i = 0;
    int startTime = pros::millis();
    int targetTime = pros::millis() + (n * 10);
    resetLeftEncoder();
    resetRightEncoder();
    double lPower;
    double rPower;
    lPreviousError = degrees;
    rPreviousError = degrees;
    while(pros::millis() < targetTime)
    {
      i = (pros::millis() - startTime) / 10;
      lError = positionArray[i] - getLeftInches();
      rError = positionArray[i] - getRightInches();
      lPower = driveArray[i+1];
      rPower = driveArray[i+1];
      setLeftVelocity(lPower);
      setRightVelocity(rPower);
      pros::delay(10);
    }
    while(pros::millis() < targetTime + 350)
    {
      lError = inches - getLeftInches();
      rError = inches - getRightInches();
      lPower = lError * KP;
      rPower = rError * KP;
      setLeftVelocity(lPower);
      setRightVelocity(rPower);
      pros::delay(10);
    }
    stopDriveVelocity();
  }


  void driveBackward(double inches, double velocity, double acceleration)
  {
    //////////////////Create the motion profile///////////////////////////
    int condition = 0;
    int n = 0;
    if(inches > calculateAccelerationTriangleDistance(velocity, acceleration) * 2) //determain if it is trapezoidal or a triangular profile
      {
    condition = 0;
      }
    else
      condition = 1;

    if(condition == 0) //if trapezoidal
    {
      double boxDistance = inches - (calculateAccelerationTriangleDistance(velocity, acceleration) * 2);
      double boxTime = boxDistance / velocity;
      double accelerationTime = calculateAccelerationTriangleTime(velocity, acceleration);
      n = (int)((accelerationTime * 2 + boxTime) * 100);
    }
    else
    {
      double triangleTarget = inches / 2;
      double triangleTime = sqrt(2 * triangleTarget / acceleration);
      n = (int)(triangleTime * 200);
    }


    double driveArray[n]; //where the path would be stored
    double positionArray[n];
    double accelerationArray[n];
    int totalPosition = 0;

    if(condition == 0) //create trapezoidal path
    {
      double boxDistance = inches - (calculateAccelerationTriangleDistance(velocity, acceleration) * 2);
      int boxTime = (int)((boxDistance / velocity) * 100);
      int accelerationTime = (int)(calculateAccelerationTriangleTime(velocity, acceleration) * 100);
      for(int i = 0; i < accelerationTime; i++)
      {
        driveArray[i] = (i /100.0) * acceleration;
        totalPosition = totalPosition + driveArray[i] * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = acceleration;
      }
      for(int i = (int)accelerationTime; i < accelerationTime + boxTime; i++)
      {
        driveArray[i] = velocity;
        totalPosition = velocity * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = 0;
      }
      double count = .01;
      for(int i = accelerationTime + boxTime; i < n; i++)
      {
        driveArray[i] = velocity - (count * acceleration);
        count = count + .01;
        totalPosition = totalPosition + driveArray[i] * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = -1 * acceleration;
      }
    }
    else // create triangular path
    {
      double triangleTarget = inches / 2;
      int triangleTime = (int)(sqrt(2 * triangleTarget / acceleration) * 100);
      for(int i = 0; i < n / 2; i++)
      {
        driveArray[i] = (i /100.0) * acceleration;
        totalPosition = totalPosition + driveArray[i] * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = acceleration;
      }

      for(int i = n/2; i < n; i++)
      {
        driveArray[i] = driveArray[i - 1] - acceleration * (1.0/100);
        totalPosition = totalPosition + driveArray[i] * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = -1 * acceleration;
      }
    }

    ////////////Follow Motion Path///////////////

    double degrees = inches * 360 / (3.1415 * wheelDiameter * gearRatio);
    int i = 0;
    int startTime = pros::millis();
    int targetTime = pros::millis() + (n * 10);
    inches = inches * -1;
    resetLeftEncoder();
    resetRightEncoder();
    double lPower;
    double rPower;
    lPreviousError = degrees;
    rPreviousError = degrees;
    while(pros::millis() < targetTime)
    {
      i = (pros::millis() - startTime) / 10;
      lError = positionArray[i] * -1 - getLeftInches();
      rError = positionArray[i] * -1  - getRightInches();
      lPower = driveArray[i + 1] * -1;
      rPower = driveArray[i + 1] * -1;
      setLeftVelocity(lPower);
      setRightVelocity(rPower);
      pros::delay(10);
    }
    while(pros::millis() < targetTime + 350)
    {
      lError = inches - getLeftInches();
      rError = inches - getRightInches();
      lPower = lError * KP * -1;
      rPower = rError * KP * -1;
      setLeftVelocity(lPower);
      setRightVelocity(rPower);
      pros::delay(10);
    }
    stopDriveVelocity();
  }


  void turnLeft(double angle, double velocity, double acceleration)
  {
    //////////////////Create the motion profile///////////////////////////
    int condition = 0;
    int n = 0;

    double inches = (angle * 3.1415 * chassisWidth)/360;


    //////////////////Create the motion profile///////////////////////////

    if(inches > calculateAccelerationTriangleDistance(velocity, acceleration) * 2) //determain if it is trapezoidal or a triangular profile
      {
    condition = 0;
      }
    else
      condition = 1;

    if(condition == 0) //if trapezoidal
    {
      double boxDistance = inches - (calculateAccelerationTriangleDistance(velocity, acceleration) * 2);
      double boxTime = boxDistance / velocity;
      double accelerationTime = calculateAccelerationTriangleTime(velocity, acceleration);
      n = (int)((accelerationTime * 2 + boxTime) * 100);
    }
    else
    {
      double triangleTarget = inches / 2;
      double triangleTime = sqrt(2 * triangleTarget / acceleration);
      n = (int)(triangleTime * 200);
    }


    double driveArray[n]; //where the path would be stored
    double positionArray[n];
    double accelerationArray[n];
    int totalPosition = 0;

    if(condition == 0) //create trapezoidal path
    {
      double boxDistance = inches - (calculateAccelerationTriangleDistance(velocity, acceleration) * 2);
      int boxTime = (int)((boxDistance / velocity) * 100);
      int accelerationTime = (int)(calculateAccelerationTriangleTime(velocity, acceleration) * 100);
      for(int i = 0; i < accelerationTime; i++)
      {
        driveArray[i] = (i /100.0) * acceleration;
        totalPosition = totalPosition + driveArray[i] * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = acceleration;
      }
      for(int i = (int)accelerationTime; i < accelerationTime + boxTime; i++)
      {
        driveArray[i] = velocity;
        totalPosition = velocity * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = 0;
      }
      double count = .01;
      for(int i = accelerationTime + boxTime; i < n; i++)
      {
        driveArray[i] = velocity - (count * acceleration);
        count = count + .01;
        totalPosition = totalPosition + driveArray[i] * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = -1 * acceleration;
      }
    }
    else // create triangular path
    {
      double triangleTarget = inches / 2;
      int triangleTime = (int)(sqrt(2 * triangleTarget / acceleration) * 100);
      for(int i = 0; i < n / 2; i++)
      {
        driveArray[i] = (i /100.0) * acceleration;
        totalPosition = totalPosition + driveArray[i] * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = acceleration;
      }

      for(int i = n/2; i < n; i++)
      {
        driveArray[i] = driveArray[i - 1] - acceleration * (1.0/100);
        totalPosition = totalPosition + driveArray[i] * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = -1 * acceleration;
      }
    }

    ////////////Follow Motion Path///////////////

    double degrees = inches * 360 / (3.1415 * wheelDiameter * gearRatio);
    int i = 0;
    int startTime = pros::millis();
    int targetTime = pros::millis() + (n * 10);
    resetLeftEncoder();
    resetRightEncoder();
    double lPower;
    double rPower;
    lPreviousError = degrees;
    rPreviousError = degrees;
    while(pros::millis() < targetTime)
    {
      i = (pros::millis() - startTime) / 10;
      lError = positionArray[i]* -1 - getLeftInches();
      rError = positionArray[i] - getRightInches();
      lPower = driveArray[i + 1]* -1;
      rPower = driveArray[i + 1];
      setLeftVelocity(lPower);
      setRightVelocity(rPower);
      pros::delay(10);
    }
    while(pros::millis() < targetTime + 350)
    {
      lError = inches* -1 - getLeftInches();
      rError = inches - getRightInches();
      lPower = lError * KP;
      rPower = rError * KP;
      setLeftVelocity(lPower);
      setRightVelocity(rPower);
      pros::delay(10);
    }
    stopDriveVelocity();
  }







  void turnRight(double angle, double velocity, double acceleration)
  {
    //////////////////Create the motion profile///////////////////////////
    int condition = 0;
    int n = 0;

    double inches = (angle * 3.1415 * chassisWidth)/360;


    //////////////////Create the motion profile///////////////////////////

    if(inches > calculateAccelerationTriangleDistance(velocity, acceleration) * 2) //determain if it is trapezoidal or a triangular profile
      {
    condition = 0;
      }
    else
      condition = 1;

    if(condition == 0) //if trapezoidal
    {
      double boxDistance = inches - (calculateAccelerationTriangleDistance(velocity, acceleration) * 2);
      double boxTime = boxDistance / velocity;
      double accelerationTime = calculateAccelerationTriangleTime(velocity, acceleration);
      n = (int)((accelerationTime * 2 + boxTime) * 100);
    }
    else
    {
      double triangleTarget = inches / 2;
      double triangleTime = sqrt(2 * triangleTarget / acceleration);
      n = (int)(triangleTime * 200);
    }


    double driveArray[n]; //where the path would be stored
    double positionArray[n];
    double accelerationArray[n];
    int totalPosition = 0;

    if(condition == 0) //create trapezoidal path
    {
      double boxDistance = inches - (calculateAccelerationTriangleDistance(velocity, acceleration) * 2);
      int boxTime = (int)((boxDistance / velocity) * 100);
      int accelerationTime = (int)(calculateAccelerationTriangleTime(velocity, acceleration) * 100);
      for(int i = 0; i < accelerationTime; i++)
      {
        driveArray[i] = (i /100.0) * acceleration;
        totalPosition = totalPosition + driveArray[i] * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = acceleration;
      }
      for(int i = (int)accelerationTime; i < accelerationTime + boxTime; i++)
      {
        driveArray[i] = velocity;
        totalPosition = velocity * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = 0;
      }
      double count = .01;
      for(int i = accelerationTime + boxTime; i < n; i++)
      {
        driveArray[i] = velocity - (count * acceleration);
        count = count + .01;
        totalPosition = totalPosition + driveArray[i] * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = -1 * acceleration;
      }
    }
    else // create triangular path
    {
      double triangleTarget = inches / 2;
      int triangleTime = (int)(sqrt(2 * triangleTarget / acceleration) * 100);
      for(int i = 0; i < n / 2; i++)
      {
        driveArray[i] = (i /100.0) * acceleration;
        totalPosition = totalPosition + driveArray[i] * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = acceleration;
      }

      for(int i = n/2; i < n; i++)
      {
        driveArray[i] = driveArray[i - 1] - acceleration * (1.0/100);
        totalPosition = totalPosition + driveArray[i] * .01;
        positionArray[i] = totalPosition;
        accelerationArray[i] = -1 * acceleration;
      }
    }

    ////////////Follow Motion Path///////////////

    double degrees = inches * 360 / (3.1415 * wheelDiameter * gearRatio);
    int i = 0;
    int startTime = pros::millis();
    int targetTime = pros::millis() + (n * 10);
    resetLeftEncoder();
    resetRightEncoder();
    double lPower;
    double rPower;
    lPreviousError = degrees;
    rPreviousError = degrees;
    while(pros::millis() < targetTime)
    {
      i = (pros::millis() - startTime) / 10;
      lError = positionArray[i] - getLeftInches();
      rError = positionArray[i]* -1 - getRightInches();
      lPower = driveArray[i + 1];
      rPower = driveArray[i + 1]* -1;
      setLeftVelocity(lPower);
      setRightVelocity(rPower);
      pros::delay(10);
    }
    while(pros::millis() < targetTime + 350)
    {
      lError = inches - getLeftInches();
      rError = inches* -1 - getRightInches();
      lPower = lError * KP;
      rPower = rError * KP;
      setLeftVelocity(lPower);
      setRightVelocity(rPower);
      pros::delay(10);
    }
    stopDriveVelocity();
  }


float calculateVelAcc()
{
  pros::lcd::clear();
  int dVel;
  float velocity = getLeftVelocity() + getRightVelocity()/2;
  int lastVelocity = velocity;
  int count = 0;
  int startTime = pros::millis();
  while(count < 20)
  {
    setLeftDrive(127);
    setRightDrive(127);

    velocity = getLeftVelocity() + getRightVelocity()/2;
    dVel = velocity - lastVelocity;
    if(dVel < .5)
      count++;
    lastVelocity = velocity;
    pros::delay(10);
  }
  float acceleration = velocity / (pros::millis() - startTime) * 1000;
  stopDriveMotors();
  pros::lcd::print(2, "Vel : %f Acc: %f", velocity, acceleration);
  pros::delay(2000);
}

};
#endif
