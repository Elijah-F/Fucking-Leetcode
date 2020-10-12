#include <stdio.h>

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *Aroot) {
    if (Aroot == nullptr)
      return Aroot;
    Node *cur = Aroot;
    while (cur != nullptr) {
      if (!cur->left && !cur->right) {
        cur = cur->next;
        continue;
      }
      if (cur->left && cur->right)
        cur->left->next = cur->right;
      if (cur->next) {
        Node *child = cur->right ? cur->right : cur->left;
        Node *cnext = nullptr;
        for (Node *n = cur->next; n != nullptr; n = n->next) {
          cnext = n->left ? n->left : n->right;
          if (cnext)
            break;
        }
        child->next = cnext;
      }
      cur = cur->next;
    }
    connect(Aroot->left);
    connect(Aroot->right);
    return Aroot;
  }
};
