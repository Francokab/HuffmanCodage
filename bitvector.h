#ifndef BITVECTOR_H
#define BITVECTOR_H

#include <iostream>
#include <vector>

class BitVector : public std::vector<bool> {
public:
  BitVector();              // default constructor
  BitVector(std::size_t n); // create a n size vector with 0
  BitVector(std::string carac); //create a vector with a string

  /*   bool operator==(const BitVector &rhs) const; // check if all element are
    equal bool operator!=(const BitVector &rhs) const; // inverse of == bool
    operator>(const BitVector &rhs) const;  // count difference bool
    operator>=(const BitVector &rhs) const; // count difference bool
    operator<(const BitVector &rhs) const;  // count difference bool
    operator<=(const BitVector &rhs) const; // count difference */

  BitVector &operator+=(const BitVector &other);     // binary and
  BitVector &operator&=(const BitVector &other);     // binary and
  BitVector &operator|=(const BitVector &other);     // binary or
  BitVector &operator^=(const BitVector &other);     // binary xor
  BitVector operator~() const;                       // binary not
  BitVector operator<<(const std::size_t pos) const; // left bit shift
  BitVector &operator<<=(const std::size_t pos);     // left bit shift on place
  BitVector operator>>(const std::size_t pos) const; // right bit shift
  BitVector &operator>>=(const std::size_t pos);     // right bit shift on place

  BitVector sliceSE(int start, int end) const; // slice
  BitVector sliceS(int start) const;           // slice that goes to the end
  BitVector sliceE(int end) const;   // slice that start from the start
  BitVector &set();                  // set all true
  BitVector &set(std::size_t pos);   // set element i true
  BitVector &reset();                // set all false
  BitVector &reset(std::size_t pos); // set element i false
  BitVector &flip();                 // flip all element
  BitVector &flip(std::size_t pos);  // flip element i
  std::size_t count() const;         // Count the number of True
  bool all() const;                  // true if all are true
  bool any() const;                  // true if any is true
  bool none() const;                 // true if none are true
};

BitVector operator+(const BitVector &bvl,
                    const BitVector &bvr); // concatenation
BitVector operator&(const BitVector &bvl, const BitVector &bvr); // binary and
BitVector operator|(const BitVector &bvl, const BitVector &bvr); // binary or
BitVector operator^(const BitVector &bvl, const BitVector &bvr); // binary xor
std::ostream &operator<<(std::ostream &os,
                         const BitVector &vec); // print vector

void BitVectorTest();
#endif // BITVECTOR_H