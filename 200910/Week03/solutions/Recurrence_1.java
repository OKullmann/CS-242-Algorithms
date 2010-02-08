// Arnold Beckmann, 05.02.2009 (Swansea)


/*
  File:  200910/Week03/solutions/Recurrence_1.java
  Descr: Experience the Master Theorem
*/


class Recurrence {

    static long counter;

    public static void recurrence(int n) {
//	ExecutionTimer.start();
	counter = 0;
	T(n);
//	ExecutionTimer.end();
//	System.out.println(" " + n + " " + ExecutionTimer.duration() );
	System.out.println(" " + n + " " + counter );
    }

    static void T(int n) {
	if (n<4)
	    sleep();
	else {
	    int i = (int) Math.floor(n/2.0);
	    int j = (int) Math.ceil(n/2.0);
	    T(i-1);
	    T(i);
	    T(j);
	    T(j+1);
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
	if (n<4)
	    return 1;
	else {
	    int i = (int) Math.floor(n/2.0);
	    int j = (int) Math.ceil(n/2.0);
//	    return (4*T(j)+n);
//	    return (2*T(i)+2*T(j)+n);
//	    return (T(i-2)+T(i-1)+T(i)+T(i+1)+n);
	    return (T(i-1)+2*T(i)+T(i+1)+n);
//	    return (T(i-1)+T(i)+T(j)+T(j+1)+n);
	}
    }

}