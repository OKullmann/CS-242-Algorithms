// Oliver Kullmann, 10.11.2011 (Swansea)

/*!
  \file Inversions.cpp
  \brief Computing the number of inversions of a list of integers, by definition and by a fast algorithm, from various sources

  <ul>
   <li> Calling it with no arguments means that integers from standard input
   are read. </li>
   <li> If one argument is given, then this is N, the number of integers, and
   N random integers are created. </li>
   <li> For two arguments, the first is again N, while the second can be "r",
   "o" and "i", for "random", "ordered" and "inversely ordered". </li>
  </ul>
  According to the solution for Coursework I, CS-270, 2011/12.
*/

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stdexcept>
#include <chrono>

namespace {

  const std::string err = "Inversions[ERROR]: ";
  enum { err_N1 = 1, err_N2 = 2, err_N3 = 3 };

  enum Input_types { sin = 1, rdm = 2, ord = 3, invord = 4 };

  typedef int int_t;
  typedef std::vector<int_t> vec_t;

  typedef unsigned long index_t;

  Input_types s2m(const std::string& s) {
    if (s == "o") return ord;
    if (s == "i") return invord;
    return rdm;
  }
  std::string m2s(const Input_types m) {
    switch (m) {
      case sin : return "standard input";
      case ord : return "ordered";
      case invord : return "inversely ordered";
      default : return "random";
    }
  }

  index_t merge(vec_t& A, const index_t p, const index_t r, const index_t q) {
    assert(p < r);
    assert(r < q);
    assert(q <= A.size());
    const index_t n1 = r - p, n2= q - r;
    const auto b = A.begin();
    vec_t L(b+p, b+r), R(b+r, b+q);
    index_t i = 0, j = 0, k = p, inv = 0;
    while (i < n1 and j < n2) {
      if (L[i] <= R[j]) A[k++] = L[i++];
      else {
        A[k++] = R[j++];
        inv += n1 - i;
      }
    }
    if (i == n1) while (k < q) A[k++] = R[j++];
    else while (k < q) A[k++] = L[i++];
    return inv;
  }

  index_t inversions(vec_t& A, const index_t p, const index_t q) {
    assert(p <= q);
    assert(q <= A.size());
    if (p+1 >= q) return 0;
    const index_t r = (p+q)/2;
    const index_t inv_l = inversions(A,p,r);
    const index_t inv_r = inversions(A,r,q);
    const index_t inv_m = merge(A,p,r,q);
    return inv_l + inv_r + inv_m;
  }

  index_t inversions_bydef(const vec_t& A) {
    typedef vec_t::size_type size_type;
    const size_type n = A.size();
    size_type inv = 0;
    for (size_type i = 0; i != n; ++i)
      for (size_type j = i+1; j != n; ++j)
        if (A[i] > A[j]) ++inv;
    return inv;
  }

}

int main(const int argc, const char* const argv[]) {

  const Input_types mode =
    (argc == 1) ? sin : (argc >= 3) ? s2m(argv[2]) : rdm;
  index_t N;
  try {
    N = (argc >= 2) ? std::stoul(argv[1]) : 0;
  }
  catch (const std::invalid_argument& e) {
    std::cerr << err << " N not a number: \"" << argv[1] << "\"\n";
    return err_N1;
  }
  catch (const std::out_of_range& e) {
    std::cerr << err << " N not in range: \"" << argv[1] << "\"\n";
    return err_N2;
  }

  std::cout << "Mode = " << m2s(mode) << "." << std::endl;
  if (mode != sin) std::cout << "N = " << N << "." << std::endl;

  vec_t V;
  try { V.reserve(N); }
  catch(const std::bad_alloc& e) {
    std::cerr << err << " N too large for memory: " << argv[1] << "\n";
    return err_N3;
  }

  switch (mode) {
    case sin :
      for (int_t i; std::cin >> i; ++N) V.push_back(i);
      std::cout << "N = " << N << "." << std::endl;
      break;
    case rdm :
      std::srand(std::time(0));
      for (index_t i = 0; i != N; ++i) V.push_back(std::rand());
      break;
    case ord :
      for (index_t i = 0; i != N; ++i) V.push_back(i);
      break;
    case invord : {
      index_t i = N;
      while (i != 0) V.push_back(--i);
      break;
    }
  }

  std::cout << "Inversion count by definition: "; std::cout.flush();
  auto start = std::chrono::system_clock::now();
  std::cout << inversions_bydef(V) << "\n";;
  std::cout << std::chrono::duration<double,std::milli>(std::chrono::system_clock::now() - start).count() << "ms" << std::endl;
  std::cout << "Fast inversion count: "; std::cout.flush();
  start = std::chrono::system_clock::now();
  std::cout << inversions(V, 0, V.size()) << "\n";
  std::cout << std::chrono::duration<double,std::milli>(std::chrono::system_clock::now() - start).count() << "ms" << std::endl;
}
