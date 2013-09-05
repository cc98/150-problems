#include <set>
#include "data_struct/node.h"

int remove_duplicate(Node * head){
    std::set<int> flag_set;
    Node *pre = head;
    Node *cur = head;
    flag_set.insert(cur->data);
    while (cur) {
        while((cur = cur->next) != NULL && flag_set.find(cur->data) != flag_set.end());
        pre->next = cur;
        flag_set.insert(cur->data);
        pre = cur;
    }
    return 0;
}
