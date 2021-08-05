void insertNode(int i, Node *p) {
  Node *node = new Node;
  node->value = i;
  if (p == NULL) {//没有下一个了，指到头上
    p = node;
    node->left = node;
    node->right = node;
  } else {//还有下一个,接着指到下一个和上一个的节点上
    node->left = p;
    node->right = p->right;
    p->right->left = node;
    p->right = node;
  }
}