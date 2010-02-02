// Arnold Beckmann, 02.02.2010 (Swansea)


/*
  File:  200910/Week01/solutions/Sorting_1.java
  Descr: Sorting algorithms
*/


class Insertion_Sort {

    public static void insertion_sort(long[] A) {
	ExecutionTimer.start();
	for (int j = 1; j < A.length; j++) {
	    long key = A[j];
	    int i = j;
	    while ((i > 0) && (A[i-1] > key)) {
		A[i] = A[i-1];
		i = i-1;
	    }
	    A[i] = key;
	}
	ExecutionTimer.end();
	System.out.println(" " + A.length + " " + (ExecutionTimer.duration()) );

    }

}


class Merge_Sort {

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
	    int r = (int) ( Math.floor((p+q)/2) );
	    merge_sort(A,p,r);
	    merge_sort(A,r+1,q);
	    merge(A,p,r,q);
	}
    }

    public static void merge_sort(long[] A) {
	/// ExecutionTimer.start();
	if (A.length>0)
	    merge_sort(A,0,A.length-1);
	/// ExecutionTimer.end();
 	/// System.out.println(" " + A.length + " " + ExecutionTimer.duration() );

    }

}

