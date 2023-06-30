/* Friedland Jacob & Liu Aaron */

#include <iostream>
#include <fstream>
#include <string>
#include <set>

int main(){

// Part A: std::multiset<std::string> names_2;

  std::ifstream file("lab7.txt");
  std::multiset<std::string> names_2;
  if(file.fail()) {
    std::cout<<"Input file opening failed.";
  }
  std::string s;
  while(file>>s){
      names_2.insert(s);
  }

  std::ofstream new_file("1c.txt");
  if(new_file.fail()) {
    std::cout<<"Output file opening failed.";
    exit(1);
  }
  for(auto e: names_2){
    new_file << e << std::endl << std::endl;
  }
}
