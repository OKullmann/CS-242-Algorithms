// Oliver Kullmann, 16.12.2015 (Swansea)

/* Inplace sorting of small fixed-size arrays

   As the array [1,0,0] shows, when stability is required, then more
   assignments are needed; thus the algorithms below for >= 3 elements
   are not stable.

   TODO: Can size3 be improved? It seems the logic could be streamlined.

*/

#ifndef SMALL_fCiBIsrRrm
#define SMALL_fCiBIsrRrm

#include <algorithm>

namespace Sort {

  template <class V>
  inline void size2(V& v) {
    if (v[0] > v[1]) std::swap(v[0], v[1]);
  }

  template <class V>
  inline void size3_(V& v) {
    if (v[0] > v[1]) // 1<0,x
      if (v[2] > v[0]) // 1<0<2
        std::swap(v[0], v[1]); 
      else // 1,x<=0
        if (v[2] > v[1]) // 1<2<=0
          {const auto t=v[0]; v[0]=v[1]; v[1]=v[2]; v[2]=t;}
        else // 2<=1<0
          std::swap(v[0], v[2]);
    else // 0<=1,x
      if (v[1] > v[2]) // 0,x<1
        if (v[0] > v[2]) // 2<0<=1
          {const auto t=v[0]; v[0]=v[2]; v[2]=v[1]; v[1]=t;}
        else // 0<=2<=1
          std::swap(v[1], v[2]);
  }

  // Same as size3_, but now just using forward iterators:
  template <class It>
  inline void size3(const It begin, const It end) {
    const It a = begin;
    const It b = ++It(begin);
    const It c = ++It(b);
    const auto va = *a, vb = *b, vc = *c;
    if (va > vb) // 1,0,x
      if (vc > va) // 1,0,2
        {*a=vb; *b=va;}
      else // 1,x,0
        if (vc > vb) // 1,2,0
          {*a=vb; *b=vc; *c=va;}
        else // 2,1,0
          {*a=vc; *c=va;}
    else // 0,1,x
      if (*b > *c) // 0,x,1
        if (*a > *c) // 2,0,1
          {*a=vc; *b=va; *c=vb;}
        else // 0,2,1
          {*b=vc; *c=vb;}
  }

  template <class V>
  inline void size3(V& v) { return size3(v.begin(), v.end()); }

}

#endif
