// Oliver Kullmann, 1.3.2010 (Swansea)

/*!
  \file AdjacencyList.hpp
  \brief Simple representation of graphs and digraphs via adjacency lists
*/

#ifndef ADJACENCYLIST_pqpMAm9I6T
#define ADJACENCYLIST_pqpMAm9I6T

#include <vector>
#include <cassert>
#include <utility>

namespace Graphs {

  /*!
    \class AdjacencyList
    \brief Representing graphs and digraphs via adjacency lists
  */

  struct AdjacencyList {
    typedef unsigned int vertex_type;
    typedef std::pair<vertex_type, vertex_type> edge_type;
    typedef vertex_type size_type;

    //! number of vertices
    const size_type N;
    // the vertices are 0, ..., N-1

    typedef std::vector<vertex_type> adjacency_list_type;
    typedef adjacency_list_type::const_iterator neighbour_iterator;
    typedef std::vector<adjacency_list_type> adjacency_vector_type;

    //! creates the graph with N vertices and 0 edges
    AdjacencyList(const size_type N) : N(N), A(N) {}

    //! reads a sequence of edges from a sequence, and inserts them
    template <class Iterator>
    void add_edges(
        const Iterator begin,
        const Iterator end,
        const bool directed = false) {
      for (Iterator i = begin; i != end; ++i) {
        const edge_type e = *i;
        const vertex_type u = e.first;
        const vertex_type v = e.second;
        A[u].push_back(v);
        if (not directed) A[v].push_back(u);
      }
    }

    //! returns a constant reference to the vector of neighbours
    const adjacency_list_type& operator[] (const vertex_type v) const {
      assert(v < N);
      return A[v];
    }

  private :

    adjacency_vector_type A;

  };

}

#endif
