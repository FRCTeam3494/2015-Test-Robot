#include "WPILib.h"
#include "Can_Stuffs\Can_Data.h"
#include <iostream>

using namespace std;
/**
 * This is a demo program showing how to use Mecanum control with the RobotDrive class.
 */
class Robot: public SampleRobot
{

    // Channels for the wheels
    const static int frontLeftChannel	= 2;							// Default values for each channel
    const static int rearLeftChannel	= 3;
    const static int frontRightChannel	= 1;
    const static int rearRightChannel	= 0;

    const static int joystickChannel	= 0;							// default joystick channel

    double Acc_Y = 0; 													// These are the accelerometer values used in the roboRIO
    double Acc_X = 0; 													//
    double Acc_Z = 0; 													//


    //SmartDashboard* Smart;
    BuiltInAccelerometer* accelerometer_1;

    Can_Data* Can; 														// Can data

    CANTalon Talon_1; 										    		// CAN Talon soon to change

    Encoder* encoder_1; 													// Encoder initiliazed

	RobotDrive* robotDrive;												// robot drive system

	Joystick* stick; 													// only joystick


	double Period_2 = 0; 												// Encoder value puller prototype

public:
	Robot()

							                                            // as they are declared above.
	{
		robotDrive = new RobotDrive(frontLeftChannel, rearLeftChannel,frontRightChannel, rearRightChannel);

		robotDrive->SetExpiration(0.1);



		robotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true); // invert the left side motors

		robotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);  // you may need to change or remove this to match your robot

		Can = new Can_Data;                                             // Initializing Can

		stick = new Joystick(0);											// Initializing joystick

		accelerometer_1 = new BuiltInAccelerometer;						// Initializing accelerometer_1

		encoder_1 = new Encoder;										// Initialize encoder


SmartDashboard::init();                                                 // Initializing Smart Dashboard

		encoder_1(0,1,false, Encoder::k1X),
		encoder_1->SetSamplesToAverage(5); 								 // Encoder settings and parameters
		encoder_1->SetDistancePerPulse(1.00 / 360.0 * 2.0 *3.1415 * 1.5); //
		encoder_1->SetMinRate(1.0); 										 //
		encoder_1->SetReverseDirection(true);							 //
		encoder_1->SetMaxPeriod(1);										 //


	}

	/**
	 * Runs the motors with Mecanum drive.
	 */
	void OperatorControl()
	{


		robotDrive.SetSafetyEnabled(false);
		while (IsOperatorControl() && IsEnabled())
		{

			robotDrive->MecanumDrive_Cartesian(stick.GetX(), stick.GetY(), stick.GetZ()); // subject to change

			Wait(0.005); 																 // wait 5ms to avoid hogging CPU cycles

			Acc_Y = accelerometer_1->GetY();											 // Pulling Accelerometer values
			Acc_X = accelerometer_1->GetX();											 //
			Acc_Z = accelerometer_1->GetZ();											 //


			Period_2 = encoder_1.Get();                                                  // Encoder values are being pulled


			if (stick.GetRawButton(1) == TRUE)     // Take out of if statement next !!!!!!!!!!!!!!!!!!
			{

				SmartDashboard::PutNumber( "Encoder" , Period_2 );						 // Pushing values to smartdashboard
				SmartDashboard::PutNumber( "Accelerometer_Y_Axis" , Acc_Y);				 //



			}
			Can->updateData();
		}



	}

};

START_ROBOT_CLASS(Robot);
