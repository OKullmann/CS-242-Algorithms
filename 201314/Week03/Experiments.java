class Experiments {

  private static long T1(final long n) {
    if (n<2) return 1;
    else return 4*T1(n/2) + n;
  }
  private static long T2(final long n) {
    if (n<2) return 1;
    else return 4*T2(n/2) + n*n;
  }
  private static long T3(final long n) {
    if (n<2) return 1;
    else return 4*T3(n/2) + n*n*n;
  }
  public static long T(final short i, final int n) {
    assert(i >= 1 && i <= 3);
    if (i == 1) return T1(n);
    else if (i == 2) return T2(n);
    else return T3(n);
  }

  public static final String program = "Experiments";
  public static final String err = "ERROR[" + program + "]: ";

  public static void main(final String[] args) {
    if (args.length != 2) {
      System.err.println(err +
        "Exactly two command-line parameters are required,\n" +
        "   the index i of the recurrence and the number N of experiments.\n");
      return;
    }

    final short index = Short.parseShort(args[0]);
    if (index < 1 || index > 3) {
      System.err.println(err + "The index must be 1, 2, or 3.");
      return;
    }
    final int N = Integer.parseInt(args[1]);

    System.out.println(" n T");
    for (int n = 0; n < N; ++n)
      System.out.println(n + " " + T(index,n));
  }
}
