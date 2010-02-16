// Oliver Kullmann, 15.2.2010 (Swansea)

/*!
  \file BinaryTree.cpp
  \brief Data from standard input is put into a binary search tree, and data about the tree is output

  The data is just a stream of integers. The "satellite data" is a counter,
  starting with 1.
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
}
