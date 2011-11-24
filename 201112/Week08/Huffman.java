// Arnold Beckmann, 09.03.2010 (Swansea)
// Oliver Kullmann, 24.11.2011 (Swansea)

/*
  File:  201112/Week08/Huffman.java
  Descr: Huffman codes
*/

import java.util.Hashtable;

/*
  Class Node defines a basic compound data structure suitable
  for implementing Huffman codes.
*/

class Node {

    final char c;
    final int f;   // frequency
    final Node l;  // left  child in Huffman code (for "0")
    final Node r;  // right child in Huffman code (for "1")
    String h;      // resulting Huffman encoding (a binary string);

    Node (final char c_, final int f_, final Node l_, final Node r_) {
      assert(f_ >= 0);
      c = c_; f = f_; l = l_; r =r_;
      h = "";
    }
    Node (final int f_, final Node l_, final Node r_) {
      assert(f_ >= 0);
      c = ' '; f = f_; l = l_; r =r_;
      h = "";
    }
    boolean larger(final Node i) { return this.f > i.f; }
}


/*
  We now give an implementation of a min priority queue for Nodes
  keyed on frequencies Node.f
 */
class PQ {

    private boolean larger(final int i, final int j) {
      return pq[i].larger(pq[j]);
    }
    private void exch(final int i, final int j) {
      final Node t = pq[i]; pq[i] = pq[j]; pq[j] = t;
    }

    private void swim(int k) {
	while (k > 1 && larger(k/2, k)) {
	  exch(k,k/2); k = k/2;
      }
    }
    private void sink(int k, final int N) {
	while (2*k <= N) {
	    int j = 2*k;
	    if (j < N && larger(j,j+1)) ++j;
	    if (!larger(k,j)) break;
	    exch(k,j); k = j;
	}
    }

    private final Node[] pq;
    private int N;

    PQ(final int maxN) { pq = new Node[maxN+1]; N=0; }
    int length() { return N; }
    void insert(final Node v) { pq[++N] = v; swim(N); }
    Node getmin() { exch(1,N); sink(1, N-1); return pq[N--]; }
}


/*
  "Huffman" implements methods to compute and make use of
  Huffman codes.
 */

class Huffman {

    static private final Hashtable M = new Hashtable();

// "generate" implements the greedy algorithm for computing Huffman codes
// from the lecture
    public static Node generate(final Node[] C) {
	final int n = C.length;

	PQ Q = new PQ(n);
	for (int i = 0; i < n; ++i) Q.insert(C[i]);

	for (int i = 1; i < n; ++i) {
	  final Node x = Q.getmin();
	  final Node y = Q.getmin();
	  final int f = x.f + y.f;
	  final Node z = new Node(f,x,y);
	  Q.insert(z);
	}
	final Node z = Q.getmin();
	hc("",z);
	return z;
    }

/*
   "hc" computes the Huffman code based on the Node structure
   and stores the result in the leafes of the Node structure,
   and also in the hashtable M keyed on the char stored in the leafes.
*/

    public static void hc(final Node H) { hc("",H); }
    private static void hc(final String s, final Node H) {
      assert(H != null);
	boolean leaf = true;
	if (H.l != null) { leaf = false; hc(s+"0",H.l); }
	if (H.r != null) { leaf = false; hc(s+"1",H.r); }
	if (leaf) { H.h = s; M.put(H.c, H); }
    }


// "out" outputs the stored Huffman codes
    public static void out(final Node[] C) {
      assert(C != null);
	int l = 0;
	System.out.println("\n\nHuffman code\n");
	for (int i = 0; i < C.length; ++i) {
	  System.out.printf("  char: %c   freq: %2d   code: %8s \n",
                          C[i].c, C[i].f, C[i].h);
	  l += C[i].f * C[i].h.length();
	}
	System.out.println("\nOverall length of code:  " + l + "\n");
    }


// "encode" encodes a string based on the Huffman code stored in the
// hashtable M
    public static String encode(final String s) {
	String o = "";
	for (int i = 0; i < s.length(); ++i) {
	  char k = s.charAt(i);
	  o += ((Node)M.get(k)).h;
	}
	return o;
    }

// "decode" decodes a binary string based on the Huffman code stored
// in the given Node structure
    public static String decode(final Node H, final String s) {
      String o = "";
      Node w = H;
      for (int i = 0; i < s.length(); i++) {
        if (s.charAt(i) == '0') {
          if (w.l == null) {
            o += w.c;
            w = H.l;
          } else w = w.l;
	  }
        else {
	    if (w.r == null) {
	      o += w.c;
	      w = H.r;
	    } else w = w.r;
	  }
      }
      o += w.c;
      return o;
    }
}
