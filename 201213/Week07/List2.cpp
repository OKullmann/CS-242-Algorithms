// Oliver Kullmann, 12.11.2012 (Swansea)

#include <iostream>
#include <cstddef>

#include "List.hpp"

int main() {
  typedef List<> list_t;

  list_t* L = nullptr;
  std::cout << "L:" << L << "\n";
  for (int i = 0; i < 5; ++i) L = insert(L, i);
  std::cout << "L:" << L << "\n";
  std::cout << size(L) << "\n";
  {
   const list_t* const f0 = search(L, 2);
   std::cout << "search:\"" << (std::size_t) f0 << "\"\n";
   std::cout << "f0:" << f0->key << "\n";
  }
  list_t* const f1 = search(L, 2);
  L = remove(L, f1);
  std::cout << "L:" << L << "\n";
  std::cout << size(L) << "\n";
  std::cout << "search:\"" << (std::size_t) search(L, 2) << "\"\n";
  while (L != nullptr) {
    L = remove(L,L);
    std::cout << "L:" << L << "\n";
    std::cout << size(L) << "\n";
  }
  std::cout << size(L) << "\n";
}
