#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>

class Sensor
{
public:
  virtual double measure() const;
};

#endif


