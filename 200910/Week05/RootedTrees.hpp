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

}

#endif
