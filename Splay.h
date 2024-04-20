#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include "Node.h"
class Splay{
private:
    Node* root;
    Node* splay(Node* helpRoot);
    Node* helperInsert(Node* helpRoot, std::string country, std::string data);
    void helperDelete(Node* helpRoot);
    static void helperLevelOrder(Node* helpRoot);
    void rotateLeft(Node* helpRoot);
    void rotateRight(Node* helpRoot);
public:
    Splay() : root(nullptr) {}
    void insert(std::string country, std::string data);
    void deleteTree();
    void levelOrder();
};