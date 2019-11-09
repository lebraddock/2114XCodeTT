#include "main.h"
#include "includeStuff.h"
#include "chassisLib.h"
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */


//arrays

double blueRightArray[266] = {0.007985,0.015963,0.035933,0.063882,0.099815,0.143734,0.195638,0.255527,0.323401,0.39926,0.483105,0.574935,0.67475,0.78255,0.898336,1.022106,1.153862,1.293604,1.44133,1.597041,1.760738,1.93242,2.112087,2.29974,2.495377,2.699,2.910608,3.130201,3.35778,3.593343,3.836892,4.088426,4.347945,4.61545,4.890939,5.174414,5.465874,5.765319,6.07275,6.388166,6.711566,7.042953,7.382324,7.72968,8.085022,8.448349,8.819661,9.198958,9.586241,9.981509,10.384762,10.796,11.215223,11.642432,12.077626,12.520805,12.971969,13.431118,13.89426,14.357402,14.820544,15.283686,15.746828,16.20997,16.673112,17.136254,15.383411,13.165168,13.408017,13.642695,13.869012,14.086818,14.296015,14.49657,14.688525,14.869304,15.036564,15.19089,15.333018,15.463849,15.584465,15.69614,15.800352,15.898786,15.993337,16.086102,16.179368,16.27559,16.377361,16.487365,16.608331,16.742972,16.893915,17.06363,17.254356,17.468031,17.706223,17.970078,18.260274,18.577,18.919948,19.288324,19.680878,20.095954,20.531543,20.985356,21.454894,21.937523,22.430549,22.93128,23.437083,23.94544,24.453979,24.96051,25.463039,25.959783,26.449171,26.929843,27.400645,27.860613,28.308965,28.745084,29.168501,29.578883,29.976012,30.359777,30.730156,31.087201,31.431035,31.761831,32.079809,32.385228,32.67797,32.958331,33.227039,33.484435,33.730869,33.966695,34.192268,34.407941,34.614063,34.810973,34.998999,35.178459,35.349653,35.512861,35.668344,35.816337,35.957048,36.09065,36.217285,36.337052,36.450005,36.55615,36.655437,36.747757,36.832934,36.91072,36.980789,37.042733,37.096056,37.140167,37.174381,37.197914,37.209882,37.209302,37.195099,37.166107,37.121082,37.05871,36.977629,36.876441,36.753737,36.608122,36.438238,36.242798,36.020608,35.770601,35.491858,35.183638,34.84539,34.476775,34.077672,33.648183,33.188628,32.699539,32.181642,31.635843,31.0632,30.464897,29.842823,29.20394,28.55465,27.896336,27.230342,26.557957,25.880405,25.198833,24.5143,23.827783,23.140162,22.45223,21.76469,21.078157,20.393165,19.710169,19.02955,18.352209,17.683852,17.02948,16.389145,15.762855,15.150587,14.552285,13.967874,13.397256,12.840319,12.296941,11.76699,11.250327,10.746811,10.256297,9.778642,9.3137,8.861331,8.421395,7.993757,7.578285,7.174852,6.783336,6.40362,6.035592,5.679146,5.334181,5.000601,4.678317,4.367243,4.0673,3.778414,3.500516,3.233541,2.977429,2.732127,2.497581,2.273748,2.060583,1.858049,1.66611,1.484737,1.313899,1.153573,1.003736,0.86437,0.735457,0.616985,0.508939,0.411311,0.324093,0.247277,0.180859,0.124835,0.079202,0.043959,0.019104,0.004637,0};

