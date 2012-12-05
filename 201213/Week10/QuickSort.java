// Oliver Kullmann, 5.12.2012 (Swansea)

class QuickSort {

  public static void sort(final int[] A, final int p, final int r) {
    assert(A != null);
    assert(p >= 0);
    assert(p <= r);
    assert(r <= A.length);
    final int length = r - p;
    if (length <= 1) return;
    place_partition_element_last(A,p,r);
    final int q = partition(A,p,r);
    assert(p <= q);
    assert(q < r);
    sort(A,p,q);
    sort(A,q+1,r);
  }
  
  // returns q and permuted A such that A[p...q] are all <= x, A[q]=x, and A[q+1...r-1] are all > x,
  // where x = A[r-1] for the *original* A:
  private static int partition(final int[] A, final int p, final int r) {
    assert(p+1 < r);
    final int x = A[r-1];
    int q = p;
    for (int j = p; j < r-1; ++j) {
      final int v = A[j];
      if (v <= x) {A[j] = A[q]; A[q++] = v;}
    }
    A[r-1] = A[q]; A[q] = x;
    return q;
  }
  
  private static void place_partition_element_last(final int[] A, final int p, final int r) {
    assert(p+1 < r);
    final int i = p + (int) Math.random()*(r-p);
    {final int t = A[i]; A[i] = A[r-1]; A[r-1] = t;}
  }
  
  public static void main(final String[] args) {
    final int N = args.length;
    final int[] a = new int[N];
    for (int i = 0; i < N; ++i) a[i] = Integer.parseInt(args[i]);
    sort(a,0,a.length);
    for (int i = 0; i < N; ++i) System.out.print(a[i] + " ");
    System.out.println();
  }
}
