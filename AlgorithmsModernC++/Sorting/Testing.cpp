// Oliver Kullmann, 3.12.2015 (Swansea)
/* Copyright 2015 Oliver Kullmann
This file is free software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation and included in this library; either version 3 of the License, or
any later version. */

#include <vector>
#include <algorithm>

#include <cassert>

#include "Insertion.hpp"
#include "Small.hpp"
#include "Selection.hpp"

namespace {

typedef std::vector<int> vec_t;

void test_insertion(const vec_t& v) {
  vec_t s(v);
  std::sort(s.begin(), s.end());
  {vec_t c(v); Sort::insertion0(c); assert(c == s);}
  {vec_t c(v); Sort::insertion1(c); assert(c == s);}
  {vec_t c(v); Sort::insertion2(c); assert(c == s);}
  {vec_t c(v); Sort::insertion3(c); assert(c == s);}
  {vec_t c(v); Sort::insertion(c); assert(c == s);}
}

void test_selection(const vec_t& v) {
  vec_t s(v);
  std::sort(s.begin(), s.end());
  {vec_t c(v); Sort::selection0(c); assert(c == s);}
  {vec_t c(v); Sort::selection1(c); assert(c == s);}
  {vec_t c(v); Sort::selection_bi(c); assert(c == s);}
}

void test_2(const vec_t& v) {
  vec_t s(v);
  std::sort(s.begin(), s.end());
  {vec_t c(v); Sort::size2(c.begin()); assert(c == s);}
}

void test_3(const vec_t& v) {
  vec_t s(v);
  std::sort(s.begin(), s.end());
  {vec_t c(v); Sort::size3(c.begin()); assert(c == s);}
  {vec_t c(v); Sort::size3_(c.begin()); assert(c == s);}
}

void test_4(const vec_t& v) {
  vec_t s(v);
  std::sort(s.begin(), s.end());
  {vec_t c(v); Sort::size4(c.begin()); assert(c == s);}
  {vec_t c(v); Sort::size4_(c.begin()); assert(c == s);}
  {vec_t c(v); Sort::size4_1(c.begin()); assert(c == s);}
}


}

int main(const int argc, const char* const argv[]) {

  test_insertion(vec_t{{}});
  test_insertion(vec_t{{3,5,1,7,9,2}});
  for (int a = -2; a <= 2; ++a)
   for (int b = -2; b <= 2; ++b)
    for (int c = -2; c <= 2; ++c)
     for (int d = -2; d <= 2; ++d)
      test_insertion(vec_t{{a,b,c,d}});

  test_selection(vec_t{{}});
  test_selection(vec_t{{0}});
  test_selection(vec_t{{0,1}});
  test_selection(vec_t{{2,0,1}});
  test_selection(vec_t{{5,3,1,7,9,2}});
  test_selection(vec_t{{11,10,9,8,7,6,5,4,3,2,1,0}});
  for (int a = -2; a <= 2; ++a)
   for (int b = -2; b <= 2; ++b)
    for (int c = -2; c <= 2; ++c)
     test_selection(vec_t{{a,b,c}});
  for (int a = -2; a <= 2; ++a)
   for (int b = -2; b <= 2; ++b)
    for (int c = -2; c <= 2; ++c)
     for (int d = -2; d <= 2; ++d)
      test_selection(vec_t{{a,b,c,d}});
  for (int a = -2; a <= 2; ++a)
   for (int b = -2; b <= 2; ++b)
    for (int c = -2; c <= 2; ++c)
     for (int d = -2; d <= 2; ++d)
      for (int e = -2; e <= 2; ++e)
       test_selection(vec_t{{a,b,c,d,e}});

  test_2(vec_t{{2,1}});
  for (int a = -2; a <= 2; ++a)
   for (int b = -2; b <= 2; ++b)
    test_2(vec_t{{a,b}});

  test_3(vec_t{{3,2,1}});
  for (int a = -2; a <= 2; ++a)
   for (int b = -2; b <= 2; ++b)
    for (int c = -2; c <= 2; ++c)
     test_3(vec_t{{a,b,c}});

  test_4(vec_t{{4,3,2,1}});
  for (int a = -2; a <= 2; ++a)
   for (int b = -2; b <= 2; ++b)
    for (int c = -2; c <= 2; ++c)
     for (int d = -2; d <= 2; ++d)
       test_4(vec_t{{a,b,c,d}});
}