double blueLeftArray[266] = {0.007985,0.015963,0.035933,0.063882,0.099815,0.143734,0.195638,0.255527,0.323401,0.39926,0.483105,0.574935,0.67475,0.78255,0.898336,1.022106,1.153862,1.293604,1.44133,1.597041,1.760738,1.93242,2.112087,2.29974,2.495377,2.699,2.910608,3.130201,3.35778,3.593343,3.836892,4.088426,4.347945,4.61545,4.890939,5.174414,5.465874,5.765319,6.07275,6.388166,6.711566,7.042953,7.382324,7.72968,8.085022,8.448349,8.819661,9.198958,9.586241,9.981509,10.384762,10.796,11.215223,11.642432,12.077626,12.520805,12.971969,13.431118,13.89426,14.357402,14.820544,15.283686,15.746828,16.20997,16.673112,17.136254,19.710282,22.95976,23.643178,24.334763,25.034709,25.743163,26.460223,27.185923,27.920219,28.657705,29.392736,30.124726,30.852942,31.576482,32.294264,33.005012,33.707251,34.399295,35.07925,35.745019,36.394315,37.024683,37.633534,38.218182,38.775898,39.303973,39.79978,40.26085,40.684943,41.070124,41.414825,41.717902,41.978676,42.196958,42.373057,42.507766,42.602334,42.658419,42.678027,42.663448,42.617178,42.54185,42.44016,42.314797,42.168392,42.003464,41.822382,41.627339,41.420325,41.203125,40.977308,40.744233,40.505056,40.260739,40.012065,39.759651,39.503964,39.245341,38.983996,38.720042,38.453501,38.18432,37.912378,37.6375,37.359468,37.078022,36.792424,36.502378,36.208012,35.908987,35.604951,35.29555,34.98043,34.659238,34.331625,33.997253,33.655791,33.306924,32.950351,32.585792,32.212986,31.831697,31.44172,31.042878,30.635032,30.218083,29.791975,29.356703,28.912317,28.458926,27.996707,27.525907,27.046852,26.55995,26.065699,25.564687,25.057601,24.545226,24.028445,23.50824,22.98569,22.461958,21.93829,21.415999,20.896448,20.381036,19.871172,19.368252,18.873632,18.388602,17.914354,17.451958,17.00233,16.566214,16.144159,15.736504,15.343371,14.964657,14.600043,14.248995,13.910787,13.584514,13.269116,12.963409,12.666361,12.378993,12.102031,11.834094,11.573836,11.319967,11.071264,10.826582,10.584857,10.345116,10.106477,9.868147,9.629425,9.389693,9.14842,8.905149,8.6595,8.411427,8.163211,7.916979,7.67268,7.430304,7.189876,6.951451,6.715106,6.480937,6.249056,6.019586,5.79266,5.568414,5.346993,5.128539,4.913196,4.70111,4.492422,4.28727,4.085791,3.888116,3.694373,3.504682,3.319162,3.137924,2.961075,2.788715,2.62094,2.45784,2.2995,2.145999,1.997411,1.853807,1.715249,1.581798,1.45351,1.330433,1.212616,1.1001,0.992924,0.891122,0.794727,0.703765,0.618263,0.538241,0.46372,0.394715,0.331241,0.27331,0.220932,0.174114,0.132865,0.097188,0.067087,0.042566,0.023626,0.010268,0.002492,0};
/*
double blueRightArray[264] =
{0.007923,0.015807,0.035653,0.063383,0.099036,0.142612,0.194111,0.253533,0.320877,0.396145,0.479335,0.570448,0.669484,0.776444,0.891326,1.01413,1.144858,1.283509,1.430082,1.584579,1.746998,1.91734,2.095605,2.281793,2.475904,2.677938,2.887895,3.105774,3.331577,3.565302,3.80695,4.056521,4.314015,4.579432,4.852772,5.134035,5.423221,5.720329,6.02536,6.338315,6.659192,6.987992,7.324715,7.669361,8.02193,8.382421,8.750836,9.127173,9.511433,9.903617,10.303723,10.711752,11.127704,11.551579,11.983376,12.423097,12.87074,13.322345,13.77395,14.225555,14.67716,15.128765,15.58037,16.031975,16.48358,16.935185,16.057673,12.71994,12.949711,13.1722,13.38736,13.595201,13.795802,13.989321,14.17601,14.35359,14.520022,14.676111,14.822818,14.961259,15.092717,15.218646,15.340669,15.460573,15.580298,15.701919,15.827624,15.95968,16.10039,16.252055,16.416915,16.597096,16.794552,17.011012,17.247919,17.506392,17.787185,18.090661,18.416781,18.765106,19.134811,19.524717,19.933325,20.358872,20.799378,21.252709,21.716631,22.188868,22.667149,23.149259,23.633069,24.116575,24.597915,25.075385,25.547453,26.01276,26.470118,26.918508,27.357069,27.785093,28.202009,28.607375,29.000863,29.382247,29.751394,30.108249,30.452826,30.7852,31.105495,31.413878,31.710552,31.993681,32.263449,32.522158,32.770093,33.007548,33.23482,33.452208,33.660008,33.858511,34.047998,34.228739,34.400992,34.564996,34.72097,34.869111,35.009588,35.142542,35.268079,35.386269,35.497139,35.600671,35.696797,35.785394,35.866276,35.939197,36.00384,36.059812,36.106648,36.143796,36.170627,36.186423,36.190385,36.18163,36.159198,36.122055,36.069103,35.999189,35.911123,35.803688,35.67566,35.525832,35.353031,35.156142,34.934134,34.686081,34.411182,34.108782,33.778391,33.419689,33.032542,32.617002,32.173307,31.701872,31.203283,30.678277,30.12773,29.55263,28.957098,28.347827,27.728512,27.100353,26.464526,25.822168,25.174368,24.522154,23.866487,23.208261,22.548291,21.887321,21.226017,20.564971,19.904706,19.245673,18.588263,17.9328,17.282535,16.643069,16.016942,15.404201,14.80486,14.218902,13.646286,13.086952,12.540821,12.007804,11.487798,10.980695,10.48638,10.004735,9.535639,9.078971,8.634609,8.202434,7.782329,7.374178,6.97787,6.593297,6.220356,5.858947,5.508975,5.170349,4.842983,4.526797,4.221714,3.927662,3.644574,3.372387,3.111042,2.860486,2.620668,2.391543,2.173067,1.965203,1.767917,1.581174,1.40495,1.239216,1.083952,0.939137,0.804754,0.680789,0.567229,0.464063,0.371282,0.28888,0.216851,0.15519,0.103895,0.062963,0.032393,0.012183,0.002334,0};

double blueLeftArray[264] =
{0.007923,0.015807,0.035653,0.063383,0.099036,0.142612,0.194111,0.253533,0.320877,0.396145,0.479335,0.570448,0.669484,0.776444,0.891326,1.01413,1.144858,1.283509,1.430082,1.584579,1.746998,1.91734,2.095605,2.281793,2.475904,2.677938,2.887895,3.105774,3.331577,3.565302,3.80695,4.056521,4.314015,4.579432,4.852772,5.134035,5.423221,5.720329,6.02536,6.338315,6.659192,6.987992,7.324715,7.669361,8.02193,8.382421,8.750836,9.127173,9.511433,9.903617,10.303723,10.711752,11.127704,11.551579,11.983376,12.423097,12.87074,13.322345,13.77395,14.225555,14.67716,15.128765,15.58037,16.031975,16.48358,16.935185,18.617498,22.956689,23.630109,24.310809,24.998836,25.69418,26.396762,27.106424,27.822912,28.540584,29.253557,29.961023,30.662024,31.355443,32.039995,32.71423,33.376523,34.025088,34.657986,35.27314,35.868365,36.441395,36.989925,37.511658,38.004353,38.465885,38.894299,39.287871,39.645155,39.965034,40.246754,40.489952,40.694669,40.861342,40.990795,41.08421,41.143082,41.169176,41.164469,41.131097,41.071291,40.987327,40.881475,40.75595,40.612879,40.454267,40.281975,40.097705,39.902991,39.69919,39.48749,39.268911,39.044311,38.814401,38.579751,38.340802,38.097883,37.851219,37.600944,37.347114,37.089712,36.828666,36.563851,36.2951,36.02221,35.742664,35.456278,35.165105,34.868858,34.567243,34.259963,33.94672,33.627217,33.301165,32.968281,32.628295,32.28095,31.926008,31.563247,31.192473,30.813516,30.426234,30.030521,29.626309,29.21357,28.79232,28.36263,27.924623,27.478483,27.024457,26.562863,26.094091,25.618611,25.136971,24.649802,24.157821,23.661829,23.162707,22.661418,22.158994,21.656535,21.155191,20.656156,20.160646,19.669885,19.18508,18.707406,18.237976,17.777823,17.327872,16.888925,16.461636,16.046497,15.643825,15.253756,14.876238,14.511032,14.157722,13.815724,13.484298,13.162571,12.849551,12.545471,12.25156,11.967694,11.692671,11.425315,11.16449,10.909106,10.658136,10.410616,10.165655,9.922436,9.680217,9.438331,9.196184,8.953256,8.709094,8.463309,8.215574,7.966995,7.71989,7.475291,7.23315,6.993455,6.756222,6.521491,6.289324,6.059799,5.833005,5.609045,5.388028,5.170068,4.955284,4.743796,4.535726,4.331195,4.130322,3.933226,3.74002,3.550817,3.365725,3.184847,3.008283,2.836127,2.668471,2.5054,2.346995,2.193333,2.044486,1.90052,1.7615,1.627482,1.498523,1.37467,1.255971,1.142467,1.034198,0.931198,0.833498,0.741127,0.65411,0.57247,0.496227,0.425397,0.359995,0.300034,0.245525,0.196476,0.152894,0.114785,0.082154,0.055003,0.033334,0.01715,0.00645,0.001236,0};

*/
void followBluePath()
{
  int i = 0;
  int startTime = pros::millis();
  int targetTime = pros::millis() + (266 * 10);
  drive.resetLeftEncoder();
  drive.resetRightEncoder();
  while(pros::millis() < targetTime)
  {
    i = (pros::millis() - startTime) / 10;
    drive.setLeftVelocity(-1 * (blueLeftArray[i] + blueLeftArray[i+1]) / 2);
    drive.setRightVelocity(-1 * (blueRightArray[i] + blueRightArray[i+1]) / 2);
    pros::delay(10);
  }
  drive.stopDriveVelocity();
}
void followRedPath()
{
  int i = 0;
  int startTime = pros::millis();
  int targetTime = pros::millis() + (266 * 10);
  drive.resetLeftEncoder();
  drive.resetRightEncoder();
  while(pros::millis() < targetTime)
  {
    i = (pros::millis() - startTime) / 10;
    drive.setRightVelocity(-1 * (blueLeftArray[i] + blueLeftArray[i+1]) / 2);
    drive.setLeftVelocity(-1 * (blueRightArray[i] + blueRightArray[i+1]) / 2);
    pros::delay(10);
  }
  drive.stopDriveVelocity();
}

