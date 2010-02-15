// Oliver Kullmann, 15.2.2010 (Swansea)

#ifndef BINARYTREES_jB4eR
#define BINARYTREES_jB4eR

#include <algorithm>
#include <ostream>
#include <cassert>

namespace BinaryTrees {

  typedef int key_type;
  typedef int satellite_type;

  struct Node {
    const Node* p;
    const Node* left;
    const Node* right;
    key_type key;
    satellite_type s;
  };

  class Tree {
  public :

    typedef long int int_type;
    typedef Node node_type;

    Tree() : root(0) {}

    int_type height() const {
      return height(root);
    }
    int_type height(const node_type* const x) const {
      if (x == 0) return -1;
      return std::max(height(x->left), height(x->right)) + 1;
    }

    // walk the tree in inorder, and output "(key,s)" to "out"
    void inorder_walk(std::ostream& out) const {
      inorder_walk(out, root);
    }
    void inorder_walk(std::ostream& out, const node_type* const x) const {
      if (x == 0) return;
      inorder_walk(out, x->left);
      out << "(" << x->key << ", " << x->s << ")"; // print key and s
      inorder_walk(out, x->right);
    }

    // return NULL if k is not present in the tree
    const node_type* search(const key_type k) const {
      return search(root, k);
    }
    const node_type* search(const node_type* const x, const key_type k) const {
      if (x == 0 or x->key == k) return x;
      if (k <= x->key) return search(x->left, k);
      return search(x->right, k);
    }

    // returns NULL iff tree is empty
    const node_type* minimum() const {
      return minimum(root);
    }
    const node_type* minimum(const node_type* x) const {
      if (x == 0) return 0;
      while (x->left != 0) x = x->left;
      return x;
    }

    // returns NULL iff tree is empty
    const node_type* maximum() const {
      return maximum(root);
    }
    const node_type* maximum(const node_type* x) const {
      if (x == 0) return 0;
      while (x->right != 0) x = x->right;
      return x;
    }

    // return NULL iff x is the last node
    const node_type* successor(const node_type* x) {
      assert(x != 0);
      if (x->right != 0) return minimum(x->right);
      const node_type* y = x->p;
      while (y != 0 and x == y->right) { x = y; y = x->p; }
      return y;
    }

    // return NULL iff x is the first node
    const node_type* predecessor(const node_type* x) {
      assert(x != 0);
      if (x->left != 0) return maximum(x->left);
      const node_type* y = x->p;
      while (y != 0 and x == y->left) { x = y; y = x->p; }
      return y;
    }

  private :
    const node_type* root;
  };

}

#endif
