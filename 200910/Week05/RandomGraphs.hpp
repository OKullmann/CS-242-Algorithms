// Oliver Kullmann, 23.2.2010 (Swansea)

/*!
  \file RandomGraphs.hpp
  \brief Creating random graphs with N vertices and with edge-probability p
*/

#ifndef RANDOMGRAPHS_536Rdlpo8
#define RANDOMGRAPHS_536Rdlpo8

#include <cstdlib>
#include <vector>
#include <utility>

namespace DisjointSets {

  //! produces a pseudo-random bit:
  inline bool random_bit(const float p) {
    return ((float) std::rand()) / RAND_MAX < p;
  }

  /*!
    \class RandomGraph
    \brief Computes a random graph with vertices 0,...,N-1, where every
    possible edge has probability p.
  */
  struct RandomGraph {
    typedef unsigned int vertex_type;
    typedef std::pair<vertex_type,vertex_type> edge_type;
    typedef std::vector<edge_type> edge_list_type;
    typedef edge_list_type::size_type size_type;
    typedef edge_list_type::const_iterator const_iterator;
    typedef float probability_type;

    const size_type N;
    const probability_type p;
    const edge_list_type edge_list;

    RandomGraph(const size_type N, const probability_type p) :
      N(N), p(p), edge_list(create()) {}

  private :

    edge_list_type create() const {
      edge_list_type L;
      L.reserve((size_type) (p * N*(N-1)/2));
      for (vertex_type i = 0; i < N; ++i)
        for (vertex_type j = i+1; j < N; ++j)
          if (random_bit(p)) L.push_back(edge_type(i,j));
      return L;
    }
  };

  //! produces a pseudo-random number from 0 to N-1 (inclusive):
  inline unsigned int random_number(const unsigned int N) {
    return (unsigned int) ((std::rand() / (RAND_MAX + 1.0)) * N);
  }

  /*!
    \class RandomGraphE
    \brief Computes a random graph with vertices 0,...,N-1 and with K edges
    (where all edges are equally likely)
  */
  struct RandomGraphE {
    typedef unsigned int vertex_type;
    typedef std::pair<vertex_type,vertex_type> edge_type;
    typedef std::vector<edge_type> edge_list_type;
    typedef edge_list_type::size_type size_type;
    typedef edge_list_type::const_iterator const_iterator;
    typedef float probability_type;

    const size_type N;
    const size_type K;
    const edge_list_type edge_list;

    RandomGraphE(const size_type N, const size_type K) :
      N(N), K(K), edge_list(create()) {}

  private :

    edge_list_type create() const {
      edge_list_type L;
      if (N <= 1) return L;
      L.reserve(K);
      for (vertex_type i = 0; i < K; ++i) {
        const vertex_type u = random_number(N);
        const vertex_type r = random_number(N-1);
        const vertex_type v = (r < u) ? r : r+1;
        L.push_back(edge_type(u,v));
      }
      return L;
    }
  };

}

#endif
