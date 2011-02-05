// Arnold Beckmann, 01.02.2010 (Swansea)

/*
  File:  201011/Week02/Experiment.java
  Descr: Experiments with sorting algorithms on sorted inputs

  "Experiment_InsertionSort_up N" calls the sorting algorithm N times with upwards
  sorted inputs; the statistics are output to standard output.
*/



class Experiment_InsertionSort_up {

    protected static String program = "Experiment_InsertionSort_up";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

	//  this program requires one argument on the command line  
        if (args.length != 1) {
	    System.err.println(err + "Exactly one parameter is required, the number N of experiments.\n");
	    return;
	}

//	long end = System.currentTimeMillis()+2000;
//	while (System.currentTimeMillis() < end) {};

	int N = (Integer.valueOf(args[0]) ).intValue();
	System.out.println("\n#  Insertion-sort on sorted lists\n");

	System.out.println("  size executionTime\n");
	for (int i = 0; i <= N; i++) {
	    long[] A = Array_Generators.sorted_up(i);
	    Insertion_Sort.insertion_sort(A);
	}

    }

}



/*
  "Experiment_InsertionSort_down N" calls the sorting algorithm N times with downwards
  sorted inputs; the statistics are output to standard output.
*/


class Experiment_InsertionSort_down {

    protected static String program = "Experiment_InsertionSort_down";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

	//  this program requires one argument on the command line  
        if (args.length != 1) {
	    System.err.println(err + "Exactly one parameter is required, the number N of experiments.\n");
	    return;
	}

	int N = (Integer.valueOf(args[0]) ).intValue();
	System.out.println("\n#  Insertion-sort on reverse sorted lists\n");

	System.out.println("  size executionTime\n");
	for (int i = 0; i <= N; i++) {
	    long[] A = Array_Generators.sorted_down(i);
	    Insertion_Sort.insertion_sort(A);
	}

    }

}



/*
  "Experiment_InsertionSort_rand N" calls the sorting algorithm N times with randomly
  sorted inputs; the statistics are output to standard output.
*/


class Experiment_InsertionSort_rand {

    protected static String program = "Experiment_InsertionSort_rand";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

	//  this program requires one argument on the command line  
        if (args.length != 1) {
	    System.err.println(err + "Exactly one parameter is required, the number N of experiments.\n");
	    return;
	}

	int N = (Integer.valueOf(args[0]) ).intValue();
	System.out.println("\n#  Insertion-sort on random lists\n");

	System.out.println("  size executionTime\n");
	for (int i = 0; i <= N; i++) {
	    long[] A = Array_Generators.sorted_rand(i);
	    Insertion_Sort.insertion_sort(A);
	}

    }

}



/*
  "Experiment_MergeSort_up N" calls the sorting algorithm N times with upwards
  sorted inputs; the statistics are output to standard output.
*/


class Experiment_MergeSort_up {

    protected static String program = "Experiment_MergeSort_up";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

	//  this program requires one argument on the command line  
        if (args.length != 1) {
	    System.err.println(err + "Exactly one parameter is required, the number N of experiments.\n");
	    return;
	}

	int N = (Integer.valueOf(args[0]) ).intValue();
	System.out.println("\n#  Merge-sort on sorted lists\n");

	//System.out.println("  size comparisons executionTime\n");
	System.out.println("  size executionTime\n");
	for (int i = 0; i <= N; i++) {
	    long[] A = Array_Generators.sorted_up(i);
	    Merge_Sort.merge_sort(A);
	}

    }

}



/*
  "Experiment_MergeSort_down N" calls the sorting algorithm N times with downwards
  sorted inputs; the statistics are output to standard output.
*/


class Experiment_MergeSort_down {

    protected static String program = "Experiment_MergeSort_down";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

	//  this program requires one argument on the command line  
        if (args.length != 1) {
	    System.err.println(err + "Exactly one parameter is required, the number N of experiments.\n");
	    return;
	}

	int N = (Integer.valueOf(args[0]) ).intValue();
	System.out.println("\n#  Merge-sort on reverse sorted lists\n");

	// System.out.println("  size comparisons executionTime\n");
	System.out.println("  size executionTime\n");
	for (int i = 0; i <= N; i++) {
	    long[] A = Array_Generators.sorted_down(i);
	    Merge_Sort.merge_sort(A);
	}

    }

}



/*
  "Experiment_MergeSort_rand N" calls the sorting algorithm N times with randomly
  sorted inputs; the statistics are output to standard output.
*/


class Experiment_MergeSort_rand {

    protected static String program = "Experiment_MergeSort_rand";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

	//  this program requires one argument on the command line  
        if (args.length != 1) {
	    System.err.println(err + "Exactly one parameter is required, the number N of experiments.\n");
	    return;
	}

	int N = (Integer.valueOf(args[0]) ).intValue();
	System.out.println("\n#  Merge-sort on random lists\n");

	System.out.println("  size executionTime\n");
	//System.out.println("  size comparisons executionTime\n");
	for (int i = 0; i <= N; i++) {
	    long[] A = Array_Generators.sorted_rand(i);
	    Merge_Sort.merge_sort(A);
	}

    }

}


