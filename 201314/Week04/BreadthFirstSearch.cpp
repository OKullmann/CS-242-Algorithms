// Oliver Kullmann, 1.3.2010 (Swansea)

/*!
  \file BreadthFirstSearch.cpp
  \brief Application for exploring breadth-first search on directed graphs

  Use by
  \verbatim
BreadthFirstSearch N s
  \endverbatim
  where N is the number of vertices, and 0 <= s < N is the root of the BFS
  to be computed. The program then reads directed edges from standard input,
  where an edge is a pair of vertices, separated by spaces.
*/

#include <iostream>
#include <sstream>
#include <vector>

#include "AdjacencyList.hpp"
#include "BreadthFirstSearch.hpp"

namespace {

  enum { errcode_parameter = 1, errcode_parameter_reading = 2,
         errcode_parameter2_reading = 3, errcode_vertex = 4 };

  const std::string program = "BreadthFirstSearch";
  const std::string err = "ERROR[" + program + "]: ";

  typedef Graphs::AdjacencyList graph_type;
  typedef graph_type::vertex_type vertex_type;
  typedef graph_type::size_type size_type;
  typedef graph_type::edge_type edge_type;
  typedef Graphs::BreadthFirstSearch<graph_type> bfs_type;
  typedef bfs_type::result_vector_type result_vector_type;

}

int main(const int argc, const char* const argv[]) {

  if (argc != 3) {
    std::cerr << err << "Exactly two parameter are needed:\n"
      "  the number N of vertices, and the start vertex s.\n";
    return errcode_parameter;
  }

  size_type dummy;
  {
    std::stringstream parameters;
    parameters << argv[1];
    parameters >> dummy;
    if (not parameters) {
      std::cerr << err << "Error when reading the number N of items (which must be a non-negative integer).\n";
      return errcode_parameter_reading;
    }
  }
  const size_type N = dummy;
  {
    std::stringstream parameters;
    parameters << argv[2];
    parameters >> dummy;
    if (not parameters) {
      std::cerr << err << "Error when reading the start vertex (which must be a non-negative integer).\n";
      return errcode_parameter_reading;
    }
    if (dummy >= N) {
      std::cerr << err << "Vertices must be integers from 0 to " << N-1 << ".\n";
      return errcode_vertex;
    }
  }
  const vertex_type s = dummy;

  const bool directed = true;

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

  const result_vector_type R = bfs_type()(G,s);
  for (vertex_type v = 0; v < N; ++v)
    std::cout << "Vertex " << v << ": " << R[v] << "\n";
}
