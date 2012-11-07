// Oliver Kullmann, 7.11.2012 (Swansea)

#include <cassert>
#include <iostream>

#include "Queue.hpp"

int main(const int argc, const char* const argv) {
  typedef Buffers::Queue<int> Queue;
  Queue Q0;
  assert(Q0.empty());
  assert(Q0.size() == 0);

  Queue Q1;
  Q1.push(33).push(44).push(55);
  std::cout << "Q1:" << Q1 << "\n";

  Queue Q2(Q1);
  assert(Q1 == Q2);
  std::cout << Q2.front() << "\n";
  Q2.pop().pop();
  std::cout << "Q2:" << Q2 << "\n";

  Q2 = Q0;
  std::cout << "Q2:" << Q2 << "\n";

  Q0 = Q1;
  std::cout << "Q0:" << Q0 << "\n";
}
