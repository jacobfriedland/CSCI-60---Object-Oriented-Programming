/* Friedland Jacob, Liu Aaron */

#include "node.h"

node::node(){
  data_ = 0;
  link_ = nullptr;
}
node::node(const int& initdata, node * initlink)
{
    data_ = initdata;
    link_ = initlink;
}

int node::data() const
{
    return data_;
}

node * node::link()
{
    return link_;
}

//returns constant node pointer
const node * node::link() const//This is a const function - I promise the function doesn't change anything - On a const node*, you can only call const functions
{
    return link_;
}

void node::set_data(const int & newdata)
{
    data_ = newdata;
}

void node::set_link(node * newlink)
{
    link_ = newlink;
}

std::size_t list_index(node * head_ptr, int target){
  std::size_t list_index = 0;
  for(const node *p = head_ptr; p != nullptr; p = p->link()){
    if(p->data() == target){
      return list_index;
    }
    else
      list_index++;
  }
  return -1;
}

node* list_at(node * head_ptr, std::size_t n){
  node* current = head_ptr;
  for(std::size_t i = 0; i < n; i++){
    current = current->link();
  }
  return current;
}
