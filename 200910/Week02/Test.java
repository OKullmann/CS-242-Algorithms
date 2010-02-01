// Arnold Beckmann, 19.01.2010 (Swansea)

/*
  File:  200910/Week01/Test.java
  Descr: Testing sorting algorithms

*/


class Test {

    public static void main(String[] args) {

	long[] A = Array_Generators.sorted_rand(10);
	System.out.println("\n\nTest Merge-sort on random lists");
	System.out.println("\nInput:   " + druck(A) + "\n");
	Merge_Sort.merge_sort(A);
	System.out.println("Output:  " + druck(A) + "\n");	

    }

    private static String druck(long[] A) {
        String s = " " + A[0];
	for (int j = 1; j < A.length; ++j) 
	    s += ", " + A[j];
	return s;
    }


}

