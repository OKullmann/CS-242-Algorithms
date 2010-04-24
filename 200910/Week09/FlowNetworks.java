// Arnold Beckmann, 30.03.2010 (Swansea)


/*
  File:  200910/Week09/FlowNetworks.java
  Descr: Simple representation of directed graphs via adjacency lists
*/

import java.util.Iterator;
import java.util.Queue;
import java.util.LinkedList;


class Edge {

    public final int l;     // left vertex
    public final int r;     // right vertex
    public final int c;     // capacity along this edge

    Edge (int l, int r, int c)
    { this.l = l; this.r = r; this.c = c; }

}


//class FlowNode implements Comparable<FlowNode> {
class FlowNode {
    public final int v;     // vertex
    public final int c;     // capacity
    public int f;     // flow to this vertex
    public int rc;    // residual capacity to v

    FlowNode (int v, int c)
    { this.v = v; this.c = c; this.f = 0;}

    void rc() {
	this.rc = this.c - this.f;
    }

    public int compareTo(Object o) {
	FlowNode n = (FlowNode) o;
	return (this.v - n.v);
    }
    public boolean equals(Object o) {
	FlowNode n = (FlowNode) o;
	return (this.v == n.v);
    }

    public String toString() {
	return "" + v + " (f: " + f + ", c:" + c + ", rc:" + rc + ") ";
    }
}
 

class FlowAdjacencyList {

    final int N;       // number of vertices
    // vertices are 0, .. ,N-1,

    // For each vertex, a FlowAdjacencyList will store the list
    // of adjacent vertices in increasing order (stored in FlowNodes)


    // Due to a flaw/ feature of java generics we cannot use
    // generic array creation. i.e. something of the form
    //    new LinkedList<FlowNode>[N]
    // Here is a workaround
    private class AdjList {
	private LinkedList<FlowNode> ll;
    }

    private AdjList [] A;
    private final int source;
    private final int target;

    FlowAdjacencyList (int N, int s, int t) {
	this.N = N;
	source = s;
	target = t;
	assert (0<=s && s<N);
	assert (0<=t && t<N);

	A = new AdjList [N];
	for (int i = 0; i < N; i++) {
	    A[i] = new AdjList();
	    A[i].ll = new LinkedList<FlowNode>();
	}
    }


    public void add_edge(final Edge edge) {
  /*
      adds edge with capacity
      if (u,v) with capacity c has to be added, we also add
      (v,u) with capacity 0  (this is beneficial later when
      computing residual graphs)
  */
	final int u = edge.l;
	final int v = edge.r;
	final int c = edge.c;

	final FlowNode fn = new FlowNode(v,c);
	LinkedList<FlowNode> fnll = A[u].ll;

	if (fnll.contains(fn)) {
	    // v occurs in u's adjacency list: 
	    // update capacity
	    fnll.remove(fn);
	    fnll.add(fn);	    
	} else {
	    // v does not occur in u's adjacency list: 
	    // add v with capacity c to u's list
	    fnll.add(fn);
	    // and u with capacity 0 to v's list
	    final FlowNode fnr = new FlowNode(u,0);
	    A[v].ll.add(fnr);
	}
    }

    public void add_edges(final Edge[] edges) {
	for (int i = 0; i < edges.length; i++)
	    add_edge( edges[i] );       
    }


    public LinkedList<FlowNode> neighb (int u) {
	return A[u].ll;
    }


    public void residual_network () {
/*
     For each edga in the flow network, we compute the residual 
     capacity.
*/
	for (int u=0; u<N; u++) {
	    for (FlowNode fn : A[u].ll) 
		fn.rc();
	}
    }


    public int[] augmenting_path () {
/*
    Try to find augmenting path using bfs.
    We return a vector  R  which stores for each node  v   either a
    parent on a path from  source  to  v,  or  -1  if no such exists.
    Thus,  target  is reachable from  source  iff  R[target]>=0.
*/
	int[] R = new int[N];   // result vector of parent nodes
	for (int i = 1; i < N; i++)  R[i] = -1;

	Queue<Integer> Q = new LinkedList<Integer>();   // queue for bfs
	Q.add(source);

	while (Q.peek() != null) {
	    int u = Q.poll();
	    LinkedList<FlowNode> fnll = A[u].ll;
	    Iterator<FlowNode> itr = fnll.iterator(); 
	    while(itr.hasNext()) {
		FlowNode fn = itr.next();
		int v = fn.v;
		if (R[v]<0 && fn.rc>0) {
		    R[v] = u;
		    Q.offer(v);
		}
	    }
	}

	return R;
    }


    public int residual_capacity (final int[] R) {
/*
    Compute residual capacity of an augmenting path given by  R
*/
	int cf = Integer.MAX_VALUE;
	assert R[target]>=0;  // augmenting path does not exists as target
	                      // is not reachable

	int v = target;
	while (v != source) {
	    int u = R[v];
	    FlowNode fn = new FlowNode(v,0);
	    LinkedList<FlowNode> fnll = A[u].ll;
	    int i = fnll.indexOf(fn);
	    assert i>=0;
	    cf = Math.min(cf, fnll.get(i).rc);
	    v = u;
	}
	return cf;
    }


    public void adjust_residual_capacity (final int[] R, final int cf) {
/*
    Given an augmenting path by R with residual capacity cf
    we update flow by induced flow along this path.
*/
	int v = target;
	assert R[target]>=0;  // augmenting path does not exists as target
	                      // is not reachable
	while (v != source) {
	    int u = R[v];

	    FlowNode fn = new FlowNode(v,0);
	    LinkedList<FlowNode> fnll = A[u].ll;
	    int i = fnll.indexOf(fn);
	    fn = fnll.get(i);
	    fn.f += cf;
	    fnll.set(i,fn);

	    fn = new FlowNode(u,0);
	    fnll = A[v].ll;
	    i = fnll.indexOf(fn);
	    fn = fnll.get(i);
	    fn.f -= cf;
	    fnll.set(i,fn);

	    v = u;
	}

    }

    public int value() {
	return value(source);
    }
    public int value(final int u) {
	int f = 0;
	for (FlowNode fn : neighb(u)) {
	    f += fn.f;
	}
	return f;
    }

    public void FordFulkerson () {
	residual_network();
	int[] R = augmenting_path();
	while (R[target]>=0) {
	    int cf = residual_capacity(R);
	    adjust_residual_capacity(R,cf);
	    residual_network();
	    R = augmenting_path();
	}
    }

    private static String full_outp(final LinkedList<FlowNode> vs) {
	String s="";
	int i = 0;
	for (FlowNode fn : vs) {
	    if (++i == 4) {
		s += "\n      ";
		i = 0;
	    }
	    s += String.format("  %2d (c:%2d  f:%2d  rc:%2d)",
			      fn.v, fn.c, fn.f, fn.rc);
	}
	return s;
    }

    public String toString() {
	String s = "";
    	for (int i=0; i<N; i++) {
	    if (i>0) s += "\n";
	    s += String.format(" %d -> ",i);
	    LinkedList<FlowNode> vs = neighb(i);
	    s += full_outp( vs );
	}

	return s;
    }


}

