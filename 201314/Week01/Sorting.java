class Insertion_Sort {

  public static void insertion_sort(final long[] A) {
    final long start = System.nanoTime();
    for (int j = 1; j < A.length; ++j) {
      final long key = A[j];
      int i = j;
      while (i > 0 && A[i-1] > key) {
        A[i] = A[i-1];
        i = i-1;
      }
      A[i] = key;
    }
    System.out.println(" " + A.length + " " + (System.nanoTime()-start));
  }
}
