// Oliver Kullmann, 3.12.2015 (Swansea)

/* Various implementations of insertion sort
   The basic idea of insertion sort of a vector v of length n is:
      incrementally sort v[1],...,v[i] for i=1,...,n.
   Sorting of v[i],...,v[i] exploits that v[1],...,v[i-1] is already
   sorted, and just needs to *insert* v[i].

   Version 0 below "inserts" via consecutive swaps, version 1 by shifting.
   The best version (apparently OK's "invention") optimises this, by saving
   on the auxiliary actions.
*/

#ifndef INSERTIONSORT_WEUhALkpF8
#define INSERTIONSORT_WEUhALkpF8

#include <algorithm>

namespace Sort {

  template <class V>
  void insertion0(V& v) {
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
  void insertion(V& v) {
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


}

#endif
