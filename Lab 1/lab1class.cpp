# include <iostream>
using namespace std;

class Carpool{
  public:
    struct Time
    {
      int hour;
      int minute;
    };
    Time t;
    int size;
    string names[5];
    
    Carpool(int hour, int min, int size1, string names1[]) {
      t.hour = hour;
      t.minute = min;
      size = size1;
      for (int i = 0; i< 5; i++) {
        names[i] = names1[i];
      }
    }
    Time earlier(Time t2){
        Time ret;
        if(t.hour == t2.hour){
            if(t.minute<t2.minute)
                ret = t;
            else
                ret = t2;
        }
        else if(t.hour<t2.hour){
            ret = t;
        }
        else{
            ret = t2;
        }
        return ret;
    }

    void combineCarpool(Carpool car2){
      if (size + car2.size <= 5) {
        t = earlier(car2.t);
        for (int i = 0; i < car2.size; i++) {
          names[size+i] = car2.names[i];
        }
        size = car2.size + size;
      } else {
        t.hour = 0;
        t.minute = 0;
        size = 0;
        for (int i = 0; i < 5; i++) {
          names[i] = "";
        }
      }
    }
    void printCarpool() {
      cout<<"Names: ";
      for (int i = 0; i < size; i++) {
        cout<<names[i]<<" ";
      }
      cout<<""<<endl;
    }
};

int main(){

  string car1names[5] = {"name1", "name2", "name3"};
  string car2names[5] = {"name4"};
  string car3names[5] = {"name5"};
  Carpool car1(5,10, 3, car1names);
  Carpool car2(6,12, 1, car2names);
  Carpool car3(6,13, 999, car3names);

  car1.combineCarpool(car2);
  car1.printCarpool();
  car2.combineCarpool(car3);
  car2.printCarpool();
}
