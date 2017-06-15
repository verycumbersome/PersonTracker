#include "gpioController.h"

using namespace std;

void gpioController::controlPin(int pin, string value, bool IO);
{
  wiringPiSetup () ;
  pinMode (pin, OUTPUT) ;

  digitalWrite (pin, HIGH) ; delay (500) ;
}
