/* Friedland Jacob and Liu Aaron */

#ifndef POINT_H
#define POINT_H
#include <iostream>

template <typename T1, typename T2>
class Point{
public:
  Point();
  Point(T2 dimension1, T1 a[]);
  Point(T2 dimension1);
  T1 get_point(int i){return arr[i];}
  T2 get_dimension(){return dimension;}
  void operator = (const Point<T1, T2>& RHS);
  void printOut();
private:
  T1 arr[10];
  T2 dimension;
};

template<typename T1, typename T2>
Point<T1, T2>::Point(){
  dimension = 0;
}
template<typename T1, typename T2>
Point<T1, T2>::Point(T2 dimension1, T1 a[]){
  dimension = dimension1;
  for (int i = 0; i < dimension; i++){
    arr[i] = a[i];
  }
}
template<typename T1, typename T2>
Point<T1, T2>::Point(T2 dimension1){
  dimension = dimension1;

}

template<typename T1, typename T2>
void Point<T1, T2>::operator = (const Point<T1, T2>& RHS){
  dimension = RHS.dimension;
  for (int i = 0; i < RHS.dimension; i++) {
    arr[i] = RHS.arr[i];
  }
}

template<typename T1, typename T2>
void Point<T1, T2>::printOut() {
  for (int i = 0; i < dimension; i++) {
    std::cout<<(i+1)<<": "<<arr[i]<<std::endl;
  }
}

#endif //POINT_H
