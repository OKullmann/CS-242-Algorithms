// Oliver Kullmann, 3.12.2015 (Swansea)

/* Various implementations of insertion sort
   The basic idea of insertion sort of a vector v of length n is:
      incrementally sort v[1],...,v[i] for i=1,...,n.
   Sorting of v[i],...,v[i] exploits that v[1],...,v[i-1] is already
   sorted, and just needs to *insert* v[i].

   Version 0 below "inserts" via consecutive swaps, version 1 by shifting.
   Version 2 (apparently OK's "invention") optimises this, by saving
   on the auxiliary actions, and the final version (apparently fastest)
   removes random access, and only exploits bidirectional iterators.
*/

#ifndef INSERTIONSORT_WEUhALkpF8
#define INSERTIONSORT_WEUhALkpF8

#include <algorithm>

namespace Sort {

  template <class V>
  inline void insertion0(V& v) {
    typedef typename V::size_type size_t;
    const size_t size = v.size();
    for (size_t i = 1; i < size; ++i)
      for (size_t j = i; j > 0 and v[j-1] > v[j]; --j) std::swap(v[j], v[j-1]);
  }

  template <class V>
  void insertion1(V& v) {
    typedef typename V::size_type size_t;
    typedef typename V::value_type val_t;
    const size_t size = v.size();
    for (size_t i = 1; i < size; ++i) {
      const val_t x = v[i];
      size_t j;
      for (j = i; j > 0 and v[j-1] > x; --j) v[j] = v[j-1];
      v[j] = x;
    }
  }

  template <class V>
  inline void insertion2(V& v) {
    typedef typename V::size_type size_t;
    typedef typename V::value_type val_t;
    const size_t size = v.size();
    if (size <= 1) return;
    val_t y = v[0];
    for (size_t i = 1; i < size; ++i) {
      const val_t x = v[i];
      if (y > x) {
        v[i] = y;
        size_t j = i-1;
        for (val_t z; j > 0 and (z = v[j-1]) > x; --j) v[j] = z;
        v[j] = x;
      }
      else y = x;
    }
  }

  // More general than funtion insertion, now only requiring bidirection
  // iterators (and not the container):
  template <class It>
  inline void insertion(const It begin, const It end) {
    typedef typename It::value_type val_t;
    if (begin == end) return;
    val_t y = *begin;
    for (It i = begin+1; i != end; ++i) {
      const val_t x = *i;
      if (y > x) {
        *i = y;
        It j = i-1;
        for (val_t z; j != begin and (z = *(j-1)) > x; --j) *j = z;
        *j = x;
      }
      else y = x;
    }
  }

  template <class V>
  inline void insertion(V& v) { insertion(v.begin(), v.end()); }


}

#endif
