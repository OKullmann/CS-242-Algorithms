// Oliver Kullmann, 23.2.2010 (Swansea)

/*!
  \file ConnectedComponents.hpp
  \brief Computing connected components by disjoint-sets data structures
*/

#ifndef CONNECTEDCOMPONENTS_hpqpqpqtR4ew2
#define CONNECTEDCOMPONENTS_hpqpqpqtR4ew2

#include <vector>

namespace DisjointSets {

  template <template <typename Element> class DisjointSets>
  struct Number_connected_components {
    template <class Graph>
    typename Graph::size_type operator() (const Graph& G) {
      typedef typename Graph::vertex_type vertex_type;
      typedef DisjointSets<vertex_type> disjoint_sets_type;
      typedef typename Graph::size_type size_type;
      typedef typename Graph::const_iterator const_iterator;
      typedef typename disjoint_sets_type::pointer_type pointer_type;
      typedef std::vector<pointer_type> vector_type;
      vector_type V;
      V.reserve(G.N);
      for (vertex_type v = 0; (size_type) v < G.N; ++v)
        V.push_back(disjoint_sets_type::make_set(v));
      size_type components_count = G.N;
      for (const_iterator i = G.edge_list.begin(); i != G.edge_list.end(); ++i)
        if (disjoint_sets_type::find_set(V[i->first]) != disjoint_sets_type::find_set(V[i->second])) {
          disjoint_sets_type::union_sets(V[i->first], V[i->second]);
          --components_count;
        }
      return components_count;
    }
    
  };

}

#endif
