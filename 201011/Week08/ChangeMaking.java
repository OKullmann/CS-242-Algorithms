// Arnold Beckmann, 20.03.2011 (Swansea)


/*
  File:  200910/Week08/ChangeMaking.java
  Descr: Solving the change-making problem via dynamic programming
*/


class ChangeMaking { 

    public final static int infinity = java.lang.Integer.MAX_VALUE;

    public static int[][] making_change(final int N, final int[] d) {
	final int n = d.length;
	int[][] c = new int[n + 1][N + 1];
	if (n == 0) return c;
	assert(N < infinity);

	for (int i = 0; i <= n; i++) c[i][0] = 0;
	for (int j = 1; j <= N; j++) c[0][j] = infinity;
	for (int i = 1; i <= n; i++)
	    for (int j = 1; j <= N; j++)
		if (j < d[i-1] || c[i][j-d[i-1]] == infinity)
		    c[i][j] = c[i-1][j];
		else
		    c[i][j] = java.lang.Math.min(c[i-1][j], 1+c[i][j-d[i-1]]);

	return c;
    }


   public static String pay_out(final int[][] c, final int[] d) {
       String out = "";
       final int n = d.length;
       if (n == 0) return out;
       final int N = c[0].length - 1;
       int i = n, j = N;
       while (j > 0)
	   if (i == 0) { j = 0; }
	   else if (c[i][j] == c[i-1][j]) { i--; }
	   else { 
	       if (out.length() != 0) out += " + ";
	       out += d[i-1]; 
	       j -= d[i-1]; 
	   }
       return out;
  }


}		


