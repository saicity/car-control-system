#ifndef MASS_AIRFLOW_SENSOR_H
#define MASS_AIRFLOW_SENSOR_H

#include "Sensor.h"
#include "Speedometer.h"
#include <iostream>

//Needs engine speed, throttle position, load and driing conditions
//Organizing it into high, moderate, low
class MassAirflowSensor : public Sensor
{
private:
  bool acceleration;
  bool load;
  int speed;
  Speedometer s;
public:
  MassAirflowSensor();
  MassAirflowSensor(bool acceleration, bool load, int speed, Speedometer s);
  void setMassAirFlow(bool acceleration, bool load, Speedometer s);
  double measure() const override;
};

std::ostream& operator<< (std::ostream& os, MassAirflowSensor& m);

#endif