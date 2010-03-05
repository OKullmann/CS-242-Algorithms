// Arnold Beckmann, 05.03.2010 (Swansea)

/*
  File:  200910/Week07/Experiment.java
  Descr: Experiments with Huffman codes

  "Experiment_InsertionSort_up N" calls the sorting algorithm N times with upwards
  sorted inputs; the statistics are output to standard output.
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


	int[][] T = {
	    {'a',1}, {'b',1}, {'c',0}, {'d',3}, {'e',2}, {'f',4},
	    {'g',3}, {'h',2}, {'i',6}, {'j',4}, {'k',2}, {'l',1}
	};
	

	int n = T.length;
	Node C[] = new Node[n];
	for (int i = 0; i < n; i++) {
	    C[i] = new Node((char)T[i][0],T[i][1],null,null);
	}
	Node H = Huffman.generate(C);
	Huffman.out(C);

	String a = "badffdeeffd";
	System.out.println("Text:      " + a);
	String s = Huffman.encode(a);
	System.out.println("Encoding:  " + s);
	System.out.println("Decoding:  " + Huffman.decode(H,s) + "\n\n");
    }

}


