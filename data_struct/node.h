class Node{
public:
  Node next = 0;
  int data;
  Node(int d):data(d){}
  void append(int d){
    Node end = new Node(d);
    Node n = this;
    while(n.next != 0) n = n.next;
    n.next = end;
  }
};
