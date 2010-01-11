// Oliver Kullmann, 22.12.2009 (Swansea)

/*!
  \file 200910/Week01/Sorting.hpp
  \brief Sorting algorithms
*/

#ifndef SORTING_nBval9R45
#define SORTING_nBval9R45

#include <vector>
#include <algorithm>

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

    template <typename value_type>
    void permutation_sort(std::vector<value_type>& A) {
      IntroAlgo::Framework::OutputMeasurement om;
      typedef typename std::vector<value_type>::size_type size_type;
      size_type counter_assignments = 0;
      size_type counter_comparisons = 0;

      size_type n = A.size();
      std::vector<size_type> P(n);
      for (size_type j = 0; j < n; ++j) 
	P[j]=n-j-1;
      bool test = false;

      while (not test) {
	test = true;
	for (size_type j = 1; j < n; ++j) {
	  if (A[P[j-1]] > A[P[j]]) test = false;
	  ++counter_assignments;
	}
	std::next_permutation(P.begin(), P.end());
      }
      std::prev_permutation(P.begin(), P.end());

      std::vector<value_type> Acopy (A);
      for (size_type j = 0; j < n; ++j) 
	A[j] = Acopy[P[j]];

      om << A.size() << counter_assignments << counter_comparisons;
    }

  }
}

#endif
