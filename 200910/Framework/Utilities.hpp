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
#include <ostream>

namespace IntroAlgo {
  namespace Framework {

    /*!
      \enum ExperimentErrors
      \brief Error return-codes for experiment-programs
    */
    enum ExperimentErrors { parameter_error = 1 };

    /*!
      \brief Converting string into type T
    */
    template <typename T>
    T lexical_cast(const std::string& x) {
      std::stringstream s;
      s << x;
      T result;
      s >> result;
      if (not s)
        throw std::runtime_error("IntroAlgo::Framework::lexical_cast : Conversion error.");
      return result;
    }

    /*!
      \class Wrapper
      \brief Wrapping containers, so that the stream-inserter can be overloaded.
    */
    template <class Container>
    struct Wrapper {
      const Container& s;
      Wrapper(const Container& s) : s(s) {}
    };
    /*!
      \brief Output of containers

      Use "out << cw(X)" for output of container X.
    */
    template <class Container>
    inline Wrapper<Container> cw(const Container& s) { return Wrapper<Container>(s); }
    template <class Container>
    std::ostream& operator <<(std::ostream& out, const Wrapper<Container>& s) {
      typedef typename Container::const_iterator iterator;
      const iterator end = s.s.end();
      for (iterator i = s.s.begin(); i != end; ++i)
        out << *i << " ";
      return out;
    }

  }
}

#endif
