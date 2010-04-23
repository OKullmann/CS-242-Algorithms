// Arnold Beckmann, 22.04.2010 (Swansea)


/*
  File:  200910/Week09/Test.java
  Descr: Testing indexOf for LinkedLists
*/

import java.util.Iterator;
import java.util.LinkedList;


class TestClass {
	public final int v;     // vertex
	public final int c;     // capacity

	TestClass (int v, int c)
	    { this.v = v; this.c = c; }

	public boolean equals(Object o) {
	    TestClass n = (TestClass) o;
	    System.err.println("Used TestClass equals method.");
	    return (this.v == n.v);
	}

	public String toString() {
	    return "" + v + ", " + c;
	}
    }



public class Test {

    protected static String program = "Test";
    protected static String err = "ERROR[" + program + "]: ";


    public static void main(String[] args) {

	//  this program requires no argument on the command line  
        if (args.length != 0) {
	    System.err.println(err + "Exactly zero parameters are required.\n");
	    return;
	}


	TestClass fn1 = new TestClass(1,5);
	TestClass fn2 = new TestClass(2,5);
	TestClass fn3 = new TestClass(1,4);
	LinkedList<TestClass> fnll = new LinkedList<TestClass>();
	fnll.add(fn1);

	// first use the indexOf method of a LinkedList object
	int i = fnll.indexOf(fn1);
	System.err.println("" + fn1 + "\n" + i + "\n\n");
	i = fnll.indexOf(fn2);
	System.err.println("" + fn2 + "\n" + i + "\n\n");
	i = fnll.indexOf(fn3);
	System.err.println("" + fn3 + "\n" + i + "\n\n");


	// now use my own indexOf method below, constructed after
	// the official java  
	i = indexOf(fnll,fn1);
	System.err.println("" + fn1 + "\n" + i + "\n\n");

	i = indexOf(fnll,fn2);
	System.err.println("" + fn2 + "\n" + i + "\n\n");

	i = indexOf(fnll,fn3);
	System.err.println("" + fn3 + "\n" + i + "\n\n");

    }



//  There seems to be a bug with the indexOf method for linked lists,
//  therefore I had to write my own method computing the index
//  of an occurrence 

    static int indexOf(final LinkedList<TestClass> fnll, final TestClass fn) {
	
	assert fnll != null;
	assert fn != null;
	Iterator<TestClass> itr = fnll.iterator(); 
	int i=-1;
	int j=0;
	while(itr.hasNext()) {
	    final TestClass fni = itr.next();
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


}

