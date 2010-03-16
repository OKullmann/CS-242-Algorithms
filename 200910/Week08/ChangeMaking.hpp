// Oliver Kullmann, 16.3.2010 (Swansea)

/*!
  \file ChangeMaking.hpp
  \brief Solving the change-making problem via dynamic programming
*/

#ifndef CHANGEMAKING_jVd4Ew2l
#define CHANGEMAKING_jVd4Ew2l

#include <vector>
#include <cassert>
#include <limits>
#include <algorithm>

namespace DynamicProgramming {

  typedef unsigned int size_type;
  const size_type infinity = std::numeric_limits<size_type>::max();
  typedef std::vector<size_type> vector_type;
  typedef std::vector<vector_type> matrix_type;

  matrix_type making_change(const size_type N, const vector_type& d) {
    const size_type n = d.size();
    matrix_type c(n);
    if (n == 0) return c;
    assert(N < infinity);
    for (size_type i = 0; i < n; ++i) c[i].assign(N+1,infinity);
    for (size_type i = 0; i < n; ++i) c[i][0] = 0;
    for (size_type j = 1; j <= N; ++j) {
      const size_type d1 = d[0];
      if (j % d1 == 0) c[0][j] = j / d1;
    }
    for (size_type i = 1; i < n; ++i)
      for (size_type j = 1; j <= N; ++j)
        if (j < d[i] or c[i][j-d[i]] == infinity)
          c[i][j] = c[i-1][j];
        else
          c[i][j] = std::min(c[i-1][j], 1+c[i][j-d[i]]);
    return c;
  }

  vector_type pay_out(const matrix_type& c, const vector_type& d) {
    const size_type n = c.size();
    vector_type a(n);
    if (n == 0) return a;
    assert(not c.front().empty());
    const size_type N = c.front().size()-1;
    size_type i = n-1, j = N;
    while (j > 0)
      if (i == 0) { a[0] = c[0][j]; j = 0; }
      else if (c[i][j] == c[i-1][j]) --i;
      else { ++a[i]; j -= d[i]; }
    return a;
  }
}

#endif
