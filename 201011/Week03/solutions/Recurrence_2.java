// Arnold Beckmann, 09.02.2009 (Swansea)


/*
  File:  201011/Week03/solutions/Recurrence_2.java
  Descr: Experience the Master Theorem
         Computing recurrence T_3
*/


class Recurrence {

    public static void recurrence(final int n) {
	System.out.println(" " + n + " " + T(n));
    }

    private static long T(final int n) {
	if (n<2)
	    return 1;
	else
	    return (4*T(n/2)+n*n*n);
    }

}