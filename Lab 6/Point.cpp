/* Friedland Jacob and Liu Aaron */
#include "Point.h"

template<typename T1, typename T2>
Point<T1, T2>::Point(){//We enter the scope of the class definition after the ::
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
