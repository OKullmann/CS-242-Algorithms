// Arnold Beckmann, 19.12.2009 (Swansea)

/*
  File:  200910/Week01/solutions/Sorting_1.hpp
  Descr: Sorting algorithms
*/


class Insertion_Sort {

    public static void insertion_sort(long[] A) {
	/// long start = System.nanoTime();
	for (int j = 1; j < A.length; j++) {
	    long key = A[j];
	    int i = j;
	    while ((i > 0) && (A[i-1] > key)) {
		A[i] = A[i-1];
		i = i-1;
	    }
	    A[i] = key;
	}
 	/// System.out.println(" " + A.length + " " + (System.nanoTime()-start) );

    }

}


class Merge_Sort {

    /// static int counter;

    static void merge(long[] A, int p, int r, int q) {
	int i,j;
	int n1 = r-p+1;
	int n2 = q-r;
	long[] L = new long[n1+1];
	long[] R = new long[n2+1];
	for (i = 0; i < n1; i++) L[i] = A[p+i];
	for (j = 0; j < n2; j++) R[j] = A[r+j+1];
	long sentinel = Math.abs(A[r]) + Math.abs(A[q]);
	L[n1] = sentinel;
	R[n2] = sentinel;
	i = 0;
	j = 0;
	for (int k = p; k <= q; k++) {
	    /// ++ counter;
	    if (L[i] <= R[j]) {
		A[k] = L[i];
		i++;
	    } else {
		A[k] = R[j];
		j++;
	    }
	}

    }


    static void merge_sort(long[] A, int p, int q) {
	if (p<q) {
	    int r = (int) ( Math.floor((p+q)/2.0) );
	    merge_sort(A,p,r);
	    merge_sort(A,r+1,q);
	    merge(A,p,r,q);
	}
    }

    public static void merge_sort(long[] A) {
	/// long start = System.nanoTime();
	/// counter = 0;
	if (A.length>0)
	    merge_sort(A,0,A.length-1);
 	/// System.out.println(" " + A.length + " " + counter + " " + (System.nanoTime()-start) );

    }

}

