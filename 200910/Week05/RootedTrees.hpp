// Oliver Kullmann, 23.2.2010 (Swansea)

/*!
  \file RootedTrees.hpp
  \brief Implementing the disjoint-sets data-structure via rooted trees
  according to CLRS
*/

#ifndef ROOTEDTREES_jHeqPo8r3
#define ROOTEDTREES_jHeqPo8r3

#include <ostream>
#include <iomanip>

namespace DisjointSets {

  template <typename Element>
  class RootedTrees {
    struct Node {
      Element x;
      Node* p;
    };
  public :
    typedef Element value_type;
    typedef const Node* pointer_type;
    static value_type value(const pointer_type x) { return x->x; }
    static pointer_type make_set(const value_type x) {
      Node* p = new Node;
      p->x = x;
      p->p = 0;
      return p;
    }
    static pointer_type find_set(pointer_type x) {
      while (x->p != 0) x = x->p;
      return x;
    }
    static void union_sets(pointer_type x, const pointer_type y) {
      const_cast<Node*>(find_set(x))->p = const_cast<Node*>(find_set(y));
    }
  };

  template <typename Element, typename Count = unsigned int>
  class RootedTreesHS {
    typedef Count size_type;
    struct Node {
      Element x;
      Node* p;
      size_type s;
    };
  public :
    typedef Element value_type;
    typedef const Node* pointer_type;
    static value_type value(const pointer_type x) { return x->x; }
    static pointer_type make_set(const value_type x) {
      Node* p = new Node;
      p->x = x;
      p->p = 0;
      p->s = 1;
      return p;
    }
    static pointer_type find_set(pointer_type x) {
      while (x->p != 0) x = x->p;
      return x;
    }
    static void union_sets(pointer_type x, const pointer_type y) {
      Node* const x_root = const_cast<Node*>(find_set(x));
      Node* const y_root = const_cast<Node*>(find_set(y));
      if (x_root->s <= y_root->s) {
        x_root->p = y_root;
        y_root->s += x_root->s;
      }
      else {
        y_root->p = x_root;
        x_root->s += y_root->s;
      }
    }
  };

  template <typename Element>
  class RootedTreesHP {
    struct Node {
      Element x;
      Node* p;
    };
  public :
    typedef Element value_type;
    typedef const Node* pointer_type;
    static value_type value(const pointer_type x) { return x->x; }
    static pointer_type make_set(const value_type x) {
      Node* p = new Node;
      p->x = x;
      p->p = 0;
      return p;
    }
    static pointer_type find_set(const pointer_type x) {
      Node* y = const_cast<Node*>(x);
      Node* x_root = y;
      while (x_root->p != 0) x_root = x_root->p;
      while (y != x_root) {
        Node* const z = y->p;
        y->p = x_root;
        y = z;
      }
      return x_root;
    }
    static void union_sets(pointer_type x, const pointer_type y) {
      const_cast<Node*>(find_set(x))->p = const_cast<Node*>(find_set(y));
    }
  };

}

#endif
