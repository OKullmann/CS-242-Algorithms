// Oliver Kullmann, 4.11.2012 (Swansea)

class Stack {
  private final int[] stack;
  private final int N; // maximal number of elements
  private int n; // number of currently held items

  public Stack(final int N_) {
    // Standard exceptions raised in case N_ < 0 or N_ is too big for available memory.
    N = N_;
    stack = new int[N];
    n = 0;
  }

  public boolean empty() { return n==0; }
  public int top() {
    // Standard exception raised in case n == 0.
    assert(n <= N);
    assert(n >= 0);
    return stack[n-1];
  }
  public boolean push(final int x) {
    assert(n <= N);
    assert(n >= 0);
    if (n == N) return false;
    stack[n++] = x;
    return true;
  }
  public boolean pop() {
    assert(n <= N);
    assert(n >= 0);
    if (n == 0) return false;
    --n;
    return true;
  }

  // additional functionality:
  public int size() { return n; }
  public int max_size() { return N; }

  public boolean equals(Stack S) {
    if (n != S.n) return false;
    for (int i = 0; i < n; ++i) if (stack[i] != S.stack[i]) return false;
    return true;
  }

  public String toString() {
    String result = "[" + n + "," + N + "]\n";
    for (int i = 0; i < n-1; ++i) result += stack[i] + " ";
    if (n > 0) result += stack[n-1] + "\n";
    return result;
  }


  public static void main(final String[] args) {
    final int N = (args.length == 0) ? 10 : Integer.parseInt(args[0]);
    final Stack S1 = new Stack(N);
    System.out.println(S1);
    System.out.println(S1.empty());
    S1.push(55); S1.push(44); S1.push(88);
    System.out.println(S1);
    System.out.println(S1.empty());
    System.out.println(S1.top());
    S1.pop();
    System.out.println(S1);
    final Stack S2 = new Stack(2);
    S2.push(55); S2.push(44);
    System.out.println(S2);
    System.out.println(S1.equals(S2));
    S2.pop();
    System.out.println(S1.equals(S2));
    S2.pop();
    System.out.println(S2.empty());
    // S2.top();
  }
  
}
