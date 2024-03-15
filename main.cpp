#include "Speedometer.h"
#include "Transmission.h"

int main() {
  Speedometer s1(30);
  Transmission t1(1, false, false, true, "Automatic");
  std::cout << s1;
  std::cout << t1;
  t1.reccomendGear();
  std::cout << t1;
}
