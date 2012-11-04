// Oliver Kullmann, 4.11.2012 (Swansea)

#ifndef STACK_BeMidU
#define STACK_BeMidU

#include <vector>
#include <cassert>
#include <ostream>

namespace Buffers {

  template <typename T>
  class Stack {
    typedef std::vector<T> vector_t ;
  public :
    typedef T value_type;
    typedef typename vector_t::size_type size_type;
  private :
    vector_t stack;
  public :

    bool empty() const { return stack.empty(); }
    T top() const {
      assert(not stack.empty());
      return stack.back();
    }
    Stack& push(const T& x) { stack.push_back(x); return *this; }
    Stack& pop() {
      assert(not stack.empty());
      stack.pop_back();
      return *this;
    }

    // additional functionality:
    size_type size() const { return stack.size(); }
    size_type max_size() const { return stack.max_size(); }
    // "capacity" refers to the size possible without (internal) re-allocation:
    size_type capacity() const { return stack.capacity(); }
    // changing (increasing) the capacity:
    void reserve(const size_type r) { stack.reserve(r); }

    friend bool operator ==(const Stack& lhs, const Stack& rhs) {
      return lhs.stack == rhs.stack;
    }

    friend std::ostream& operator <<(std::ostream& out, const Stack& S) {
      out << "[" << S.size() << "," << S.capacity() << "," << S.max_size() << "]\n";
      for (auto x : S.stack) out << x << " ";
      return out << "\n";
    }

  };

}

#endif
