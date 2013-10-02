// Oliver Kullmann, 11.11.2012 (Swansea)

class List {
  private List prev, next;
  public int key;
  
  public List(final int k) { key = k; }
  
  public static List search(List L, final int key) {
    while (L != null && L.key != key) L = L.next;
    return L;
  }
  public static List insert(List L, final List x) {
    assert(x != null);
    x.next = L;
    x.prev = null;
    if (L != null) L.prev = x;
    L = x;
    return L;
  }
  public static List insert(List L, final int x) {
    return insert(L, new List(x));
  }
  public static List delete(List L, final List x) {
    assert(x != null);
    assert(L != null);
    if (x.prev != null) x.prev.next = x.next;
    else L = x.next;
    if (x.next != null) x.next.prev = x.prev;
    return L;
  }
  
  public static int size(List L) {
    int res = 0;
    while (L != null) { ++res; L = L.next; }
    return res;
  }
  
  public static String show(List L) {
    String res = "";
    for (; L != null; L = L.next)
      res += L.key + " ";
    return res;
  }
  
  public static void main(final String[] args) {
    List L = null;
    System.out.println("L:" + List.show(L));
    for (int i = 0; i < 5; ++i) L = List.insert(L, i);
    System.out.println("L:" + List.show(L));
    System.out.println(List.size(L));
    final List f1 = List.search(L, 2);
    L = List.delete(L, f1);
    System.out.println("L:" + List.show(L));
    System.out.println(List.size(L));
    System.out.println(List.search(L, 2));
    while (L != null) {
      L = List.delete(L,L);
      System.out.println("L:" + List.show(L));
      System.out.println(List.size(L));
    }
    System.out.println(List.size(L));
  }
}
