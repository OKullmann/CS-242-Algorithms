// Arnold Beckmann, 30.03.2010 (Swansea)


/*
  File:  200910/Week09/FlowNetworks.java
  Descr: Simple representation of directed graphs via adjacency lists
*/


// import java.util.Hashtable;


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


class FlowNode {
    int v;     // vertex
    int c;     // capacity
    int f;     // flow to this vertex
    int rc;    // residual capacity to v

    FlowNode (int v, int c)
    { this.v = v; this.c = c; this.f = 0;}

    void rc() {
	this.rc = this.c - this.f;
    }
}
 

class FlowAdjacencyList {

    // For each vertex, a FlowadjacencyList will store the list
    // of adjacent vertices in increasing order (stored in FlowNodes)

    int N;       // number of vertices
    // vertices are 0, .. ,N-1,

    FlowNode[][] A;

    FlowAdjacencyList (int N) {
	this.N = N;
	A = new FlowNode[N][N+1];
	for (int i = 0; i < N; i++) {
	    for (int j = 0; j < N+1; j++)
		A[i][j] = null;
	}
    }

    void add_edge(Edge edge) {
	int u = edge.l;
	int v = edge.r;
	int c = edge.c;

	int i = 0;
	int j;
	// try to find v in u's adjacency list
	while (A[u][i] != null  &&  A[u][i].v < v)  i++;
	if (A[u][i] != null  &&  A[u][i].v == v) {
	    // v is in u's adjacency list, just update capacity.
	    A[u][i].c = c;
	    return;
	}
	if (A[u][i] == null) {
	    // v not in u's adjacency list
	    // and all elements in u's adjacency list are smaller than v
	    A[u][i] = new FlowNode(v,c);
	} else {
	    // v is not in u's adjacency list, and some elements are bigger
	    // than v - we make space for v by shifting elements
	    j = i+1;
	    while (A[u][j] != null)  j++;
	    while (j > i)  A[u][j] = A[u][--j];
	    A[u][i] = new FlowNode(v,c);
	}

	// We also add u to v's adjacency list with 0 capacity.
	// We know that u is not in v's adjacency list.
	i = 0;
	while (A[v][i] != null  &&  A[v][i].v < u)  i++;
	if (A[v][i] == null) {
	    // all elements in v's adjacency list are smaller than u
	    A[v][i] = new FlowNode(u,0);
	} else {
	    // some elements in v's adjacency list are bigger
	    // than u - we make space for u by shifting elements
	    j = i+1;
	    while (A[v][j] != null)  j++;
	    while (j > i)  A[v][j] = A[v][--j];
	    A[v][i] = new FlowNode(u,0);
	}

    }

    void add_edges(Edge[] edges) {
	for (int i = 0; i < edges.length; i++)
	    add_edge( edges[i] );       
    }

    FlowNode[] neighb (int u) {
	return A[u];
    }

    void residual_network () {
	//	System.out.printf("<rn> start \n");
	for (int u=0; u<N; u++) {
	    //  System.out.printf("<rn> %d \n",u);
	    for (int j=0; A[u][j] != null; j++)
		A[u][j].rc();
	}
    }

}

