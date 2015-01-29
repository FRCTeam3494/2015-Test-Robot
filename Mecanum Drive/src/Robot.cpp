#include "WPILib.h"
#include "Can_Stuffs\Can_Data.h"
#include <iostream>

using namespace std;
/**
 */
class Robot: public SampleRobot
{

    // Channels for the wheels
    const static int frontLeftChannel	= 2;
    const static int rearLeftChannel	= 3;
    const static int frontRightChannel	= 1;
    const static int rearRightChannel	= 0;

    const static int joystickChannel	= 0;

    //SmartDashboard* Smart;
    Can_Data* Can;
    Encoder encoder_1;
	RobotDrive robotDrive;	// robot drive system
	Joystick stick; // only joystick
	bool Period = 0;
	DigitalInput encoder_digital;


public:
	Robot() : encoder_1(0,1,false, Encoder::k1X),
			robotDrive(frontLeftChannel, rearLeftChannel,
					   frontRightChannel, rearRightChannel),	// these must be initialized in the same order
			stick(joystickChannel), encoder_digital(1)					// as they are declared above.
	{
		robotDrive.SetExpiration(0.1);
		robotDrive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);	// invert the left side motors
		robotDrive.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);	// you may need to change or remove this to match your robot
		Can = new Can_Data;
SmartDashboard::init();
		encoder_1.SetSamplesToAverage(5);
		encoder_1.SetDistancePerPulse(1.00 / 360.0 * 2.0 *3.1415 * 1.5);
		encoder_1.SetMinRate(1.0);
		encoder_1.SetReverseDirection(true);
		encoder_1.SetMaxPeriod(1);


	}

	/**
	 * Runs the motors with Mecanum drive.
	 */
	void OperatorControl()
	{


		robotDrive.SetSafetyEnabled(false);
		while (IsOperatorControl() && IsEnabled())
		{
        	// Use the joystick X axis for lateral movement, Y axis for forward movement, and Z axis for rotation.
        	// This sample does not use field-oriented drive, so the gyro input is set to zero.
			robotDrive.MecanumDrive_Cartesian(stick.GetX(), stick.GetY(), stick.GetZ());

			Wait(0.005); // wait 5ms to avoid hogging CPU cycles

			Period = encoder_digital.Get();

			if (stick.GetRawButton(1) == TRUE)
						{
				SmartDashboard::PutNumber( "Encoder_?" , Period );
						}
			Can->updateData();
		}



	}

};

START_ROBOT_CLASS(Robot);
