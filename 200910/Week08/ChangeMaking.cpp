// Oliver Kullmann, 16.3.2010 (Swansea)

/*!
  \file ChangeMaking.cpp
  \brief Application for exploring the change-making algorithm

  Use by
  \verbatim
ChangeMaking N d1 ... dn
  \endverbatim
  where N is the amount to be returned, n is the number of coins and
  d1, ..., dn are the coin values.
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
#include <string>
#include <iomanip>

#include "ChangeMaking.hpp"

namespace {

  enum { errcode_parameter = 1, errcode_parameter_reading = 2,
         errcode_parameter2_reading = 3, errcode_nonpositive = 4 };

  const std::string program = "ChangeMaking";
  const std::string err = "ERROR[" + program + "]: ";

  using DynamicProgramming::size_type;
  using DynamicProgramming::vector_type;
  using DynamicProgramming::matrix_type;

  inline void size_out(const size_type s) {
    if (s == DynamicProgramming::infinity)
      std::cout << "inf";
    else
      std::cout << s;
  }

}

int main(const int argc, const char* const argv[]) {

  if (argc < 2) {
    std::cerr << err << "At least one parameter is needed, the amount N to be returned.\n";
    return errcode_parameter;
  }

  size_type dummy;
  {
    std::stringstream parameters;
    parameters << argv[1];
    parameters >> dummy;
    if (not parameters) {
      std::cerr << err << "Error when reading the amount N (which must be a non-negative integer).\n";
      return errcode_parameter_reading;
    }
  }
  const size_type N = dummy;
  const size_type n = argc-2;
  if (n == 0) {
    if (N == 0)
      std::cout << "No coins needed.\n";
    else
      std::cout << "Without coins no solution.\n";
    return 0;
  }
  vector_type d;
  for (size_type i = 2; i < (size_type) argc; ++i) {
    std::stringstream parameters;
    parameters << argv[i];
    parameters >> dummy;
    if (not parameters) {
      std::cerr << err << "Error when reading coin " << i-1 << " (which must be a non-negative integer).\n";
      return errcode_parameter2_reading;
    }
    if (dummy == 0) {
      std::cerr << err << "Coin " << i-1 << " is zero.\n";
      return errcode_nonpositive;
    }
    d.push_back(dummy);
  }
  assert(d.size() == n);

  const matrix_type c = DynamicProgramming::making_change(N, d);
  std::cout << "Optimal number of coins needed: ";
  size_out(c.back()[N]);
  std::cout << "\n";

  if (c.back()[N] != DynamicProgramming::infinity) {
    std::cout << "Solution: ";
    const vector_type a = DynamicProgramming::pay_out(c,d);
    assert(a.size() == n);
    for (size_type i = 0; i < n; ++i) {
      std::cout << a[i] << "*" << d[i];
      if (i+1 < n) std::cout << " + ";
    }
    std::cout << " = " << N << "\n";
  }

  std::cout << "\nOutput of array c ? Enter \"y\" or \"n\": ";
  std::string question;
  std::cin >> question;
  if (question == "y")
    for (size_type i = 0; i < n; ++i) {
      std::cout << i+1 << ": ";
      for (size_type j = 0; j <= N; ++j) {
        std::cout << std::setw(3);
        size_out(c[i][j]);
        std::cout << " ";
      }
      std::cout << "\n";
    }

}
