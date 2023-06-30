/* Friedland Jacob & Liu Aaron */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

int main(){

// Part A: std::map<std::string, int> service;

  std::ifstream ifs("lab7.txt");
  std::ofstream ofs("1b.txt");
  std::map<std::string, int> service;

  if(ifs.fail()) {
    std::cout<<"Input file opening failed.";
    exit(1);
  }
  std::string s;

  while(getline(ifs, s)){
    service[s]++;
  }

  if(ofs.fail()) {
    std::cout<<"Output file opening failed.";
    exit(1);
  }

  for(auto e: service){
    ofs << e.first << e.second << std::endl << std::endl;
  }

  int totalmeals = 0;
  int totalpeople = 0;
  for(auto e: service) {
    totalpeople++;
    totalmeals += e.second;
  }
  double avgmeals = 1.0 * totalmeals / totalpeople;

  std::cout<<"Total meals: "<<totalmeals<<", Total people: "<<totalpeople<<", Average meals per person: "<<avgmeals<<std::endl;
}
