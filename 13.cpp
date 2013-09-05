/*
Given a circular linked list, implement an algorithm which returns node at the 
beginning of the loop
DEFINITION
  Circular linked list: A (corrupt) linked list in which a node’s next pointer 
  points to an earlier node, so as to make a loop in the linked list
EXAMPLE
  input: A -> B -> C -> D -> E -> C [the same C as earlier]
  output: C
*/

#include <set>
#include "data_struct/node.h"

Node* find_circle(Node * link) {
  std::set<int> flag;
  std::pair<std::set<int>::iterator, bool> ret;
  
  while(link != NULL){
    ret = flag.insert(link->data);
    if(ret.second == false) 
      break;
    link = link->next;
  }
  return link;
}
