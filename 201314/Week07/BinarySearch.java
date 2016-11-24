// Oliver Kullmann, 11.11.2012 (Swansea)

class BinarySearch {

  // Searches for x in the range of array A from begin (included) to end (excluded),
  // where this range needs to be sorted for the search to be complete, and returns some
  // such index, if it exists, and -1 otherwise:
  public static int binary_search(final int[] A, int begin, int end, final int x) {
    if (A == null) return -1;
    assert(begin >= 0);
    assert(begin <= end);
    assert(end <= A.length);
    if (begin == end) return -1;
    while (true) {
      assert(begin >= 0);
      assert(begin < end);
      assert(end <= A.length);
      final int mid = begin + (end-begin)/2;
      assert(begin <= mid);
      assert(mid < end);
      if (A[mid] == x) return mid;
      if (begin+1 == end) return -1;
      assert(begin < mid);
      if (A[mid] < x) {
        begin = mid+1;
        if (begin == end) return -1;
      }
      else end = mid;
    }
  }
  public static int binary_search(final int[] A, final int x) {
    if (A == null) return -1;
    return binary_search(A, 0, A.length, x);
  }

  public static void main(final String[] args) {
    if (args.length == 0) {
      System.err.println("ERROR: At least one command-line argument is needed.");
      System.exit(1);
    }
    final int N = args.length-1;
    final int x = Integer.parseInt(args[N]);
    final int[] A = new int[N];
    for (int i = 0; i != N; ++i) A[i] = Integer.parseInt(args[i]);
    System.out.println(binary_search(A, x));
  }

}
