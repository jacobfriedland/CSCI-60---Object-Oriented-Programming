#include "lbiguint.h"
#include "node.h"
#include <string>

int main(){
  std::string number = "100";
  lbiguint a(number);
  std::cout << a << std::endl;
  std::cout << a[1] << std::endl;
  std::cout << a.size() << std::endl;
  return 0;
}
