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

import java.util.Hashtable;


class Node {

    char c;      // the symbol to be stored
    int f;       // the frequency
    String h;    // Huffman code;
    Node l;      // left  child in Huffman code (for "0")
    Node r;      // right child in Huff man code (for "1")
    Node (char c, int f, Node l, Node r)
	{ this.c = c; this.f = f; this.h = ""; this.l = l; this.r =r; }
    Node (int f, Node l, Node r)
	{ this.c = ' '; this.f = f; this.h = ""; this.l = l; this.r =r; }
    boolean larger(Node i) {
	return this.f > i.f;
    }

}


/*
  We now give an implementation of a min priority queue for Nodes 
  keyed on frequencies Node.f
 */
class PQ {

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



class Huffman { 

    static private Hashtable M = new Hashtable();

    public static Node generate(Node[] C) {
	Node x,y,z;
	int f;
	int n = C.length;

	PQ Q = new PQ(n);
	for (int i = 0; i < n; i++) {
	    Q.insert(C[i]);
	}

	for (int i = 1; i < n; i++) {
	    x = Q.getmin();
	    y = Q.getmin();
	    f = x.f + y.f;
	    z = new Node(f,x,y);
	    Q.insert(z);
	}
	z = Q.getmin();
	hc("",z);
	return z;
    }

// Generate the Huffman code based on the binary

    public static void hc(Node H) {
	hc("",H);
    }
    private static void hc(String s, Node H) {
	boolean leaf = true;
	if (H.l != null) { leaf = false; hc(s+"0",H.l); }
	if (H.r != null) { leaf = false; hc(s+"1",H.r); }
	if (leaf) { H.h = s; M.put(H.c, H); }
    }

    public static void out(Node[] C) {
	int l = 0;
	System.out.println("\n\nHuffman code\n");
	for (int i = 0; i < C.length; i++) {
	    System.out.printf("  char: %c   freq: %2d   code: %8s \n",
			      C[i].c, C[i].f, C[i].h);
	    l += C[i].f * C[i].h.length();
	}
	System.out.println("\nOverall length of code:  " + l + "\n");
    }

    public static String encode(String s) {
	String o = "";
	for (int i = 0; i < s.length(); i++) {
	    char k = s.charAt(i);
	    o = o + ((Node)M.get(k)).h;
	}
	return o;
    }

    public static String decode(Node H, String s) {
	String o = "";
	Node w = H;
	for (int i = 0; i < s.length(); i++) {
	    if (s.charAt(i) == '0') {
		if (w.l == null) {
		    o = o + w.c;
		    w = H.l;
		} else
		    w = w.l;
	    } else {
		if (w.r == null) {
		    o  = o + w.c;
		    w = H.r;
		} else
		    w = w.r;
	    }
	}
	o = o + w.c;
	return o;
    }

}		


