/* Friedland (Jacob) + Liu (Aaron) */

#include "dbiguint.h"
#include <iostream>

dbiguint::dbiguint() {
  capacity_ = 0;
  data_ = NULL;
}

dbiguint::dbiguint(const std::string& s){
  capacity_ = s.length();
  data_ = new unsigned short[capacity_];
  for(std::size_t i = 0; i < capacity_; i++) {
    data_[i] = s[s.length()-i-1] - '0';
  }
}

std::size_t dbiguint::size() const{
  return capacity_;
}


unsigned short dbiguint::operator [](std::size_t pos) const{
  if (pos >= capacity_) {
    return 0;
  }
  return data_[pos];
}

void dbiguint::reserve(std::size_t new_capacity){
  if (capacity_ <= new_capacity) {
    unsigned short* data2 = new unsigned short[new_capacity];
    for (int i = 0; i < capacity_; i++) {
      data2[i] = data_[i];
    }
    for (int j = capacity_; j < new_capacity; j++) {
      data2[j] = 0;
    }
    capacity_ = new_capacity;
    delete[] data_;
    data_ = data2;
    return;
  }
  return;
}


void dbiguint::operator += (const dbiguint& b){
  if(b.size() >= capacity_) {
    reserve(b.size() + 1);
  }
  /*
  [0,1] += [0,0,0,5]
  */
  std::size_t i;
  for(i = 0; i < capacity_; i++){
    if(data_[i] + b[i] >= 10){
      data_[i+1] = data_[i+1] + 1;
    }
    data_[i] = (data_[i] + b[i]) % 10;
  }
  int j = capacity_-1;
  int k = 0;
  while (data_[j] == 0) {
    k++;
    j--;
  }
  capacity_ -= k;
  unsigned short * data3 = new unsigned short[capacity_];
  for (int i = 0; i < capacity_; i++) {
    data3[i] = data_[i];
  }
  delete[] data_;
  data_ = data3;
}

/*
void biguint::operator -= (const biguint& b){
  if(compare(b) == -1){
    for(std::size_t i = 0; i < CAPACITY; i++){
      data[i] = 0;
    }
    return;
  }
  short borrow = 0;
  for(std::size_t i = 0; i < CAPACITY; i++){
    if(b[i] > data[i]){
      data[i] = ((10 + data[i]) - b[i]) + borrow;
      borrow = -1;
    }
    if(b[i] <= data[i]){
      data[i] = data[i] - b[i] + borrow;
      borrow = 0;
    }
  }
  return;
}

int biguint::compare(const biguint& b) const {
  for(std::size_t i = CAPACITY; i > 0; i--){
    if(data[i-1] > b[i-1])
      return 1;
    if(data[i-1] < b[i-1])
      return -1;
  }
  return 0;
}

std::string biguint::toString(){
  std::string text = "";
  for(std::size_t i = 0; i < CAPACITY; i++){
    text = text + char(data[i] + '0');
  }
  return text;
}


// nonmember functions

biguint operator + (const biguint& a, const biguint& b){
  biguint c;
  c += a;
  c += b;
  return c;
}

biguint operator - (const biguint& a, const biguint& b){
  biguint c;
  c += a;
  c -= b;
  return c;
}

bool operator < (const biguint& a, const biguint& b){
  return a.biguint::compare(b) == -1;
}

bool operator <= (const biguint& a, const biguint& b){
  return a.biguint::compare(b) == -1 || 0;
}

bool operator != (const biguint& a, const biguint& b){
  return a.biguint::compare(b) == -1 || 1;
}
bool operator == (const biguint& a, const biguint& b){
  return a.biguint::compare(b) == 0;
}

bool operator >= (const biguint& a, const biguint& b){
  return a.biguint::compare(b) == 1 || 0;
}

bool operator > (const biguint& a, const biguint& b){
  return a.biguint::compare(b) == 1;
}

*/
std::ostream& operator << (std::ostream& out, const dbiguint& RHS) {
  for (std::size_t i = 0; i < RHS.size(); i++) {
    out<<RHS[i];
  }
  return out;
}

int main(){
  dbiguint a;
  dbiguint b("123456");
  dbiguint c("1234567");
  std::cout << b << std::endl;
  b.reserve(12);
  std::cout << b << std::endl;
  b+=c;
  std::cout << b << std::endl;
  return 0;
}
