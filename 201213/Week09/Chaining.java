class Chaining {
  private final List[] T;
  private final int m;
  
  private int h(final int k) { return k % m; }
  
  public Chaining(final int m_) {
    assert m_ >= 1;
    m = m_;
    T = new List[m];
  }
  
  public void insert(final int k) {
    final int hv = h(k);
    T[hv] = List.insert(T[hv], k);
  }
  public List search(final int k) {
    return List.search(T[h(k)], k);
  }
  public void delete(final List x) {
    List.delete(T[h(x.key)],x);
  }
  
  public String toString() {
    String res = "";
    for (int i = 0; i < m; ++i)
      res += i + ": " + List.show(T[i]) + "\n";
    return res;
  }
  
  public static void main(final String[] args) {
    final int m = Integer.parseInt(args[0]);
    final Chaining C = new Chaining(m);
    C.insert(5); C.insert(28); C.insert(19); C.insert(15);
    C.insert(20); C.insert(33); C.insert(12); C.insert(17);
    C.insert(10);
    System.out.println(C);
    System.out.println(C.search(1));
    final List f1 = C.search(19);
    C.delete(f1);
    System.out.println(C);
  }
}
