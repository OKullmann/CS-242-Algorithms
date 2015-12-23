// Oliver Kullmann, 22.12.2015 (Swansea)
/* Copyright 2015 Oliver Kullmann
This file is free software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation and included in this library; either version 3 of the License, or
any later version. */


/* Various generators for sequences, for testing sorting algorithms

*/

#ifndef GENERATORS_0sF8SXkCTU
#define GENERATORS_0sF8SXkCTU

#include <vector>
#include <limits>

#include <cassert>

namespace Sort {

  typedef std::vector<int> vec_t;
  typedef vec_t::size_type Large;

  void increasing(vec_t& v, const Large s) {
    assert(s < std::numeric_limits<int>::max());
    v.reserve(s);
    v.resize(0);
    for (Large i = 0; i < s; ++i) v.push_back(i);
  }

  void decreasing(vec_t& v, const Large s) {
    assert(s <= std::numeric_limits<int>::max());
    v.reserve(s);
    v.resize(0);
    for (Large i = 0; i < s; ++i) v.push_back(s - i);
  }

}

#endif
