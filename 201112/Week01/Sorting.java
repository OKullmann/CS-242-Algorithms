// Arnold Beckmann, 19.12.2009 (Swansea)
// Modified Oliver Kullmann, 30.9.2011 (Swansea)

/*
  File:  201112/Week01/solutions/Sorting_1.hpp
  Descr: Sorting algorithms
*/


class Insertion_Sort {

    public static void insertion_sort(long[] A) {
	long start = System.nanoTime();
	for (int j = 1; j < A.length; j++) {
	    long key = A[j];
	    int i = j;
	    while ((i > 0) && (A[i-1] > key)) {
		A[i] = A[i-1];
		i = i-1;
	    }
	    A[i] = key;
	}
 	System.out.println(" " + A.length + " " + (System.nanoTime()-start));
    }
}
