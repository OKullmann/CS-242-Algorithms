// Arnold Beckmann, 05.03.2010 (Swansea)

/*
  File:  200910/Week09/Experiment_0.java
  Descr: Experiments with network flows
*/

import java.util.LinkedList;

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
//    public static Edge[] edges = {e2,e6};
}


/*
  "ExperimentA" implements a non optimal prefix code for text in
  "Experiment" and applies it to the text.  You will have to 
  change this to an optimal prefix code, i.e. one such that the
  encoded text has minimal length.
*/

class ExperimentA extends Experiment {

    static void outp(LinkedList<FlowNode> vs) {
	int i = 0;
	for (FlowNode fn : vs) {
	    if (++i == 4) {
		System.out.print("\n      ");
		i = 0;
	    }
	    System.out.printf("  %2d (c:%2d  f:%2d  rc:%2d)",
			      fn.v, fn.c, fn.f, fn.rc);
	}
	System.out.print("\n");
    }

    static void flow_outp(LinkedList<FlowNode> vs) {
	int i = 0;
	for (FlowNode fn : vs) {
	    if (i == 3) {
		System.out.print("\n      ");
		i = 0;
	    }
	    if (fn.c > 0) {
		System.out.printf("  %2d (c:%2d  f:%2d)",
				  fn.v, fn.c, fn.f);
		i++;
	    }
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

	System.out.println("");
	FlowAdjacencyList G = new FlowAdjacencyList(5,1,4);
	G.add_edges(edges);
	G.FordFulkerson();
	for (int i=0; i<5; i++) {
	    System.out.printf(" %d -> ",i);
	    LinkedList<FlowNode> vs = G.neighb(i);
	    flow_outp( vs );
	}
	System.out.println("");
	return;

/*
	G.residual_network();
 	for (int i=0; i<5; i++) {
	    System.out.printf(" %d -> ",i);
	    LinkedList<FlowNode> vs = G.neighb(i);
	    outp( vs );
	}

	int[] R = G.augmenting_path();
	int cf = G.residual_capacity(R);
	System.out.printf("\n\nresidual capacity:  %d \n",cf);
	G.adjust_residual_capacity(R,cf);
	G.residual_network();
 	for (int i=0; i<5; i++) {
	    System.out.printf(" %d -> ",i);
	    LinkedList<FlowNode> vs = G.neighb(i);
	    outp( vs );
	}

	R = G.augmenting_path();
	cf = G.residual_capacity(R);
	System.out.printf("\n\nresidual capacity:  %d \n",cf);
	G.adjust_residual_capacity(R,cf);
	G.residual_network();
 	for (int i=0; i<5; i++) {
	    System.out.printf(" %d -> ",i);
	    LinkedList<FlowNode> vs = G.neighb(i);
	    outp( vs );
	}

	R = G.augmenting_path();
	cf = G.residual_capacity(R);
	if (R[G.target]<0) {
	    System.out.printf("\n\nNo augmenting path exists. \n");
	} else {
	    cf = G.residual_capacity(R);
	    System.out.printf("\n\nresidual capacity:  %d \n",cf);
	}
*/
   }

}



