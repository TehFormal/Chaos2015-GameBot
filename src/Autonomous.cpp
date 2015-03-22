#include <cstdint>
#include <cmath>
#include "WPILib.h"
#include "DevBot.h"
#include <iostream>

/*void DevBot::AutonomousInit() {
	robotDrive.SetSafetyEnabled( false );
	Backward( 0.25, 2.5 );

	rightArm.Set( 1 );
	leftArm.Set( 1 );

	Wait( 0.25 );

	rightArm.Set( 0 );
	leftArm.Set( 0 );
}*/

void DevBot::AutonomousInit() {
	rightArm.Set( -1 );
	leftArm.Set( -1 );

	///////////////////////////////////////////////////////////////////////////////

	robotDrive.SetSafetyEnabled( false );

	// Reset the gyro to 0 degrees
	gyro.Reset();

	// Initialize Timer
	Timer timer;
	timer.Reset();
	timer.Start();

	// Move straight, changing angle to adjust for drift
	while ( accelerometer.GetX() > -0.75 || timer.Get() < 2 ) {
		robotDrive.MecanumDrive_Cartesian( 0, -0.20, gyro.GetAngle() * 0.1 );

		// Set real motor values based off of the fake ones
		frontRight.Set(PWMfr.Get());
		frontLeft.Set(PWMfl.Get());
		rearLeft.Set(PWMrl.Get());
		rearRight.Set(PWMrr.Get());

		Wait( 0.005 );
	}

	// Leave everything as we found it
	robotDrive.MecanumDrive_Cartesian( 0, 0, 0 );

	// Set real motor values based off of the fake ones
	frontRight.Set(PWMfr.Get());
	frontLeft.Set(PWMfl.Get());
	rearLeft.Set(PWMrl.Get());
	rearRight.Set(PWMrr.Get());

	timer.Stop();

	/////////////////////////////////////////////////////////////////////////////////////////

	// Leave everything as we found it
	robotDrive.MecanumDrive_Cartesian( 0.1, 0, 0 );

	// Set real motor values based off of the fake ones
	frontRight.Set(PWMfr.Get());
	frontLeft.Set(PWMfl.Get());
	rearLeft.Set(PWMrl.Get());
	rearRight.Set(PWMrr.Get());

	Wait( 0.5 );

	// Leave everything as we found it
	robotDrive.MecanumDrive_Cartesian( 0, 0, 0 );

	// Set real motor values based off of the fake ones
	frontRight.Set(PWMfr.Get());
	frontLeft.Set(PWMfl.Get());
	rearLeft.Set(PWMrl.Get());
	rearRight.Set(PWMrr.Get());

	rightArm.Set( 1 );
	leftArm.Set( 1 );

	Wait( 2 );

	rightArm.Set( 0 );
	leftArm.Set( 0 );

	/////////////////////////////////////////////////////////////////////////////////////////



	robotDrive.SetSafetyEnabled( false );

	// Reset the gyro to 0 degrees
	gyro.Reset();

	// Initialize Timer
	//Timer timer;
	timer.Reset();
	timer.Start();

	/*
	// Move straight, changing angle to adjust for drift
	while ( accelerometer.GetX() < 0.75 || timer.Get() < 2 ) {
		robotDrive.MecanumDrive_Cartesian( 0, 0.25, -gyro.GetAngle() * 0.1 );

		// Set real motor values based off of the fake ones
		frontRight.Set(PWMfr.Get());
		frontLeft.Set(PWMfl.Get());
		rearLeft.Set(PWMrl.Get());
		rearRight.Set(PWMrr.Get());

		Wait( 0.005 );
	}
	*/

	// Leave everything as we found it
	robotDrive.MecanumDrive_Cartesian( 0.25, 0, 0 );

	// Set real motor values based off of the fake ones
	frontRight.Set(PWMfr.Get());
	frontLeft.Set(PWMfl.Get());
	rearLeft.Set(PWMrl.Get());
	rearRight.Set(PWMrr.Get());

	Wait(0.5);

	// Leave everything as we found it
	robotDrive.MecanumDrive_Cartesian( 0, 0, 0 );

	// Set real motor values based off of the fake ones
	frontRight.Set(PWMfr.Get());
	frontLeft.Set(PWMfl.Get());
	rearLeft.Set(PWMrl.Get());
	rearRight.Set(PWMrr.Get());

	timer.Stop();

	///////////////////////////////////////////////////////////////////////////////
}

void DevBot::AutonomousPeriodic() {
	Wait( 0.005 );
}

void DevBot::Turn( float absSpeed, float targetAngle ) {
	float offset;
	float absOffset;
	float speed;

	// Reset the gyro to 0 degrees
	gyro.Reset();
	
	do {
		// Find the offsets for the rest of the math
		offset = gyro.GetAngle() - targetAngle;
		absOffset = std::abs( offset );
		
		// Calculate output speed
		if( offset > 0 )
			speed = absSpeed;
		else
			speed = -1*absSpeed;

		// Turn
		robotDrive.MecanumDrive_Cartesian( 0, 0, speed );

		// Keep CPU from catching fire and network from exploding in a fireball of packets.
		Wait( 0.005 );
	} while( absOffset > 1 ); // Repeat until target is reached.

	// Leave everything as we found it
	robotDrive.MecanumDrive_Cartesian( 0, 0, 0 );
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

	// Initialize Timer
	Timer timer;
	timer.Reset();
	timer.Start();

	// Move straight, changing angle to adjust for drift
	while ( timer.Get() <= Time ) {
		robotDrive.MecanumDrive_Cartesian( 0, Speed, -gyro.GetAngle() * 0.1 );
		Wait( 0.005 );
	}
	
	// Leave everything as we found it
	robotDrive.MecanumDrive_Cartesian( 0, 0, 0 );
	timer.Stop();
}