void liftHigh()
{
  if(isCube() == true)
    intakeThing();
  lift.move_absolute(highTower, 100);
  liftDown = false;
}

void liftMed()
{
  if(isCube() == true)
    intakeThing();
  lift.move_absolute(lowTower, 100);
  liftDown = false;
}
void liftLow()
{
  while(liftSense.get_value() != 1)
  {
    lift.move(-120);
  }
  lift.move(-10);
  liftDown = true;
  lift.tare_position();
}

 void trayToggle()
 {
   if(tray == true)
   {
     ttarget = finalPos;
     tray = false;
   }
   else
   {
     ttarget = startPos;
     tray = true;
   }
 }

 void trayControl(void * param)
 {
   int terror;
   int ttotalError = 0;
   int tpower;
   int tsign = 1;
   int tlastSign = 1;


   while(true)
   {
   //tilter pi loop
   terror = ttarget - tilter.get_position();
   ttotalError += terror;
   tsign = signchk(terror);
   if(tsign != tlastSign)
     ttotalError = 0;
   tlastSign = tsign;
   tpower = terror * atkp + atki * ttotalError;
   if(terror > 220)
     tpower = 127;
   tilter.move(tpower);
   pros::delay(20);
    }
 }


void setIntake(int v)
{
  intake1.move(v);
  intake2.move(v);
}

