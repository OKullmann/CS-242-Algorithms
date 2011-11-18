// Arnold Beckmann, 20.03.2011 (Swansea)
// Oliver Kullmann, 18.11.2011 (Swansea)

/*
  File:  201112/Week09/Experiment_0.java
  Descr: Experiments with Change Making
*/

import java.io.* ;



/*
  The Dynamic Programming solution:
  Use by
      java ExperimentDP N d1 ... dn
  where N is the amount to be returned, n is the number of coins and
  d1, ..., dn are the coin values.

*/

class ExperimentDP {

    protected static String program = "Experiment";
    protected static String err = "ERROR[" + program + "]: ";

    private static String size_out(final int s) {
	String out = new String();
	if (s == ChangeMaking.infinity) out = "inf";
	else out = "" + s;
	return out;
    }

    public static void main(String[] args) {
      if (args.length < 1) {
	  System.err.print(err + "At least one parameter is needed, the amount N to be returned.\n");
	  return;
	}

	final int N = (Integer.valueOf(args[0])).intValue();
	final int n = args.length - 1;
	if (n == 0) {
	  if (N == 0) System.out.print("No coins needed.\n");
	  else System.out.print("Without coins no solution.\n");
	  return;
	}
	int[] d = new int[n];
	for (int i = 0; i < n; i++) {
	  int dummy = (Integer.valueOf(args[i+1]) ).intValue();
	  if (dummy == 0) {
	    System.err.print(err + "Coin " + (i+1) + " is zero.\n");
	    return;
	  }
	  d[i] = dummy;
      }
	
	final int[][] c = ChangeMaking.making_change(N, d);
	System.out.println("Optimal number of coins needed: "
			   + size_out(c[n][N]));
	
	if (c[n][N] != ChangeMaking.infinity) {
	  System.out.print("Solution: ");
	  final int[] a = ChangeMaking.pay_out(c,d);
	  assert(a.length == n);
	  for (int i = 0; i < n; ++i) {
	    System.out.print("" + a[i] + "*" + d[i]);
	    if (i+1 < n) System.out.print(" + ");
	  }
	  System.out.println(" = " + N);
	}
	
	InputStreamReader istream = new InputStreamReader(System.in);
	BufferedReader bufRead = new BufferedReader(istream);

	String question = new String();
	try {
	  System.out.print("\nOutput of array c ? Enter \"y\" or \"n\": ");
	  question = bufRead.readLine();
      }
	catch (IOException err) {
	    System.out.println("Error reading line");
	}
	if (question.equals("y")) {
        System.out.print("Amount:      ");
        for (int i = 0; i <= N; ++i) {
          System.out.print(i + "  ");
          if (i < 9) System.out.print(" ");
        }
        System.out.println();
	  for (int i = 0; i <= n; i++) {
	    if (i==0) System.out.print("zero coins:");
	    else System.out.print("d[" + i + "] =" + String.format("%3d: ", d[i-1]));
	    for (int j = 0; j <= N; j++)
	      System.out.print(String.format("%3s ",size_out(c[i][j])));
	    System.out.println();
	  }
      }
    }
}


/*
  The top-down recursive solution:
  Use by
      java ExperimentRec N d1 ... dn
  where N is the amount to be returned, n is the number of coins and
  d1, ..., dn are the coin values.

*/

class ExperimentRec {

    protected static String program = "ExperimentD";
    protected static String err = "ERROR[" + program + "]: ";

    private static String size_out(final int s) {
	String out = new String();
	if (s == ChangeMaking.infinity) out = "inf";
	else out = "" + s;
	return out;
    }

    public static void main(String[] args) {
      if (args.length < 1) {
	  System.err.print(err + "At least one parameter is needed, the amount N to be returned.\n");
	  return;
	}

	final int N = (Integer.valueOf(args[0]) ).intValue();
	final int n = args.length - 1;
	if (n == 0) {
	  if (N == 0) System.out.print("No coins needed.\n");
	  else System.out.print("Without coins no solution.\n");
	  return;
	}
	int[] d = new int[n];
	for (int i = 0; i < n; i++) {
	  int dummy = (Integer.valueOf(args[i+1]) ).intValue();
	  if (dummy == 0) {
	    System.err.print(err + "Coin " + (i+1) + " is zero.\n");
	    return;
	  }
	  d[i] = dummy;
	}
	
	final int nc = ChangeMaking.rec_making_change(N, d);
	System.out.println("Optimal number of coins needed: "
			   + size_out(nc));
    }
}


/*
  Running the dynamic programming program on various amounts
  with a hard coded list of coin-values.
  Use by
      java ExperimentA N
  which will run  ChangeMaking.making_change  for the hard-coded list
  of coin-values on amounts 0 .. N

*/

class ExperimentA {

    protected static String program = "ExperimentA";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

      // this program requires one argument on the command line
      if (args.length != 1) {
	  System.err.print(err + "Exactly one parameter is required, the number N of experiments.\n");
	  return;
      }

      final int N = (Integer.valueOf(args[0]) ).intValue();
      final int[] d = { 1 };

      System.out.println("\n#  Dynamic Programming Making Change\n");

      System.out.println("  amount executionTime\n");
      for (int i = 0; i <= N; i++) ChangeMaking.making_change(i, d);
    }
}



/*
  Running the top-down recursive program on various amounts
  with a hard coded list of coin-values.
  Use by
      java ExperimentA N
  which will run  ChangeMaking.rec_making_change  for the hard-coded list
  of coin-values on amounts 0 .. N

*/

class ExperimentB {

    protected static String program = "ExperimentA";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

	// this program requires one argument on the command line
      if (args.length != 1) {
	  System.err.print(err + "Exactly one parameter is required, the number N of experiments.\n");
	  return;
	}

      final int N = (Integer.valueOf(args[0]) ).intValue();
      final int[] d = { 1 };

      System.out.println("\n#  Recursive Making Change\n");

      System.out.println("  amount executionTime\n");
	for (int i = 0; i <= N; i++) ChangeMaking.rec_making_change(i, d);
    }
}
