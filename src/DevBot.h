#ifndef SRC_DEVBOT_H_
#define SRC_DEVBOT_H_

#include <cstdint>
#include "WPILib.h"

// Wheel Motor IDs
#define	frontLeft	0
#define	frontRight	1
#define	rearLeft	2
#define	rearRight	3

// Joystick IDs
#define	joystickChannel	0

// Main Robot Class
class DevBot: public IterativeRobot
{
private:	
	RobotDrive robotDrive;	// robot drive system
	Joystick stick;		// only joystick
	Gyro gyro;
	Compressor compressor;
	
	// Solenoids
	Solenoid solenoid0;
	Solenoid solenoid1;
	Solenoid solenoid2;
	Solenoid solenoid3;
	Solenoid solenoid4;
	Solenoid solenoid5;
	Solenoid solenoid6;
	Solenoid solenoid7;

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
