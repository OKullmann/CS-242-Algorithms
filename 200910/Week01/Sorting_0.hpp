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

    /*!
      \brief Sorting (in ascending order) by insertion

      The idea of this elementary algorithm is as follows:
      <ul>
       <li> Given an array A[0], ..., A[A.size()-1], starting with
       i=1, the range A[0], ..., A[j-1] is given as sorted,
       and after the execution of the main loop body the range 
       A[0], ..., A[j] is also sorted (internally). </li>
       <li> This is achieved by storing value A[j] in variable "key",
       and then moving all those elements A[i-1] in A[0], ..., A[j-1]
       one place up (starting from the top, decrementing i) as long as
       A[i-1] > key holds. The final value of i is then the index of the
       free place where key can be inserted (i is as large as possible). </li>
      </ul>

      This is algorithm "Insertion-Sort(A)" from [Cormen, Leiserson, Rivest,
      Stein; 2009], page 18, with the following modifications:
      <ol>
       <li> Arrays in C-based languages (C, C++, Java, Perl, ...) are 0-based,
       not 1-based (as in the book). </li>
       <li> An "array" is best understood as having a compile-time fixed size,
       and thus we use a "vector" (whose size can be dynamically changed).
       </li>
       <li> Index types are in general *unsigned* integral types. Variable i
       in the original algorithm can reach value -1, which doesn't work with
       "size types" or "index types" (since in general they are unsigned,
       i.e., can't take negative values). </li>
       <li> So the value of variable i is moved "one step up". </li>
       <li> That parameter A is a reference parameter (changed "in-place")
       is denoted in C and C++ by using the "&" type-modifier. </li>
       <li> That a variable (like "key") doesn't change it's value after
       definition is encoded in C/C++ by the "const" type-modifier (in Java
       this would be "final"). </li>
       <li> What type of values are in A doesn't matter (most of the
       time), and so we use the type-parameter "value_type". </li>
       <li> Finally the type of the index i (which has nothing to do with
       the value type) is in C++ the "size type" of a container. </li>
      </ol>

      Further remarks:
      <ul>
       <li> The while-loop over i could be more idiomatically written as
       \verbatim
for (; i > 0 and A[i-1] > key; --i) A[i] = A[i-1];
       \endverbatim
       </li>
       <li> The main part of the algorithm then reads:
       \verbatim
for (size_type j = 1; j < A.size(); ++j) {
  const value_type key = A[j];
  size_type i = j;
  for (; i > 0 and A[i-1] > key; --i) A[i] = A[i-1];
  A[i] = key;
}
       \endverbatim
       This is a more succinct expression of the operations. </li>
       <li> The loop over i could also be written as follows:
       \verbatim
for (; i > 0 and A[--i] > key;) A[i+1] = A[i];
       \endverbatim
       or, performing the same operations:
       \verbatim
while (i > 0 and A[--i] > key) A[i+1] = A[i];
       \endverbatim
       which might be the best expression of the idea here. </li>
       <li> Then the main part of the algorithm reads:
       \verbatim
for (size_type j = 1; j < A.size(); ++j) {
  const value_type key = A[j];
  size_type i = j;
  while (i > 0 and A[--i] > key) A[i+1] = A[i];
  A[i] = key;
}
       \endverbatim
       This seems to be the best expression of the idea of insertion-sort.
       </li>
      </ul>
    */

    template <typename value_type>
    void insertion_sort(std::vector<value_type>& A) {
      typedef typename std::vector<value_type>::size_type size_type;
      for (size_type j = 1; j < A.size(); ++j) {
        const value_type key = A[j];
        // Insert A[j] into sorted sequence A[0..j-1]
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
