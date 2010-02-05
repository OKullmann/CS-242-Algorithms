// This file has been generated from   solutions/Recurrences_1.java 
// Arnold Beckmann, 05.02.2009 (Swansea)


/*
  File:  200910/Week03/solutions/Recurrence_1.java
  Descr: Experience the Master Theorem
*/


class Recurrence {

    public static void recurrence(int n) {
	ExecutionTimer.start();
	T(n);
	ExecutionTimer.end();
	System.out.println(" " + n + " " + (ExecutionTimer.duration()) );
    }

    static void T(int n) {
	if (n<1)
	    sleep();
	else {
	    int j = Math.Floor(n/2);
	    T(j);
	    T(j);
	    T(j);
	    T(j);
	    for (j = 1; j < n; j++) 
		sleep();
	}
    }

    static void sleep() {
	// do nothing
    }

}

