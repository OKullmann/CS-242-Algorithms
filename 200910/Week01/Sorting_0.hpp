// Oliver Kullmann, 22.12.2009 (Swansea)

/*!
  \file 200910/Week01/Sorting.hpp
  \brief Sorting algorithms
*/

#ifndef SORTING_nBval9R45
#define SORTING_nBval9R45

#include <vector>

#include <200910/Framework/Measurement.hpp>

namespace IntroAlgo {
  namespace Week01 {

    template <typename value_type>
    void insertion_sort(std::vector<value_type>& A) {
      typedef typename std::vector<value_type>::size_type size_type;
      for (size_type j = 1; j < A.size(); ++j) {
        const value_type key = A[j];
        size_type i = j;
        while (i > 0 and A[i-1] > key) {
          A[i] = A[i-1];
          i = i-1;
        }
        A[i] = key;
      }
    }

  }
}

#endif
