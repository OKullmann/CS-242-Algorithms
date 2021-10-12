class Recurrence1 {

  public static final long max_n = 411175444467L;

  public static long rec(final long n) {
    assert(n >= 1);
    assert(n <= max_n);
    if (n == 1) return 1;
    else if (n % 2 == 0) return 3*rec(n/2) + 2 + n;
    else return rec(n/2+1) + 2*rec(n/2) + 2 + n;
  }

  public static void main(final String[] args) {
    assert(rec(1) == 1);
    assert(rec(2) == 7);
    assert(rec(410000000000L) == 9100131083681673202L);
    assert(rec(max_n) == 9223372031224988194L);

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
