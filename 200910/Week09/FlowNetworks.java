// Arnold Beckmann, 30.03.2010 (Swansea)


/*
  File:  200910/Week09/FlowNetworks.java
  Descr: Simple representation of directed graphs via adjacency lists
*/

import java.util.Iterator;
import java.util.Queue;
import java.util.LinkedList;

/*
  The next class defines a basic compound data structure suitable
  for implementing Huffman codes.


    Undirected graphs are represented via symmetric digraphs.
    The main functionality:
     - AdjacencyList(N) creates a graph with N vertices and zero edges.
     - G.add_edges(begin,end, directed=false) adds edges (as vertex-pairs)
       to graph G.
     - G[v] returns the adjacency-vector of vertex v.

    Vertices are represented by natural numbers 0, ..., N-1.

*/

class Edge {

    int l;     // left vertex
    int r;     // right vertex
    int c;     // capacity along this edge

    Edge (int l, int r, int c)
    { this.l = l; this.r = r; this.c = c; }

}


class FlowNode implements Comparable<FlowNode> {
    int v;     // vertex
    int c;     // capacity
    int f;     // flow to this vertex
    int rc;    // residual capacity to v

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
	target = t;  // 0,..,N-1 and through exception otherwise.

	A = new AdjList [N];
	for (int i = 0; i < N; i++) {
	    A[i] = new AdjList();
	    A[i].ll = new LinkedList<FlowNode>();
	}
    }


    int indexOf(LinkedList<FlowNode> fnll, FlowNode fn) {
//  There seems to be a bug with the indexOf method, therefore I have
//  written my own method computing the index of an occurrence
	Iterator<FlowNode> itr = fnll.iterator(); 
	int i=-1;
	int j=0;
	while(itr.hasNext()) {
	    if (fn.equals(itr.next()))
		i=j;
	    j++;
	}
//  i  is an index of an element in the linked list with vertex v,
//  if it exists, o/w i=-1
	return i;
    }


    void add_edge(Edge edge) {
	int u = edge.l;
	int v = edge.r;
	int c = edge.c;

	FlowNode fn = new FlowNode(v,c);
	LinkedList<FlowNode> fnll = A[u].ll;
	int i = indexOf(fnll,fn);
	if (i>=0) {
	    // v in u's adjacency list: 
	    // update capacity
	    fnll.remove(i);
	    fnll.add(fn);	    
	} else {
	    // v not in u's adjacency list: 
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
	for (int u=0; u<N; u++) {
	    for (FlowNode fn : A[u].ll) 
		fn.rc();
	}
    }


    int[] augmenting_path () {
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


    int residual_capacity (int[] R) {
	int cf = Integer.MAX_VALUE;
	if (R[target]<0) return cf;

	int v = target;
	while (v != source) {
	    int u = R[v];
	    FlowNode fn = new FlowNode(v,0);
	    LinkedList<FlowNode> fnll = A[u].ll;
	    int i = indexOf(fnll,fn);
	    cf = Math.min(cf, fnll.get(i).rc);
	    v = u;
	}
	return cf;
    }


    void adjust_residual_capacity (int[] R, int cf) {
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
}

