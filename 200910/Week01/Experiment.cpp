// Oliver Kullmann, 22.12.2009 (Swansea)

/*!
  \file 200910/Week01/Experiment.cpp
  \brief Experiments with sorting algorithms
*/

#include <string>
#include <iostream>

#include <200910/Framework/Measurement.hpp>

#include <200910/Week01/Sorting.hpp>

namespace {

  const std::string program = "Experiment";
  const std::string err = "ERROR[" + program + "]: ";

}

int main(const int argc, const char* const argv[]) {
  if (argc != 2) {
    std::cerr << err << "Exactly one parameter is required, the number N of experiments.\n";
    return IntroAlgo::Framework::parameter_error;
  }

  const int N = IntroAlgo::Framework::lexical_cast<int>(argv[1]);

}
