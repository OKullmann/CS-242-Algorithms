// Oliver Kullmann, 4.12.2015 (Swansea)

#include <vector>
#include <iostream>
#include <ostream>

#include "Insertion.hpp"
#include "Small.hpp"

namespace {

typedef std::vector<int> vec_t;

typedef vec_t::size_type Large;
constexpr Large vec_large = 600000000;
constexpr Large vec_medium = 40000;
constexpr long loop3 = 250;

typedef double Time_point;
#include <sys/resource.h>
class UserTime {
  rusage timing;
  rusage* const ptiming;
public :
  UserTime() : ptiming(&timing) {}
  Time_point operator()() {
    getrusage(RUSAGE_SELF, ptiming);
    return timing.ru_utime.tv_sec + timing.ru_utime.tv_usec / 1000000.0;
  }
} timing;

void set_vector(vec_t& v) {
   v.resize(0);
   for (Large i = 0; i < vec_medium; ++i) v.push_back(vec_medium - i);
}

void run_insertion() {
  {std::cout << "INSERTION:\n";
  std::cout << "Sorted: " << vec_large << "\n";
  vec_t v; v.reserve(vec_large);
  for (Large i = 0; i < vec_large; ++i) v.push_back(i);
  const Time_point t0 = timing();
  Sort::insertion0(v);
  const Time_point t1 = timing();
  Sort::insertion1(v);
  const Time_point t2 = timing();
  Sort::insertion2(v);
  const Time_point t3 = timing();
  Sort::insertion3(v);
  const Time_point t4 = timing();
  Sort::insertion(v);
  const Time_point t5 = timing();
  Sort::insertion0(v);
  const Time_point t6 = timing();
  std::cout <<"0: " << t1-t0 <<"\t1: " << t2-t1 << "\t2: " << t3-t2
    << "\t3: " << t4-t3 << "\t*: " << t5-t4 << "\t0: " << t6-t5
    << std::endl;}

  {std::cout << "Inverse sorted: " << vec_medium << "\n";
  vec_t v; v.reserve(vec_medium);
  set_vector(v);
  const Time_point t0 = timing();
  Sort::insertion0(v);
  const Time_point t1 = timing();
  set_vector(v);
  const Time_point t2 = timing();
  Sort::insertion1(v);
  const Time_point t3 = timing();
  set_vector(v);
  const Time_point t4 = timing();
  Sort::insertion2(v);
  const Time_point t5 = timing();
  set_vector(v);
  const Time_point t6 = timing();
  Sort::insertion3(v);
  const Time_point t7 = timing();
  set_vector(v);
  const Time_point t8 = timing();
  Sort::insertion(v);
  const Time_point t9 = timing();
  set_vector(v);
  const Time_point t10 = timing();
  Sort::insertion0(v);
  const Time_point t11 = timing();
  std::cout << "0: " << t1-t0 << "\t1: " << t3-t2 << "\t2: " << t5-t4
    << "\t3: " << t7-t6 << "\t*: " << t9-t8 << "\t0: " << t11-t10
    << std::endl;}
}

void run_3() {
  std::cout << "3 ELEMENTS:\n";
  std::cout << "Loop: " << loop3 << "^3 = " << loop3*loop3*loop3 << "\n";
  vec_t v; v.resize(3);
  const Time_point t0 = timing();
  for(int a=0; a<loop3; ++a)for(int b=0; b<loop3; ++b)for(int c=0; c<loop3; ++c) {v=vec_t({{a,b,c}}); Sort::insertion0(v);}
  const Time_point t1 = timing();
  for(int a=0; a<loop3; ++a)for(int b=0; b<loop3; ++b)for(int c=0; c<loop3; ++c) {v=vec_t({{a,b,c}}); Sort::insertion1(v);}
  const Time_point t2 = timing();
  for(int a=0; a<loop3; ++a)for(int b=0; b<loop3; ++b)for(int c=0; c<loop3; ++c) {v=vec_t({{a,b,c}}); Sort::insertion2(v);}
  const Time_point t3 = timing();
  for(int a=0; a<loop3; ++a)for(int b=0; b<loop3; ++b)for(int c=0; c<loop3; ++c) {v=vec_t({{a,b,c}}); Sort::insertion3(v);}
  const Time_point t4 = timing();
  for(int a=0; a<loop3; ++a)for(int b=0; b<loop3; ++b)for(int c=0; c<loop3; ++c) {v=vec_t({{a,b,c}}); Sort::insertion(v);}
  const Time_point t5 = timing();
  for(int a=0; a<loop3; ++a)for(int b=0; b<loop3; ++b)for(int c=0; c<loop3; ++c) {v=vec_t({{a,b,c}}); Sort::size3_(v);}
  const Time_point t6 = timing();
  for(int a=0; a<loop3; ++a)for(int b=0; b<loop3; ++b)for(int c=0; c<loop3; ++c) {v=vec_t({{a,b,c}}); Sort::size3(v);}
  const Time_point t7 = timing();
  std::cout << "0: " << t1-t0 << "\t1: " << t2-t1 << "\t2: " << t3-t2
    << "\t3: " << t4-t3 << "\t*: " << t5-t4 << "\t_3_: " << t6-t5 <<
    "\t_3: " << t7-t6 << std::endl;
}

}

int main(const int argc, const char* const argv[]) {
  run_insertion();
  run_3();
}
