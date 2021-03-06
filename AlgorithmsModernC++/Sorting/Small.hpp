// Oliver Kullmann, 16.12.2015 (Swansea)
/* Copyright 2015 Oliver Kullmann
This file is free software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation and included in this library; either version 3 of the License, or
any later version. */

/* Inplace sorting of small fixed-size ranges a,b,...

   More precisely, sorting the first elements of a range, by comparison and
   assignments, where the range is given by a forward-iterator ia to the
   first element.

   It seems reasonable to use only checks of the form "x > y" with x, y one
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

   It seems size3 is considerably faster than an alternative version which
   minimises the two cases with 3 assignments at the expense of needing
   3 comparisons for the sorted cases (and instability): -- why?
   Perhaps the main point is that the empty branch for size3 happens already
   after 2 comparisons, while for the alternative 3 comparisons are needed?!
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
  inline void size2(const It ia) {
    const It ib = ++It(ia);
    const auto a = *ia, b = *ib;
    if (a > b) {*ia=b; *ib=a;}
  }

  // Stably sorting a,..,a+2 :
  template <class It>
  inline void size3(const It ia) {
    const It ib = ++It(ia);
    const It ic = ++It(ib);
    const auto a = *ia, b = *ib, c = *ic;
    if (a > b) // b < a; c
      if (a > c) { // (b,c) < a
         *ic=a;
        if (b > c) // c < b < a
          {*ia=c;}
        else // b <= c < a
          {*ia=b; *ib=c;}
          // if b=c, then only {*ia=c; *ic=a;} is needed (breaking stability)
        }
      else // b < a <= c
        {*ia=b; *ib=a;}
    else // a <= b; c
      if (b > c) { // a <= b; c < b
        *ic=b;
        if (a > c) // c < a <= b
          {*ia=c; *ib=a;}
        else // a <= c <= b
          {*ib=c;}
      }
      // else a <= b <= c
  }

  // Same structure as size3, but updating the elements immediately
  // (this amounts here to insertion-sort):
  template <class It>
  inline void size3_(const It a) {
    const It b = ++It(a);
    const It c = ++It(b);
    auto t = *a;
    if (t > *b) {*a=*b;*b=t;}
    else t = *b;
    if (t > *c) {
      *b=*c;*c=t;
      if (*a > *b) {t=*a;*a=*b;*b=t;}
    }
  }

  // Stably sorting a,..,a+3 (sorting the first three elements as in size3,
  // and then comparing the fourth element to the middle one):
  template <class It>
  inline void size4_(const It ia) {
    const It ib = ++It(ia);
    const It ic = ++It(ib);
    const It id = ++It(ic);
    const auto a = *ia, b = *ib, c = *ic, d = *id;

    if (a > b) //  b < a; c,d
      if (a > c) // (b,c) < a; d
        if (b > c) // c < b < a; d
          if (b > d) { // (c,d) < b < a
            *ic=b; *id=a;
            if (c > d) // d < c < b < a
              {*ia=d; *ib=c;}
            else // c <= d < b < a
              {*ia=c; *ib=d;}
          }
          else { // c < b < a; b <= d
            *ia=c;
            if (a > d) // c < b <= d < a
              {*ic=d; *id=a;}
            else // c < b < a <= d
              {*ic=a;}
          }
        else // b <= c < a; d
          if (c > d) { // b <= c < a; d < c
            *id=a;
            if (b > d) // d < b <= c < a
              {*ia=d;}
            else // b <= d < c < a
              {*ia=b; *ib=d;}
          }
          else { // b <= c < a; c <= d
            *ia=b; *ib=c;
            if (a > d) // b <= c <= d < a
              {*ic=d; *id=a;}
            else // b <= c < a <= d
              {*ic=a;}
          }
      else // b < a <= c; d
        if (a > d) { // b < a <= c; d < a
          *ic=a; *id=c;
          if (b > d) // d < b < a <= c
            {*ia=d;}
          else // b <= d < a <= c
            {*ia=b; *ib=d;}
        }
        else { // b < a <= c; a <= d
          *ia=b; *ib=a;
          if (c > d) // b < a <= d < c
            { *ic=d; *id=c;}
          // b < a <= c <= d
        }
    else // a <= b; c,d
      if (b > c) // a <= b; c < b; d
        if (a > c) // c < a <= b; d
          if (a > d) { // c < a <= b; d < a
            *ic=a; *id=b;
            if (c > d) // d < c < a <= b
              {*ia=d; *ib=c;}
            else // c <= d < a <= b
              {*ia=c; *ib=d;}
          }
          else {// c < a <= (b,d)
            *ia=c; *ib=a;
            if (b > d) // c < a <= d < b
              {*ic=d; *id=b;}
            else // c < a <= b <= d
              {*ic=b;}
          }
        else // a <= c < b; d
          if (c > d) { // a <= c < b; d < c
            *id=b;
            if (a > d) // d < a <= c < b
              {*ia=d; *ib=a;}
            else // a <= d < c < b
              {*ib=d;}
          }
          else { // a <= c < b; c <= d
            *ib=c;
            if (b > d) // a <= c <= d < b
              {*ic=d; *id=b;}
            else // a <= c < b <= d
              {*ic=b;}
          }
      else // a <= b <= c; d
        if (b > d) { // a <= b <= c; d < b
          *ic=b; *id=c;
          if (a > d) // d < a <= b <= c
            {*ia=d; *ib=a;}
          else // a <= d < b <= c
            {*ib=d;}
        }
        else // a <= b <= c; b <= d
          if (c > d) // a <= b <= d < c
            {*ic=d; *id=c;}
          // a <= b <= c <= d
  }

  // Same structure as size4_, but updating the elements immediately:
  template <class It>
  inline void size4_1(const It a) {
    size3(a);
    const It b = ++It(a);
    const It c = ++It(b);
    const It d = ++It(c);
    const auto t = *d;
    if (*b > t) {
      *d=*c; *c=*b;
      if (*a > t) {*b=*a;*a=t;}
      else {*b=t;}
    }
    else if (*c > t) {*d=*c;*c=t;}
  }
  /* Remark: Using size3_(a) here instead of its code currently doubles
  the run-time (gcc 4.7.x), but that should be a weakness of the compiler. */

  // Stably sorting a,..,a+3, using max-min-computation with additional
  // short-cut:
  template <class It>
  inline void size4(const It ia) {
    const It ib = ++It(ia);
    const It ic = ++It(ib);
    const It id = ++It(ic);
    const auto a = *ia, b = *ib, c = *ic, d = *id;

    if (a > b) // b < a; c,d
      if (c > d) // b < a, d < c
        if (a > d) // b < a, d < (c,a); shortcut to ordered case
          if (b > d) { // d < b < a; d < c
            *ia = d;
            if (a > c) { // d < b < a, c < a
              *id = a;
              if (b > c) // d < c < b < a
                {*ib=c; *ic=b;}
              // d < b <= c < a
            }
            else // d < b < a <= c
              {*ic=a; *id=c;}
          }
          else { // b <= d < (a,c)
            *ia = b; *ib = d;
            if (a > c) // b <= d < c < a
              {*id=a;}
            else // b <= d < a <= c
              {*ic=a; *id=c;}
          }
        else // b < a <= d < c
          {*ia=b; *ib=a; *ic=d; *id=c;}
      else // b < a, c <= d
        if (a > c) // (b,c) < a, c <= d
          if (a > d) { // (b,c,d) < a, c <= d
            *id = a;
            if (b > c) { // c < b < a, c <= d < a
              *ia = c;
              if (b > d) // c <= d < b < a
                {*ib=d; *ic=b;}
              else // c < b <= d < a
                {*ic=d;}
            }
            else // b <= c <= d < a
              {*ia=b; *ib=c; *ic=d;}
          }
          else { // (b,c) < a <= d
            *id = d;
            if (b > c) // c < b < a <= d
              {*ia=c; *ic=a;}
            else // b <= c < a <= d
              {*ia=b; *ib=c; *ic=a;}
          }
        else // b < a <= c <= d
          {*ia=b; *ib=a;}
    else // a <= b; c,d
      if (c > d) // a <= b, d < c
        if (b > d) // a <= b, d < (b,c)
          if (b > c) { // a <= b, d < c < b
            *id = b;
            if (a > d) { // d < a <= b, d < c < b
              *ia = d;
              if (a > c) // d < c < a <= b
                {*ib=c; *ic=a;}
              else // d < a <= c < b
                {*ib=a;}
            }
            else // a <= d < c < b
              {*ib=d;}
          }
          else { // a <= b <= c, d < b
            *id = c;
            if (a > d) // d < a <= b <= c
              {*ia=d; *ib=a; *ic=b;}
            else // a <= d < b <= c
              {*ib=d; *ic=b;}
          }
        else // a <= b <= d < c
          {*ic=d; *id=c;}
      else // a <= b, c <= d
        if (b > c) // a <= b, c < b, c <= d
          if (b > d) { // a <= b, c <= d < b
            *id = b;
            if (a > c) { // c < a <= b, c <= d < b
              *ia = c;
              if (a > d) // c <= d < a <= b
                {*ib=d; *ic=a;}
              else // c < a <= d < b
                {*ib=a; *ic=d;}
            }
            else // a <= c <= d < b
              {*ib=c; *ic=d;}
          }
          else { // a <= b <= d, c < b
            *ic = b;
            if (a > c) // c < a <= b <= d
              {*ia=c; *ib=a;}
            else // a <= c < b <= d
              {*ib=c;}
          }
        // a <= b <= c <= d
  }

}

#endif
