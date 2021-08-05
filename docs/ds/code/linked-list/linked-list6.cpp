void deleteNode(Node *p) {
  p->value = p->next->value;//把下一个的值提到前面来
  Node *t = p->next;//复制
  p->next = p->next->next;//下一个节点的指针也提前
  delete t;
}