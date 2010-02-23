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


  template <typename Element, typename Count = unsigned int>
  class LinkedListsH {

    typedef Count size_type;

    struct Node {
      Element x;
      Node* rep;
      Node* next;
      Node* last;
      size_type s;
    };

    // output the whole node together with its address
    friend std::ostream& operator <<(std::ostream& out, const Node* const p) {
      using std::setw;
      out << (void*) p << ": " << setw(5) << p->x << " " << setw(10) << (void*) p->rep << " " << setw(10) << (void*) p->next << " " << setw(10) << (void*) p->last << " " << setw(7) << p->s;
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
      p->s = 1;
      return p;
    }

    static pointer_type find_set(const pointer_type x) { return x->rep; }

    static void union_sets(pointer_type x, pointer_type y) {
      if (x->rep->s <= y->rep->s) {
        Node* const new_rep = y->rep;
        new_rep->last->next = x->rep;
        new_rep->last = x->rep->last;
        new_rep->s = new_rep->s + x->rep->s;
        for (Node* p = x->rep; p != 0; p = p->next)
          p->rep = new_rep;
      }
      else {
        Node* const new_rep = x->rep;
        new_rep->last->next = y->rep;
        new_rep->last = y->rep->last;
        new_rep->s = new_rep->s + y->rep->s;
        for (Node* p = y->rep; p != 0; p = p->next)
          p->rep = new_rep;
      }
    }
  };

}

#endif
