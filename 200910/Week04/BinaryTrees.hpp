// Oliver Kullmann, 15.2.2010 (Swansea)

#ifndef BINARYTREES_jB4eR
#define BINARYTREES_jB4eR

#include <algorithm>
#include <ostream>
#include <cassert>
#include <iomanip>

namespace BinaryTrees {

  typedef int key_type;
  typedef int satellite_type;

  class Tree {

    struct Node {
      const Node* p;
      const Node* left;
      const Node* right;
      key_type key;
      satellite_type s;
    };

  public :

    typedef long int int_type;
    typedef const Node* public_node_type;

    Tree() : root(0) {}

    int_type height() const { return height(root); }
    int_type height(const public_node_type x) const {
      if (x == 0) return -1;
      return std::max(height(x->left), height(x->right)) + 1;
    }

    // walk the tree in inorder, and output "(key,s)" to "out"
    void inorder_walk(std::ostream& out) const { inorder_walk(out, root); }
    void inorder_walk(std::ostream& out, const public_node_type x) const {
      if (x == 0) return;
      inorder_walk(out, x->left);
      out << "(" << x->key << ", " << x->s << ") "; // print key and s
      inorder_walk(out, x->right);
    }

    // return NULL if k is not present in the tree
    public_node_type search(const key_type k) const { return search(root, k); }
    public_node_type search(const public_node_type x, const key_type k) const {
      if (x == 0 or x->key == k) return x;
      if (k <= x->key) return search(x->left, k);
      return search(x->right, k);
    }

    // returns NULL iff tree is empty
    public_node_type minimum() const { return minimum(root); }
    public_node_type minimum(public_node_type x) const {
      if (x == 0) return 0;
      while (x->left != 0) x = x->left;
      return x;
    }

    // returns NULL iff tree is empty
    public_node_type maximum() const { return maximum(root); }
    public_node_type maximum(public_node_type x) const {
      if (x == 0) return 0;
      while (x->right != 0) x = x->right;
      return x;
    }

    // return NULL iff x is the last node
    public_node_type successor(public_node_type x) {
      assert(x != 0);
      if (x->right != 0) return minimum(x->right);
      public_node_type y = x->p;
      while (y != 0 and x == y->right) { x = y; y = x->p; }
      return y;
    }

    // return NULL iff x is the first node
    public_node_type predecessor(public_node_type x) {
      assert(x != 0);
      if (x->left != 0) return maximum(x->left);
      public_node_type y = x->p;
      while (y != 0 and x == y->left) { x = y; y = x->p; }
      return y;
    }

    Tree& insert(const key_type k, const satellite_type s) {
      Node* const z = new Node;
      z->p = 0; z->left = 0; z->right = 0;
      z->key = k; z->s = s;
      if (root == 0) { root = z; return *this; }
      Node* y = 0;
      public_node_type x = root;
      while (x != 0) {
        y = const_cast<Node*>(x);
        if (x->key <= z->key) x = x->right;
        else x = x->left;
      }
      z->p = y;
      if (y->key <= z->key) y->right = z;
      else y->left = z;
      return *this;
    }

    /* Remark: Since insert returns a reference to Tree, we can chain inserts,
    for example "T.insert(10,1).insert(-11,2)". */

    // like inorder_walk, but now outputting all data
    friend std::ostream& operator <<(std::ostream& out, Tree T) {
      T.inorder_walk_internal(out, T.root);
      return out;
    }

  private :
    public_node_type root;

    void inorder_walk_internal(std::ostream& out, const public_node_type x) const {
      if (x == 0) return;
      inorder_walk_internal(out, x->left);
      using std::setw;
      out << x << ": " << setw(10) << x->p << " " << setw(10) << x->left << " " << setw(10) << x->right << " " << setw(5) << x->key << " " << setw(5) << x->s << "\n";
      inorder_walk_internal(out, x->right);
    }

  };

}

#endif
