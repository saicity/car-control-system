#include "Speedometer.h"

Speedometer::Speedometer()
{
  speed = 0;
}

Speedometer::Speedometer(int speed)
{
  if (speed > 0) {
    this->speed = speed;
  }
  else
  {
    this->speed = 0;
  }
}

Speedometer::Speedometer(const Speedometer& s)
{
  if (this->speed != s.getSpeed())
  {
    this->speed = s.getSpeed();
  }
}

//Using a setter function to set the speed
void Speedometer::setSpeed(int speed)
{
  if (speed < 0) {
    this->speed = 0;
  }
  else
  {
    this->speed = 0;
  }
}

//Using a getter function to get the speed
int Speedometer::getSpeed() const
{
  return this->speed;
}

std::ostream& operator<<(std::ostream& os, const Speedometer& s)
{
  //Displays Speed
  os << "Current Speed: " << s.getSpeed() << " km/h\n";
  return os;
}
