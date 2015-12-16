// Oliver Kullmann, 16.12.2015 (Swansea)

/* Inplace sorting of small fixed-size arrays

*/

#ifndef SMALL_fCiBIsrRrm
#define SMALL_fCiBIsrRrm

#include <algorithm>

#include <cassert>

namespace Sort {

  template <class V>
  inline void size2(V& v) {
    if (v[0] > v[1]) std::swap(v[0], v[1]);
  }

  template <class V>
  inline void size3(V& v) {
    if (v[0] > v[1]) // 1,0,x
      if (v[2] > v[0]) // 1,0,2
        std::swap(v[0], v[1]); 
      else // 1,x,0
        if (v[2] > v[1]) // 1,2,0
          {const auto t=v[0]; v[0]=v[1]; v[1]=v[2]; v[2]=t;}
        else // 2,1,0
          std::swap(v[0], v[2]);
    else // 0,1,x
      if (v[1] > v[2]) // 0,x,1
        if (v[0] > v[2]) // 2,0,1
          {const auto t=v[0]; v[0]=v[2]; v[2]=v[1]; v[1]=t;}
        else // 0,2,1
          std::swap(v[1], v[2]);
  }

}

#endif
