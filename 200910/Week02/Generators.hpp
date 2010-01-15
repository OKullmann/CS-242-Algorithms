// Oliver Kullmann, 22.12.2009 (Swansea)

/*!
  \file 200910/Week01/Generators.hpp
  \brief Generators for input of sorting algorithms
*/

#ifndef GENERATORS_973TvF42O
#define GENERATORS_973TvF42O

#include <vector>
#include <time.h>

namespace IntroAlgo {
  namespace Week01 {

    /*!
      \class ArrayGenerators
      \brief Wrapper for various array generators
    */
    struct ArrayGenerators {
      typedef unsigned int size_type;
      typedef int value_type;
      typedef std::vector<value_type> vector_type;

      static vector_type sorted(const size_type n) {
        vector_type A(n);
        for (size_type i = 1; i < n; ++i)
          A[i] = i;
        return A;
      }

      static vector_type sorted_r(const size_type n) {
        vector_type A(n);
        for (size_type i = 1; i < n; ++i)
          A[i] = n-i;
        return A;
      }

      static vector_type random(const size_type n) {
        vector_type A(n);
	int rnumb;
	/* initialize random seed: */
	srand ( time(NULL) );
        for (size_type i = 1; i < n; ++i) {
	  /* generate random number in [0..10n] */
	  rnumb = rand() % (10 * n) - 5 * n;
          A[i] = rnumb;
	}
        return A;
      }

    };

  }
}

#endif
