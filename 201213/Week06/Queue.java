// Oliver Kullmann, 4.11.2012 (Swansea)

class Queue {
  private final int[] queue;
  private final int N; // maximal number of elements
  private int n; // number of currently held elements
  private int a, b; // first and one past-the-last index of current elements

  public Queue(final int N_) {
    // Standard exceptions raised in case N_ < 0 or N_ is too big for available memory.
    N = N_;
    queue = new int[N];
    n = a = b = 0;
  }

  public boolean empty() { return n==0; }
  public int front() {
    // Queue underflow in case n == 0 (not detected)
    assert(a < N);
    assert(a >= 0);
    return queue[a];
  }
  public boolean push(final int x) {
    assert(n <= N);
    assert(n >= 0);
    if (n == N) return false;
    assert(b >= 0);
    assert(b < N);
    queue[b] = x;
    if (b == N-1) b = 0; else ++b;
    ++n;
    return true;
  }
  public boolean pop() {
    assert(n <= N);
    assert(n >= 0);
    if (n == 0) return false;
    if (a == N-1) a = 0; else ++a;
    --n;
    assert(a >= 0);
    assert(a < N);
    return true;
  }

  // additional functionality:
  public int size() { return n; }
  public int max_size() { return N; }

  public boolean equals(Queue S) {
    if (n != S.n) return false;
    for (int i=a, j=S.a, c=0; c<n; i = (i==N-1)?0:i+1, j = (j==N-1)?0:j+1, ++c)
      if (queue[i] != S.queue[j]) return false;
    return true;
  }

  public String toString() {
    String result = "[" + n + "," + N + "]\n";
    for (int i = a, c = 0; c < n; i = (i==N-1) ? 0:i+1, ++c)
      result += queue[i] + " ";
    return result;
  }


  public static void main(final String[] args) {
    final int N = (args.length == 0) ? 10 : Integer.parseInt(args[0]);
    System.out.println("Q1:");
    final Queue Q1 = new Queue(N);
    System.out.println(Q1);
    System.out.println(Q1.empty());
    Q1.push(55); Q1.push(44); Q1.push(88);
    System.out.println(Q1);
    System.out.println(Q1.empty());
    System.out.println(Q1.front());
    Q1.pop();
    System.out.println(Q1);
    System.out.println("Q2:");
    final Queue Q2 = new Queue(2);
    Q2.push(44); Q2.push(88);
    System.out.println(Q2);
    System.out.println(Q1.equals(Q2));
    Q2.pop();
    System.out.println(Q1.equals(Q2));
    Q2.pop();
    System.out.println(Q2.empty());
    System.out.println("Q1:");
    Q1.push(11);
    System.out.println(Q1);
    System.out.println(Q1.front());
    Q1.pop();
    System.out.println(Q1);
    System.out.println(Q1.equals(Q2));
    System.out.println(Q1.front());
    Q1.pop();
    System.out.println(Q1);
    System.out.println(Q1.front());
    Q1.pop();
    System.out.println(Q1);
    System.out.println(Q1.empty());
    for (int i = 0; i < Q1.max_size(); ++i) Q1.push(i);
    System.out.println(Q1);
    System.out.println(Q1.front());
    Q1.pop();
    System.out.println(Q1);
    Q1.push(10);
    System.out.println(Q1);
    System.out.println(Q1.push(11));
    System.out.println(Q1);
    for (int i = 0; i < Q1.max_size(); ++i) Q1.pop();
    System.out.println(Q1);
    System.out.println(Q1.empty());
  }

}
