// Oliver Kullmann, 14.10.2011 (Swansea)
/* Copyright 2011 Oliver Kullmann
This file free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 3 of the License,
or any later version. */

/*!
  \file MeasureMinMaxAlgorithms.cpp
  \brief Application for timing three versions of min-max algorithms

  <ul>
   <li> Two parameter are accepted, the size N of the array (default 10^8),
   and the seed (default 0). </li>
   <li> Runs in an endless loop. </li>
   <li> Output in R-format: header "tn tdac tp min max". </li>
   <li> For "time naive", "time divide-and-conquer", "time pairing". </li>
  </ul>

  Compilation optimised:
  \verbatim
g++ -O3 -DNDEBUG -Wall -o MeasureMinMaxAlgorithms MeasureMinMaxAlgorithms.cpp
  \endverbatim
  Unoptimised, with asserts:
  \verbatim
g++ -Wall -o MeasureMinMaxAlgorithms MeasureMinMaxAlgorithms.cpp
  \endverbatim
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <utility>
#include <cassert>
#include <algorithm>

#include <boost/lexical_cast.hpp>
#include <boost/timer.hpp>

namespace {
  
  enum {
    error_parameters = 1,
    error_impossible = 2
  };

  const std::string program = "MeasureMinMaxAlgorithms";
  const std::string err = "ERROR[" + program + "]: ";

  const std::string version = "0.0.6";

  const unsigned int seed_default = 0;

  // managing the indices for the sequences:
  typedef unsigned long uint_type;
  const uint_type N_default = 100000000;
  const unsigned int digits_fractional_part = 2;

  // managing the values of the sequences:
  typedef unsigned long value_type;
  value_type random_value;
  //! Simulating the array A
  inline value_type A(uint_type i) {
    return (i+1) * random_value;
  }
  typedef std::pair<value_type, value_type> min_max_type;

  //! Min-max in the naive way:
  inline min_max_type naive_minmax(const uint_type N) {
    assert(N >= 1);
    const value_type first_value = A(0);
    value_type min = first_value, max = first_value;
    for (uint_type i = 1; i < N; ++i) {
      const value_type value = A(i);
      if (value < min) min = value;
      if (value > max) max = value;
    }
    return min_max_type(min,max);
  }
  //! Min-max via divide-and-conquer:
  inline min_max_type dac_minmax(const uint_type p, const uint_type q) {
    assert(p < q);
    if (p == q-1) {
      const value_type value = A(p);
      return min_max_type(value, value);
    }
    if (p == q-2) {
      const value_type value_1 = A(p), value_2 = A(p+1);
      if (value_1 < value_2) return min_max_type(value_1, value_2);
      else return min_max_type(value_2, value_1);
    }
    const uint_type r = (p+q)/2;
    const min_max_type mm1 = dac_minmax(p,r);
    const min_max_type mm2 = dac_minmax(r,q);
    return min_max_type(
      std::min(mm1.first, mm2.first),
      std::max(mm1.second, mm2.second));
  }
  inline min_max_type divide_and_conquer_minmax(const uint_type N) {
    assert(N >= 1);
    return dac_minmax(0, N);
  }
  //! Min-max via pairing:
  inline min_max_type pairing_minmax(const uint_type N) {
    assert(N >= 1);
    const bool odd = N % 2;
    min_max_type mm;
    if (odd) {
      const value_type value_1 = A(0);
      mm = min_max_type(value_1, value_1);
    }
    else {
      const value_type value_1 = A(0);
      const value_type value_2 = A(1);
      if (value_1 < value_2) mm = min_max_type(value_1, value_2);
      else mm = min_max_type(value_2, value_1);
    }
    for (uint_type i = odd ? 1 : 2; i < N; i+=2) {
      const value_type value_1 = A(i);
      const value_type value_2 = A(i+1);
      const min_max_type mm_new = (value_1 < value_2) ?
        min_max_type(value_1, value_2) :
        min_max_type(value_2, value_1);
      mm = min_max_type(
        std::min(mm.first, mm_new.first),
        std::max(mm.second, mm_new.second));
    }
    return mm;
  }
}

int main(const int argc, const char* const argv[]) {
  if (argc > 3) {
    std::cerr << err << "At most two parameters can be used, the "
      "length of the sequence and the seed.\n"
      "However, the actual number of input parameters was " << argc-1 << ".\n";
    return error_parameters;
  }

  const uint_type N = (argc >= 2) ?
    boost::lexical_cast<uint_type>(argv[1]) : N_default;
  unsigned int seed = (argc == 3) ?
    boost::lexical_cast<unsigned int>(argv[2]) : seed_default;

  std::cout << "# Program: " << program << "\n# N = " << N <<
    "\n# time-naive time-dac time-pairing min max\n" <<
    " tn tdac tp min max\n";
  std::cout << std::fixed << std::showpoint << std::setprecision(digits_fractional_part);
  
  boost::timer T; 
  for (uint_type i = 1; true; ++i, ++seed) {
    std::srand(seed);
    random_value = (value_type) std::rand();
    T.restart();
    const min_max_type mm_naive = naive_minmax(N);
    const double elapsed_naive = T.elapsed();
    T.restart();
    const min_max_type mm_dac = divide_and_conquer_minmax(N);
    const double elapsed_dac = T.elapsed();
    T.restart();
    const min_max_type mm_pairing = pairing_minmax(N);
    const double elapsed_pairing = T.elapsed();
    std::cout << i << " " << elapsed_naive << " " << elapsed_dac << " " <<
     elapsed_pairing << " " << mm_naive.first << " " << mm_naive.second << "\n";
    if (mm_naive != mm_dac or mm_dac != mm_pairing) {
      std::cerr << "This can never happen.\n"
      " But otherwise the computation might be optimised away.\n";
      return error_impossible;
    }
  }

}
