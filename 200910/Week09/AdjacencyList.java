// Arnold Beckmann, 30.03.2010 (Swansea)


/*
  File:  200910/Week09/AdjacencyList.java
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

    Edge (int l, int r)
    { this.l = l; this.r = r; }

}



class AdjacencyList {

    int N;       // number of vertices
    // vertices are 1, .. ,N,
    // const int nil = 0;  // no vertex

    int[][] A;

    AdjacencyList (int N) {
	A = new int[N+1][N+1];
	for (int i = 1; i <= N; i++) {
	    A[i][0] = 0;  // initially, number of adjacent elements is 0
	    for (int j = 1; i <= N; i++)
		A[i][j] = 0; // "0" indicates no vertex
	}
    }

    void add_edge(Edge edge) {
	int u = edge.l;
	int v = edge.r;
	int l = A[u][0]+1;

	int i = 1;
	while (i < l && A[u][i] < v) i++;
	if (i == l || A[u][i] > v) { 
		A[u][0] = l;
		for (int j = l; j > i; j--) 
		    A[u][j] = A[u][j-1];
		A[u][i] = v;
	}
    }

    void add_edges(Edge[] edges) {
	for (int i = 0; i < edges.length; i++)
	    add_edge( edges[i] );       
    }

    int[] neighb (int u) {
	return A[u];
    }

}

