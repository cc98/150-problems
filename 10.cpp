#include "data_struct/node.h"

Node* find_Kth_of_last(Node *head, int k){
  Node* cur = head;
  Node* target = head;
  while(k-- >= 0 && cur != NULL) {
    cur = cur->next;
  }
  
  if(k >= 0) return NULL;
  
  while(cur != NULL) {
    cur = cur->next;
    target = target->next;
  }
  return target;
}
