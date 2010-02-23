// Oliver Kullmann, 22.2.2010 (Swansea)

/*!
  \file LinkedLists.hpp
  \brief Implementing the disjoint-sets data-structure via linked lists
  according to CLRS
*/

#ifndef LINKEDLISTS_jBVCCr43W
#define LINKEDLISTS_jBVCCr43W

#include <ostream>
#include <iomanip>

namespace DisjointSets {

  template <typename Element>
  class LinkedLists {

    struct Node {
      Element x;
      Node* rep;
      Node* next;
      Node* last;
    };

    // output the whole node together with its address
    friend std::ostream& operator <<(std::ostream& out, const Node* const p) {
      using std::setw;
      out << (void*) p << ": " << setw(5) << p->x << " " << setw(10) << (void*) p->rep << " " << setw(10) << (void*) p->next << " " << setw(10) << (void*) p->last;
      return out;
    }

  public :
    typedef Element value_type;
    typedef const Node* pointer_type;

    static value_type value(const pointer_type x) { return x->x; }

    // returns the pointer to the node of x
    static pointer_type make_set(const value_type x) {
      Node* p = new Node;
      p->x = x;
      p->rep = p;
      p->next = 0;
      p->last = p;
      return p;
    }

    static pointer_type find_set(const pointer_type x) { return x->rep; }

    static void union_sets(const pointer_type x, const pointer_type y) {
      Node* const new_rep = y->rep;
      new_rep->last->next = x->rep;
      new_rep->last = x->rep->last;
      for (Node* p = x->rep; p != 0; p = p->next)
        p->rep = new_rep;
    }
  };

}

#endif
