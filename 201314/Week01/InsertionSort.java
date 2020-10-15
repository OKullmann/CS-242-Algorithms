class InsertionSort {

  static final long repetitions = 10000;
  // Input n is nanoseconds, prints as microseconds:
  public static void print_as_mus(final long n) {
    final double d = (double) n;
    System.out.printf(" %f", d / 1000);
  }

  public static void sort(final long[] A) {
    if (A == null || A.length <= 1) return;
    final int n = A.length;
    for (int j = 1; j != n; ++j) {
      final long key = A[j];
      int i;
      for (i = j; i != 0 && A[i-1] > key; --i) A[i] = A[i-1];
      A[i] = key;
    }
  }

  public static boolean is_sorted(final long[] A) {
    if (A == null || A.length <= 1) return true;
    final int n = A.length;
    for (int i = 0; i != n-1; ++i)
      if (A[i] > A[i+1]) return false;
    return true;
  }

  public static long[] ascending(final int n) {
    if (n < 0) return null;
    final long[] A = new long[n];
    for (int i = 0; i != n; ++i) A[i] = i;
    return A;
  }
  public static long[] descending(final int n) {
    if (n < 0) return null;
    final long[] A = new long[n];
    for (int i = 0; i != n; ++i) A[i] = n-i;
    return A;
  }
  public static long[] random(final int n) {
    if (n < 0) return null;
    final long[] A = new long[n];
    for (int i = 0; i != n; ++i)
      A[i] = (long)(Math.random() * (double)Long.MAX_VALUE);
    return A;
  }
  
  public static void experiment(final int n) {
    if (n < 0) return;
    for (int v = 0; v < 3; ++v) {
      long min = Long.MAX_VALUE;
      for (long i = 0; i < repetitions; ++i) {
        final long[] A = (v==0) ? ascending(n) :
          ((v==1) ? descending(n) : random(n));
        final long start = System.nanoTime();
        sort(A);
        final long end = System.nanoTime();
        final long duration = end - start;
        assert(is_sorted(A));
        if (duration < min) min = duration;
      }
      print_as_mus(min);
    }
  }
  
  public static void main(final String[] args) {
    final int n = Integer.parseInt(args[0]);
    System.out.print(n);
    experiment(n);
    System.out.println();
  }
}
