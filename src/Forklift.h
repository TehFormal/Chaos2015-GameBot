#ifndef SRC_FORKLIFT_H_
#define SRC_FORKLIFT_H_

#include "WPILib.h"

class Forklift {

private:
	CANTalon forkliftMotor;

public:
	// Constructors
	Forklift( int talon_id );

	// Member Methods
	void Set( float speed );

};

#endif /* SRC_FORKLIFT_H_ */
