// Oliver Kullmann, 3.12.2015 (Swansea)

#include <vector>
#include <algorithm>

#include <cassert>

#include "Insertion.hpp"
#include "Small.hpp"

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


}

int main(const int argc, const char* const argv[]) {

  test_insertion(vec_t{{}});
  test_insertion(vec_t{{3,5,1,7,9,2}});
  for (int a = -2; a <= 2; ++a)
   for (int b = -2; b <= 2; ++b)
    for (int c = -2; c <= 2; ++c)
     for (int d = -2; d <= 2; ++d)
      test_insertion(vec_t{{a,b,c,d}});

  test_2(vec_t{{2,1}});
  for (int a = -2; a <= 2; ++a)
   for (int b = -2; b <= 2; ++b)
    test_2(vec_t{{a,b}});

  test_3(vec_t{{3,2,1}});
  for (int a = -2; a <= 2; ++a)
   for (int b = -2; b <= 2; ++b)
    for (int c = -2; c <= 2; ++c)
     test_3(vec_t{{a,b,c}});
}
