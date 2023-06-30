#include "lbiguint.h"
#include <cassert>
#include <sstream>

lbiguint::lbiguint(){
  head = new node(0, nullptr);
  tail = nullptr;
}

lbiguint::lbiguint (const std::string & s) {
  head = new node((s[s.size()-1]-'0'), nullptr);
  node * pcurr = head;
  for(int i = s.size()-2; i >= 1; i--) {
    pcurr->set_link(new node((s[i]-'0'), nullptr));
    pcurr = pcurr->link();
  }
  pcurr->set_link(new node((s[0]-'0'), nullptr));
  pcurr = pcurr->link();
  tail = pcurr;
}

lbiguint::~lbiguint() {
  node* temp;
  for(node *p = head; p != nullptr; p = temp) {
    temp = p->link();
    delete p;
  }
  head = nullptr;
  tail = nullptr;
}

std::size_t lbiguint::size() {
  size_ = 0;
  node * temp = head;
  while(temp) {
    temp = temp->link();
    size_++;
  }
  return size_;
}

unsigned short lbiguint::operator [](std::size_t pos) {
  if(pos < size()) {
    node * temp = head;
    for(std::size_t i = 0; i < pos; i++) {
      temp = temp->link();
    }
    return temp->data();
  } else {return 0;}
}

std::ostream & operator << (std::ostream & os, lbiguint & b) {
  node * head1 = b.head();
  for(node * p = head1; p!=nullptr; p = p->link()){
    os << p->data();
  }
  return os;
}

//
//
//
// int biguint::compare(const biguint & b) const{
//     for(std::size_t i =CAPACITY-1; i>=0; --i){
//         if(_data[i]>b._data[i])
//             return 1;
//         else if (_data[i]<b._data[i])
//             return -1;
//
//     }
//     return 0;
// }
//
//
//
// std::string biguint::toStdString() const
// {
//     std::stringstream ss;
//     ss << *this;
//     return ss.str();
// }//We haven't talked about stringstreams; just ignore this, I was being lazy.

//
// std::istream & operator >> (std::istream & is, biguint & b)
// {
//     std::string s;
//     is >> s;
//     b = biguint(s);
//     return is;
//
//
// }
//
// bool operator <(const biguint& a, const biguint& b){
//     return (a.compare(b)==-1);
// }
//
// bool operator <= (const biguint & b1, const biguint & b2)
// {
//     return (b1.compare(b2) <= 0);
// }
//
// bool operator == (const biguint & b1, const biguint & b2)
// {
//     return (b1.compare(b2) == 0);
// }
//
// bool operator != (const biguint & b1, const biguint & b2)
// {
//     return (b1.compare(b2) != 0);
// }

//You do > and >=
