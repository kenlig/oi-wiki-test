void deleteNode(Node *&p) {
  p->left->right = p->right;//和上面的同理
  p->right->left = p->left;
  Node *t = p;
  p = p->right;
  delete t;
}