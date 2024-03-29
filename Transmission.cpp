#include "Transmission.h"

Transmission::Transmission()
{
  currentGear = 1;
  highThrottlePosition = false;
  coldTemperature = true;
  steadyPosition = false;
  transmissionMode = "Automatic";
}

Transmission::Transmission(int currentGear, bool highThrottlePosition, bool coldTemperature, bool steadyPosition, std::string transmissionMode)
{
  this->highThrottlePosition = highThrottlePosition;
  this->coldTemperature = coldTemperature;
  this->steadyPosition = steadyPosition;

  if (currentGear < 1 || currentGear > 5)
  {
    //Gear is set to default if paramter isn't realistic.
    this->currentGear = 1;
  }
  else
  {
    this->currentGear = currentGear;
  }

  if (transmissionMode != "Automatic" && transmissionMode != "Manual" && transmissionMode != "Winter")
  {
    this->transmissionMode = "Automatic";
  }
  else
  {
    this->transmissionMode = transmissionMode;
  }
}

Transmission::Transmission(const Transmission& t)
{
  currentGear = t.currentGear;
  coldTemperature = t.coldTemperature;
  highThrottlePosition = t.highThrottlePosition;
  steadyPosition = t.steadyPosition;
  transmissionMode = t.transmissionMode;
}

void Transmission::setCurrentGear(int currentGear)
{
  if (currentGear < 1 || currentGear > 5)
  {
    //Gear is set to default if paramter isn't realistic.
    this->currentGear = 1;
  }
  else
  {
    this->currentGear = currentGear;
  }
}

void Transmission::setHighThrottlePosition(bool highThrottlePosition)
{
  this->highThrottlePosition = highThrottlePosition;
}

void Transmission::setColdTemperature(bool coldTemperature)
{
  this->coldTemperature = coldTemperature;
}

void Transmission::setSteadyPosition(bool steadyPosition)
{
  this->steadyPosition = steadyPosition;
}

void Transmission::setTransmissionMode(std::string transmissionMode)
{
  this->transmissionMode = transmissionMode;
}

void Transmission::reccomendGear()
{
  //In the highway and it's not winter
  if ((highThrottlePosition == false) && (coldTemperature == false) && (steadyPosition == true))
  {
    std::cout << "Reccomendation: Fifth gear.\n";
    setCurrentGear(5);
  }

  //In the suburbs or city 
  else if ((highThrottlePosition == false) && (coldTemperature == false) && (steadyPosition == false))
  {
    std::cout << "Reccomendation: Third gear.\n";
    setCurrentGear(3);
  }

  //Winter on highway
  else if ((highThrottlePosition == false) && (coldTemperature == true) && (steadyPosition == true))
  {
    std::cout << "Reccomendation: Fourth gear.\n";
    setCurrentGear(4);
  }
  
  //Winter in suburbs or city
  else if ((highThrottlePosition == true) && (coldTemperature == true) && (steadyPosition == false))
  {
    std::cout << "Reccomendation: Second gear/\n";
    setCurrentGear(2);
  }
}

int Transmission::getCurrentGear() const
{
  return currentGear;
}

bool Transmission::getHighThrottlePosition() const
{
  return highThrottlePosition;
}

bool Transmission::getColdTemperature() const
{
  return coldTemperature;
}

bool Transmission::getSteadyPosition() const
{
  return steadyPosition;
}

std::string Transmission::getTransmissionMode() const
{
  return transmissionMode;
}

std::ostream& operator<<(std::ostream& os, const Transmission& t)
{
  os << "Transmission Mode: " << t.getTransmissionMode() << '\n';
  os << "Current Gear: " << t.getCurrentGear() << '\n';
  os << "High Throttle Position: ";
  if (t.getHighThrottlePosition() == true)
  {
    os << "True\n";
  }
  else
  {
    os << "False\n";
  }
  os << "Cold Temperature Outside: ";
  if (t.getColdTemperature() == true)
  {
    os << "True\n";
  }
  else
  {
    os << "False\n";
  }
  return os;
}
