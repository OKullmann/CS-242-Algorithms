// Oliver Kullmann, 22.12.2009 (Swansea)

/*!
  \file 200910/Framework/Utilities.hpp
  \brief Various utilities
*/

#ifndef UTILITIES_jBfRe3
#define UTILITIES_jBfRe3

#include <string>
#include <sstream>
#include <stdexcept>

namespace IntroAlgo {
  namespace Framework {

    enum ExperimentErrors { parameter_error = 1 };

    template <typename T>
    T lexical_cast(const std::string x) {
      std::stringstream s;
      s << x;
      T result;
      s >> result;
      if (not s)
        throw std::runtime_error("IntroAlgo::Framework::lexical_cast : Conversion error.");
      return result;
    }


  }
}

#endif
