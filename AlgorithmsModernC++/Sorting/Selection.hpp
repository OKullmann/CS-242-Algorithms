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


  // Selecting min-max at once, with pre-sorting pairs:
  template <class It>
  inline void selection_bi(It begin, It end) {
    auto size = end - begin;
    if (size <= 1) return;
    if (size % 2 != 0) {
      auto min = *begin; It opt = begin;
      for (It i = ++It(begin); i != end; ++i) if (*i < min) {min=*i; opt=i;}
      std::swap(*(begin++), *opt);
    }
    for (It i=begin, j=begin; i!=end; i=++j) if (*i > *++j) std::swap(*i, *j);
    if (size <= 3) return;
    bool align = true;
    It beginp1 = begin; ++beginp1;
    It endm1 = end; --endm1;
    size += 2; size /= 3;
    do {
      if (align) {
        It i = begin; It j = beginp1;
        It min_i = i, max_i = j;
        auto min = *min_i, max = *max_i;
        i = ++j;
        while (i != end) {
          ++j;
          if (*i < min) { min = *i; min_i = i; }
          if (*j > max) { max = *j; max_i = j; }
          i = ++j;
        }
        if (min == max) return;
        if (min_i != begin) {
          std::swap(*min_i, *begin);
          if (*min_i > *(++It(min_i))) std::swap(*min_i, *(++It(min_i)));
        }
        if (max_i == begin) {max_i = min_i; ++max_i;}
        if (max_i != endm1) {
          std::swap(*max_i, *endm1);
          if (*max_i < *(--It(max_i))) std::swap(*max_i, *(--It(max_i)));
        }
      }
      else {
        if (*begin > *endm1) std::swap(*begin, *endm1);
        It min_i = begin, max_i = endm1;
        auto min = *min_i, max = *max_i;
        It i = beginp1, j = i;
        while (i != endm1) {
          ++j;
          if (*i < min) { min = *i; min_i = i; }
          if (*j > max) { max = *j; max_i = j; }
          i = ++j;
        }
        if (min == max) return;
        if (min_i != begin) {
          std::swap(*min_i, *begin);
          if (*min_i > *(++It(min_i))) std::swap(*min_i, *(++It(min_i)));
        }
        if (max_i == begin) {max_i = min_i; ++max_i;}
        if (max_i != endm1) {
          std::swap(*max_i, *endm1);
          if (*max_i < *(--It(max_i)))
            std::swap(*max_i, *(--It(max_i)));
        }
      }
      align = !align;
      begin = beginp1++; end = endm1--;
    } while (--size != 0);
  }
  template <class V>
  inline void selection_bi(V& v) { selection_bi(v.begin(), v.end()); }

}

#endif
