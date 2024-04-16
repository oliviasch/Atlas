#pragma once
#include <string>
#include <utility>
#include "Node.h"
class Splay{
private:
    Node* root = nullptr;
    Node* helperInsert(Node* helpRoot, std::string country, double data);
    void helperDelete(Node* helpRoot);
    void helperLevelOrder(Node* helpRoot);
    static Node* splay(Node* helpRoot);
public:
    Splay() : root(nullptr) {}
    void insert();
    void deleteTree();
    void levelOrder();
};