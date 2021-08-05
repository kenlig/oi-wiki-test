void insertNode(int i, Node *p) {
  Node *node = new Node; 
  node->value = i;//赋值
  node->next = p->next;//复制
  p->next = node;
}