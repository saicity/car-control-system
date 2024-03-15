#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include <iostream>

  class Speedometer
  {
  private:
    int speed;
  public:
    Speedometer();
    Speedometer(int speed);
    Speedometer(const Speedometer& s);
    void setSpeed(int speed);
    int getSpeed() const;
  };

  //Helper function to display speedometer 
  std::ostream& operator<< (std::ostream& os, const Speedometer& s);
#endif