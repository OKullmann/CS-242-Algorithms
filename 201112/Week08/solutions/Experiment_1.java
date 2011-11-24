// Arnold Beckmann, 05.03.2010 (Swansea)

/*
  File:  200910/Week07/solutions/Experiment_1.java
  Descr: Experiments with Huffman codes
*/


/*
  "Experiment" stores the frequencies of letters in the plain text
  "adeedbede"
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
  "ExperimentA1" implements an optimal prefix code for text in
  "Experiment" and applies it to the text.
*/

class ExperimentA1 extends Experiment {

    protected static final String program = "Experiment";
    protected static final String err = "ERROR[" + program + "]: ";

    public static void main(final String[] args) {

	//  this program requires no argument on the command line  
        if (args.length != 0) {
	    System.err.println(err + "Exactly zero parameters are required.\n");
	    return;
	}

	Node x = new Node(7,c,a);
	x = new Node(7,x,b);
	final Node y = new Node(8,x,d);
	final Node H = new Node(9,e,y);
	Huffman.hc(H);

	Huffman.out(C);
	System.out.println("Text:      " + plaintext);
	String s_code = Huffman.encode(plaintext);
	System.out.println("Encoding:  " + s_code);
	System.out.println("Decoding:  " + Huffman.decode(H,s_code) + "\n\n");
    }

}


/*
  In "ExperimentC1", the frequencies from "ExperimentC" have been changed
  so that the computed optimal prefix code form a complete binary tree:
                 
            ______/\______ 
           0              1
        __/ \__        __/ \__ 
       0       1      0       1
      / \     / \    / \     / \
     0   1   0   1  0   1   0   1

     a   h   e   c  f   d   g   b

*/

class ExperimentC1 {

    protected static final String program = "ExperimentC";
    protected static final String err = "ERROR[" + program + "]: ";

    public static void main(final String[] args) {

	//  this program requires no argument on the command line  
        if (args.length != 0) {
	    System.err.println(err + "Exactly zero parameters are required.\n");
	    return;
	}

      final Node a = new Node('a', 1,null,null);
      final Node b = new Node('b', 1,null,null);
      final Node c = new Node('c', 1,null,null);
      final Node d = new Node('d', 1,null,null);
      final Node e = new Node('e', 1,null,null);
      final Node f = new Node('f', 1,null,null);
      final Node g = new Node('g', 1,null,null);
      final Node h = new Node('h', 1,null,null);
      final Node[] C = {a,b,c,d,e,f,g,h};

	final Node H = Huffman.generate(C);
	Huffman.out(C);
    }
}


/*
  In "ExperimentC2", the frequencies from "ExperimentC" have been changed
  so that the computed optimal prefix code forms a saw:
                   _    
                  / \ 
                 0   1
                / \   h
               0   1 
              / \   g
 	     0   1 
            / \   f
           0   1 
          / \   e
         0   1 
        / \   d 
       0   1 
      / \   c
     0   1
    a     b

*/

class ExperimentC2 {

    protected static final String program = "ExperimentC";
    protected static final String err = "ERROR[" + program + "]: ";

    public static void main(final String[] args) {

	//  this program requires no argument on the command line  
        if (args.length != 0) {
	    System.err.println(err + "Exactly zero parameters are required.\n");
	    return;
	}

      final Node a = new Node('a', 0,null,null);
      final Node b = new Node('b', 1,null,null);
      final Node c = new Node('c', 2,null,null);
      final Node d = new Node('d', 4,null,null);
      final Node e = new Node('e', 8,null,null);
      final Node f = new Node('f',16,null,null);
      final Node g = new Node('g',32,null,null);
      final Node h = new Node('h',64,null,null);
      final Node[] C = {a,b,c,d,e,f,g,h};

	final Node H = Huffman.generate(C);
	Huffman.out(C);

    }

}
