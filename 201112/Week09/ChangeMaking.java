// Arnold Beckmann, 20.03.2011 (Swansea)
// Oliver Kullmann, 30.11.2011 (Swansea)

/*
  File:  201011/Week09/ChangeMaking.java
  Descr: Solving the change-making problem via dynamic programming
*/

class ChangeMaking {

    public final static int infinity = Integer.MAX_VALUE;

    public static int[][] making_change(final int N, final int[] d) {
      final int n = d.length;
      int[][] c = new int[n + 1][N + 1];
      if (n == 0) return c;
      assert(N < infinity);

      for (int j = 1; j <= N; ++j) c[0][j] = infinity;
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= N; ++j)
          if (j < d[i-1] || c[i][j-d[i-1]] == infinity)
            c[i][j] = c[i-1][j];
          else
            c[i][j] = Math.min(c[i-1][j], 1+c[i][j-d[i-1]]);
      return c;
    }

    public static int[] pay_out(final int[][] c, final int[] d) {
      final int n = d.length;
      final int[] a = new int[n];
      if (n == 0) return a;

      final int N = c[0].length - 1;
      int i = n, j = N;
      while (j > 0)
	  if (i == 0) { j = 0; }
	  else if (c[i][j] == c[i-1][j]) --i;
	  else {
	    ++a[i-1];
	    j -= d[i-1];
	  }
      return a;
    }

    public static int rec_making_change(final int N, final int[] d) {
	final int n = d.length;
	final int nc = rec_making_change(d, n, N);
	return nc;
    }

    private static int rec_making_change(final int[] d,
					final int i, final int j) {
	if (j <= 0) return 0;
	if (i <= 0) return infinity;
	final int nc1 = rec_making_change(d, i-1, j);
	if (j < d[i-1])  return nc1;
	final int nc2 = rec_making_change(d, i, j-d[i-1]);
	return Math.min(nc1, 1+nc2);
    }


}		


