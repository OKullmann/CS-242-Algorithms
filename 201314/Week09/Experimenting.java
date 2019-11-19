class Experimenting {
  public static void main(final String[] args) {
    final int m = Integer.parseInt(args[0]);
    final Chaining C = new Chaining(m);
    for (int i = 1; i <= 100; ++i) C.insert(i);
    System.out.println(C);
  }
}
