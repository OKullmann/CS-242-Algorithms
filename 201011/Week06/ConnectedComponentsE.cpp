// Oliver Kullmann, 25.2.2010 (Swansea)

/*!
  \file ConnectedComponentsE.cpp
  \brief Applying the computation of connected components by the fast disjoint-sets data structures for random graphs (using the model of given number of edges)
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
        
  const std::string program = "ConnectedComponentsE";
  const std::string err = "ERROR[" + program + "]: ";

  typedef DisjointSets::RandomGraphE graph_type;
  typedef graph_type::size_type size_type;

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
  
  if (argc != 3) {
    std::cerr << err << "Exactly two parameters are needed: N and K.\n";
    return errcode_parameter;
  }

  size_type dummy;
  {
    std::stringstream parameters;
    parameters << argv[1];
    parameters >> dummy;
    if (not parameters) {
      std::cerr << err << "Error when reading the first parameter, the number of vertices (which must be an unsigned integer).\n";
      return errcode_parameter1;
    }
  }
  const size_type N = dummy;
  {
    std::stringstream parameters;
    parameters << argv[2];
    parameters >> dummy;
    if (not parameters) {
      std::cerr << err << "Error when reading the second parameter, the number of edges (which must be an unsigned integer).\n";
      return errcode_parameter2;
    }
  }
  const size_type K = dummy;


  std::cout << "Creating the graph with " << N << " vertices and " << K << " edges: " << std::flush;
  using namespace Utilities;
  SystemTime T;
  const graph_type G(N,K);
  std::cout << TimingOutput(T()) << ".\n";

  using namespace DisjointSets;
  measure_and_output<LinkedListsH>(G, "LinkedListsH", T);
  measure_and_output<RootedTreesHS>(G, "RootedTreesHS", T);
  measure_and_output<RootedTreesHP>(G, "RootedTreesHP", T);
  measure_and_output<RootedTreesHSP>(G, "RootedTreesHSP", T);
}
