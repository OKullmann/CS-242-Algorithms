// Oliver Kullmann, 15.2.2010 (Swansea)

/*!
  \file BinaryTree_Output.cpp
  \brief Reading data into a binary search tree, printing data on the tree, and then waiting for queries

  Data from standard input is put into a binary search tree, and data about
  the tree is output. The data consists of integers, and is augmented with
  counter-data (as "satellite data", starting with 1). After that a loop is
  entered, where the tree can be searched for integers.
*/

#include <iostream>

#include "BinaryTrees.hpp"

int main() {
  BinaryTrees::Tree T;
  for (int counter = 1; ; ++counter) {
    BinaryTrees::key_type k;
    if (not (std::cin >> k)) break;
    T.insert(k, counter);
  }

  std::cout << "The full tree:\n" << T << "\n";
  std::cout << "Height = " << T.height() << "\n";
  std::cout << "Inorder walk:\n"; T.inorder_walk(std::cout); std::cout << "\n";
  std::cout << "Minimum = " << T.minimum() << "\n";
  std::cout << "Maximum = " << T.maximum() << "\n";

  std::cin.clear();
  std::cout << "\nSearching for keys:\n";
  for (;;) {
    BinaryTrees::key_type k;
    if (not (std::cin >> k)) break;
    const BinaryTrees::Tree::public_node_type p = T.search(k);
    std::cout << "search for " << k << " yields " << p << "\n";
    if (p) {
      std::cout << "predecessor of " << p << " is " << T.predecessor(p);
      std::cout << ", successor is " << T.successor(p) << "\n";
    }
  }

}
