// Arnold Beckmann, 30.03.2010 (Swansea)


/*
  File:  200910/Week09/FlowNetworks.java
  Descr: Simple representation of directed graphs via adjacency lists
*/

import java.util.Iterator;
import java.util.LinkedList;


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
	
	int i = fnll.indexOf(fn1);
	System.err.println("\n" + fn1 + "\n" + i + "\n\n");

	i = fnll.indexOf(fn2);
	System.err.println("\n" + fn2 + "\n" + i + "\n\n");

	i = fnll.indexOf(fn3);
	System.err.println("\n" + fn3 + "\n" + i + "\n\n");

	
	i = indexOf(fnll,fn1);
	System.err.println("\n" + fn1 + "\n" + i + "\n\n");

	i = indexOf(fnll,fn2);
	System.err.println("\n" + fn2 + "\n" + i + "\n\n");

	i = indexOf(fnll,fn3);
	System.err.println("\n" + fn3 + "\n" + i + "\n\n");

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

