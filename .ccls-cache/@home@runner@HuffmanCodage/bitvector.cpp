#include "bitvector.h"
#include <iostream>
#include <vector>

BitVector::BitVector() : std::vector<bool>() {}
BitVector::BitVector(size_t n) : std::vector<bool>(n, false) {}

BitVector &BitVector::operator+=(const BitVector &other) {
  this->insert(this->end(), other.begin(), other.end());
  return *this;
}

BitVector &BitVector::operator&=(const BitVector &other) {
  size_t size = std::min(
      this->size(),
      other.size()); // If one vector is bigger we remove the last elements
  for (int i = 0; i < size; i++) {
    (*this)[i] = (*this)[i] & other[i];
  }
  return *this;
}

BitVector &BitVector::operator|=(const BitVector &other) {
  size_t size = std::min(
      this->size(),
      other.size()); // If one vector is bigger we remove the last elements
  for (int i = 0; i < size; i++) {
    (*this)[i] = (*this)[i] | other[i];
  }
  return *this;
}

BitVector &BitVector::operator^=(const BitVector &other) {
  size_t size = std::min(
      this->size(),
      other.size()); // If one vector is bigger we remove the last elements
  for (int i = 0; i < size; i++) {
    (*this)[i] = (*this)[i] ^ other[i];
  }
  return *this;
}

BitVector BitVector::operator~() const { return BitVector(*this).flip(); }

BitVector BitVector::operator<<(const std::size_t pos) const {
  BitVector outVec(*this);
  outVec.erase(outVec.begin(), outVec.begin() + pos);
  outVec += BitVector(pos);
  return outVec;
}

BitVector &BitVector::operator<<=(const std::size_t pos) {
  this->erase(this->begin(), this->begin() + pos);
  *this += BitVector(pos);
  return *this;
}

BitVector BitVector::operator>>(const std::size_t pos) const {
  BitVector outVec(*this);
  outVec.erase(outVec.end() - pos, outVec.end());
  outVec += BitVector(pos);
  return outVec;
}

BitVector &BitVector::operator>>=(const std::size_t pos) {
  this->erase(this->begin(), this->begin() + pos);
  *this = BitVector(pos) + *this;
  return *this;
}

BitVector BitVector::sliceSE(int start, int end) const {
  BitVector outVec;
  if (start < 0) {
    start = this->size() + start;
  }
  if (end < 0) {
    end = this->size() + end;
  }
  outVec.insert(outVec.begin(), this->begin() + start, this->begin() + end);
  return outVec;
}

BitVector BitVector::sliceS(int start) const {
  BitVector outVec;
  if (start < 0) {
    start = this->size() + start;
  }
  outVec.insert(outVec.begin(), this->begin() + start, this->end());
  return outVec;
}

BitVector BitVector::sliceE(int end) const {
  BitVector outVec;
  if (end < 0) {
    end = this->size() + end;
  }
  outVec.insert(outVec.begin(), this->begin(), this->begin() + end);
  return outVec;
}

BitVector &BitVector::set() {
  for (int i = 0; i < this->size(); i++) {
    (*this)[i] = true;
  }
  return *this;
}

BitVector &BitVector::set(std::size_t pos) {
  (*this)[pos] = true;
  return *this;
}

BitVector &BitVector::reset() {
  for (int i = 0; i < this->size(); i++) {
    (*this)[i] = false;
  }
  return *this;
}

BitVector &BitVector::reset(std::size_t pos) {
  (*this)[pos] = false;
  return *this;
}

BitVector &BitVector::flip() {
  for (int i = 0; i < this->size(); i++) {
    (*this)[i] = ~(*this)[i];
  }
  return *this;
}

BitVector &BitVector::flip(std::size_t pos) {
  (*this)[pos] = ~(*this)[pos];
  return *this;
}

std::size_t BitVector::count() const {
  std::size_t size = 0;
  for (int i = 0; i < this->size(); i++) {
    if ((*this)[i]) {
      size++;
    }
  }
  return size;
}

bool BitVector::all() const {
  for (int i = 0; i < this->size(); i++) {
    if ((*this)[i] == false) {
      return false;
    }
  }
  return true;
}

bool BitVector::any() const {
  for (int i = 0; i < this->size(); i++) {
    if ((*this)[i]) {
      return true;
    }
  }
  return false;
}

bool BitVector::none() const { return ~this->any(); }

BitVector operator+(const BitVector &bvl, const BitVector &bvr) {
  BitVector outVec;
  outVec.insert(outVec.end(), bvl.begin(), bvl.end());
  outVec.insert(outVec.end(), bvr.begin(), bvr.end());
  return outVec;
}

BitVector operator&(const BitVector &bvl, const BitVector &bvr) {
  size_t size = std::min(
      bvl.size(),
      bvr.size()); // If one vector is bigger we remove the last elements
  BitVector outVec(size);
  for (int i = 0; i < size; i++) {
    outVec[i] = bvl[i] & bvr[i];
  }
  return outVec;
}

BitVector operator|(const BitVector &bvl, const BitVector &bvr) {
  size_t size = std::min(
      bvl.size(),
      bvr.size()); // If one vector is bigger we remove the last elements
  BitVector outVec(size);
  for (int i = 0; i < size; i++) {
    outVec[i] = bvl[i] | bvr[i];
  }
  return outVec;
}

BitVector operator^(const BitVector &bvl, const BitVector &bvr) {
  size_t size = std::min(
      bvl.size(),
      bvr.size()); // If one vector is bigger we remove the last elements
  BitVector outVec(size);
  for (int i = 0; i < size; i++) {
    outVec[i] = bvl[i] ^ bvr[i];
  }
  return outVec;
}

std::ostream &operator<<(std::ostream &os, const BitVector &vec) {
  for (const bool &element : vec) {
    os << element;
  }
  return os;
}

void BitVectorTest() {
  BitVector myVector(3);

  // Add some bool values
  myVector.push_back(true);
  myVector.push_back(false);
  myVector.push_back(true);

  myVector = myVector.sliceSE(1, 6);
  // Use the extended functionality
  for (int i = 0; i < myVector.size(); i++) {
    std::cout << myVector[i] << " ";
  }
}
