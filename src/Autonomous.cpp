#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"

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