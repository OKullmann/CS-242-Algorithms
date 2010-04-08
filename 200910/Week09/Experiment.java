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
    public static Edge e1 = new Edge(1,2,5);
    public static Edge e2 = new Edge(1,3,4);
    public static Edge e3 = new Edge(1,4,3);
    public static Edge e4 = new Edge(2,3,7);
    public static Edge e5 = new Edge(3,4,1);
    public static Edge e6 = new Edge(3,1,5);
    public static Edge e7 = new Edge(4,2,3);
    public static Edge e8 = new Edge(4,0,8);
    public static Edge[] edges = {e1,e2,e3,e4,e5,e6,e7,e8};
}


/*
  "ExperimentA" implements a non optimal prefix code for text in
  "Experiment" and applies it to the text.  You will have to 
  change this to an optimal prefix code, i.e. one such that the
  encoded text has minimal length.
*/

class ExperimentA extends Experiment {

    static void outp(FlowNode[] vs) {
	int i = 0;
	while (vs[i] != null) {
	    System.out.printf("  %2d (c:%2d  f:%2d  rc:%2d)",
			      vs[i].v, vs[i].c, vs[i].f, vs[i].rc);
	    i++;
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

	FlowAdjacencyList G = new FlowAdjacencyList(5);
	G.add_edges(edges);
	for (int i=0; i<5; i++) {
	    System.out.printf(" %d -> ",i);
	    FlowNode[] vs = G.neighb(i);
	    outp( vs );
	}
	G.residual_network();
 	for (int i=0; i<5; i++) {
	    System.out.printf(" %d -> ",i);
	    FlowNode[] vs = G.neighb(i);
	    outp( vs );
	}
   }

}



