#include <iostream>
#include <cmath>
//Jacob Friedland, Aaron Liu

int salary(int n) {
  if (n == 0) {
    return 50000;
  }
  return 5000 + 1.1 * salary(n-1);
}

int main() {
  std::cout<<"1 years: "<<salary(1)<<std::endl;
  std::cout<<"2 years: "<<salary(2)<<std::endl;
  std::cout<<"3 years: "<<salary(3)<<std::endl;
  return 0;
}
