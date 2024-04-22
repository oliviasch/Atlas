#include "RBTree.h"
Node* RBTree::insert(Node* helpRoot, std::string country, std::string data){
    if(!root){
        root = new Node(country, data, false);
        return root;
    }
    if(!helpRoot){
        return new Node(country, data, true);
    }
    if(helpRoot->left && helpRoot->right && helpRoot->left->color && helpRoot->right->color){
        flipColors(helpRoot);
    }
    if(helpRoot->data == data){
        helpRoot->data = data; // add precision for dupes
    }
    else if(data < helpRoot->data){
        helpRoot->left = insert(helpRoot->left, country, data);
    }
    else{
        helpRoot->right = insert(helpRoot->right, country, data);
    }

    if(helpRoot->left && helpRoot->right && helpRoot->right->color && !helpRoot->left->color){
        helpRoot = rotateLeft(helpRoot);
    }

    if(helpRoot->left && helpRoot->left->left && helpRoot->left->color && helpRoot->left->left->color){
        helpRoot = rotateRight(helpRoot);
    }

    return helpRoot;
}
Node* RBTree::rotateLeft(Node* helpRoot){
    Node temp = *(helpRoot->right);
    helpRoot->right = temp.left;
    temp.left = helpRoot;
    temp.color = helpRoot->color;
    helpRoot->color = true;
    return helpRoot;
}
Node* RBTree::rotateRight(Node* helpRoot){
    Node temp = *(helpRoot->left);
    helpRoot->left = temp.right;
    temp.right = helpRoot;
    temp.color = helpRoot->color;
    helpRoot->color = true;
    return helpRoot;
}
void RBTree::flipColors(Node* helpRoot){
    helpRoot->color = !helpRoot->color;
    helpRoot->left->color = !helpRoot->left->color;
    helpRoot->right->color = !helpRoot->right->color;
}
void RBTree::search(Node* helpRoot, const std::string& country){
    if (!helpRoot) { return; }
    std::queue<Node*> q;
    q.push(helpRoot);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (current->country == country) {
            std::cout << "RB tree search: " << current->data;
        }
        if (current->left) { q.push(current->left); }
        if (current->right) { q.push(current->right); }
    }
    std::cout << std::endl;
}
Node* RBTree::searchData(Node *helpRoot, const std::string& data) {
    // if the tree is empty
    if (helpRoot == nullptr) {
        std::cout << "";
    }
        // val is integer ufid
        // else if the target matches the root node's data
    else if (data == helpRoot->data) {
        // return the country with the data
        std::cout << helpRoot->country << " RB" << "\n";
    }
        // else if the target is less than the root node's data
    else if (data < helpRoot->data) {
        // return the result of searching the left subtree of the root
        searchData(helpRoot->left, data);
    }
    else {
        // return the result of searching the right subtree of the root
        searchData(helpRoot->right, data);
    }
    return helpRoot;
}
void RBTree::levelOrder(Node* helpRoot){
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
void RBTree::deleteTree(Node* helpRoot){
    if (!helpRoot){ return; }
    deleteTree(helpRoot->left);
    deleteTree(helpRoot->right);
    delete(helpRoot);
}