void deploy()
{
  setIntake(-127);
  pros::delay(13);
  ttarget = finalPos;
  setIntake(0);

    pros::delay(1700);
    setIntake(30);
    pros::delay(300);
    setIntake(0);
    pros::delay(1000);
  ttarget = startPos;

  pros::delay(170);
}
void deploy2()
{
  setIntake(-127);
  pros::delay(13);
  ttarget = finalPos;
  setIntake(0);

    pros::delay(1700);
  ttarget = startPos;

  pros::delay(170);
}

void redStack()
{
  drive.setLeftDrive(-10);
  drive.setRightDrive(-10);
    liftLow();
  setIntake(-127);
  pros::delay(140);
  setIntake(0);
  pros::delay(300);
  setIntake(127);
  pros::delay(150);
  drive.stopDriveMotors();
  drive.driveForward(43,30,70);
  setIntake(0);
  followRedPath();
  setIntake(127);
  drive.driveForward(38, 35, 60);
  int timeOut = pros::millis() + 700;
  while((isIntake()) && pros::millis() < timeOut)
  {
    pros::delay(20);
  }
  setIntake(0);
  drive.turnRight(149, 25, 18);
  setIntake(-70);
  timeOut = pros::millis() + 700;
  while(!(isIntake()) && pros::millis() < timeOut)
  {
    pros::delay(20);
  }
  setIntake(127);  pros::delay(100);setIntake(0);
  ttarget = midPos;
  setIntake(12);
  drive.driveForward(47, 40, 50);
  drive.setLeftDrive(25);
  drive.setRightDrive(25);
  setIntake(0);
  deploy2();
  setIntake(-90);
  drive.driveBackward(24, 50, 100);
}

