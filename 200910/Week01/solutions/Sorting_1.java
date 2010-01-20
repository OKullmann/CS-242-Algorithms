// Arnold Beckmann, 19.12.2009 (Swansea)

/*
  File:  200910/Week01/solutions/Sorting_1.hpp
  Descr: Sorting algorithms
*/


class Insertion_Sort {

    public static void insertion_sort(long[] A) {
	/// int counter_comparisons = 0;
	for (int j = 1; j < A.length; j++) {
	    long key = A[j];
	    int i = j;
	    while ((i > 0) && (A[i-1] > key)) {
		/// ++counter_comparisons;
		A[i] = A[i-1];
		i = i-1;
	    }
	    /// if (i > 0) ++counter_comparisons;
	    A[i] = key;
	}
 	/// System.out.println(" " + A.length + " " + counter_comparisons);

    }

}


