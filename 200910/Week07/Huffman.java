// This file has been generated from   solutions/Sorting_1.java 
// Arnold Beckmann, 19.12.2009 (Swansea)


/*
  File:  200910/Week01/solutions/Sorting_1.hpp
  Descr: Sorting algorithms
*/


/*
  The next class defines a basic compound data structure suitable
  for implementing Huffman codes.
*/

class Huffman { 


static class Node {

    char c;      // the symbol to be stored
    int f;       // the frequency
    Node l; Node r;
    Node (char c, int f, Node l, Node r)
	{ this.c = c; this.f = f; this.l = l; this.r =r; }
    boolean larger(Node i) {
	return this.f > i.f;
    }

}


/*
  We now give an implementation of a min priority queue for ITEMs 
  keyed on frequencies ITEM.f
 */
static class PQ {

    private boolean larger(int i, int j)
	{ return pq[i].larger(pq[j]); }
    private void exch(int i, int j)
	{ Node t = pq[i]; pq[i] = pq[j]; pq[j] = t; }

    private void swim(int k) {
	while (k > 1 && larger(k/2, k)) 
	    { exch(k,k/2); k = k/2; }
    }
    private void sink(int k, int N) {
	while (2*k <= N) {
	    int j = 2*k;
	    if (j < N && larger(j,j+1)) j++;
	    if (!larger(k,j)) break;
	    exch(k,j); k = j;
	}
    }

    private Node[] pq;
    private int N;

    PQ(int maxN)
	{ pq = new Node[maxN+1]; N=0; }
    int length()
	{ return N; }
    void insert(Node v)
	{ pq[++N] = v; swim(N); }
    Node getmin()
	{ exch(1,N); sink(1, N-1); return pq[N--]; }
}


    public static Node Huffman(ITEM[] C) {
	Node x,y,z;
	ITEM v;
	int n = C.length;

	PQ Q = new PQ(n);
	for (int i = 0; i < n; i++) {
	    z = new Node(C[i],null,null);
	    Q.insert(z);
	}

	for (int i = 1; i < n; i++) {
	    x = Q.getmin();
	    y = Q.getmin();
	    v.f = x.item.f + y.item.f;
	    z = new Node(v,x,y);
	    Q.insert(z);
	}
	return Q.getmin();
    }

}		


