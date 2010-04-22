// Arnold Beckmann, 30.03.2010 (Swansea)


/*
  File:  200910/Week09/FlowNetworks.java
  Descr: Simple representation of directed graphs via adjacency lists
*/

import java.util.Iterator;
import java.util.Queue;
import java.util.LinkedList;


class Edge {

    int l;     // left vertex
    int r;     // right vertex
    int c;     // capacity along this edge

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

    public int compareTo(FlowNode n) {
	return (this.v - n.v);
    }
    public boolean equals(FlowNode n) {
	return (this.v == n.v);
    }

    public String toString() {
	return "" + v + ", " + c + ", " + f + ", " + rc;
    }
}
 

class FlowAdjacencyList {

    int N;       // number of vertices
    // vertices are 0, .. ,N-1,

    // For each vertex, a FlowAdjacencyList will store the list
    // of adjacent vertices in increasing order (stored in FlowNodes)


    // Due to a flaw/ feature of java generics we cannot use
    // generic array creation. i.e. something of the form
    //    new LinkedList<FlowNode>[N]
    // Here is a workaround
    class AdjList {
	private LinkedList<FlowNode> ll;
    }

    AdjList [] A;
    int source;
    int target;

    FlowAdjacencyList (int N, int s, int t) {
	this.N = N;
	source = s;  // one should check that s,t are in the right range
	target = t;  // 0,..,N-1 and throw an exception otherwise.

	A = new AdjList [N];
	for (int i = 0; i < N; i++) {
	    A[i] = new AdjList();
	    A[i].ll = new LinkedList<FlowNode>();
	}
    }


//  There seems to be a bug with the indexOf method for linked lists,
//  therefore I had to write my own method computing the index
//  of an occurrence 

    int indexOf(final LinkedList<FlowNode> fnll, final FlowNode fn) {
	
	assert fnll != null;
	assert fn != null;
	Iterator<FlowNode> itr = fnll.iterator(); 
	int i=-1;
	int j=0;
	while(itr.hasNext()) {
	    final FlowNode fni = itr.next();
//System.err.println(fni);
	    if (fn.equals(fni)) {
		i=j;
		break;
	    }
	    j++;
	}
//System.err.println();
	return i;
	
        // return fnll.indexOf(fn);
//  i  is an index of an element in the linked list with vertex v,
//  if it exists, o/w i=-1
    }


    void add_edge(Edge edge) {
  /*
      adds edge with capacity
      if (u,v) with capacity c has to be added, we also add
      (v,u) with capacity 0  (this is beneficial later when
      computing residual graphs)
  */
	int u = edge.l;
	int v = edge.r;
	int c = edge.c;

	FlowNode fn = new FlowNode(v,c);
	LinkedList<FlowNode> fnll = A[u].ll;
	int i = indexOf(fnll,fn);  // computes index of occurrence of fn
	                           // in fnll

	if (i>=0) {
	    // v occurs in u's adjacency list: 
	    // update capacity
	    fnll.remove(i);
	    fnll.add(fn);	    
	} else {
	    // v does not occur in u's adjacency list: 
	    // add v with capacity c to u's list
	    fnll.add(fn);
	    // and u with capacity 0 to v's list
	    FlowNode fnr = new FlowNode(u,0);
	    A[v].ll.add(fnr);
	}
    }

    void add_edges(Edge[] edges) {
	for (int i = 0; i < edges.length; i++)
	    add_edge( edges[i] );       
    }


    LinkedList<FlowNode> neighb (int u) {
	return A[u].ll;
    }


    void residual_network () {
/*
     For each edga in the flow network, we compute the residual 
     capacity.
*/
	for (int u=0; u<N; u++) {
	    for (FlowNode fn : A[u].ll) 
		fn.rc();
	}
    }


    int[] augmenting_path () {
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


    int residual_capacity (final int[] R) {
/*
    Compute residual capacity of an augmenting path given by  R
*/
	int cf = Integer.MAX_VALUE;
	if (R[target]<0) return cf;

	int v = target;
	while (v != source) {
	    int u = R[v];
	    FlowNode fn = new FlowNode(v,0);
	    LinkedList<FlowNode> fnll = A[u].ll;
	    int i = indexOf(fnll,fn);
	    assert i>=0;
	    cf = Math.min(cf, fnll.get(i).rc);
	    v = u;
	}
	return cf;
    }


    void adjust_residual_capacity (int[] R, int cf) {
/*
    Given an augmenting path by R with residual capacity cf
    we update flow by induced flow along this path.
*/
	int v = target;
	if (R[target]<0) return;
	while (v != source) {
	    int u = R[v];

	    FlowNode fn = new FlowNode(v,0);
	    LinkedList<FlowNode> fnll = A[u].ll;
	    int i = indexOf(fnll,fn);
	    fn = fnll.get(i);
	    fn.f += cf;
	    fnll.set(i,fn);

	    fn = new FlowNode(u,0);
	    fnll = A[v].ll;
	    i = indexOf(fnll,fn);
	    fn = fnll.get(i);
	    fn.f -= cf;
	    fnll.set(i,fn);

	    v = u;
	}

    }


    void FordFulkerson () {
	residual_network();
	int[] R = augmenting_path();
	while (R[target]>=0) {
	    int cf = residual_capacity(R);
	    adjust_residual_capacity(R,cf);
	    residual_network();
	    R = augmenting_path();
	}
    }


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


}

