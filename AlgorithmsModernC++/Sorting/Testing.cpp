// Oliver Kullmann, 3.12.2015 (Swansea)

#include <vector>

#include <cassert>

#include "InsertionSort.hpp"

namespace {

typedef std::vector<int> vec_t;

void test_insertion(const vec_t& v) {
  vec_t s(v);
  std::sort(s.begin(), s.end());
  {vec_t c(v); Sort::insertion0(c); assert(c == s);}
  {vec_t c(v); Sort::insertion1(c); assert(c == s);}
  {vec_t c(v); Sort::insertion(c); assert(c == s);}
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

}
