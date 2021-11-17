class Chaining {
  private final List[] T;
  private final int m;
  private int s;
  
  private int h(final int k) { return k % m; }
  
  public Chaining(final int m_) {
    assert m_ >= 1;
    m = m_;
    T = new List[m];
    s = 0;
  }
  
  public void insert(final int k) {
    final int hv = h(k);
    T[hv] = List.insert(T[hv], k);
    ++s;
  }
  public List search(final int k) {
    return List.search(T[h(k)], k);
  }
  public void delete(final List x) {
    final int hv = h(x.key);
    T[hv] = List.delete(T[hv],x);
    --s;
  }
  
  public int size() { return s; }

  public String toString() {
    String res = "";
    for (int i = 0; i < m; ++i)
      res += i + ": " + List.show(T[i]) + "\n";
    res += "size=" + size() + "\n";
    return res;
  }
  
  public static void main(final String[] args) {
    if (args.length == 0) {
      System.err.println("[CHAINING]: m [N] [step] or m + >= 3 inputs");
      System.exit(1);
    }
    final int m = Integer.parseInt(args[0]);
    final Chaining C = new Chaining(m);

    if (args.length == 1) {
      C.insert(5); C.insert(28); C.insert(19); C.insert(15);
      C.insert(20); C.insert(33); C.insert(12); C.insert(17);
      C.insert(10);
      System.out.println(C);
      System.out.println(C.search(1));
      System.out.println("****\n");

      final List f1 = C.search(19);
      C.delete(f1);
      System.out.println(C);
      System.out.println("****\n");

      C.insert(5);
      final List f2 = C.search(12);
      C.delete(f2);
      System.out.println(C);
      System.out.println("****");

      return;
    }
    else if (args.length <= 3) {
      final int N = Integer.parseInt(args[1]);
      final int step =
        args.length == 3 ? Integer.parseInt(args[2]) : 1;
      for (int i = 0; i < N; i+=step) C.insert(i);
    }
    else {
      final int S = args.length - 1;
      for (int i = 0; i < S; ++i)
        C.insert(Integer.parseInt(args[i+1]));
    }
    System.out.println(C);
  }
}
