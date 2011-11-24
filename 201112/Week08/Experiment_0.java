// Arnold Beckmann, 05.03.2010 (Swansea)
// Oliver Kullmann, 24.11.2011 (Swansea)

/*
  File:  201112/Week08/Experiment_0.java
  Descr: Experiments with Huffman codes
*/


/*
   Class Experiment contains the trivial trees, represented by their
   root notes, for the latters a-e, with frequencies as occurring in the
   text "adeedbede".
*/

class Experiment {
    public static final Node a = new Node('a',1,null,null);
    public static final Node b = new Node('b',1,null,null);
    public static final Node c = new Node('c',0,null,null);
    public static final Node d = new Node('d',3,null,null);
    public static final Node e = new Node('e',4,null,null);
    public static final Node[] C = {a,b,c,d,e};
    public static final String plaintext = "adeedbede";
}


/*
  "ExperimentA" implements a non-optimal prefix code for the nodes as
  given in class Experiment and applies it to the text.  You will have to
  change this to an optimal prefix code, i.e., one such that the
  encoded text has minimal length.
*/

class ExperimentA extends Experiment {

    protected static final String program = "Experiment";
    protected static final String err = "ERROR[" + program + "]: ";

    public static void main(final String[] args) {

	//  this program requires no argument on the command line
        if (args.length != 0) {
	    System.err.println(err + "Exactly zero parameters are required.\n");
	    return;
	}

	Node y = new Node(7,d,e);
	y = new Node(7,c,y);
	y = new Node(8,b,y);
	final Node H = new Node(9,a,y);
	Huffman.hc(H);

	Huffman.out(C);
	System.out.println("Text:      " + plaintext);
	final String s_code = Huffman.encode(plaintext);
	System.out.println("Encoding:  " + s_code);
	System.out.println("Decoding:  " + Huffman.decode(H,s_code) + "\n\n");
    }

}


/*
  "ExperimentB" applies Huffman's algorithm to compute an optimal prefix code
  for plaintext in "Experiment", and applies the computed prefix code
  to the text.
*/

class ExperimentB extends Experiment {

    protected static final String program = "ExperimentD";
    protected static final String err = "ERROR[" + program + "]: ";

    public static void main(final String[] args) {

	//  this program requires no argument on the command line
        if (args.length != 0) {
	    System.err.println(err + "Exactly zero parameters are required.\n");
	    return;
	}

	final Node H = Huffman.generate(C);
	Huffman.out(C);

	System.out.println("Text:      " + plaintext);
	final String s = Huffman.encode(plaintext);
	System.out.println("Encoding:  " + s);
	System.out.println("Decoding:  " + Huffman.decode(H,s) + "\n\n");
    }

}



/*
  "ExperimentC" applies Huffman's algorithm to compute an optimal prefix code
  for 8 letters given with some fequencies, and displays the prefix code.
*/

class ExperimentC {

    protected static final String program = "ExperimentC";
    protected static final String err = "ERROR[" + program + "]: ";

    public static void main(final String[] args) {

	//  this program requires no argument on the command line
        if (args.length != 0) {
	    System.err.println(err + "Exactly zero parameters are required.\n");
	    return;
	}

      final Node a = new Node('a', 1,null,null);
      final Node b = new Node('b', 2,null,null);
      final Node c = new Node('c', 3,null,null);
      final Node d = new Node('d', 4,null,null);
      final Node e = new Node('e', 5,null,null);
      final Node f = new Node('f', 6,null,null);
      final Node g = new Node('g', 7,null,null);
      final Node h = new Node('h', 8,null,null);
      final Node[] C = {a,b,c,d,e,f,g,h};

	final Node H = Huffman.generate(C);
	Huffman.out(C);

    }

}


