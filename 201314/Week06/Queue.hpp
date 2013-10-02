// Oliver Kullmann, 7.11.2012 (Swansea)

#ifndef STACK_A4G5Si
#define STACK_A4G5Si

#include <deque>
#include <cassert>
#include <ostream>

namespace Buffers {

  template <typename T>
  class Queue {
    typedef std::deque<T> deque_t ;
  public :
    typedef T value_type;
    typedef typename deque_t::size_type size_type;
  private :
    deque_t queue;
  public :

    bool empty() const { return queue.empty(); }
    T front() const {
      assert(not queue.empty());
      return queue.front();
    }
    T back() const {
      assert(not queue.empty());
      return queue.back();
    }
    Queue& push(const T& x) { queue.push_back(x); return *this; }
    Queue& pop() {
      assert(not queue.empty());
      queue.pop_front();
      return *this;
    }

    // additional functionality:
    size_type size() const { return queue.size(); }
    size_type max_size() const { return queue.max_size(); }

    friend bool operator ==(const Queue& lhs, const Queue& rhs) {
      return lhs.queue == rhs.queue;
    }

    friend std::ostream& operator <<(std::ostream& out, const Queue& S) {
      out << "[" << S.size() << "," << S.max_size() << "]\n";
      for (auto x : S.queue) out << x << " ";
      return out;
    }

  };

}

#endif
