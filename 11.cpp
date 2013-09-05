#include "data_struct/node.h"

int delete_node(Node *node){
  if(node == NULL || node->next == NULL)
    return FALSE;
  
  Node* next = node->next;
  node->data = next->data;
  node->next = next->next;
  return TRUE;
}
