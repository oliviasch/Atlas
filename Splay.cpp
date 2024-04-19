#include "Splay.h"
Node* Splay::helperInsert(Node* helpRoot, std::string country, double data){
    // If tree is empty
    if (!helpRoot){ return new Node(country, data); }
    Node* parent = nullptr;
    Node* current = helpRoot;
    while (current){ // Traverses tree for insertion
        parent = current;
        if (data < current->data){ current = current->left; // Traverse lesser values
        }else if (data > current->data){ current = current->right; } // Traverse higher values
        else{ return helpRoot; } // TO DO: Change to handle duplicate data by adding precision
    }
    Node* newNode = new Node(std::move(country), data);
    // Links node to its parent
    newNode->parent = parent;
    if (parent && data < parent->data){ parent->left = newNode;
    }else if (parent){ parent->right = newNode; }
    return splay(newNode); // Splays new node to root
}
Node* Splay::splay(Node* helpRoot){
    while (helpRoot->parent){ // Continue splaying until helpRoot becomes global root
        if (!helpRoot->parent->parent){
            // Zig case - helpRoot is a direct child of the root node
            if (helpRoot->parent->left == helpRoot){ // helpRoot is the left child
                rotateRight(helpRoot->parent);
            }else{ // helpRoot is the right child
                rotateLeft(helpRoot->parent);
            }
        }else if (helpRoot->parent->left == helpRoot && helpRoot->parent->parent->left == helpRoot->parent){
            // Zig-zig left case - helpRoot and its parent are left children
            rotateRight(helpRoot->parent->parent);
            rotateRight(helpRoot->parent);
        }else if (helpRoot->parent->right == helpRoot && helpRoot->parent->parent->right == helpRoot->parent){
            // Zig-zig right case - helpRoot and its parent are right children
            rotateLeft(helpRoot->parent->parent);
            rotateLeft(helpRoot->parent);
        }else if (helpRoot->parent->left == helpRoot && helpRoot->parent->parent->right == helpRoot->parent){
            // Zigzag right case - helpRoot is left child, parent is right child
            rotateRight(helpRoot->parent);
            rotateLeft(helpRoot->parent);
        }else{
            // Zigzag left case - helpRoot is right child, parent is left child
            rotateLeft(helpRoot->parent);
            rotateRight(helpRoot->parent);
        }
    }
    return helpRoot;  // Return the new root after splaying
}
void Splay::rotateLeft(Node *helpRoot) {
    Node* newParent = helpRoot->right;
    helpRoot->right = newParent->left;
    if (newParent->left){
        newParent->left->parent = helpRoot;
    }
    newParent->parent = helpRoot->parent; // New parent is parameter node's parent
    if (!helpRoot->parent){ // Updates pointers if the helpRoot is currently global root
        this->root = newParent;
    } else if (helpRoot == helpRoot->parent->left){
        helpRoot->parent->left = newParent;
    } else{
        helpRoot->parent->right = newParent;
    }
    newParent->left = helpRoot; // helpRoot is the left child of newParent
    helpRoot->parent = newParent;
}
void Splay::rotateRight(Node *helpRoot){
    Node* newParent = helpRoot->left;
    helpRoot->left = newParent->right;
    if (newParent->right){
        newParent->right->parent = helpRoot;
    }
    newParent->parent = helpRoot->parent; // New parent is parameter node's parent
    if (!helpRoot->parent){ // Updates pointers if the helpRoot is currently global root
        root = helpRoot;
    } else if (helpRoot == helpRoot->parent->right){
        helpRoot->parent->right = newParent;
    } else {
        helpRoot->parent->left = newParent;
    }
    newParent->right = helpRoot;
    helpRoot->parent = newParent;
}
// Memory management
void Splay::deleteTree(){
    helperDelete(this->root);
    this->root = nullptr;
}
void Splay::helperDelete(Node* helpRoot){
    if (!helpRoot){ return; }
    helperDelete(helpRoot->left);
    helperDelete(helpRoot->right);
    delete(helpRoot);
}
// Traversals
void Splay::helperLevelOrder(Node* helpRoot){
    if (!helpRoot){ return; }
    std::queue<Node*> q;
    q.push(helpRoot);
    while (!q.empty()){
        Node *current = q.front();
        q.pop();
        std::cout << current->data << " ";
        if (current->left){ q.push(current->left); }
        if (current->right){ q.push(current->right); }
    }
}
// Public methods
void Splay::insert(std::string country, double data){ this->root = helperInsert(this->root, std::move(country), data); }
void Splay::levelOrder(){ helperLevelOrder(this->root); }