#ifndef SRC_DEVBOT_H_
#define SRC_DEVBOT_H_

#include <cstdint>
#include "WPILib.h"

// Wheel Motor IDs
#define	rearRight	0
#define	frontRight	1
#define	frontLeft	2
#define	rearLeft	3

// Joystick IDs
#define	joystickChannel	0

// Main Robot Class
class DevBot: public IterativeRobot
{
private:	
	RobotDrive robotDrive;	// robot drive system
	Joystick driver;		// only joystick
	Gyro gyro;
	Compressor compressor;
public:
	// Constructor Method
	DevBot();

	// Various Iterators
	//void RobotInit();
	//void AutonomousInit();
	//void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	
	// Various Helper Functions
	void Forward( float Speed, float Time );
};

#endif /* SRC_DEVBOT_H_ */
