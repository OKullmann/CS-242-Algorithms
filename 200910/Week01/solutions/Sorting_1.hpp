// Arnold Beckmann, 17.12.2009 (Swansea)
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

    void insertion_sort(std::vector<int>& A) {
      /// IntroAlgo::Framework::OutputMeasurement om;
      unsigned int i,j;
      int key;
      bool condition;
      /// unsigned int counter_comparisons = 0;
      for (j = 1; j < A.size(); j++) {
        key = A[j];
        i = j;
	condition = true;
	while (i > 0 and condition) {
          /// ++counter_comparisons;
          if (A[i-1] > key) {
	    A[i] = A[i-1];
	    i = i-1;
	  } else {
	    condition = false;
	  }
        }
        A[i] = key;
      }
      /// om << A.size() << counter_comparisons;
    }

  }
}

#endif
