#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"

void DevBot::AutonomousInit() {
	robotDrive.setSafetyEnabled( false );
	Backward( 0.25, 2.5 );
}

void DevBot::AutonomousPeriodic() {
	Wait( 0.005 );
}

void DevBot::Backward( float Speed, float Time ) {
	// Reset the gyro to 0 degrees
	gyro.Reset();

	// Initialize Timer
	Timer timer;
	timer.Reset();
	timer.Start();

	// Move straight, changing angle to adjust for drift
	while ( timer.Get() <= Time ) {
		robotDrive.MecanumDrive_Cartesian( 0, -Speed, gyro.GetAngle() * 0.1 );
		Wait( 0.005 );
	}
	
	// Leave everything as we found it
	robotDrive.MecanumDrive_Cartesian( 0, 0, 0 );
	timer.Stop();
}

void DevBot::Forward( float Speed, float Time ) {
	// Reset the gyro to 0 degrees
	gyro.Reset();

	// Timer Stuff
	Timer timer;
	timer.Reset();
	timer.Start();

	while ( timer.Get() <= Time ) {
		float angle = gyro.GetAngle();
		//cout << "\t" << timer.Get() << "\n";
		robotDrive.Drive( Speed, -angle * 0.03 );
		Wait( 0.005 );
	}
	robotDrive.Drive( 0, 0 );

	timer.Stop();
}
