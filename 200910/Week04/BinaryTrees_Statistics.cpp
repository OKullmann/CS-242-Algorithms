// Oliver Kullmann, 17.2.2010 (Swansea)

/*!
  \file BinaryTree_Statistics.cpp
  \brief Create binary search trees randomly for n from 1 to N, each time with t tries, and outputs the height
*/

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

#include "BinaryTrees.hpp"

namespace {

  enum { errcode_parameter = 1, errcode_parameter1 = 2, errcode_parameter2 = 3,
         errcode_generator = 4 };
        
  const std::string program = "BinaryTree_Statistics";
  const std::string err = "ERROR[" + program + "]: ";

  typedef unsigned int uint_type;

}

int main(const int argc, const char* const argv[]) {

  if (argc != 3) {
    std::cerr << err << "Exactly two parameters are needed, N and t.\n";
    return errcode_parameter;
  }

  uint_type dummy;
  {
    std::stringstream parameters;
    parameters << argv[1];
    parameters >> dummy;
    if (not parameters) {
      std::cerr << err << "Error when reading the first parameter, the maximal number of items (which must be an unsigned integer).\n";
      return errcode_parameter1;
    }
  }
  const uint_type N = dummy;
  {
    std::stringstream parameters;
    parameters << argv[2];
    parameters >> dummy;
    if (not parameters) {
      std::cerr << err << "Error when reading the second parameter, the number t of tries (which must be an unsigned integer).\n";
      return errcode_parameter2;
    }
  }
  const uint_type t = dummy;

  std::cout << " n h\n";
  uint_type total_count = 0;
  for (uint_type i = 1; i <= N; ++i) {
    for (uint_type j = 1; j <= t; ++j) {
      BinaryTrees::Tree T; ++total_count;
      for (uint_type k = 1; k <= i; ++k) {
        const BinaryTrees::key_type r = std::rand() % i;
        T.insert(r, (BinaryTrees::satellite_type) k);
      }
      std::cout << total_count << " " << i << " " << T.height() << "\n";
    }
  }
}
