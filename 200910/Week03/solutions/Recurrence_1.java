// Arnold Beckmann, 05.02.2009 (Swansea)


/*
  File:  200910/Week03/solutions/Recurrence_1.java
  Descr: Experience the Master Theorem
*/


class Recurrence {

    static long counter;

    public static void recurrence(int n) {
	counter = 0;
	T(n);
	System.out.println(" " + n + " " + counter );
    }

    static void T(int n) {
	if (n<2)
	    sleep();
	else {
	    int i = (int) Math.floor(n/2.0);
	    int j = (int) Math.ceil(n/2.0);
//	System.out.println("n,i,j:  " + n + " " + i + " " + j );
	    T(j);
	    T(j);
	    T(j);
	    T(j);
	    for (j = 1; j < n; j++) 
		sleep();
	}
    }

    static void sleep() {
	counter++;
    }

}


class Recurrence2 {

    static long counter;

    public static void recurrence(int n) {
	counter = 0;
	T((double) n);
	System.out.println(" " + n + " " + counter );
    }

    static void T(double n) {
	if (n<2.0)
	    sleep();
	else {
	    double r = n/2.0;
	    T(r);
	    T(r);
	    T(r);
	    T(r);
	    for (int j = 1; j < (2*n); j++) 
		sleep();
	}
    }

    static void sleep() {
	counter++;
    }

}