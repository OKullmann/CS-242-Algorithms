// Oliver Kullmann, 24.2.2010 (Swansea)

/*!
  \file Timing.hpp
  \brief Tools for measing times and for their output
*/

#ifndef TIMING_pqpBag16tr
#define TIMING_pqpBag16tr

#include <ctime>
#include <ostream>
#include <iomanip>

namespace Utilities {

  /*!
    \class SystemTime
    \brief Stop-watch and total time (in seconds)

    After an object T has been created, by T() we get the time elapsed since
    the last request (starting with creation time), while by T.total() we
    get the total time since start.
  */

  class SystemTime {
  public :
    SystemTime() : start_time(std::clock()), time_point(start_time) {}
    double operator() () {
      const std::clock_t new_time_point = std::clock();
      const double elapsed = double(new_time_point - time_point) / CLOCKS_PER_SEC;
      time_point = new_time_point;
      return elapsed;
    }
    double total() const {
      return double(std::clock() - start_time) / CLOCKS_PER_SEC;
    }
  private :
    const std::clock_t start_time;
    std::clock_t time_point;
  };

  /*!
    \class TimingOutput
    \brief Wrapper for times in seconds together with format information

    The formatting information is the number of decimal places after the
    decimal point, and the total width of output.
  */

  struct TimingOutput {
    TimingOutput(
      const double seconds,
      const unsigned int precision,
      const unsigned int total_width)
      : s(seconds), p(precision), w(total_width) {}
    TimingOutput(
      const double seconds,
      const unsigned int precision)
      : s(seconds), p(precision), w(p+2) {}
    TimingOutput(
      const double seconds)
      : s(seconds), p(2), w(p+2) {}
    double s;
    unsigned int p;
    unsigned int w;
  };

  std::ostream& operator <<(std::ostream& out, const TimingOutput& w) {
    return out << std::showpoint << std::fixed << std::setprecision(w.p) << std::setw(w.w) << w.s << "s";
  }

}

#endif

