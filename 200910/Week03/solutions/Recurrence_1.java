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
	    T(i);
	    T(i);
	    T(j);
	    T(j);
	    for (j = 1; j < n*n*n; j++) 
		sleep();
	}
    }

    static void sleep() {
	counter++;
    }

}


class Recurrence2 {

    public static void recurrence(int n) {
	System.out.println(" " + n + " " + T(n) );
    }

    static long T(int n) {
	if (n<2)
	    return 1;
	else {
	    int i = (int) Math.floor(n/2.0);
	    int j = (int) Math.ceil(n/2.0);
	    return (2*T(i)+2*T(j)+n*n*n);
	}
    }

}