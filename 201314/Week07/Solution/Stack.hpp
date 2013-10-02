// Oliver Kullmann, 12.11.2012 (Swansea)

#ifndef STACK_3vS15P
#define STACK_3vS15P

#include "../List.hpp"

template <typename Key = int>
class Stack {
  typedef List<Key> list_t;
  list_t* s;
public :
  typedef Key key_type;

  Stack() : s(nullptr) {}

  bool empty() const { return s == nullptr; }
  key_type top() const { return s->key; }
  void push(const key_type x) { s = insert(s,x); }
  void pop() { s = remove(s,s); }
};

#endif
