#include "Splay.h"
Node* Splay::helperInsert(Node* helpRoot, std::string country, double data){
    // Adapted from slide 34 of the Trees presented, adjusted for Zig/Zag rotations
    if (!helpRoot){
        return new Node(std::move(country), data); // put in info from node later
    }else if (data == helpRoot->data){ // If the data entered is non-unique
        // code here to add an arbitrary precision
        data += 1;
        // Otherwise appropriately travels down tree
    }else if (data < helpRoot->data){ // Data less than node data
        helpRoot->left = helperInsert(helpRoot->left, country, data);
    }else{ // Data is greater than node data
        helpRoot->right = helperInsert(helpRoot->right, country, data);
    }
    // Splaying
    // put like helpRoot = Splay(helpRoot) later
    helpRoot = splay(helpRoot);
    return helpRoot;
}
Node* Splay::splay(Node* helpRoot) {
    // to write rotations/zigzag stuff
    return nullptr;
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
void Splay::helperLevelOrder(Node* helpRoot){
    // to write
}
void Splay::insert(){ this->root = helperInsert(this->root, root->country, root->data); }

void Splay::levelOrder(){ helperLevelOrder(this->root); }