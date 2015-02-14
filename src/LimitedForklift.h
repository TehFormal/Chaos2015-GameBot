#ifndef SRC_LIMITEDFORKLIFT_H_
#define SRC_LIMITEDFORKLIFT_H_

class LimitedForklift {

private:
	CANTalon forkliftMotor;

	// Limit Switches
	DigitalInput topLS;
	DigitalInput bottomLS;

public:
	// Constructors
	LimitedForklift( int talon_id, int bottomLS_port, int topLS_port );

	// Member Methods
	void Set( float speed );

};

#endif /* SRC_LIMITEDFORKLIFT_H_ */
