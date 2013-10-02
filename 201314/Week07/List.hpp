// Oliver Kullmann, 12.11.2012 (Swansea)

#ifndef LIST_J8tw3p
#define LIST_J8tw3p

#include <cassert>
#include <cstddef>
#include <ostream>

template <typename Key = int>
class List {
  List* prev;
  List* next;
public :
  typedef Key key_type;
  key_type key;
  typedef std::size_t size_type;

  List(const key_type k) : prev(nullptr), next(nullptr), key(k) {}

  friend List* search(List* L, const key_type key) {
    while (L != nullptr and L->key != key) L = L->next;
    return L;
  }
  friend const List* search(const List* L, const key_type key) {
    while (L != nullptr and L->key != key) L = L->next;
    return L;
  }
  friend List* insert(List* L, List* const x) {
    assert(x != nullptr);
    x->next = L;
    x->prev = nullptr;
    if (L != nullptr) L->prev = x;
    L = x;
    return L;
  }
  friend List* insert(List* const L, const key_type x) {
    return insert(L, new List(x));
  }
  friend List* remove(List* L, List* const x) {
    assert(x != nullptr);
    assert(L != nullptr);
    if (x->prev != nullptr) x->prev->next = x->next;
    else L = x->next;
    if (x->next != nullptr) x->next->prev = x->prev;
    delete x;
    return L;
  }

  friend size_type size(const List* L) {
    size_type res = 0;
    while (L != nullptr) { ++res; L = L->next; }
    return res;
  }

  friend std::ostream& operator <<(std::ostream& out, const List* L) {
    for (; L != nullptr; L = L->next)
      out << L->key << " ";
    return out;
  }

};

#endif
