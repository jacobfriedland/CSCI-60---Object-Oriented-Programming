/* Friedland Jacob & Liu Aaron */

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

int main(){

// Part A: std::unordered_set<std::string> names;

  std::ifstream file("lab7.txt");
  std::unordered_set<std::string> names;
  if(file.fail()) {
    std::cout<<"Input file opening failed.";
  }
  std::string s;
  while(file>>s){
      names.insert(s);
  }

  std::ofstream new_file("1a.txt");
  if(new_file.fail()) {
    std::cout<<"Output file opening failed.";
    exit(1);
  }
  for(auto e: names){
    new_file << e << std::endl << std::endl;
  }
}
