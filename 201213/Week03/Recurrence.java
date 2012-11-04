// Arnold Beckmann, 05.02.2009 (Swansea)
// Modified Oliver Kullmann, 17.10.2011 (Swansea)

/*
  File:  201112/Week03/Recurrence.java
  Descr: Experience the Master Theorem (recurrence T_1)
*/

class Recurrence {

  public static void recurrence(final int n) {
    System.out.println(" " + n + " " + T(n));
  }

  private static long T(final int n) {
    if (n<2) return 1;
    else return 4*T(n/2)+n;
  }

}
