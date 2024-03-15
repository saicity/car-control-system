#include "MassAirflowSensor.h"


MassAirflowSensor::MassAirflowSensor()
{
  //Default: Moderate Conditions
  acceleration = true;
  load = true;
  speed = s.getSpeed();
}

MassAirflowSensor::MassAirflowSensor(bool acceleration, bool load, int speed, Speedometer s)
{
  this->acceleration = acceleration;
  this->load = load;
  this->speed = s.getSpeed();
  this->s = s;
}

void MassAirflowSensor::setMassAirFlow(bool acceleration, bool load, Speedometer s)
{
  this->acceleration = acceleration;
  this->load = load;
  this->speed = s.getSpeed();
}

double MassAirflowSensor::measure() const
{
  if (acceleration == true && load == true && speed > 90)
  {
    return 250.0;
  }
  else if (acceleration == true && load == false && speed < 90 && speed > 30)
  {
    return 100.0;
  }
  else
  {
    return 20.0;
  }
}

std::ostream& operator<<(std::ostream& os, MassAirflowSensor& m)
{
  os << "Mass Air Flow: " << m.measure() << " g/s\n";
  return os;
}
