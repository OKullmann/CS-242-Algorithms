// Oliver Kullmann, 22.12.2009 (Swansea)

/*!
  \file 200910/Framework/Measurement.hpp
  \brief Components for various complexity measurements of algorithms
*/

#ifndef MEASUREMENT_NNvTr4k
#define MEASUREMENT_NNvTr4k

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

namespace IntroAlgo {
  namespace Framework {

    const std::string error_file = "Measurement[ERROR]: File not writable.";
    const std::string error_output = "Measurement[ERROR]: Output not writable.";
    const std::string output_filename_ = "IntroAlgo_Measurements";

    enum OutputHandling { with_delete, without_delete };

    enum ExperimentErrors { parameter_error = 1 };

    template <typename T>
    std::string lexical_cast(const T& x) {
      std::stringstream s;
      s << x;
      if (not s)
        throw std::runtime_error("IntroAlgo::Framework::lexical_cast : Conversion error.");
      return s.str();
    }

    /*!
      \class OutputMeasurement
      \brief For simple output of statistical data to files
    */

    class OutputMeasurement {

    public :
      const std::string header_line;
      std::string sep;
      bool eol;
      bool flush;

      OutputMeasurement(const std::string& header_line_ = " size value\n") :
        header_line(header_line_), sep(" "), eol(false), flush(false) {
        initialise();
      }

      void set_output(std::ostream* new_out, const OutputHandling h = without_delete) {
        if (h == with_delete) delete out;
        out = new_out;
      }

    template <typename Input>
    friend OutputMeasurement& operator<< (
      OutputMeasurement& M,
      const Input& x) {
      M.check_streams();
      *M.out << x << M.sep;
      if (M.eol) *M.out << "\n";
      if (M.flush) *M.out << std::flush;
      return M;
    }

      ~OutputMeasurement() {
        *out << "\n";
      }

    private :
      static std::ostream* out;

      void initialise() {
        check_streams();
        *out << header_line;
      }
      static void check_streams() {
        if (not out) throw std::runtime_error(error_output);
      }
    };

    std::ostream* OutputMeasurement::out = & std::cout;

  }
}

#endif
