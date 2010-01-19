// Arnold Beckmann, 19.01.2009 (Swansea)

/*
  File:  200910/Week01/Sorting_0.java
  Descr: Sorting algorithms
*/

/*
  Sorting (in ascending order) by insertion
  
  The idea of this elementary algorithm is as follows:
      
  * Given an array A[0], ..., A[A.size()-1], starting with
    j=1, the range A[0], ..., A[j-1] is given as sorted,
    and after the execution of the main loop body the range 
    A[0], ..., A[j] is also sorted (internally).
  * This is achieved by storing value A[j] in variable "key",
    and then moving all those elements A[i-1] in A[0], ..., A[j-1]
    one place up (starting from the top, decrementing i) as long as
    A[i-1] > key holds. The final value of i is then the index of the
    free place where key can be inserted (i is as large as possible). 

  This is algorithm "Insertion-Sort(A)" from [Cormen, Leiserson, Rivest,
  Stein; 2009], page 18, with the following modifications:
      
  * Arrays in C-based languages (C, C++, Java, Perl, ...) are 0-based,
    not 1-based (as in the book).
  * Index types should in general be *unsigned*, that is non-negative,
    integral types.  Variable i in the original algorithm can now reach
    value -1, after making the array 0-based. Thus, the value of
    variable i is moved "one step up".
*/


class Insertion_Sort {

    public static void insertion_sort(int[] A) {
	for (int j = 1; j < A.length; j++) {
	    int key = A[j];
	    int i = j;
	    while ((i > 0) && (A[i-1] > key)) {
		A[i] = A[i-1];
		i = i-1;
	    }
	    A[i] = key;
	}
    }

}


