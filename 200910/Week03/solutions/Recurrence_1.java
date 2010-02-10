// Arnold Beckmann, 09.02.2009 (Swansea)


/*
  File:  200910/Week03/solutions/Recurrence_1.java
  Descr: Experience the Master Theorem
         Computing recurrence T_2
*/


class Recurrence {

    public static void recurrence(int n) {
	System.out.println(" " + n + " " + ((long) T((double) n)) );
    }

    static double T(double n) {
	if (n<2)
	    return 1;
	else
	    return (4*T(n/2)+n*n);
    }

}