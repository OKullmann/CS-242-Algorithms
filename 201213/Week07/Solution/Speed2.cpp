// Oliver Kullmann, 12.11.2012 (Swansea)

#include <cassert>
#include <iostream>
#include <sstream>
#include <ctime>

#include "Stack.hpp"

int main(const int argc, const char* const argv[]) {
  typedef Stack<> stack_t;
  using std::size_t;

  size_t N;
  std::istringstream(argv[1]) >> N;
  size_t M;
  std::istringstream(argv[2]) >> M;
  stack_t S;
  for (size_t counter = 0; true; ++counter) {
    const std::clock_t start = std::clock();
    for (size_t i = 0; i < N; ++i) {
      for (size_t j = 0; j < M; ++j) S.push(j);
      for (size_t j = 0; j < M; ++j) S.pop();
    }
    assert(S.empty());
    std::cout << counter << ":" << double(std::clock() - start) / CLOCKS_PER_SEC << " ";
    std::cout.flush();
  }
}
