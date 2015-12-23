// Oliver Kullmann, 4.12.2015 (Swansea)
/* Copyright 2015 Oliver Kullmann
This file is free software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation and included in this library; either version 3 of the License, or
any later version. */

#include <iostream>
#include <ostream>
#include <algorithm>

#include "Insertion.hpp"
#include "Small.hpp"
#include "Selection.hpp"
#include "Generators.hpp"

namespace {

using Sort::vec_t;
using Sort::Large;

constexpr Large vec_large = 600000000;
constexpr Large vec_medium = 40000;
constexpr long loop3 = 800;
constexpr long loop4 = 150;
constexpr long loop7 = 20;

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


void run_insertion() {
  {std::cout << "INSERTION:\n";
  std::cout << "Sorted: " << vec_large << "\n";
  vec_t v;
  Sort::increasing(v,vec_large);
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
  std::cout <<"i0: " << t1-t0 <<"\ti1: " << t2-t1 << "\ti2: " << t3-t2
    << "\ti3: " << t4-t3 << "\ti: " << t5-t4 << "\ti0: " << t6-t5
    << "\nstd: " << t7-t6 << std::endl;}

  {std::cout << "Inverse sorted: " << vec_medium << "\n";
  vec_t v;
  Sort::decreasing(v,vec_medium);
  const Time_point t0 = timing();
  Sort::insertion0(v);
  const Time_point t1 = timing();
  Sort::decreasing(v,vec_medium);
  const Time_point t2 = timing();
  Sort::insertion1(v);
  const Time_point t3 = timing();
  Sort::decreasing(v,vec_medium);
  const Time_point t4 = timing();
  Sort::insertion2(v);
  const Time_point t5 = timing();
  Sort::decreasing(v,vec_medium);
  const Time_point t6 = timing();
  Sort::insertion3(v);
  const Time_point t7 = timing();
  Sort::decreasing(v,vec_medium);
  const Time_point t8 = timing();
  Sort::insertion(v);
  const Time_point t9 = timing();
  Sort::decreasing(v,vec_medium);
  const Time_point t10 = timing();
  Sort::insertion0(v);
  const Time_point t11 = timing();
  Sort::decreasing(v,vec_medium);
  const Time_point t12 = timing();
  std::sort(v.begin(),v.end());
  const Time_point t13 = timing();
  std::cout << "i0: " << t1-t0 << "\ti1: " << t3-t2 << "\ti2: " << t5-t4
    << "\ti3: " << t7-t6 << "\ti: " << t9-t8 << "\ti0: " << t11-t10
    << "\nstd: " << t13-t12 <<std::endl;}
}

void run_selection() {
  {std::cout << "SELECTION:\n";
  std::cout << "Sorted: " << vec_medium << "\n";
  vec_t v;
  Sort::increasing(v,vec_medium);
  const Time_point t0 = timing();
  Sort::selection0(v);
  const Time_point t1 = timing();
  Sort::selection1(v);
  const Time_point t2 = timing();
  Sort::selection_bi(v);
  const Time_point t3 = timing();
  std::sort(v.begin(),v.end());
  const Time_point t4 = timing();
  std::cout << "s0: " << t1-t0 << "\ts1: " << t2-t1 << "\tbi: " << t3-t2
    << "\nstd: " << t4-t3 << std::endl;}

  {std::cout << "Inverse sorted: " << vec_medium << "\n";
  vec_t v;
  Sort::decreasing(v,vec_medium);
  const Time_point t0 = timing();
  Sort::selection0(v);
  const Time_point t1 = timing();
  Sort::decreasing(v,vec_medium);
  const Time_point t2 = timing();
  Sort::selection1(v);
  const Time_point t3 = timing();
  Sort::decreasing(v,vec_medium);
  const Time_point t4 = timing();
  Sort::selection_bi(v);
  const Time_point t5 = timing();
  Sort::decreasing(v,vec_medium);
  const Time_point t6 = timing();
  std::sort(v.begin(),v.end());
  const Time_point t7 = timing();
  std::cout << "s0: " << t1-t0 << "\ts1: " << t3-t2 << "\tbi: " << t5-t4
    << "\nstd: " << t7-t6 << std::endl;}

  {std::cout << "Constant: " << vec_large << "\n";
  vec_t v(vec_large);
  const Time_point t0 = timing();
  Sort::selection_bi(v);
  const Time_point t1 = timing();
  Sort::insertion(v);
  const Time_point t2 = timing();
  std::sort(v.begin(),v.end());
  const Time_point t3 = timing();
  std::cout << "bi: " << t1-t0
    << "\ni: " << t2-t1
    << "\nstd: " << t3-t2 << std::endl;}
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
  for(int a=0;a<loop3;++a){v[0]=a;for(int b=0;b<loop3;++b){v[1]=b;for(int c=0;c<loop3;++c) {v[2]=c; Sort::selection0(v);}}}
  const Time_point t6 = timing();
   for(int a=0;a<loop3;++a){v[0]=a;for(int b=0;b<loop3;++b){v[1]=b;for(int c=0;c<loop3;++c) {v[2]=c; Sort::selection1(v);}}}
  const Time_point t7 = timing();
  for(int a=0;a<loop3;++a){v[0]=a;for(int b=0;b<loop3;++b){v[1]=b;for(int c=0;c<loop3;++c) {v[2]=c; Sort::selection_bi(v);}}}
  const Time_point t8 = timing();
  for(int a=0;a<loop3;++a){v[0]=a;for(int b=0;b<loop3;++b){v[1]=b;for(int c=0;c<loop3;++c) {v[2]=c; Sort::size3(v.begin());}}}
  const Time_point t9 = timing();
  for(int a=0;a<loop3;++a){v[0]=a;for(int b=0;b<loop3;++b){v[1]=b;for(int c=0;c<loop3;++c) {v[2]=c; Sort::size3_(v.begin());}}}
  const Time_point t10 = timing();
  for(int a=0;a<loop3;++a){v[0]=a;for(int b=0;b<loop3;++b){v[1]=b;for(int c=0;c<loop3;++c) {v[2]=c; std::sort(v.begin(),v.end());}}}
  const Time_point t11 = timing();
  std::cout << "i0: " << t1-t0 << "\ti1: " << t2-t1 << "\ti2: " << t3-t2
    << "\ti3: " << t4-t3 << "\ti: " << t5-t4
    << "\ns0: " << t6-t5 << "\ts1: " << t7-t6 << "\tbi: " << t8-t7
    << "\n_3: " << t9-t8 << "\t_3_: " << t10-t9
    << "\nstd: " << t11-t10 << std::endl;
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
  for(int a=0;a<loop4;++a){v[0]=a;for(int b=0;b<loop4;++b){v[1]=b;for(int c=0;c<loop4;++c){v[2]=c;for(int d=0;d<loop4;++d) {v[3]=d; Sort::selection0(v);}}}}
  const Time_point t6 = timing();
  for(int a=0;a<loop4;++a){v[0]=a;for(int b=0;b<loop4;++b){v[1]=b;for(int c=0;c<loop4;++c){v[2]=c;for(int d=0;d<loop4;++d) {v[3]=d; Sort::selection0(v);}}}}
  const Time_point t7 = timing();
  for(int a=0;a<loop4;++a){v[0]=a;for(int b=0;b<loop4;++b){v[1]=b;for(int c=0;c<loop4;++c){v[2]=c;for(int d=0;d<loop4;++d) {v[3]=d; Sort::selection_bi(v);}}}}
  const Time_point t8 = timing();
  for(int a=0;a<loop4;++a){v[0]=a;for(int b=0;b<loop4;++b){v[1]=b;for(int c=0;c<loop4;++c){v[2]=c;for(int d=0;d<loop4;++d) {v[3]=d; Sort::size4(v.begin());}}}}
  const Time_point t9 = timing();
  for(int a=0;a<loop4;++a){v[0]=a;for(int b=0;b<loop4;++b){v[1]=b;for(int c=0;c<loop4;++c){v[2]=c;for(int d=0;d<loop4;++d) {v[3]=d; Sort::size4_(v.begin());}}}}
  const Time_point t10 = timing();
  for(int a=0;a<loop4;++a){v[0]=a;for(int b=0;b<loop4;++b){v[1]=b;for(int c=0;c<loop4;++c){v[2]=c;for(int d=0;d<loop4;++d) {v[3]=d; std::sort(v.begin(),v.end());}}}}
  const Time_point t11 = timing();
  std::cout << "i0: " << t1-t0 << "\ti1: " << t2-t1 << "\ti2: " << t3-t2
    << "\ti3: " << t4-t3 << "\ti: " << t5-t4
    << "\ns0: " << t6-t5 << "\ts1: " << t7-t6 << "\tbi: " << t8-t7
    << "\n_4: " << t9-t8 << "\t_4_: " << t10-t9
    << "\nstd: " << t11-t10 << std::endl;
}

void run_7() {
  std::cout << "7 ELEMENTS:\n";
  std::cout << "Loop: " << loop7 << "^7 = " << loop7*loop7*loop7*loop7*loop7*loop7*loop7 << "\n";
  vec_t v; v.resize(7);
  const Time_point t0 = timing();
  for(int a=0;a<loop7;++a){v[0]=a;for(int b=0;b<loop7;++b){v[1]=b;for(int c=0;c<loop7;++c){v[2]=c;for(int d=0;d<loop7;++d){v[3]=d;for(int e=0;e<loop7;++e){v[4]=e;for(int f=0;f<loop7;++f){v[5]=f;for(int g=0;g<loop7;++g){v[6]=g; Sort::insertion0(v);}}}}}}}
  const Time_point t1 = timing();
  for(int a=0;a<loop7;++a){v[0]=a;for(int b=0;b<loop7;++b){v[1]=b;for(int c=0;c<loop7;++c){v[2]=c;for(int d=0;d<loop7;++d){v[3]=d;for(int e=0;e<loop7;++e){v[4]=e;for(int f=0;f<loop7;++f){v[5]=f;for(int g=0;g<loop7;++g){v[6]=g; Sort::insertion1(v);}}}}}}}
  const Time_point t2 = timing();
  for(int a=0;a<loop7;++a){v[0]=a;for(int b=0;b<loop7;++b){v[1]=b;for(int c=0;c<loop7;++c){v[2]=c;for(int d=0;d<loop7;++d){v[3]=d;for(int e=0;e<loop7;++e){v[4]=e;for(int f=0;f<loop7;++f){v[5]=f;for(int g=0;g<loop7;++g){v[6]=g; Sort::insertion2(v);}}}}}}}
  const Time_point t3 = timing();
  for(int a=0;a<loop7;++a){v[0]=a;for(int b=0;b<loop7;++b){v[1]=b;for(int c=0;c<loop7;++c){v[2]=c;for(int d=0;d<loop7;++d){v[3]=d;for(int e=0;e<loop7;++e){v[4]=e;for(int f=0;f<loop7;++f){v[5]=f;for(int g=0;g<loop7;++g){v[6]=g; Sort::insertion3(v);}}}}}}}
  const Time_point t4 = timing();
  for(int a=0;a<loop7;++a){v[0]=a;for(int b=0;b<loop7;++b){v[1]=b;for(int c=0;c<loop7;++c){v[2]=c;for(int d=0;d<loop7;++d){v[3]=d;for(int e=0;e<loop7;++e){v[4]=e;for(int f=0;f<loop7;++f){v[5]=f;for(int g=0;g<loop7;++g){v[6]=g; Sort::insertion(v);}}}}}}}
  const Time_point t5 = timing();
  for(int a=0;a<loop7;++a){v[0]=a;for(int b=0;b<loop7;++b){v[1]=b;for(int c=0;c<loop7;++c){v[2]=c;for(int d=0;d<loop7;++d){v[3]=d;for(int e=0;e<loop7;++e){v[4]=e;for(int f=0;f<loop7;++f){v[5]=f;for(int g=0;g<loop7;++g){v[6]=g; Sort::selection0(v);}}}}}}}
  const Time_point t6 = timing();
  for(int a=0;a<loop7;++a){v[0]=a;for(int b=0;b<loop7;++b){v[1]=b;for(int c=0;c<loop7;++c){v[2]=c;for(int d=0;d<loop7;++d){v[3]=d;for(int e=0;e<loop7;++e){v[4]=e;for(int f=0;f<loop7;++f){v[5]=f;for(int g=0;g<loop7;++g){v[6]=g; Sort::selection1(v);}}}}}}}
  const Time_point t7 = timing();
  for(int a=0;a<loop7;++a){v[0]=a;for(int b=0;b<loop7;++b){v[1]=b;for(int c=0;c<loop7;++c){v[2]=c;for(int d=0;d<loop7;++d){v[3]=d;for(int e=0;e<loop7;++e){v[4]=e;for(int f=0;f<loop7;++f){v[5]=f;for(int g=0;g<loop7;++g){v[6]=g; Sort::selection_bi(v);}}}}}}}
  const Time_point t8 = timing();
   for(int a=0;a<loop7;++a){v[0]=a;for(int b=0;b<loop7;++b){v[1]=b;for(int c=0;c<loop7;++c){v[2]=c;for(int d=0;d<loop7;++d){v[3]=d;for(int e=0;e<loop7;++e){v[4]=e;for(int f=0;f<loop7;++f){v[5]=f;for(int g=0;g<loop7;++g){v[6]=g; std::sort(v.begin(),v.end());}}}}}}}
   const Time_point t9 = timing();
   std::cout << "i0: " << t1-t0 << "\ti1: " << t2-t1 << "\ti2: " << t3-t2
    << "\ti3: " << t4-t3 << "\ti: " << t5-t4
    << "\ns0: " << t6-t5 << "\ts1: " << t7-t6 << "\tbi: " << t8-t7
    << "\nstd: " << t9-t8 << std::endl;
}

}

int main(const int argc, const char* const argv[]) {
  run_insertion();
  run_selection();
  run_3();
  run_4();
  run_7();
}
