#include <vector>

typedef struct _Node Node;
struct _Node{
  int data;
  std::vector<Node*> children;
};

int length  = 0;

bool is_balance(Node * tree, int high) {
  if(tree->children.size() > 0) {
    for(int i = 0; i <tree->children.size(); i++) {
      if(!is_balance(tree->children.at(i), high+1))
        return false;
    }
  } else if (length == 0) {
    length = high;
  }
  return length == high;
}
