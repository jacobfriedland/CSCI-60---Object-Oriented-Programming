/* Jacob Friedland & Aaron Liu */
#include "pickup.h"

Pickup::Pickup():Automobile(),haulingcapacity_(0.0),extendedcab_(false){}

Pickup::Pickup(std::string imake, std::string imodel, int iyear, double iprice, int istall,
  double ihaulingcapacity, bool iextendedcab):Automobile(imake, imodel, iyear, iprice, istall),
  haulingcapacity_(ihaulingcapacity),extendedcab_(iextendedcab){}

bool Pickup::park(bool lot[], int size) {
  int spot=size;
  for(int i=0; i<size-1; i++){
      if( (!lot[i]) && (!lot[i+1]) ){
          spot = i;
      }
  }
  if(spot>=size)
     return false;
  else{
      lot[spot] = true;
      lot[spot+1] = true;
      set_stall(spot);
      return true;
  }
}
