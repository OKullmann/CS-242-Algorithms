// For the example from the lecture:
// java -ea Heap 4 1 3 2 16 9 10 14 8

class Heap {
  private final int[] H;
  private int n;

  public Heap(final int[] a) {
    assert(a != null);
    H = a;
    n = a.length;
  }

  public int size() { return n; }

  private boolean valid(final int x) {
    return x >= 0 && x < n;
  }

  // the first index of a leaf:
  private int first_leaf() { return n/2; }
  // whether i is a leaf:
  private boolean leaf(final int i) {
    assert(valid(i));
    return i >= first_leaf();
  }

  // children, left and right:
  private int ls(final int x) {
    assert(! leaf(x));
    return 2*x+1;
  }
  // returning n in case there is no right child:
  private int rs(final int x) {
    assert(! leaf(x));
    return Math.min(2*x+2, n);
  }
  // parent (returning 0 for the root):
  private int p(final int x) {
    assert(valid(x));
    return (x-1)/2;
  }

  public boolean heap_property() {
    for (int i = 1; i < n; ++i)
      if (H[p(i)] < H[i]) return false;
    return true;
  }

  // floating down a single disturbance at node i:
  private void heapify(final int i) {
    assert(valid(i));
    if (leaf(i)) return;
    final int v = H[i];
    final int left_child = ls(i);
    final int right_child = rs(i);
    int largest = (v >= H[left_child]) ? i : left_child;
    if (right_child != n && H[largest] < H[right_child])
      largest = right_child;
    assert(valid(largest));
    if (largest != i) {
      H[i] = H[largest]; H[largest] = v;
      heapify(largest);
    }
  }

  public void build_heap() {
    final int fl = first_leaf();
    for (int i = fl-1; i >= 0; --i) heapify(i);
    assert(heap_property());
  }

  public void sort(final boolean log) {
    if (log) print();
    if (n <= 1) return;
    build_heap(); if (log) print();
    while (true) {
      {final int t = H[0]; H[0] = H[--n]; H[n] = t;}
      if (n == 0) return;
      heapify(0); if (log) print();
    }
  }

  // output
  //   "(n, total length): array"
  // with ";" indicating end of current binary heap:
  public String toString() {
    String res = String.format("(%2d,%2d):", n, H.length);
    for (int i = 0; i < n; ++i)
      res += String.format(" %3d", H[i]);
    if (n != 0) res += ";"; else res += " ";
    if (n < H.length) {
      res += String.format("%3d", H[n]);
      for (int i = n+1; i < H.length; ++i)
        res += String.format(" %3d", H[i]);
    }
    return res;
  }
  // print with additional leading step-counter:
  private int counter = 0;
  private void print() {
    System.out.printf("%-5d  ", counter++);
    System.out.println(this);
  }

  public static void main(final String[] args) {
    final int[] a = new int[args.length];
    for (int i = 0; i < args.length; ++i)
      a[i] = Integer.parseInt(args[i]);

    Heap H = new Heap(a);
    H.sort(true);
  }
}
