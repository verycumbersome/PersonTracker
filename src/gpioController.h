#ifndef GPIO_CONTROLLER_INCLUDED
#define GPIO_CONTROLLER_INCLUDED

#include <wiringPi.h>
#include <iostream>

using namespace std;

class gpioController {
	public:
		controlPin(int pin, string value, bool IO = true);
};

#endif /* GPIO_CONTROLLER_INCLUDED */
