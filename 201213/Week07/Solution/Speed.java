// Oliver Kullmann, 12.11.2012 (Swansea)

// Run with
//   java -ea -XX:ParallelGCThreads=n Speed N M
// Note that default is n= max number of processors.

class Speed {
  public static void main(final String[] args) {
    final int N = Integer.parseInt(args[0]);
    final int M = Integer.parseInt(args[1]);
    Stack S = new Stack();
    for (long counter = 0; true; ++counter) {
      final long start = System.currentTimeMillis();
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) S.push(j);
        for (int j = 0; j < M; ++j) S.pop();
      }
      assert(S.empty());
      System.out.print(counter + ":" + (System.currentTimeMillis() - start) + " ");
    }
  }
}