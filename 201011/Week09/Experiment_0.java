// Arnold Beckmann, 05.03.2010 (Swansea)

/*
  File:  201011/Week09/Experiment_0.java
  Descr: Experiments with network flows
*/

import java.util.LinkedList;


/*
  "ExperimentA" runs FordFulkerson on some flow network
  and outputs the computed flow.
*/

class ExperimentA {

    protected static String program = "ExperimentA";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

	//  this program requires no argument on the command line  
        if (args.length != 0) {
	    System.err.println(err + "Exactly zero parameters are required.\n");
	    return;
	}

	Edge e1 = new Edge(0,2,5);
	Edge e2 = new Edge(1,2,3);
	Edge e3 = new Edge(1,3,4);
	Edge e4 = new Edge(1,4,3);
	Edge e5 = new Edge(2,1,2);
	Edge e6 = new Edge(2,3,7);
	Edge e7 = new Edge(3,4,1);
	Edge e8 = new Edge(3,1,5);
	Edge[] edges = {e1,e2,e3,e4,e5,e6,e7,e8};

	FlowAdjacencyList G = new FlowAdjacencyList(5,0,4);
	G.add_edges(edges);

	G.FordFulkerson();

	System.out.println("\n" + G + "\n");
	for (int i=0; i<5; i++) {
	    System.out.printf("Net flow out of vertex %d:  %d\n",i,G.value(i));
	}
	System.out.println();
   }

}



/*
  "ExperimentB" produces some flow network with some flow and then
  does one iteration of FordFulkerson, producing appropriate outputs
  for each step.
*/

class ExperimentB {

    protected static String program = "ExperimentB";
    protected static String err = "ERROR[" + program + "]: ";

    public static void main(String[] args) {

	//  this program requires no argument on the command line  
        if (args.length != 0) {
	    System.err.println(err + "Exactly zero parameters are required.\n");
	    return;
	}

	Edge e1 = new Edge(0,2,5);
	Edge e2 = new Edge(1,2,3);
	Edge e3 = new Edge(1,3,4);
	Edge e4 = new Edge(1,4,3);
	Edge e5 = new Edge(2,1,2);
	Edge e6 = new Edge(2,3,7);
	Edge e7 = new Edge(3,4,1);
	Edge e8 = new Edge(3,1,5);
	Edge[] edges = {e1,e2,e3,e4,e5,e6,e7,e8};

	FlowAdjacencyList G = new FlowAdjacencyList(5,0,4);
	G.add_edges(edges);

	System.out.println("\n\n     Some intermediate step in computing "
	    + "maximum flow in a flow network:\n");

	G.residual_network();
	int[] R = G.augmenting_path();
	int cf = G.residual_capacity(R);
	G.adjust_residual_capacity(R,cf);

	G.residual_network();
	System.out.println("\nThe flow network with some flow "
			   + "and residual capacities:\n");
	System.out.println(G);

	System.out.println("\nFind augmenting path using BFS:");
	R = G.augmenting_path();
	for (int i=0; i<5; i++) {
	    System.out.printf(" %d has parent %d    ",i,R[i]);
	    if ((i % 4) == 3) System.out.println();
	}

	cf = G.residual_capacity(R);
	System.out.printf("\n\nResidual capacity "
	      + "along augmenting path:  %d\n\n", cf);

   }

}


