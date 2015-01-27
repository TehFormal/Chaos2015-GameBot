#ifndef SRC_DEVBOT_H_
#define SRC_DEVBOT_H_

// Wheel Motor IDs
#define	frontLeft	1
#define	rearLeft	2
#define	frontRight	0
#define	rearRight	3

// Joystick IDs
#define	joystickChannel	0

// Main Robot Class
class DevBot: public IterativeRobot
{
private:	
	RobotDrive robotDrive;	// robot drive system
	Joystick stick;		// only joystick
	
public:
	// Constructor Method
	DevBot();

	// Various Iterators
	//void RobotInit();
	//void AutonomousInit();
	//void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
};

#endif /* SRC_DEVBOT_H_ */
