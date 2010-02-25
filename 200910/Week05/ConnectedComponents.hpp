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
      typedef typename disjoint_sets_type::node_type node_type;
      typedef typename disjoint_sets_type::pointer_type pointer_type;
      typedef std::vector<node_type> vector_type;
      vector_type V(G.N);
      node_type* const p0 = &V[0];
      for (vertex_type v = 0; (size_type) v < G.N; ++v)
        disjoint_sets_type::make_set(v, p0 + v);
      size_type components_count = G.N;
      for (const_iterator i = G.edge_list.begin(); i != G.edge_list.end(); ++i) {
        const pointer_type pu = p0 + i->first;
        const pointer_type pv = p0 + i->second;
        if (disjoint_sets_type::find_set(pu) != disjoint_sets_type::find_set(pv)) {
          disjoint_sets_type::union_sets(pu, pv);
          --components_count;
        }
      }
      return components_count;
    }
    
  };

}

#endif
