// Arnold Beckmann, 05.02.2010 (Swansea)

/*
  File:  200910/Week03/Experiment.java
  Descr: Experiments with recurrences

  "Experiment N" calls the recurrence N times;
  the statistics are output to standard output.
*/



class Experiment {

    protected static String program = "Experiment";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

	//  this program requires one argument on the command line  
        if (args.length != 1) {
	    System.err.println(err + "Exactly one parameter is required, the number N of experiments.\n");
	    return;
	}

	int N = (Integer.valueOf(args[0]) ).intValue();
	System.out.println("\n#  Experience Recurrences \n");

	System.out.println("  size executionTime\n");
	for (int i = 0; i <= N; i++) {
	    Recurrence2.recurrence(i);
	}

    }

}


