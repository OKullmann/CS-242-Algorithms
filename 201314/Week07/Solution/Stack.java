// Oliver Kullmann, 12.11.2012 (Swansea)

class Stack {
  private List s;
  public boolean empty() { return s == null; }
  public int top() { return s.key; }
  public void push(final int x) { s = List.insert(s,x); }
  public void pop() { s = List.delete(s,s); }

  public static void main(final String[] args) {
    Stack S = new Stack();
    assert(S.empty());
    S.push(1); S.push(2);
    assert(S.top() == 2);
    S.pop();
    assert(S.top() == 1);
    S.pop();
    assert(S.empty());
  }
}
