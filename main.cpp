#include "Speedometer.h"
#include "Transmission.h"
#include "Sensor.h"
#include "MassAirflowSensor.h"

int main() {
  Speedometer s1(100);
  Transmission t1(4, false, false, true, "Automatic");
  MassAirflowSensor MAS1(true, true, s1.getSpeed(), s1);

  std::cout << s1;
  std::cout << t1;
  t1.reccomendGear();
  std::cout << t1;
  std::cout << MAS1;
}

