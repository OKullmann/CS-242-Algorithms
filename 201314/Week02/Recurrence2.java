class Recurrence2 {
  public static long rec(final long n) {
    assert(n >= 1);
    if (n == 1) return 1;
    if (n % 2 == 0) return 2*rec(n/2) + n;
    return rec(n/2+1) + rec(n/2) + n;
  }

  public static final long default_n = 150000000000000000L;
    // rec(default_n) == 8711769623848288256

  public static void main(final String[] args) {
    final long n;
    if (args.length == 0) n = default_n;
    else n = Long.parseLong(args[0]);
    System.out.println(n + " " + rec(n));
  }
}
