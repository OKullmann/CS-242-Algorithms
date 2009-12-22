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
    void selection_sort(std::vector<value_type>& V) {
      
    }

    template <typename value_type>
    void insertion_sort(std::vector<value_type>& A) {
      IntroAlgo::Framework::OutputMeasurement om;
      typedef typename std::vector<value_type>::size_type size_type;
      size_type counter_assignments = 0;
      size_type counter_comparisons = 0;
      for (size_type j = 1; j < A.size(); ++j) {
        const value_type key = A[j];
        ++counter_assignments;
        size_type i = j;
        for (; i > 0; --i) {
          ++counter_comparisons;
          if (not (A[i-1] > key)) break;
          A[i] = A[i-1];
          ++counter_assignments;
        }
        A[i] = key;
        ++counter_assignments;
      }
      om << A.size() << counter_assignments << counter_comparisons;
    }

  }
}

#endif
