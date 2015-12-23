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
#include <iostream>

namespace Sort {

  // The simplest expression:
  template <class It>
  inline void selection0(const It begin, const It end) {
    for (It i = begin; i != end; ++i) std::swap(*i, *std::min_element(i, end));
  }
  template <class V>
  inline void selection0(V& v) { selection0(v.begin(), v.end()); }

  /* Remark: This code is four time more efficient than
  template <class It>
  inline void selection0(const It begin, const It end) {
    for (It i = begin; i != end; ++i) {
      const It j = std::min_element(i, end);
      if (j != i) std::swap(*i,*j);
    }
  }
  and double as efficient as selection1, for longer sequences.
  It seems the main point is the missing case-distinction on i ! */


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


  // The most basic expression of "bi-selection":
  template <class It>
  inline void selection_bi_0(It begin, It end) {
    auto size = (end - begin) / 2;
    if (size == 0) return;
    It endm1 = --It(end);
    do {
      const auto mima = std::minmax_element(begin,end);
      std::swap(*begin, *mima.first);
      std::swap(*endm1, (mima.second==begin) ? *mima.first : *mima.second);
      ++begin; end = endm1--;
    } while (--size != 0);
  }
  template <class V>
  inline void selection_bi_0(V& v) { selection_bi_0(v.begin(), v.end()); }

  // Selecting min-max at once, with pre-sorting pairs:
  template <class It>
  inline void selection_bi(It begin, It end) {
    auto size = end - begin;
    if (size <= 1) return;
    It beginp1 = begin; ++beginp1;
    if (size % 2 == 0)
      for (It i=begin,j=begin; i!=end; i=++j) {if(*i>*++j) std::swap(*i, *j);}
    else {
      for (It i=beginp1,j=beginp1; i!=end; i=++j) if(*i>*++j) std::swap(*i,*j);
      const auto vbegin = *begin;
      auto min = vbegin; It opt = begin;
      for (It i = beginp1; i != end; ++i) if (*i < min) {min=*i; opt=i; ++i;}
      if (opt != begin) {
        *begin = min, *opt = vbegin;
        const It optp1 = ++It(opt); const auto voptp1 = *optp1;
        if (vbegin > voptp1) {*opt=voptp1; *optp1=vbegin;}
      }
      begin = beginp1++;
    }
    if (size <= 3) return;
    It endm1 = end; --endm1;
    size /= 4;
    do {
      {
        const auto first = *begin;
        It min_i = begin, max_i = beginp1;
        auto min = first, max = *max_i;
        for (It i = ++It(beginp1); i != end; ++i) {
          if (*i < min) { min = *i; min_i = i; }
          if (*++i > max) { max = *i; max_i = i; }
        }
        if (min == max) return;
        if (min_i != begin) {
          *begin = min;
          const It min_ip1 = ++It(min_i); const auto vmin_ip1 = *min_ip1;
          if (first > vmin_ip1) {*min_i = vmin_ip1; *min_ip1 = first;}
          else *min_i = first;
        }
        if (max_i != endm1) {
          const auto last = *endm1;
          *endm1 = max;
          const It max_im1 = --It(max_i); const auto vmax_im1 = *max_im1;
          if (last < vmax_im1) {*max_im1 = last; *max_i = vmax_im1;}
          else *max_i = last;
        }
      }
      begin = beginp1++; end = endm1--;
      {
        if (*begin > *endm1) std::swap(*begin, *endm1);
        const auto first = *begin, last = *endm1;
        It min_i = begin, max_i = endm1;
        auto min = first, max = last;
        for (It i = beginp1; i != endm1; ++i) {
          if (*i < min) { min = *i; min_i = i; }
          if (*++i > max) { max = *i; max_i = i; }
        }
        if (min == max) return;
        if (min_i != begin) {
          *begin = min;
          const It min_ip1 = ++It(min_i); const auto vmin_ip1 = *min_ip1;
          if (first > vmin_ip1) {*min_i = vmin_ip1; *min_ip1 = first;}
          else *min_i = first;
        }
        if (max_i != endm1) {
          *endm1 = max;
          const It max_im1 = --It(max_i); const auto vmax_im1 = *max_im1;
          if (last < vmax_im1) {*max_im1 = last; *max_i = vmax_im1;}
          else *max_i = last;
        }
      }
      begin = beginp1++; end = endm1--;
    } while (--size != 0);
  }
  template <class V>
  inline void selection_bi(V& v) { selection_bi(v.begin(), v.end()); }

}

#endif
