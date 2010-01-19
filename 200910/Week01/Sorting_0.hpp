// Arnold Beckmann, 18.01.2009 (Swansea)

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

    /*!
      \brief Sorting (in ascending order) by insertion

      The idea of this elementary algorithm is as follows:
      
       * Given an array A[0], ..., A[A.size()-1], starting with
         j=1, the range A[0], ..., A[j-1] is given as sorted,
         and after the execution of the main loop body the range 
         A[0], ..., A[j] is also sorted (internally).
       * This is achieved by storing value A[j] in variable "key",
         and then moving all those elements A[i-1] in A[0], ..., A[j-1]
         one place up (starting from the top, decrementing i) as long as
         A[i-1] > key holds. The final value of i is then the index of the
         free place where key can be inserted (i is as large as possible). 

      This is algorithm "Insertion-Sort(A)" from [Cormen, Leiserson, Rivest,
      Stein; 2009], page 18, with the following modifications:
      
       * Arrays in C-based languages (C, C++, Java, Perl, ...) are 0-based,
         not 1-based (as in the book).
       * An "array" is best understood as having a compile-time fixed size,
         and thus we use a "vector" (whose size can be dynamically changed).
       * Index types are in general *unsigned* integral types. Variable i
         in the original algorithm can reach value -1, which doesn't work with
         "size types" or "index types" (since in general they are unsigned,
         i.e., can't take negative values).
       * So the value of variable i is moved "one step up".
       * That parameter A is a reference parameter (changed "in-place")
         is denoted in C and C++ by using the "&" type-modifier.
       * That a variable (like "key") doesn't change it's value after
         definition is encoded in C/C++ by the "const" type-modifier (in Java
         this would be "final").
    */

    void insertion_sort(std::vector<int>& A) {
	int key;
	unsigned int i,j;

      for (j = 1; j < A.size(); j++) {
        key = A[j];
        i = j;
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
