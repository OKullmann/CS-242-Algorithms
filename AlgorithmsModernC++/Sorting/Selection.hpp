// Oliver Kullmann, 20.12.2015 (Swansea)
/* Copyright 2015 Oliver Kullmann
This file is free software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation and included in this library; either version 3 of the License, or
any later version. */


/* Various implementations of selection sort

   The basic idea of selection sort of a vector v of length n is:
      determine v[i] for i=1,...,n-1 as the minimum of v[i],...,v[n-1].

   See also https://en.wikipedia.org/wiki/Selection_sort .
*/

#ifndef SELECTION_kZxNktA2Du
#define SELECTION_kZxNktA2Du

#include <algorithm>

namespace Sort {

  // The simplest expression:
  template <class It>
  inline void selection0(const It begin, const It end) {
    for (It i = begin; i != end; ++i) {
      const It j = std::min_element(i, end);
      if (j != i) std::swap(*i,*j);
    }
  }
  template <class V>
  inline void selection0(V& v) { selection0(v.begin(), v.end()); }


  template <class It>
  inline void selection1(const It begin, const It end) {
    for (It i = begin; i != end; ++i) {
      auto min = *i; It opt = i;
      for (It j = ++It(i); j != end; ++j)
        if (*j < min) { min = *j; opt = j;}
      if (opt != i) std::swap(*i,*opt);
    }
  }
  template <class V>
  inline void selection1(V& v) { selection1(v.begin(), v.end()); }

}

#endif
