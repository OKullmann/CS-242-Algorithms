// Oliver Kullmann, 4.12.2015 (Swansea)
/* Copyright 2015 Oliver Kullmann
This file is free software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation and included in this library; either version 3 of the License, or
any later version. */

#include <vector>
#include <iostream>
#include <ostream>
#include <algorithm>

#include "Insertion.hpp"
#include "Small.hpp"

namespace {

typedef std::vector<int> vec_t;

typedef vec_t::size_type Large;
constexpr Large vec_large = 600000000;
constexpr Large vec_medium = 40000;
constexpr long loop3 = 800;
constexpr long loop4 = 150;

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
  std::sort(v.begin(),v.end());
  const Time_point t7 = timing();
  std::cout <<"0: " << t1-t0 <<"\t1: " << t2-t1 << "\t2: " << t3-t2
    << "\t3: " << t4-t3 << "\t*: " << t5-t4 << "\t0: " << t6-t5
    << "\tstd: " << t7-t6 << std::endl;}

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
  set_vector(v);
  const Time_point t12 = timing();
  std::sort(v.begin(),v.end());
  const Time_point t13 = timing();
  std::cout << "0: " << t1-t0 << "\t1: " << t3-t2 << "\t2: " << t5-t4
    << "\t3: " << t7-t6 << "\t*: " << t9-t8 << "\t0: " << t11-t10
    << "\tstd: " << t13-t12 <<std::endl;}
}

void run_3() {
  std::cout << "3 ELEMENTS:\n";
  std::cout << "Loop: " << loop3 << "^3 = " << loop3*loop3*loop3 << "\n";
  vec_t v; v.resize(3);
  const Time_point t0 = timing();
  for(int a=0;a<loop3;++a){v[0]=a;for(int b=0;b<loop3;++b){v[1]=b;for(int c=0;c<loop3;++c) {v[3]=c; Sort::insertion0(v);}}}
  const Time_point t1 = timing();
  for(int a=0;a<loop3;++a){v[0]=a;for(int b=0;b<loop3;++b){v[1]=b;for(int c=0;c<loop3;++c) {v[2]=c; Sort::insertion1(v);}}}
  const Time_point t2 = timing();
  for(int a=0;a<loop3;++a){v[0]=a;for(int b=0;b<loop3;++b){v[1]=b;for(int c=0;c<loop3;++c) {v[2]=c; Sort::insertion2(v);}}}
  const Time_point t3 = timing();
  for(int a=0;a<loop3;++a){v[0]=a;for(int b=0;b<loop3;++b){v[1]=b;for(int c=0;c<loop3;++c) {v[2]=c; Sort::insertion3(v);}}}
  const Time_point t4 = timing();
  for(int a=0;a<loop3;++a){v[0]=a;for(int b=0;b<loop3;++b){v[1]=b;for(int c=0;c<loop3;++c) {v[2]=c; Sort::insertion(v);}}}
  const Time_point t5 = timing();
  for(int a=0;a<loop3;++a){v[0]=a;for(int b=0;b<loop3;++b){v[1]=b;for(int c=0;c<loop3;++c) {v[2]=c; Sort::size3(v.begin());}}}
  const Time_point t6 = timing();
  for(int a=0;a<loop3;++a){v[0]=a;for(int b=0;b<loop3;++b){v[1]=b;for(int c=0;c<loop3;++c) {v[2]=c; Sort::size3_(v.begin());}}}
  const Time_point t7 = timing();
  for(int a=0;a<loop3;++a){v[0]=a;for(int b=0;b<loop3;++b){v[1]=b;for(int c=0;c<loop3;++c) {v[2]=c; std::sort(v.begin(),v.end());}}}
  const Time_point t8 = timing();
  std::cout << "0: " << t1-t0 << "\t1: " << t2-t1 << "\t2: " << t3-t2
    << "\t3: " << t4-t3 << "\t*: " << t5-t4 << "\t_3: " << t6-t5 <<
    "\t_3_: " << t7-t6 << "\tstd: " << t8-t7 << std::endl;
}

void run_4() {
  std::cout << "4 ELEMENTS:\n";
  std::cout << "Loop: " << loop4 << "^4 = " << loop4*loop4*loop4*loop4 << "\n";
  vec_t v; v.resize(4);
  const Time_point t0 = timing();
  for(int a=0;a<loop4;++a){v[0]=a;for(int b=0;b<loop4;++b){v[1]=b;for(int c=0;c<loop4;++c){v[2]=c;for(int d=0;d<loop4;++d) {v[3]=d; Sort::insertion0(v);}}}}
  const Time_point t1 = timing();
  for(int a=0;a<loop4;++a){v[0]=a;for(int b=0;b<loop4;++b){v[1]=b;for(int c=0;c<loop4;++c){v[2]=c;for(int d=0;d<loop4;++d) {v[3]=d; Sort::insertion1(v);}}}}
  const Time_point t2 = timing();
  for(int a=0;a<loop4;++a){v[0]=a;for(int b=0;b<loop4;++b){v[1]=b;for(int c=0;c<loop4;++c){v[2]=c;for(int d=0;d<loop4;++d) {v[3]=d; Sort::insertion2(v);}}}}
  const Time_point t3 = timing();
  for(int a=0;a<loop4;++a){v[0]=a;for(int b=0;b<loop4;++b){v[1]=b;for(int c=0;c<loop4;++c){v[2]=c;for(int d=0;d<loop4;++d) {v[3]=d; Sort::insertion3(v);}}}}
  const Time_point t4 = timing();
  for(int a=0;a<loop4;++a){v[0]=a;for(int b=0;b<loop4;++b){v[1]=b;for(int c=0;c<loop4;++c){v[2]=c;for(int d=0;d<loop4;++d) {v[3]=d; Sort::insertion(v);}}}}
  const Time_point t5 = timing();
  for(int a=0;a<loop4;++a){v[0]=a;for(int b=0;b<loop4;++b){v[1]=b;for(int c=0;c<loop4;++c){v[2]=c;for(int d=0;d<loop4;++d) {v[3]=d; Sort::size4(v.begin());}}}}
  const Time_point t6 = timing();
  for(int a=0;a<loop4;++a){v[0]=a;for(int b=0;b<loop4;++b){v[1]=b;for(int c=0;c<loop4;++c){v[2]=c;for(int d=0;d<loop4;++d) {v[3]=d; Sort::size4_(v.begin());}}}}
  const Time_point t7 = timing();
  for(int a=0;a<loop4;++a){v[0]=a;for(int b=0;b<loop4;++b){v[1]=b;for(int c=0;c<loop4;++c){v[2]=c;for(int d=0;d<loop4;++d) {v[3]=d; std::sort(v.begin(),v.end());}}}}
  const Time_point t8 = timing();
  std::cout << "0: " << t1-t0 << "\t1: " << t2-t1 << "\t2: " << t3-t2
    << "\t3: " << t4-t3 << "\t*: " << t5-t4 << "\t_3: " << t6-t5 <<
    "\t_3_: " << t7-t6 << "\tstd: " << t8-t7 << std::endl;
}

}

int main(const int argc, const char* const argv[]) {
  run_insertion();
  run_3();
  run_4();
}
