/*
FRIEDLAND (JACOB)
LIU (AARON)
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <cmath>

// WANT: integers with CAPACITY digits, only non-negative
//
// support:
//    2 constructors: int, string
//    member functions:  [] returns individual digits given position
//                        +=
//                        -=
//                        compare: return +1, 0, -1, depending on
//                        whether this biguint >, ==, < than given biguint
//                        +, - (binary), - (unary), <, <=, ==, !=, >=, >
//                        <<, >>

class biguint
{
public:
    // CONSTANTS & TYPES

    static const std::size_t CAPACITY = 20;

    // CONSTRUCTORS

    // pre: none
    // post: creates a biguint with value 0
    biguint();

    // pre: s contains only decimal digits
    // post: creates a biguint whose value corresponds to given string of digits
    biguint(const std::string& s);

    // CONSTANT MEMBER FUNCTIONS

    // pre: pos < CAPACITY
    // post: returns the digit at position pos
    //          0 is the least significant (units) position
    unsigned short operator [](std::size_t pos) const;

    // pre: none
    // post: returns 1 if this biguint > b
    //               0 if this biguint == b
    //              -1 if this biguint < b
    int compare(const biguint& b) const;

    // MODIFICATION MEMBER FUNCTIONS

    // pre: none
    // post: b is added to this biguint; ignore last carry bit if any
    void operator += (const biguint& b);

    // pre: none
    // post: b is subtracted from this biguint; set to 0 if negative result
    void operator -= (const biguint& b);

    std::string toString();

private:

    unsigned short data[CAPACITY];

    // INVARIANTS:
    //    data_[i] holds the i^th digit of this biguint or 0 if not used
    //    data_[0] holds the least significant (units) digit
};

biguint::biguint() {
  for(std::size_t i = 0; i < CAPACITY; i++) {
     data[i] = 0;
  }
}

/*
PROBLEM 2: Fill array with 0s first (using for loop), then fill in/overlay characters from string to the array.
For each character in string (second for loop), find its character encoding/corresponding integer
and subtract it by the character encoding of char '0'. The result is an integer between 0-9.
*/
biguint::biguint(const std::string& s){
  for(std::size_t i = 0; i < CAPACITY; i++) {
    data[i] = 0;
  }
  for(std::size_t j = 0; j < s.length(); j++) {
    data[j] = s[s.length()-j-1] - '0';
  }
}

unsigned short biguint::operator [](std::size_t pos) const{
  assert(pos < CAPACITY);
  return data[pos];
}

/* PROBLEM 6: Add digits of the same position i in two biguint arrays. if the result is larger
than 10, increment the value of the following position in the array being modified by one.
Then mod 10 the sum of the two digits and set value in position i of the biguint array being
modified as such.
*/
void biguint::operator += (const biguint& b){
  for(std::size_t i = 0; i < CAPACITY; i++){
    if(data[i] + b[i] >= 10){
      data[i+1] = data[i+1] + 1;
    }
    data[i] = (data[i] + b[i]) % 10;
  }
}

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

// pre: non
// post: return a new biguint that is the sum of two biguints passed in as
// arguments
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

std::ostream& operator << (std::ostream& out, const biguint& RHS) {
  for (std::size_t i = 0; i < biguint::CAPACITY; i++) {
    out<<RHS[i];
  }
  return out;
}

int main(){
  biguint a;
  biguint b("1234");
  biguint c("125667");
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  b += c;
  std::cout << b << std::endl;
  b -= c;
  std::cout << b << std::endl;
  biguint d = b + c;
  std::cout << d << std::endl;
  biguint e = d - c;
  std::cout << e << std::endl;
  return 0;
}
