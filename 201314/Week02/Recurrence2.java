class Recurrence2 {

  public static final long max_n = 150000000000000000L;

  public static long rec(final long n) {
    assert(n >= 1);
    assert(n <= max_n);
    if (n == 1) return 1;
    else if (n % 2 == 0) return 2*rec(n/2) + n;
    else return rec(n/2+1) + rec(n/2) + n;
  }

  public static void main(final String[] args) {
    assert(rec(1) == 1);
    assert(rec(max_n) == 8711769623848288256L);

    final int N = args.length;
    if (N == 0) return;
    final long a[] = new long[N];
    for (int i = 0; i < N; ++i)
      a[i] = Long.parseLong(args[i]);

    final long res0 = rec(a[0]);
    System.out.println(a[0] + " " + res0);
    for (int i = 1; i < N; ++i) {
      final long res = rec(a[i]);
      System.out.print(a[i] + " " + res);
      final double q1 = (double) a[i] / a[0];
      final double q2 = (double) res / res0;
      System.out.println(" " + q1 + " " + q2);
    }
  }
}
