#pragma once
#include <iostream>
#include <queue>
#include "Node.h"
class RBTree{
private:
    void deleteTree(Node* helpRoot);
public:
    RBTree() : root(nullptr){};
    Node* root;
    Node* insert(Node* helpRoot, const std::string& country, const std::string& data);
    Node* rotateLeft(Node* helpRoot);
    Node* rotateRight(Node* helpRoot);
    Node* searchData(Node *helpRoot, const std::string& data);
    void flipColors(Node* helpRoot);
    void levelOrder(Node* helpRoot);
    static void search(Node* helpRoot, const std::string& country);
    void deleteTree();
};