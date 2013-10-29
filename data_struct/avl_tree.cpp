// AVL Insert And Delete

int Max(int left, int right){
    return left > right ? left : right;
}

struct Node{
    int value;
    int height;
    Node* left;
    Node* right;
};

int Height(Node* const &node){
    return node ? node->height : -1;
}

void LeftLeft(Node* &node){
    Node* tmp=node->left;
    node->left=tmp->right;
    tmp->right=node;
    
    node->height = Max(Height(node->left), Height(node->right)) + 1;
    tmp->height = Max(Height(tmp->left), node->height) + 1;
    node = tmp;
}

void RightRight(Node* &node){
    Node* tmp= node->right;
    node->right = tmp->left;
    tmp->left=node;
    
    node->height = Max(Height(node->left), Height(node->right)) + 1;
    tmp->height = Max(Height(tmp->right), node->height) + 1;
    node = tmp;
}

void LeftRight(Node* & node){
    RightRight(node->left);
    LeftLeft(node);
}

void RightLeft(Node* & node){
    LeftLeft(node->right);
    RightRight(node);
}

void Insert(Node *&tree, int value){
    if(!tree){
        tree = new Node;
        tree->left = tree->right = NULL;
        tree->value = value;
        tree->height = 0;
        return;
    }
    if(tree->value > value){
        Insert(tree->left, value);
        if(Height(tree->left) - Height(tree->right) == 2){
            if(value < tree->left->value)
                LeftLeft(tree);
            else
                LeftRight(tree);
        }
    }
    else if (tree->value < value){
        Insert(tree->right, value);
        if(Height(tree->right) - Height(tree->left) == 2){
            if(value > tree->right->value)
                RightRight(tree);
            else
                RightLeft(tree);
        }
    }
    tree->height = Max(Height(tree->left), Height(tree->right)) + 1;
}

void Delete(Node*&tree, int value){
    if(!tree) return;
    if(value < tree->value){
        Delete(tree->left, value);
        if(Height(tree->right) - Height(tree->left) == 2){
            if(tree->right->left
               && (Height(tree->right->left) > Height(tree->right->right)))
                RightLeft(tree);
            else
                RightRight(tree);
        }
    }
    else if(value > tree->value){
        Delete(tree->right, value);
        if(Height(tree->left) - Height(tree->right) == 2){
            if(tree->left->right
               && (Height(tree->left->right) > Height(tree->left->left)))
                LeftRight(tree);
            else
                LeftLeft(tree);
        }
    }
    else {
        if(tree->left && tree->right){
            Node* tmp = tree->right;
            while (tmp->left) tmp = tmp->left;
            tree->value = tmp->value;
            Delete(tree->right, tmp->value);
            if(Height(tree->left) - Height(tree->right) == 2) {
                if(tree->left->right
                   && Height(tree->left->right) > Height(tree->left->left))
                    LeftRight(tree);
                else
                    LeftLeft(tree);
            }
        }
        else {
            Node* tmp = tree;
            if(tree->left)
                tree = tree->left;
            else if(tree->right)
                tree = tree->right;
            delete tmp;
            tmp = NULL;
        }
    }
    if(tree)
        tree->height = Max(Height(tree->left), Height(tree->right)) + 1;
}
