#include "Splay.h"
#include <iostream>
int main(){
    Splay splay;
    splay.insert("test", 6);
    splay.levelOrder();
    std::cout << std::endl;
    splay.insert("test", 8);
    splay.levelOrder();
    std::cout << std::endl;
    splay.insert("test", 4);
    splay.insert("test", 7);
    splay.insert("test", 23);
    splay.insert("test", 16);
    splay.insert("test", 42);
    splay.insert("test", 89);
    splay.levelOrder();
    std::cout << std::endl;
    splay.deleteTree();
    return 0;
}
