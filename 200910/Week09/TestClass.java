
public class TestClass {
	public final int v;     // vertex
	public final int c;     // capacity

	TestClass (int v, int c)
	    { this.v = v; this.c = c; }

	public boolean equals(TestClass n) {
	    System.err.println("Used TestClass equals method.");
	    return (this.v == n.v);
	}

	public String toString() {
	    return "" + v + ", " + c;
	}
    }

