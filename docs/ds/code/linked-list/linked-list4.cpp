void insertNode(int i, Node *p) {
  Node *node = new Node;
  node->value = i;
  node->next = NULL;
  if (p == NULL) { //没有下一个了，指到头上
    p = node;
    node->next = node;
  } else {
    node->next = p->next;//还有下一个,接着指到下一个上
    p->next = node;
  }
}