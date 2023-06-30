/* Friedland, Jacob; Liu, Aaron */
void clean(){
  std::size_t j = capacity_ - 1;
  std::size_t k = 0;
  while (data_[j] == 0) {
    k++;
    j--;
  }
  capacity_ = capacity_ - k;
  unsigned short * data2 = new unsigned short[capacity_];
  for (std::size_t m = 0; m < capacity_; m++) {
    data2[m] = data_[m];
  }
  delete [] data_;
  data_ = data2;
}
