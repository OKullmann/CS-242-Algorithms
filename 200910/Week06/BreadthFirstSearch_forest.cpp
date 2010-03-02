// Oliver Kullmann, 1.3.2010 (Swansea)

/*!
  \file BreadthFirstSearch_forest.cpp
  \brief Application for exploring breadth-first search forests on
  (undirected) graphs
*/

#include <iostream>
#include <sstream>
#include <vector>

#include "AdjacencyList.hpp"
#include "BreadthFirstSearch.hpp"

namespace {

  enum { errcode_parameter = 1, errcode_parameter_reading = 2,
         errcode_vertex = 3 };

  const std::string program = "BreadthFirstSearch_forest";
  const std::string err = "ERROR[" + program + "]: ";

  typedef Graphs::AdjacencyList graph_type;
  typedef graph_type::vertex_type vertex_type;
  typedef graph_type::size_type size_type;
  typedef graph_type::edge_type edge_type;
  typedef Graphs::BreadthFirstSearch<graph_type> bfs_type;
  typedef bfs_type::result_vector_type result_vector_type;

}

int main(const int argc, const char* const argv[]) {

  if (argc != 2) {
    std::cerr << err << "Exactly one parameter is needed, the number N of vertices.\n";
    return errcode_parameter;
  }

  size_type dummy;
  {
    std::stringstream parameters;
    parameters << argv[1];
    parameters >> dummy;
    if (not parameters) {
      std::cerr << err << "Error when reading the parameter, the number of items (which must be a non-negative integer).\n";
      return errcode_parameter_reading;
    }
  }
  const size_type N = dummy;
  const bool directed = false;

  graph_type G(N);
  typedef std::vector<edge_type> edge_list_type;
  edge_list_type E;
  for (;;) {
    vertex_type u, v;
    if (not (std::cin >> u >> v)) break;
    if (u >= N or v >= N) {
      std::cerr << err << "Vertices must be integers from 0 to " << N-1 << ".\n";
      return errcode_vertex;
    }
    E.push_back(edge_type(u,v));
  }
  std::cout << E.size() << " edges have been read.\n";
  G.add_edges(E.begin(), E.end(), directed);

  const result_vector_type R = bfs_type()(G);
  for (vertex_type v = 0; v < N; ++v)
    std::cout << "Vertex " << v << ": " << R[v] << "\n";
}
