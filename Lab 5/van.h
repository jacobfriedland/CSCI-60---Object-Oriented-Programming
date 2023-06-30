/* Jacob Friedland & Aaron Liu */
#ifndef VAN_H
#define VAN_H
#include "automobile.h"
#include <string>

class Van:public Automobile{
public:
  Van();

  Van(std::string imake, std::string imodel, int iyear, double iprice, int istall, int iseats);

  bool park(bool lot[], int size);

  int seats(){
    return seats_;
  }
private:
  int seats_;
};
#endif //VAN_H
