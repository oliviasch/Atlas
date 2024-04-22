#pragma once
#include <iostream>
#include <queue>
#include "Node.h"
class RBTree{
    public:
        Node* root;
        Node* insert(Node* helpRoot, std::string country, std::string data);
        Node* rotateLeft(Node* helpRoot);
        Node* rotateRight(Node* helpRoot);
        void flipColors(Node* helpRoot);
        void levelOrder(Node* helpRoot);
        static void search(Node* helpRoot, std::string country);
        RBTree() : root(nullptr){};
};
