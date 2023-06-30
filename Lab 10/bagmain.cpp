/* Friedland, Jacob; Liu, Aaron */
#include <iostream>
#include <string>
#include "bag.h"

int main(){
  int arr1 [] = {1, 2, 3, 4, 5};
  bag<int> b(arr1, 5);
  for(auto e:b){
    std::cout << e;
  }
  std::cout << std::endl;
  bag<int>::iterator i;
  for(i = b.begin(); i != b.end(); ++i){
    std::cout << (*i);
  }
  std::cout << std::endl;
  return 0;
}
