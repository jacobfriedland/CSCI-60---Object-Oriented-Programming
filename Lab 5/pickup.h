/* Jacob Friedland & Aaron Liu */
#ifndef PICKUP_H
#define PICKUP_H
#include "automobile.h"
#include <string>

class Pickup:public Automobile{
public:
  Pickup();
  Pickup(std::string imake, std::string imodel, int iyear, double iprice, int istall, double ihaulingcapacity, bool iextendedcab);

  bool park(bool lot[], int size);

  bool extendedcab() {
    return extendedcab_;
  }
  double haulingcapacity(){
    return haulingcapacity_;
  }
private:
  double haulingcapacity_;
  bool extendedcab_;
};
#endif // PICKUP_H
