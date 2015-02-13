#ifndef SRC_DEVBOT_H_
#define SRC_DEVBOT_H_

#include <cstdint>
#include "WPILib.h"
#include "LimitedForklift.h"
#include "Arm.h"

// Wheel Motor IDs
#define	rearRight	0
#define	frontRight	1
#define	frontLeft	2
#define	rearLeft	3

// Main Robot Class
class DevBot: public IterativeRobot
{
private:	
	RobotDrive robotDrive;	// robot drive system
	Joystick driver;
	Joystick copilot;
	Gyro gyro;
	Compressor compressor;
	LimitedForklift forklift;
	DoubleSolenoid grabber;
	Arm rightArm;
	Arm leftArm;
public:
	// Constructor Method
	DevBot();

	// Various Iterators
	//void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	
	// Various Helper Functions
	void Forward( float Speed, float Time );
	void Backward( float Speed, float Time );
	void Turn( float absSpeed, float targetAngle );
};

#endif /* SRC_DEVBOT_H_ */
