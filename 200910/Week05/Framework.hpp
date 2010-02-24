// Oliver Kullmann, 23.2.2010 (Swansea)

/*!
  \file Framework.hpp
  \brief Framework to use the disjoint-sets data-structures according to CLRS
*/

#ifndef FRAMEWORK_kqRd240
#define FRAMEWORK_kqRd240

#include <ostream>
#include <vector>
#include <utility>

namespace DisjointSets {

  template <class DS>
  class Framework {
  public :
    typedef DS disjoint_sets_type;
    typedef typename disjoint_sets_type::value_type value_type;
    typedef typename disjoint_sets_type::pointer_type pointer_type;

  private :
    typedef std::vector<pointer_type> vector_type;

  public :
    typedef typename vector_type::size_type size_type;

    Framework(const size_type n) {
      V.reserve(n);
      for (value_type i = 1; (size_type) i <= n; ++i)
        V.push_back(disjoint_sets_type::make_set(i));
    }
    ~Framework() {
      typedef typename vector_type::const_iterator iterator;
      for (iterator i = V.begin(); i != V.end(); ++i)
        delete *i;
    }

    pointer_type operator[] (const size_type i) { return V[i]; }

    // output all cells
    friend std::ostream& operator <<(std::ostream& out, const Framework& F) {
      typedef typename vector_type::const_iterator iterator;
      size_type i = 0;
      for (iterator it = F.V.begin(); it != F.V.end(); ++it, ++i) {
        out << i << ": ";
        disjoint_sets_type::output(out, *it);
        out << "\n";
      }
      return out;
    }

  private :

    vector_type V;

  };

}

#endif
