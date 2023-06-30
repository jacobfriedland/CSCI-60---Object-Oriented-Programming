/* Friedland Jacob, Liu Aaron */
#include <iostream>
#include <string>

double water(int n){
  if(n == 0)
    return 10;
  else {
    return (water(n-1) / 2) + 1;
  }
}

/*
2.
a) if the current element is less then the next element in the array, then the array is sorted
b) you need to check if the n-1 is less than the added n element
*/

bool isSorted(int a[], int n) {
  if(n == 1) {
    if (a[0] < a[1]) {
      return true;
    } else {
      return false;
    }
  }
  else{
    if(a[n] > a[n-1]) {
      return isSorted(a, n-1);
    }
    return false;
  }
}
