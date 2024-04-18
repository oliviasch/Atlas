#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <sstream>
#include <algorithm>
class AVL{;
private:
    struct TreeNode{
        std::string ID;
        std::string name;
        TreeNode *left;
        TreeNode *right;
        int height = 1;
        TreeNode(std::string ID, std::string name) : ID(std::move(ID)), name(std::move(name)), left(nullptr), right(nullptr){}
    };
    TreeNode* root = nullptr;
    AVL::TreeNode* helperInsert(TreeNode* helpRoot, const std::string& ID, const std::string& name);
    AVL::TreeNode* helperRemove(TreeNode* helpRoot, const std::string& ID);
    AVL::TreeNode* helperRemoveInorder(TreeNode* helpRoot, int n);
    static AVL::TreeNode* rotateRight(TreeNode* helpRoot);
    static AVL::TreeNode* rotateLeft(TreeNode* helpRoot);
    void helperInorder(TreeNode* helpRoot);
    void helperPreorder(TreeNode* helpRoot, bool first);
    void IDInorder(TreeNode* helpRoot, std::vector<std::string>& preorder);
    void helperPostorder(TreeNode* helpRoot, bool first);
    void helperSearchID(AVL::TreeNode* helpRoot, const std::string& ID);
    void helperSearchName(AVL::TreeNode* helpRoot, const std::string& name, unsigned int& success);
    void helpCatchPreorder(TreeNode* helpRoot, std::vector<std::string>& preorder);
    void helpCatchInorder(TreeNode* helpRoot, std::vector<std::string>& inorder);
    void helperDelete(TreeNode* helpRoot);
    static int helperHeight(TreeNode* helpRoot);
    static int getBalance(TreeNode* helpRoot);
public:
    void printInorder();
    void printPreorder();
    void printPostorder();
    void insert(const std::string& ID, const std::string& name);
    void remove(const std::string& ID);
    void searchID(const std::string& ID);
    void searchName(const std::string& name);
    void printLevelCount();
    void removeInorder(int n);
    void catchPreorder(std::vector<std::string>& preorder);
    void catchInorder(std::vector<std::string>& inorder);
    void deleteTree();
};

