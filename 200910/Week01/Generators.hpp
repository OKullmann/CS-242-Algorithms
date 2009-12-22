// Oliver Kullmann, 22.12.2009 (Swansea)

/*!
  \file 200910/Week01/Generators.hpp
  \brief Generators for input of sorting algorithms
*/

#ifndef GENERATORS_973TvF42O
#define GENERATORS_973TvF42O

#include <vector>

namespace IntroAlgo {
  namespace Week01 {

    std::vector<int> sorted(const unsigned int n) {
      std::vector<int> A(n);
      for (std::vector<int>::size_type i = 1; i < n; ++i)
        A[i] = i;
      return A;
    }

  }
}

#endif
