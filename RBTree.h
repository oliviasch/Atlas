#pragma once
#include <iostream>
#include <queue>
#include "Node.h"
class RBTree{
public:
    RBTree() : root(nullptr){};
    Node* root;
    Node* insert(Node* helpRoot, std::string country, std::string data);
    Node* rotateLeft(Node* helpRoot);
    Node* rotateRight(Node* helpRoot);
    Node* searchData(Node *helpRoot, const std::string& data);
    void flipColors(Node* helpRoot);
    void levelOrder(Node* helpRoot);
    void search(Node* helpRoot, const std::string& country);
    void deleteTree(Node* helpRoot);
};