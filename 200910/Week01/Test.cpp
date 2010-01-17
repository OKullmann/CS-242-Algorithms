// Arnold Beckmann, 07.01.2010 (Swansea)

/*!
  \file 200910/Week01/Test.cpp
  \brief Testing sorting algorithms

*/

#include <string>
#include <iostream>
#include <vector>

#include <200910/Framework/Utilities.hpp>

#include <200910/Week01/Sorting.hpp>
#include <200910/Week01/Generators.hpp>

using namespace std;
using IntroAlgo::Week01::ArrayGenerators;


int main(const int argc, const char* const argv[]) {

  using namespace IntroAlgo::Framework;

  // int Alist[] = {9,6,5,7,2,4,1,3,6,8};
  vector<int> A;
  /*
  A.assign (Alist, Alist + 10 );
  */
  A = ArrayGenerators::random(10);

  cout << "\nTest Insertion-sort\n\nInput:   > " << cw(A) << "<\n\n";

  IntroAlgo::Week01::insertion_sort(A);

  cout << "\nOutput:  > " << cw(A) << "<\n\n";

  return 0;
}

