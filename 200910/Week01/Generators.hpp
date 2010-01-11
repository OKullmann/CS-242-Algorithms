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

    /*!
      \class ArrayGenerators
      \brief Wrapper for various array generators
    */
    struct ArrayGenerators {
      typedef unsigned int value_type;
      typedef std::vector<value_type> vector_type;

      static vector_type sorted(const value_type n) {
        vector_type A(n);
        for (value_type i = 1; i < n; ++i)
          A[i] = i;
        return A;
      }

      static vector_type sorted_r(const value_type n) {
        vector_type A(n);
        for (value_type i = 1; i < n; ++i)
          A[i] = n-i;
        return A;
      }

    };

  }
}

#endif
