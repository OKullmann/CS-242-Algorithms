// Oliver Kullmann, 16.12.2015 (Swansea)
/* Copyright 2015 Oliver Kullmann
This file is free software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation and included in this library; either version 3 of the License, or
any later version. */

/* Inplace sorting of small fixed-size ranges

   More precisely, sorting the first elements of a range, by comparison and
   assignments, where the range is given by a forward-iterator to the
   first element.

   It seems reasonable to use only checks of the form "vx > vy" with x, y one
   of a,b,..., and with x lexicographically before y, that is, checking
   "out-of-order".

   TODO: Can we always achieve stability, while using the minimum maximal
   number of comparisons? sort3 below is stable, and it seems by the above
   checks "out-of-order" we guarantee stability.

   As the array [1,0,0] shows, when stability is required, then more
   assignments are needed in general (the stable solution performs a
   cyclic left-shift, the non-stable solution just needs to swap first
   and last element).

   TODO: Formulate and prove some form of optimality.
   At least the algorithm should use the minimum maximal number of comparison.
   And assignments should be performed only if necessary -- however that might
   need additional comparisons?

   It seems size3 is considerably faster than size3_ -- why?
   Perhaps the main point is that the empty branch for size3 happens already
   after 2 comparisons, while for size3_ 3 comparisons are needed?!
   One should count the number of comparisons and assignments over all
   testcases.

   TODO: Which of <, <= is fastest?
   Apparently, according to
   http://stackoverflow.com/questions/12135518/is-faster-than ,
   both should be considered as equally fast, and then we can use whatever
   is more appropriate -- is there ever any difference?

*/

#ifndef SMALL_fCiBIsrRrm
#define SMALL_fCiBIsrRrm

namespace Sort {

  // Stably sorting a,..,a+1 :
  template <class It>
  inline void size2(const It a) {
    const It b = ++It(a);
    const auto va = *a, vb = *b;
    if (va > vb) {*a=vb; *b=va;}
  }

  // Stably sorting a,..,a+2 :
  template <class It>
  inline void size3(const It a) {
    const It b = ++It(a);
    const It c = ++It(b);
    const auto va = *a, vb = *b, vc = *c;
    if (va > vb) // 1<0,x
      if (va > vc) // 1,x<0
        if (vb > vc) // 2<1<0
          {*a=vc; *c=va;}
        else // 1<=2<0
          {*a=vb; *b=vc; *c=va;}
          // if vb=vc, then only {*a=vc; *c=va;} is needed (breaking stability)
      else // 1<0<=2
        {*a=vb; *b=va;}
    else // 0<=1,x
      if (vb > vc) // 0,x<1
        if (va > vc) // 2<0<1
          {*a=vc; *b=va; *c=vb;}
        else // 0<=2<1
          {*b=vc; *c=vb;}
      // else 0<=1<=2
  }

  // Minimising the two cases with 3 assignments (at the expense as needing
  // 3 comparisons for the sorted cases, and unstability):
  template <class It>
  inline void size3_(const It a) {
    const It b = ++It(a);
    const It c = ++It(b);
    const auto va = *a, vb = *b, vc = *c;
    if (vb < vc) {
      if (vc < va) {*a=vb; *b=vc; *c=va;}
      else if (vb < va) {*a=vb; *b=va;}
    } else
      if (va < vb)
        if (vc < va) {*a=vc; *b=va; *c=vb;}
        else {*b=vc; *c=vb;}
      else {*a=vc; *c=va;}
  }

}

#endif
