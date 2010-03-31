// Arnold Beckmann, 05.03.2010 (Swansea)

/*
  File:  200910/Week09/Experiment_0.java
  Descr: Experiments with network flows
*/


/*
  "Experiment" stores the frequencies of the letters
   occurring in the plain text "adeedbede"
*/

class Experiment {
    public static Edge e1 = new Edge(1,2);
    public static Edge e2 = new Edge(1,3);
    public static Edge e3 = new Edge(1,4);
    public static Edge e4 = new Edge(2,3);
    public static Edge e5 = new Edge(3,4);
    public static Edge e6 = new Edge(3,1);
    public static Edge e7 = new Edge(4,2);
    public static Edge e8 = new Edge(4,5);
    public static Edge[] edges = {e1,e2,e3,e4,e5,e6,e7,e8};
}


/*
  "ExperimentA" implements a non optimal prefix code for text in
  "Experiment" and applies it to the text.  You will have to 
  change this to an optimal prefix code, i.e. one such that the
  encoded text has minimal length.
*/

class ExperimentA extends Experiment {

    static void outp(int[] vs) {
	for (int i = 1; i <= vs[0]; i++) {
	    System.out.printf("  %2d", vs[i]);
	}
	System.out.print("\n");
    }

    protected static String program = "Experiment";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

	//  this program requires no argument on the command line  
        if (args.length != 0) {
	    System.err.println(err + "Exactly zero parameters are required.\n");
	    return;
	}

	AdjacencyList G = new AdjacencyList(5);
	G.add_edges(edges);
	System.out.print(" 1 -> ");
	int[] vs = G.neighb(1);
	outp( vs );

	/*
	Node H,x,y;
	y = new Node(7,d,e);
	y = new Node(7,c,y);
	y = new Node(8,b,y);
	H = new Node(9,a,y);
	Huffman.hc(H);

	Huffman.out(C);
	System.out.println("Text:      " + plaintext);
	String s_code = Huffman.encode(plaintext);
	System.out.println("Encoding:  " + s_code);
	System.out.println("Decoding:  " + Huffman.decode(H,s_code) + "\n\n");
	*/

    }

}



