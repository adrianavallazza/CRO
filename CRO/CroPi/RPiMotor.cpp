#include "RPiMotor.h"
#include "wiringPi.h"
#include "softPwm.h"

RPiMotor::RPiMotor(int BCM_pin1, int BCM_pin2)
{
	this->BCM_pin1 = BCM_pin1;
	this->BCM_pin2 = BCM_pin2;
	// digitalWrite(BCM_pin1, 0)
	// softPwmWrite(BCM_pin2, (int)power)
}

double RPiMotor::get_power()
{
	return power;
}

void RPiMotor::set_power(double power)
{
  this->power = power;

  if ((int)power == 0) {
	  softPwmWrite(BCM_pin1, 0);
	  softPwmWrite(BCM_pin2, 0);
	  digitalWrite(BCM_pin1, 0);
	  digitalWrite(BCM_pin2, 0);
  } else if (power > 0) {
   softPwmWrite(BCM_pin1, (int)power);
   softPwmWrite(BCM_pin2, 0);
  }
  //if (power < 0) {
	 // // Drive backwards
	 // softPwmWrite(BCM_pin1, 0);
	 // softPwmWrite(BCM_pin2, -(int)power); // neg pin with positive power value
  //}
  //else {
	 // // Drive forward
	 // softPwmWrite(BCM_pin1, (int)power);
	 // softPwmWrite(BCM_pin2, 0);
  //}

	
	// digitalWrite(BCM_pin1, 0);
	// softPwmWrite(BCM_pin2, (int)power);
}
