// Arnold Beckmann, 05.03.2010 (Swansea)

/*
  File:  200910/Week07/Experiment.java
  Descr: Experiments with Huffman codes
*/

/*
  "Experiment_InsertionSort_up N" calls the sorting algorithm N times with upwards
  sorted inputs; the statistics are output to standard output.
*/


class Experiment {
    public static Node a = new Node('a',1,null,null);
    public static Node b = new Node('b',1,null,null);
    public static Node c = new Node('c',0,null,null);
    public static Node d = new Node('d',3,null,null);
    public static Node e = new Node('e',4,null,null);
    public static Node[] C = {a,b,c,d,e};
    public static String plaintext = "adeedbede";
}



class ExperimentA {

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




/*
  "ExperimentB" does what???
*/

class ExperimentB extends Experiment {

    protected static String program = "Experiment";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

	//  this program requires no argument on the command line  
        if (args.length != 0) {
	    System.err.println(err + "Exactly zero parameters are required.\n");
	    return;
	}


	Node H,x,y;
	y = new Node(7,d,e);
	y = new Node(7,c,y);
	y = new Node(8,b,y);
	H = new Node(9,a,y);
	Huffman.hc(H);

	Huffman.out(C);
	String s_plain = "adeedbede";
	System.out.println("Text:      " + s_plain);
	String s_code = Huffman.encode(s_plain);
	System.out.println("Encoding:  " + s_code);
	System.out.println("Decoding:  " + Huffman.decode(H,s_code) + "\n\n");
    }

}




/*
  "ExperimentC" does what???
*/

class ExperimentC extends Experiment {

    protected static String program = "Experiment";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

	//  this program requires no argument on the command line  
        if (args.length != 0) {
	    System.err.println(err + "Exactly zero parameters are required.\n");
	    return;
	}

	Node H,x,y;
	x = new Node(7,c,a);
	x = new Node(7,x,b);
	y = new Node(8,x,d);
	H = new Node(9,e,y);
	Huffman.hc(H);

	Huffman.out(C);
	String s_plain = "adeedbede";
	System.out.println("Text:      " + s_plain);
	String s_code = Huffman.encode(s_plain);
	System.out.println("Encoding:  " + s_code);
	System.out.println("Decoding:  " + Huffman.decode(H,s_code) + "\n\n");
    }

}




class ExperimentD extends Experiment {

    protected static String program = "ExperimentD";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

	//  this program requires no argument on the command line  
        if (args.length != 0) {
	    System.err.println(err + "Exactly zero parameters are required.\n");
	    return;
	}

	Node H = Huffman.generate(C);
	Huffman.out(C);

	System.out.println("Text:      " + plaintext);
	String s = Huffman.encode(plaintext);
	System.out.println("Encoding:  " + s);
	System.out.println("Decoding:  " + Huffman.decode(H,s) + "\n\n");
    }

}


class ExperimentE {

    protected static String program = "ExperimentD";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

	//  this program requires no argument on the command line  
        if (args.length != 0) {
	    System.err.println(err + "Exactly zero parameters are required.\n");
	    return;
	}

	Node a = new Node('a', 1,null,null);
    	Node b = new Node('b', 2,null,null);
    	Node c = new Node('c', 3,null,null);
    	Node d = new Node('d', 4,null,null);
    	Node e = new Node('e', 5,null,null);
    	Node f = new Node('f', 6,null,null);
    	Node g = new Node('g', 7,null,null);
    	Node h = new Node('h', 8,null,null);
    	Node[] C = {a,b,c,d,e,f,g,h};

	Node H = Huffman.generate(C);
	Huffman.out(C);

    }

}


