#include "data_struct/node.h"

int link_add(Node *left,const Node* right) {
  int flag = 0;
  if(left == NULL) return FALSE;
  while(right != NULL){
    left->data += right->data + flag;
    flag = left->data / 10;
    left->data = left->data % 10;
    
    if(left->next == NULL) {
      Node *tmp = new Node;
      left->next = tmp;
      tmp->data = 0;
      tmp->next = NULL;
    }
    
    left = left->next;
    right = right->next;
  }
  
  while(flag){
    left->data += flag;
    flag = left->data / 10;
    left->data = left->data % 10;
    
    if(flag && left->next == NULL) {
      Node *tmp = new Node;
      left->next = tmp;
      tmp->data = flag;
      tmp->next = NULL;
    }
    left = left->next;
  }
  
  return true;
}
