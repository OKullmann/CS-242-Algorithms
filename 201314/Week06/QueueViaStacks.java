// Oliver Kullmann, 8.11.2012 (Swansea)

class QueueViaStacks {
  private final Stack in, out;
  
  public QueueViaStacks(final int N) {
    in = new Stack(N);
    out = new Stack(N);
  }
  
  public boolean empty() { return in.empty() && out.empty(); }
  public int front() {
    if (out.empty()) transfer();
    return out.top();
  }
  public boolean push(final int x) { return in.push(x); }
  public boolean pop() {
    if (out.empty()) transfer();
    return out.pop();
  }
  
  // additional functionality:
  public int size() { return in.size() + out.size(); }
  public int max_size() { return in.max_size(); }

  private void transfer() {
    while (! in.empty()) {
      out.push(in.top());
      in.pop();
    }
  }
  
  public static void main(final String[] args) {
    final int N = (args.length == 0) ? 10 : Integer.parseInt(args[0]);
    final QueueViaStacks Q = new QueueViaStacks(N);
    for (int i = 1; i <= N; ++i) Q.push(i);
    for (int i = 1; i <= N; ++i) {
      System.out.print(Q.front() + " ");
      Q.pop();
    }
    System.out.println();
    assert(Q.empty());
  }
}