void redCollect()
{
  drive.setLeftDrive(-10);
  drive.setRightDrive(-10);
  liftLow();
  setIntake(-127);
  pros::delay(140);
  setIntake(0);
}

void blueStack()
{
  drive.setLeftDrive(-10);
  drive.setRightDrive(-10);
  liftLow();
  setIntake(-127);
  pros::delay(140);
  setIntake(0);
  pros::delay(300);
  setIntake(127);
  pros::delay(150);
  drive.stopDriveMotors();
  drive.driveForward(43,30,70);
  setIntake(0);
  followBluePath();
  setIntake(127);
  drive.driveForward(38, 35, 60);
  int timeOut = pros::millis() + 700;
  while((isIntake()) && pros::millis() < timeOut)
  {
    pros::delay(20);
  }
  setIntake(0);
  drive.turnLeft(149, 25, 18);
  setIntake(-70);
  timeOut = pros::millis() + 700;
  while(!(isIntake()) && pros::millis() < timeOut)
  {
    pros::delay(20);
  }
  setIntake(127);  pros::delay(100);setIntake(0);
  ttarget = midPos;
  setIntake(12);
  drive.driveForward(47, 40, 50);
  drive.setLeftDrive(25);
  drive.setRightDrive(25);
  setIntake(0);
  deploy2();
  setIntake(-90);
  drive.driveBackward(24, 50, 100);

}

void blueCollect()
{
  drive.setLeftDrive(-10);
  drive.setRightDrive(-10);
  liftLow();
  setIntake(-127);
  pros::delay(140);
  setIntake(0);
}

