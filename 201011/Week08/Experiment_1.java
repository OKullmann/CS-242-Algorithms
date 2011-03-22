// Arnold Beckmann, 20.03.2011 (Swansea)

/*
  File:  200910/Week08/solutions/Experiment_1.java
  Descr: Experiments with Change Making

  Use by
      ChangeMaking N d1 ... dn
  where N is the amount to be returned, n is the number of coins and
  d1, ..., dn are the coin values.

*/

import java.io.* ;



class Experiment {

    protected static String program = "Experiment";
    protected static String err = "ERROR[" + program + "]: ";


    private static String size_out(final int s) {
	String out = new String();
	if (s == ChangeMaking.infinity)
	    out = "inf";
	else
	    out = "" + s;
	return out;
    }


    public static void main(String[] args) {

	//  this program requires one argument on the command line  
        if (args.length < 1) {
	    System.err.print(err + "At least one parameter is needed, the amount N to be returned.\n");
	    return;
	}



	final int N = (Integer.valueOf(args[0]) ).intValue();
	final int n = args.length - 1;
	if (n == 0) {
	    if (N == 0)
		System.out.print("No coins needed.\n");
	    else
		System.out.print("Without coins no solution.\n");
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
	System.out.print("Optimal number of coins needed: "
			 + size_out(c[n][N]));
	System.out.print("\n");
	
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
	if (question.equals("y"))
	    for (int i = 0; i <= n; i++) {
		if (i==0) System.out.print("  no coins: ");
		else System.out.print(" d[" + i + "] = "
		       + String.format("%2d: ", d[i-1]));
		for (int j = 0; j <= N; j++) {
		    System.out.print(String.format("%3s ",size_out(c[i][j])));
		}
		System.out.print("\n");
	    }
	
    }
   


}



class ExperimentA {

    protected static String program = "ExperimentA";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

	//  this program requires one argument on the command line  
        if (args.length != 1) {
	    System.err.print(err + "Exactly one parameter is required, the number N of experiments.\n");
	    return;
	}

	final int N = (Integer.valueOf(args[0]) ).intValue();
	final int[] d = { 1, 2, 5, 10 };	

	System.out.println("\n#  Recursive Making Change\n");

	System.out.println("  size executionTime\n");
	for (int i = 0; i <= N; i++) {
	    ExecutionTimer.start();
	    ChangeMaking.making_change(i, d);
	    ExecutionTimer.end();
	    System.out.println(" " + i + " " + (ExecutionTimer.duration()) );

	}
    }
}



class ExperimentB {

    protected static String program = "ExperimentA";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

	//  this program requires one argument on the command line  
        if (args.length != 1) {
	    System.err.print(err + "Exactly one parameter is required, the number N of experiments.\n");
	    return;
	}

	final int N = (Integer.valueOf(args[0]) ).intValue();
	final int[] d = { 1, 2, 5, 10 };	

	System.out.println("\n#  Recursive Making Change\n");

	System.out.println("  size executionTime\n");
	for (int i = 0; i <= N; i++) {
            ExecutionTimer.start();
	    ChangeMaking.rec_making_change(i, d);
	    ExecutionTimer.end();
	    System.out.println(" " + i + " " + (ExecutionTimer.duration()) );
	}
    }
   


}




class ExperimentD {

    protected static String program = "ExperimentD";
    protected static String err = "ERROR[" + program + "]: ";


    private static String size_out(final int s) {
	String out = new String();
	if (s == ChangeMaking.infinity)
	    out = "inf";
	else
	    out = "" + s;
	return out;
    }


    public static void main(String[] args) {

	//  this program requires one argument on the command line  
        if (args.length < 1) {
	    System.err.print(err + "At least one parameter is needed, the amount N to be returned.\n");
	    return;
	}



	final int N = (Integer.valueOf(args[0]) ).intValue();
	final int n = args.length - 1;
	if (n == 0) {
	    if (N == 0)
		System.out.print("No coins needed.\n");
	    else
		System.out.print("Without coins no solution.\n");
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
	
	final int[] a = ChangeMaking.rec_making_change2(N, d);
	int nc = 0;
	if (a[0] == ChangeMaking.infinity)
	    nc = ChangeMaking.infinity;
	else
	    for (int i = 0; i < n; i++)  nc += a[i];
	System.out.print("Optimal number of coins needed: "
			 + size_out(nc));
	System.out.print("\n");
	
	if (nc != ChangeMaking.infinity) {
	    System.out.print("Solution: ");
	    assert(a.length == n);
	    for (int i = 0; i < n; ++i) {
		System.out.print("" + a[i] + "*" + d[i]);
		if (i+1 < n) System.out.print(" + ");
	    }
	    System.out.println(" = " + N);
	}
	
    }

}