/* Friedland Jacob and Liu Aaron */

#include <iostream>
#include "Point.cpp"
#include <string>

int main() {
  std::string arr[] = {"bob", "mary", "dan", "joe", "catherine", "john"};
  Point<int, int> P1;
  Point<std::string, int> P2(2);
  Point<std::string, int> P3(6, arr);
  P2.printOut();
  P3.printOut();
  P2 = P3;
  P2.printOut();
  return 0;
}
