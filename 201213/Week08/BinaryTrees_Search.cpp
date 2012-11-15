// Oliver Kullmann, 16.2.2010 (Swansea)

/*!
  \file BinaryTree_Search.cpp
  \brief Create a binary search tree and search for an element

  Takes two parameter, N and c, where N is a natural number and c is 0 or 1.
  N is the number of keys created, "0" means the keys are the numbers from 1
  to N (in this order), "1" means that the numbers are (pseudo-)random
  numbers from 0 to N-1.

  The running time and the height of the tree is output. Then in a loop
  keys can be queried, and the satellite-count is output (if found) together
  with the time the query took.
*/

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include "BinaryTrees.hpp"

namespace {

  enum { errcode_parameter = 1, errcode_parameter1 = 2, errcode_parameter2 = 3,
         errcode_generator = 4 };
        
  const std::string program = "BinaryTree_Search";
  const std::string err = "ERROR[" + program + "]: ";

  typedef BinaryTrees::Tree::int_type int_type;

  enum Generator_codes { ascending = 0, pseudorandom = 1 };
  const int number_generators = 2;
  static const long eps = CLOCKS_PER_SEC;

}

int main(const int argc, const char* const argv[]) {

  if (argc != 3) {
    std::cerr << err << "Exactly two parameters are needed, the number of items, and the generator-type (\"0\" or \"1\").\n";
    return errcode_parameter;
  }

  int dummy;
  {
    std::stringstream parameters;
    parameters << argv[1];
    parameters >> dummy;
    if (not parameters) {
      std::cerr << err << "Error when reading the first parameter, the number of items (which must be an integer).\n";
      return errcode_parameter1;
    }
  }
  const int_type N = dummy;
  {
    std::stringstream parameters;
    parameters << argv[2];
    parameters >> dummy;
    if (not parameters) {
      std::cerr << err << "Error when reading the second parameter, the generator type (which must be an integer).\n";
      return errcode_parameter2;
    }
  }
  if (dummy < 0 or dummy >= number_generators) {
    std::cerr << err << "The generator type must be 0 or 1.\n";
    return errcode_generator;
  }
  const Generator_codes g = (Generator_codes) dummy;

  using BinaryTrees::key_type;
  using BinaryTrees::satellite_type;
  BinaryTrees::Tree T;
  std::clock_t old_time = std::clock();
  switch (g) {
  case ascending :
    for (int_type i = 1; i <= N; ++i)
      T.insert((key_type) i, (satellite_type) i);
    break;
  case pseudorandom :
    for (int_type i = 1; i <= N; ++i) {
      const key_type r = std::rand() % N;
      T.insert(r, (satellite_type) i);
    }
  }

  std::clock_t used_time = std::clock() - old_time;
  std::cout << "User time usage: " << std::scientific << std::showpoint << std::setprecision(2) << (double) used_time / eps << "s\n";
  std::cout << "Height = " << T.height() << "\n";

  std::cout << "\nSearching for keys:\n";
  for (;;) {
    key_type k;
    if (not (std::cin >> k)) break;
    old_time = std::clock();
    const BinaryTrees::Tree::public_node_type p = T.search(k);
    used_time = std::clock() - old_time;
    std::cout << "User time usage: " << (double) used_time / eps << "s\n";
    if (p == 0) std::cout << "key not found\n";
    else std::cout << "count = " << p->s << "\n";
  }
}
