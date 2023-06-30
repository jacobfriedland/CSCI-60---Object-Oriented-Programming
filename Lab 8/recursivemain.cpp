/* Friedland Jacob, Liu Aaron */
#include <iostream>
#include <string>
#include "recursive.cpp"
#include "node.cpp"

int main(){

  int a[] = {1,2,3,4,5};
  bool answer = isSorted(a, 4);
  std::cout << answer << std::endl;
  int amount = water(1);
  std::cout << amount << std::endl;
}
