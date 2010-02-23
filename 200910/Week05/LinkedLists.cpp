// Oliver Kullmann, 22.2.2010 (Swansea)

/*!
  \file LinkedLists.cpp
  \brief Application for testing and running LinkedLists.hpp
*/

#include <iostream>
#include <sstream>

#include "LinkedLists.hpp"
#include "Framework.hpp"

namespace {

  enum { errcode_parameter = 1, errcode_parameter_reading = 2 };

  const std::string program = "LinkdedLists";
  const std::string err = "ERROR[" + program + "]: ";

  typedef int value_type;

  typedef DisjointSets::LinkedLists<value_type> SimpleDisjointSets;
  typedef DisjointSets::Framework<SimpleDisjointSets> Framework;

  typedef Framework::disjoint_sets_type disjoint_sets_type;
  typedef Framework::pointer_type pointer_type;
  typedef Framework::size_type size_type;

}

int main(const int argc, const char* const argv[]) {

  if (argc != 2) {
    std::cerr << err << "Exactly one parameter is needed, the number of items.\n";
    return errcode_parameter;
  }

  size_type dummy;
  {
    std::stringstream parameters;
    parameters << argv[1];
    parameters >> dummy;
    if (not parameters) {
      std::cerr << err << "Error when reading the parameter, the number of items (which must be a non-negative integer).\n";
      return errcode_parameter_reading;
    }
  }
  const size_type N = dummy;

  Framework F(N);
  std::cout << F << "\n";

  for (;;) {
    size_type v1, v2;
    if (not (std::cin >> v1 >> v2)) break;
    if (v1 >= N or v2 >= N) break;
    const pointer_type
      p1 = disjoint_sets_type::find_set(F[v1]),
      p2 = disjoint_sets_type::find_set(F[v2]);
    std::cout << "Cell for " << v1 << ":\n" << p1 << "\n";
    std::cout << "Cell for " << v2 << ":\n" << p2 << "\n";
    if (p1 != p2) {
      std::cout << "Both sets are different, thus union is performed.\n";
      disjoint_sets_type::union_sets(p1,p2);
      std::cout << "Now the whole data structure is as follows:\n" << F << "\n";
    }
  }
}
