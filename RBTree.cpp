#include "RBTree.h"
Node* RBTree::insert(Node* helpRoot, std::string country, std::string data){
    std::cout<<country<<" "<<data<<std::endl;
    if(!root){
        std::cout<<"new root"<<std::endl;
        root = new Node(country, data, false);
        return root;
    }
    if(!helpRoot){
        std::cout<<"new node"<<std::endl;
        return new Node(country, data, true);
    }
    std::cout<<"previous value: "<<helpRoot->data<<" next value: "<<data<<std::endl;
    if(helpRoot->left && helpRoot->right && helpRoot->left->color && helpRoot->right->color){
        std::cout<<"flip colors"<<std::endl;
        flipColors(helpRoot);
    }
    if(helpRoot->data == data){
        std::cout<<"equal data"<<std::endl;
        helpRoot->data = data; // add precision for dupes
    }
    else if(data < helpRoot->data){
        std::cout<<"smaller data"<<std::endl;
        helpRoot->left = insert(helpRoot->left, country, data);
    }
    else{
        std::cout<<"bigger data"<<std::endl;
        helpRoot->right = insert(helpRoot->right, country, data);
    }
    if(helpRoot->left && helpRoot->right)std::cout<<"left flippable "<<(helpRoot->right->color && !helpRoot->left->color)<<std::endl;
    if(helpRoot->left && helpRoot->left->left)std::cout<<"right flippable "<<(helpRoot->left->color && !helpRoot->left->left->color)<<std::endl;

    if(helpRoot->left && helpRoot->right && helpRoot->right->color && !helpRoot->left->color){
        std::cout<<"rotate left"<<std::endl;
        helpRoot = rotateLeft(helpRoot);
    }

    if(helpRoot->left && helpRoot->left->left && helpRoot->left->color && helpRoot->left->left->color){
        std::cout<<"rotate right"<<std::endl;
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
Node* RBTree::search(Node* helpRoot, std::string country, std::string data){
    Node* temp = helpRoot;
    while(temp != nullptr){
        if(helpRoot->data == data) return temp;
        else if(helpRoot->data > data) temp = helpRoot->left;
        else if(helpRoot->data < data) temp = helpRoot->right;
    }
    return nullptr;
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


