// Oliver Kullmann, 4.11.2012 (Swansea)

#include <cassert>
#include <iostream>

#include "Stack.hpp"

int main(const int argc, const char* const argv) {
  typedef Buffers::Stack<int> Stack;
  Stack S0;
  assert(S0.empty());
  assert(S0.size() == 0);

  Stack S1;
  S1.push(33).push(44).push(55);
  std::cout << "S1:" << S1 << "\n";

  Stack S2(S1);
  assert(S1 == S2);
  std::cout << S2.top() << "\n";
  S2.pop().pop();
  std::cout << "S2:" << S2 << "\n";

  S2 = S0;
  std::cout << "S2:" << S2 << "\n";

  S0 = S1;
  std::cout << "S0:" << S0 << "\n";
  S0.reserve(1000);
  std::cout << "S0:" << S0 << "\n";
}
