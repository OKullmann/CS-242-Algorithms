class MergeSort {
  public static void sort(final int[] A) { sort(A,0,A.length); }
  private static void sort(final int[] A, final int p, final int q) {
    if (p+1 < q) {
      final int r = (p+q)/2;
      sort(A,p,r);
      sort(A,r,q);
      merge(A,p,r,q);
    }
  }
  public static void merge(final int[] A, final int p, final int r, final int q) {
    final int n1 = r - p, n2 = q - r;
    final int[] L = new int[n1], R = new int[n2];
    for (int i = 0; i < n1; ++i) L[i] = A[p+i];
    for (int i = 0; i < n2; ++i) R[i] = A[r+i];
    for (int i = 0, j = 0, k = p; k < q;)
      if (i == n1) while (j < n2) A[k++] = R[j++];
      else if (j == n2) while (i < n1) A[k++] = L[i++];
      else if (L[i] <= R[j]) A[k++] = L[i++];
      else A[k++] = R[j++];
  }

  public static void main(final String[] args) {
    final int N = args.length;
    final int[] A = new int[N];
    for (int i = 0; i < N; ++i) A[i] = Integer.parseInt(args[i]);
    sort(A);
    for (int i = 0; i < N; ++i) System.out.print(A[i] + " ");
    System.out.println();
  }
}
