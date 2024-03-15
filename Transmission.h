#ifndef TRANSMISSION_H
#define TRANSMISSION_H

#include <iostream>
#include <string.h>

  class Transmission
  {
  private:
    int currentGear;
    bool highThrottlePosition;
    bool coldTemperature;
    bool steadyPosition;
    std::string transmissionMode;
  public:
    Transmission();
    Transmission(int currentGear, bool highThrottlePosition, bool coldTemperature, bool steadyPosition, std::string transmissionMode);
    void setCurrentGear(int currentGear);
    void setHighThrottlePosition(bool highThrottlePosition);
    void setColdTemperature(bool coldTemperature);
    void setSteadyPosition(bool steadyPosition);
    void reccomendGear();
    int getCurrentGear();
  };

  std::ostream& operator<<(std::ostream& os, const Transmission& t);
#endif