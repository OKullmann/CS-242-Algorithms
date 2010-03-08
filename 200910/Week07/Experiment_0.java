// Arnold Beckmann, 05.03.2010 (Swansea)

/*
  File:  200910/Week07/Experiment_0.java
  Descr: Experiments with Huffman codes
*/


/*
  "Experiment" stores the frequencies of letters in the plain text
  "adeedbede"
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


/*
  "ExperimentA" implements a non optimal prefix code for text in
  "Experiment" and applies it to the text.
*/

class ExperimentA extends Experiment {

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
  "ExperimentB" applies Huffman's algorithm to compute an optimal prefix code
  for text in "Experiment", and applies the computed prefix code to the text.
*/

class ExperimentB extends Experiment {

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



/*
  "ExperimentC" applies Huffman's algorithm to compute an optimal prefix code
  for 8 letters given with some fequencies, and displays the prefix code.
*/

class ExperimentC {

    protected static String program = "ExperimentC";
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


