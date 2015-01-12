#include "WPILib.h"

#define	frontLeft	1
#define	rearLeft	2
#define	frontRight	0
#define	rearRight	3

#define	joystickChannel	0

class Robot: public IterativeRobot
{
private:	
	RobotDrive robotDrive;	// robot drive system
	Joystick stick;			// only joystick
	
public:
	// Constructor Method
	Robot():
		robotDrive(frontLeft, rearLeft, frontRight, rearRight),	// Must be initialized in the proper order
		stick(joystickChannel)
	{
		
	}

	// Various Iterators
	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};

START_ROBOT_CLASS(Robot);
