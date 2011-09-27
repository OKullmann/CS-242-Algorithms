// Oliver Kullmann, 23.2.2010 (Swansea)

/*!
  \file ConnectedComponents.cpp
  \brief Applying the computation of connected components by disjoint-sets data structures for random graphs (using the model of given edge-probability)
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include <Utilities/Timing.hpp>

#include "LinkedLists.hpp"
#include "RootedTrees.hpp"

#include "RandomGraphs.hpp"
#include "ConnectedComponents.hpp"

namespace {

  enum { errcode_parameter = 1, errcode_parameter1 = 2, errcode_parameter2 = 3,
         errcode_probability = 4 };
        
  const std::string program = "ConnectedComponents";
  const std::string err = "ERROR[" + program + "]: ";

  typedef DisjointSets::RandomGraph graph_type;
  typedef graph_type::size_type size_type;
  typedef graph_type::probability_type probability_type;

  template <template <typename Element> class DSets>
  void measure_and_output(
      const graph_type& G,
      const std::string& text,
      Utilities::SystemTime& T) {
    std::cout << std::setw(15) << text << ": " << std::flush; 
    std::cout << std::setw(7) << DisjointSets::Number_connected_components<DSets>()(G) << "; ";
    std::cout << Utilities::TimingOutput(T(),3,7) << "\n";
  }

}

int main(const int argc, const char* const argv[]) {
  
  if (argc != 3 and argc != 4) {
    std::cerr << err << "Two or three parameters are needed: N and p, while "
      "a third parameter indicates that only fast algorithms are used.\n";
    return errcode_parameter;
  }

  size_type dummy1;
  {
    std::stringstream parameters;
    parameters << argv[1];
    parameters >> dummy1;
    if (not parameters) {
      std::cerr << err << "Error when reading the first parameter, the number of vertices (which must be an unsigned integer).\n";
      return errcode_parameter1;
    }
  }
  const size_type N = dummy1;

  probability_type dummy2;
  {
    std::stringstream parameters;
    parameters << argv[2];
    parameters >> dummy2;
    if (not parameters) {
      std::cerr << err << "Error when reading the second parameter, the edge probability (which must be a floating-pointer number).\n";
      return errcode_parameter2;
    }
    if (dummy2 < 0 or dummy2 > 1) {
      std::cerr << err << "The edge probability must lie in the intervall from 0 to 1.\n";
      return errcode_probability;
    }
  }
  const probability_type p = dummy2;

  std::cout << "Creating the graph with " << N << " vertices: " << std::flush;
  using namespace Utilities;
  SystemTime T;
  const graph_type G(N,p);
  std::cout << G.edge_list.size() << " edges created in "
    << TimingOutput(T()) << ".\n";

  using namespace DisjointSets;
  if (argc == 3)
    measure_and_output<LinkedLists>(G, "LinkedLists", T);
  measure_and_output<LinkedListsH>(G, "LinkedListsH", T);
  if (argc == 3)
    measure_and_output<RootedTrees>(G, "RootedTrees", T);
  measure_and_output<RootedTreesHS>(G, "RootedTreesHS", T);
  measure_and_output<RootedTreesHP>(G, "RootedTreesHP", T);
  measure_and_output<RootedTreesHSP>(G, "RootedTreesHSP", T);
}
