/* Jacob Friedland & Aaron Liu */
#include "automobile.h"
#include "pickup.h"
#include "van.h"
using namespace std;
#include <iostream>

int main(){
  bool parkinglot[20];
  for (int i = 0; i < 20; i++) {
    parkinglot[i] = false;
  }
  Automobile a;
  Automobile b("Make A", "Model A", 2000, 50000.0, -2);

  a.park(parkinglot, 20);
  b.park(parkinglot,20);

  for (int i = 0; i < 20; i++) {
    cout<<parkinglot[i];
  }
  cout<<"\n";

  Pickup p1;
  Pickup p2("Make B", "Model B", 3000, 10000.0, -3, 100.0, false);

  p1.park(parkinglot, 20);
  p2.park(parkinglot, 20);
  for (int i = 0; i < 20; i++) {
    cout<<parkinglot[i];
  }
  cout<<"\n";
  Van v1;
  Van v2("Make C", "Model C", 4000, 60000.0, -4, 5);
  Van v3("Make D", "Model D", 5000, 10001.0, -3, 8);

  v1.park(parkinglot, 20);
  v2.park(parkinglot, 20);
  v3.park(parkinglot, 20);
  for (int i = 0; i < 20; i++) {
    cout<<parkinglot[i];
  }
  cout<<"\n";
  return 0;
}
