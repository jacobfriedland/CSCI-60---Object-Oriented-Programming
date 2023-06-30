#include <iostream>
using namespace std;

struct Time
{
  int hour;
  int minute;
};

struct Carpool
{
  Time t;
  int size;
  string names[5];
};


Time earlier(Time t1, Time t2){
    Time ret;
    if(t1.hour == t2.hour){
        if(t1.minute<t2.minute)
            ret = t1;
        else
            ret = t2;
    }
    else if(t1.hour<t2.hour){
        ret = t1;
    }
    else{
        ret = t2;
    }
    return ret;
}

Carpool initCarpool(Carpool& a) {
  a.t.hour = 0;
  a.t.minute = 0;
  a.size = 0;
  for (int i = 0; i < 5; i++) {
    a.names[i] = "";
  }
  return a;
}

Carpool combineCarpool(Carpool car1, Carpool car2)
{
  Carpool car3;
  initCarpool(car3);
  if (car1.size + car2.size <= 5) {
    car3.t = earlier(car1.t, car2.t);
    car3.size = car2.size + car1.size;
    int index;
    for (int i = 0; i < car1.size; i++) {
      car3.names[i] = car1.names[i];
      index++;
    }
    for (int i = 0; i < car2.size; i++) {
      car3.names[index+i] = car2.names[i];
    }
    return car3;
  }
  return car3;
}

void printCarpool(Carpool b) {
  cout<<"Time: "<<b.t.hour<<":"<<b.t.minute<<endl;
  cout<<"Number of people: "<<b.size<<endl;
  cout<<"Names: ";
  for (int i = 0; i < b.size; i++) {
    cout<<b.names[i]<<" ";
  }
  cout<<""<<endl;
}

int main(){
  Carpool car1 = {{5,10}, 3, {"name1", "name2", "name3"}};
  Carpool car2 = {{6,12}, 1, {"name4"}};
  Carpool car3 = {{6,13}, 999, {"name4"}};
  Carpool combined_car1 = combineCarpool(car1, car2);
  printCarpool(combined_car1);
  Carpool combined_car2 = combineCarpool(car1, car3);
  printCarpool(combined_car2);
}
