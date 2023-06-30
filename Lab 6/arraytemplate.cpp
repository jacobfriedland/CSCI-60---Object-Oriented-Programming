/* Friedland Jacob and Liu Aaron */

#include <iostream>
#include <string>

//for this to work, T1 must have the operator = defined. T2 must be convertable to an int.
template <typename T1, typename T2>
int count_exact(T1 a[], T2 size, T1 find){
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (a[i] == find) {
      count++;
    }
  }
  return count;
}

//for this to work, T1 must have operator <= and >= since the bounds are inclusive. T2 must be convertable to an int.
template <typename T1, typename T2>
int count_range(T1 a[], T2 size, T1 low, T1 high) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (a[i] >= low && a[i] <= high) {
      count++;
    }
  }
  return count;
}


int main(){
  int size = 6;
  int arr1[] = {6, 2, 3, 2, 6, 2};
  int count1 = count_exact(arr1, size, 2);
  std::cout << count1 << std::endl;

  std::string arr2[] = {"bob", "mary", "dan", "joe", "catherine", "john"};
  std::string b = "bob";
  std::string c = "john";
  int count2 = count_exact(arr2, size, b);
  std::cout << count2 << std::endl;

  int range_amount1 = count_range(arr1, size, 2, 4);
  std::cout << range_amount1 << std::endl;

  int range_amount2 = count_range(arr2, size, b, c);
  std::cout << range_amount2 << std::endl;

}
