// Oliver Kullmann, 22.12.2009 (Swansea)

/*!
  \file 200910/Framework/Measurement.hpp
  \brief Components for various complexity measurements of algorithms
*/

#ifndef MEASUREMENT_NNvTr4k
#define MEASUREMENT_NNvTr4k

#include <iostream>
#include <string>
#include <stdexcept>

namespace IntroAlgo {
  namespace Framework {

    const std::string error_file = "Measurement[ERROR]: File not writable.";
    const std::string error_output = "Measurement[ERROR]: Output not writable.";
    const std::string output_filename_ = "IntroAlgo_Measurements";

    enum OutputHandling { with_delete, without_delete };

    /*!
      \class OutputMeasurement
      \brief For simple output of statistical data to files
    */

    class OutputMeasurement {

    public :
      std::string sep;
      bool eol;
      bool flush;

      OutputMeasurement() :
        sep(" "), eol(false), flush(false) {
        initialise();
      }

      static void set_output(std::ostream* new_out, const OutputHandling h = without_delete) {
        if (h == with_delete) delete out;
        out = new_out;
      }

      static void header_line(const std::string& header) {
        *out << header;
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
      }
      static void check_streams() {
        if (not out) throw std::runtime_error(error_output);
      }
    };

    std::ostream* OutputMeasurement::out = & std::cout;

  }
}

#endif
