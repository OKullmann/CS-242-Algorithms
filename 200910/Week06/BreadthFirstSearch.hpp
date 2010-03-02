// Oliver Kullmann, 1.3.2010 (Swansea)

/*!
  \file BreadthFirstSearch.hpp
  \brief Applying breadth-first search to a directed graph
*/

#include <limits>
#include <vector>
#include <queue>
#include <ostream>

#ifndef BREADTHFIRSTSEARCH_81910Uijn
#define BREADTHFIRSTSEARCH_81910Uijn

namespace Graphs {

  template <class AdjacencyListGraph>
  struct BreadthFirstSearch {
    typedef AdjacencyListGraph adjacencylist_graph_type;
    typedef typename adjacencylist_graph_type::vertex_type vertex_type;
    typedef typename adjacencylist_graph_type::size_type size_type;
    typedef typename adjacencylist_graph_type::neighbour_iterator neighbour_iterator;
    //! unreachable distance
    static const size_type infinity;
    //! singular vertex
    static const vertex_type nil;

    struct Node {
      size_type d;
      vertex_type p;
      Node() : d(infinity) {}
    };
    friend std::ostream& operator <<(std::ostream& out, const Node& node) {
      std::cout << "Distance: ";
      if (node.d == infinity) std::cout << "infinity";
      else {
        std::cout << node.d;
        std::cout << "; Parent: ";
        if (node.p == nil) std::cout << "nil";
        else std::cout << node.p;
      }
      return std::cout;
    }
    typedef std::vector<Node> result_vector_type;

    /*! Compute the BFS for root s, and return the vector of pairs
        distance/parent, representing the tree.
        Unreachable vertices have undefined parents.
    */
    result_vector_type operator() (const adjacencylist_graph_type& G, const vertex_type s) const {
      assert(s < G.N);
      result_vector_type R(G.N);
      std::queue<vertex_type> Q;
      R[s].d = 0;
      R[s].p = nil;
      Q.push(s);
      while (not Q.empty()) {
        const vertex_type u = Q.front();
        Q.pop();
        const size_type du = R[u].d;
        const neighbour_iterator nend = G[u].end();
        for (neighbour_iterator i = G[u].begin(); i != nend; ++i) {
          const vertex_type v = *i;
          if (R[v].d == infinity) {
            R[v].d = du + 1;
            R[v].p = u;
            Q.push(v);
          }
        }
      }
      return R;
    }

    /*! For symmetric digraphs (represting undirected graphs):
        perform BFS on all vertices in the given order, and return
        the vector of pairs distance/parent, representing the forest
        of BFS-trees.
    */
    result_vector_type operator() (const adjacencylist_graph_type& G) const {
      result_vector_type R(G.N);
      if (G.N == 0) return R;
      std::queue<vertex_type> Q;
      for (vertex_type s = 0; s < G.N; ++s) {
        if (R[s].d == infinity) { // s is taken as the root of a new BFS-tree
          R[s].d = 0;
          R[s].p = nil;
          Q.push(s);
          assert(Q.size() == 1);
          while (not Q.empty()) {
            const vertex_type u = Q.front();
            Q.pop();
            const size_type du = R[u].d;
            const neighbour_iterator nend = G[u].end();
            for (neighbour_iterator i = G[u].begin(); i != nend; ++i) {
              const vertex_type v = *i;
              if (R[v].d == infinity) {
                R[v].d = du + 1;
                R[v].p = u;
                Q.push(v);
              }
            }
          }
        }
      }
      return R;
    }
  };

  template <class AdjacencyListGraph>
  const typename BreadthFirstSearch<AdjacencyListGraph>::size_type
    BreadthFirstSearch<AdjacencyListGraph>::infinity = 
    std::numeric_limits<typename BreadthFirstSearch<AdjacencyListGraph>::size_type>::max();

  template <class AdjacencyListGraph>
  const typename BreadthFirstSearch<AdjacencyListGraph>::vertex_type
    BreadthFirstSearch<AdjacencyListGraph>::nil =
    BreadthFirstSearch<AdjacencyListGraph>::infinity;

}

#endif
