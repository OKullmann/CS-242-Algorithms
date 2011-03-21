// Arnold Beckmann, 02.02.2010 (Swansea)

/*
  File:  201011/Week02/ExecutionTimer.java
  Descr: provides a class for measuring execution time in nanoseconds
*/


class ExecutionTimer {
  private static long start;
  private static long end;

  public static void start() {
    start = System.nanoTime();
  }

  public static void end() {
    end = System.nanoTime();
  }

  public static long duration(){
    return (end-start);
  }

  public static void reset() {
    start = 0;  
    end   = 0;
  }

}