void skills()
{

  drive.setLeftDrive(-10);
  drive.setRightDrive(-10);
    liftLow();
  setIntake(-127);
  pros::delay(140);
  setIntake(0);
  pros::delay(300);
  setIntake(127);
  pros::delay(150);
  drive.stopDriveMotors();
  setIntake(127);
  drive.driveForward(41, 30, 50);
  pros::delay(1000);
  setIntake(0);
  drive.turnRight(23, 25, 40);
  liftMed();
  pros::delay(1200);
  drive.driveForward(9, 10, 20);
  setIntake(-90);
  pros::delay(500);
  setIntake(0);
  drive.driveBackward(10, 25, 50);
  liftLow();
  pros::delay(1000);
  drive.turnLeft(148, 20, 40);
  liftMed();
  pros::delay(1200);
  drive.driveForward(14, 20, 30);
  setIntake(-90);
  pros::delay(500);
  setIntake(0);
  drive.driveBackward(10, 20, 30);
  drive.turnRight(87, 30, 50);
  liftLow();
  drive.driveBackward(45, 35, 50);
  drive.turnRight(42, 25, 35);
  setIntake(127);
  drive.driveForward(36, 35, 50);
  int timeOut = pros::millis() + 700;
  while(isIntake() && pros::millis() < timeOut)
  {
    pros::delay(20);
  }
  setIntake(0);
  drive.turnLeft(145, 25, 18);
  setIntake(-70);
  timeOut = pros::millis() + 700;
  while(!(isIntake()) && pros::millis() < timeOut)
  {
    pros::delay(20);
  }
  setIntake(0);
  drive.driveForward(48, 40, 35);
  drive.setLeftDrive(20);
  drive.setRightDrive(20);
  deploy();

  setIntake(-127);
  drive.driveBackward(20, 50, 100);
  drive.turnLeft(160, 30, 40);
  setIntake(127);
  drive.driveForward(16, 40, 70);
  pros::delay(300);
  drive.driveBackward(6, 13, 20);
  setIntake(0);
  liftHigh();
  drive.driveForward(12, 16, 20);
  setIntake(-127);
  pros::delay(600);
  setIntake(0);
  drive.driveBackward(8, 23, 40);
  liftLow();
  drive.turnLeft(93, 30, 50);
  drive.driveBackward(24, 13, 30);
  drive.stopDriveMotors();

  setIntake(127);
  drive.driveForward(96, 42, 60);
  pros::delay(200);
  setIntake(0);
  drive.turnRight(70, 30, 50);
  liftHigh();
  pros::delay(600);
  drive.driveForward(10, 13, 20);
  setIntake(-127);
  pros::delay(500);
  drive.driveBackward(6, 12, 20);
  setIntake(0);
  drive.turnRight(90, 30, 40);
  liftLow();
  drive.driveBackward(24, 35, 60);
  drive.turnRight(33, 30, 50);
  setIntake(127);
  drive.driveForward(30, 35, 60);
  pros::delay(300);
  setIntake(0);
  drive.driveBackward(30, 35,60);
  drive.turnRight(65, 30, 50);
  liftMed();
  drive.driveForward(13, 13, 20);
  setIntake(-127);
  pros::delay(300);
  drive.driveBackward(13, 23, 50);
  drive.turnRight(70, 20, 30);
  drive.driveForward(16, 20, 30);
  deploy();
  setIntake(-127);
  drive.driveBackward(24, 40, 70);
}




void autonomous()
{
  pros::Task angle (trayControl, (void*)"PROS", TASK_PRIORITY_DEFAULT,
                TASK_STACK_DEPTH_DEFAULT, "Tary");
                drive.resetLeftEncoder();
                drive.resetRightEncoder();

  if(autoNum == 1)
    redStack();
  if(autoNum == 2)
    redCollect();
  if(autoNum == 3)
    blueStack();
  if(autoNum == 4)
    blueCollect();
  if(autoNum == 5)
    skills();



}