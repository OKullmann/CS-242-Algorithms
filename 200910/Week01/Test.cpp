// Arnold Beckmann, 07.01.2010 (Swansea)

/*!
  \file 200910/Week01/Test.cpp
  \brief Testing sorting algorithms

*/

#include <string>
#include <iostream>
#include <vector>

#include <200910/Week01/Sorting.hpp>

using namespace std;

namespace {

  void druck(vector<int>& A) {
    
    unsigned int i;
    cout << A[0];
    for (i = 1; i < A.size(); ++i)
      cout << ", " << A[i];

    return;

  }

}


int main(const int argc, const char* const argv[]) {

  int Alist[] = {9,6,5,7,2,4,1,3,6,8};
  vector<int> A;
  A.assign (Alist, Alist + 10 );

  cout << "\nPermutation Sort\n\nInput:   >";
  druck(A);
  cout << "<\n\n";

  IntroAlgo::Week01::permutation_sort(A);

  cout << "\nOutput:  >";
  druck(A);
  cout << "<\n\n";

  return 0;
}

