// Oliver Kullmann, 6.12.2012 (Swansea)

// Max-Heap operations

import java.util.Arrays;

class Heap {
  private final int[] H;
  private int n;
  
  public Heap(final int[] a) {
    assert(a != null);
    H = a;
    n = a.length;
  }
  
  public int size() { return n; }
  public boolean set_size(final int n_) {
    if (n_ > H.length) return false;
    n = n_;
    return true;
  }
  
  // children, left and right:
  private int ls(final int x) { return 2*x+1; }
  private int rs(final int x) { return 2*x+2; }
  // parent:
  private int p(final int x) { return (x-1)/2; }
  
  // the first index of a leaf:
  private int first_leaf() { return n/2; }
  private boolean leaf(final int i) { return i >= first_leaf(); }
  
  public boolean heap_property() {
    final int fl = first_leaf();
    for (int i = 0; i < fl; ++i) {
      final int left_child = ls(i);
      final int right_child = rs(i);
      if (H[i] < H[left_child]) return false;
      if (right_child < n && H[i] < H[right_child]) return false;
    }
    return true;
  }
  
  private void heapify(final int i) {
    if (leaf(i)) return;
    final int v = H[i];
    final int left_child = ls(i);
    final int right_child = rs(i);
    int largest = (v >= H[left_child]) ? i : left_child;
    if (right_child < n && H[largest] < H[right_child]) largest = right_child;
    if (largest != i) {
      H[i] = H[largest]; H[largest] = v;
      heapify(largest);
    }
  }
  
  public void build_heap() {
    final int fl = first_leaf();
    for (int i = fl-1; i >= 0; --i) heapify(i);
  }
  
  public void sort() {
    build_heap();
    while (n > 0) {
      {final int t = H[0]; H[0] = H[--n]; H[n] = t;}
      heapify(0);
    }
  }
  
  public String toString() {
    String res = "(" + n + "," + H.length + "):";
    for (int i = 0; i < H.length; ++i) res += " " + H[i];
    return res;
  }
  
  public static void main(final String[] args) {
    {
     final int[] a = {0,1};
     final Heap H = new Heap(a);
     assert(! H.heap_property());
    }
    {
     final int[] a = {16,14,10,8,7,9,3,2,4,1};
     final Heap H = new Heap(a);
     assert(H.heap_property());
     final int[] b = {4,1,3,2,16,9,10,14,8,7};
     final int[] c = b.clone();
     final Heap H2 = new Heap(b);
     assert(! H2.heap_property());
     H2.build_heap();
     assert(Arrays.equals(a,b));
     final Heap H3 = new Heap(c);
     H3.sort();
     Arrays.sort(a);
     assert(Arrays.equals(a,c));
    }
  }
}
