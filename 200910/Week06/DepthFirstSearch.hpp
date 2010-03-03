// Oliver Kullmann, 2.3.2010 (Swansea)

/*!
  \file DepthFirstSearch.hpp
  \brief Applying depth-first search to a directed graph
*/

#include <limits>
#include <vector>
#include <ostream>
#include <stdexcept>

#ifndef DEPTHFIRSTSEARCH_81910Uijn
#define DEPTHFIRSTSEARCH_81910Uijn

namespace Graphs {

  template <class AdjacencyListGraph>
  struct DepthFirstSearch {
    typedef AdjacencyListGraph adjacencylist_graph_type;
    typedef typename adjacencylist_graph_type::vertex_type vertex_type;
    typedef typename adjacencylist_graph_type::size_type size_type;
    typedef typename adjacencylist_graph_type::neighbour_iterator neighbour_iterator;
    //! unreachable time
    static const size_type infinity;
    static const size_type max_N;
    //! singular vertex
    static const vertex_type nil;

    struct Node {
      size_type d;
      size_type f;
      vertex_type p;
      Node() : d(infinity) {}
    };
    friend std::ostream& operator <<(std::ostream& out, const Node& node) {
      std::cout << "Discovery time: " << node.d <<
        ", Finishing time: " << node.f << "; Parent: ";
      if (node.p == nil) std::cout << "nil";
      else std::cout << node.p;
      return std::cout;
    }
    typedef std::vector<Node> result_vector_type;
    

    //! Compute the DFS-spanning forest, visiting the vertices in the given
    //! order.
    const result_vector_type& operator() (const adjacencylist_graph_type& G) {
      assert(2*max_N < infinity);
      if (G.N > max_N)
        throw std::range_error("DepthFirstSearch: too many vertices.");
      if (G.N == 0) return R;
      R.assign(G.N, Node());
      time = 0;
      for (vertex_type u = 0; u < G.N; ++u)
        if (R[u].d == infinity) { R[u].p = nil; visit(u,G); }
      assert(time = 2 * G.N);
      return R;
    }

  private :

    result_vector_type R;
    size_type time;

    void visit(const vertex_type u, const adjacencylist_graph_type& G) {
      R[u].d = ++time;
      const neighbour_iterator nend = G[u].end();
      for (neighbour_iterator i = G[u].begin(); i != nend; ++i) {
        const vertex_type v = *i;
        if (R[v].d == infinity) { R[v].p = u; visit(v,G); }
      }
      R[u].f = ++time;
    }
  };

  template <class AdjacencyListGraph>
  const typename DepthFirstSearch<AdjacencyListGraph>::size_type
    DepthFirstSearch<AdjacencyListGraph>::infinity = 
    std::numeric_limits<typename DepthFirstSearch<AdjacencyListGraph>::size_type>::max();

  template <class AdjacencyListGraph>
  const typename DepthFirstSearch<AdjacencyListGraph>::size_type
    DepthFirstSearch<AdjacencyListGraph>::max_N = 
    DepthFirstSearch<AdjacencyListGraph>::infinity / 2;

  template <class AdjacencyListGraph>
  const typename DepthFirstSearch<AdjacencyListGraph>::vertex_type
    DepthFirstSearch<AdjacencyListGraph>::nil =
    DepthFirstSearch<AdjacencyListGraph>::infinity;

}

#endif
