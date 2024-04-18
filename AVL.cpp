#include "AVL.h"
AVL::TreeNode* AVL::helperInsert(TreeNode* helpRoot, const std::string& ID, const std::string& name) {
    // Adapted from slide 34 of the Trees presentation, adjusted to update height and rotate after
    if (!helpRoot){ // If the tree is empty
        std::cout << "successful" << std::endl;
        return new TreeNode(ID, name);
    }else if (ID == helpRoot->ID){ // If the ID entered is non-unique
        std::cout << "unsuccessful" << std::endl;
        return helpRoot; // Return the current node without insertion
        // Travels down tree until there is an appropriate spot
    }else if (ID < helpRoot->ID){ // If the ID is less than the current node's ID
        helpRoot->left = helperInsert(helpRoot->left, ID, name);
    }else{ // If the ID is greater than the current node's ID
        helpRoot->right = helperInsert(helpRoot->right, ID, name);
    }
    // Updates height
    helpRoot->height = 1 + std::max(helperHeight(helpRoot->left), helperHeight(helpRoot->right));
    // Check balance and adjust if necessary
    if (getBalance(helpRoot) > 1 && ID < helpRoot->left->ID){ return rotateRight(helpRoot); } // Left Left Case
    if (getBalance(helpRoot) < -1 && ID > helpRoot->right->ID){ return rotateLeft(helpRoot); } // Right Right Case
    if (getBalance(helpRoot) > 1 && ID > helpRoot->left->ID){ // Left Right Case
        helpRoot->left = rotateLeft(helpRoot->left);
        return rotateRight(helpRoot);
    }
    if (getBalance(helpRoot) < -1 && ID < helpRoot->right->ID){ // Right Left Case
        helpRoot->right = rotateRight(helpRoot->right);
        return rotateLeft(helpRoot);
    }
    return helpRoot;
}
AVL::TreeNode* AVL::helperRemove(TreeNode* helpRoot, const std::string& ID){
    if (!helpRoot){
        std::cout << "unsuccessful" << std::endl;
        return helpRoot; // Return the current node without removal
    }
    // Travels down tree until ID is found
    if (ID < helpRoot->ID){ // Checks if node to be deleted is in the left subtree of the current root
        helpRoot->left = helperRemove(helpRoot->left, ID);
    }else if (ID > helpRoot->ID){ // Checks if node to be deleted is in the right subtree of current root
        helpRoot->right = helperRemove(helpRoot->right, ID);
    }else{
        if (!helpRoot->left || !helpRoot->right){ // The root has one or zero children
            TreeNode* toDelete = helpRoot->right ? helpRoot->right : helpRoot->left;
            if (!toDelete){ // No child
                toDelete = helpRoot;
                helpRoot = nullptr;
            }else{ *helpRoot = *toDelete; } // One child
            delete toDelete;
            std::cout << "successful" << std::endl;
        }else{ // The root has two children
            TreeNode* successor = helpRoot->right;
            while (successor->left) // Traverse left as much as possible
                successor = successor->left;
            helpRoot->ID = successor->ID; // Changes ID to successor
            helpRoot->name = successor->name; // Changes name to successor
            helpRoot->right = helperRemove(helpRoot->right, successor->ID);
        }
    }
    if (!helpRoot){ return helpRoot; } // Prevents segfaults when accessing height
    helpRoot->height = 1 + std::max(helperHeight(helpRoot->left), helperHeight(helpRoot->right));
    return helpRoot;
}
AVL::TreeNode* AVL::helperRemoveInorder(AVL::TreeNode* helpRoot, int n){
    std::vector<std::string> inorder;
    IDInorder(helpRoot, inorder); // Saves preorder to vector
    helpRoot = helperRemove(helpRoot, inorder[n]); // Removes nth node of helpRoot
    return helpRoot;
}
AVL::TreeNode* AVL::rotateRight(AVL::TreeNode *helpRoot){ // O(1)
    // Adapted from slide 14 of the Balanced Trees presentation, adapted to adjust height and direction
    if (!helpRoot || !helpRoot->left){ // Edge case where a rotation cannot be performed
        return helpRoot;
    }
    TreeNode* newParent = helpRoot->left;
    TreeNode* grandchild = newParent->right;
    newParent->right = helpRoot; // Rotates
    helpRoot->left = grandchild; // Rotates
    helpRoot->height = 1 + std::max(helperHeight(helpRoot->left), helperHeight(helpRoot->right));
    newParent->height = 1 + std::max(helperHeight(newParent->left), helperHeight(newParent->right));
    return newParent;
}
AVL::TreeNode* AVL::rotateLeft(AVL::TreeNode* helpRoot){ // O(1)
    // Adapted from slide 14 of the Balanced Trees presentation, adapted to adjust height
    if (!helpRoot || !helpRoot->right){ // Edge case where a rotation cannot be performed
        return helpRoot;
    }
    TreeNode* newParent = helpRoot->right;
    TreeNode* grandchild = newParent->left;
    newParent->left = helpRoot; // Rotates
    helpRoot->right = grandchild; // Rotates
    helpRoot->height = 1 + std::max(helperHeight(helpRoot->left), helperHeight(helpRoot->right));
    newParent->height = 1 + std::max(helperHeight(newParent->left), helperHeight(newParent->right));
    return newParent;
}
void AVL::helperInorder(TreeNode* helpRoot){
    // Adapted from slide 55 of Trees presentation, adjusted to include commas
    if (!helpRoot){ return; } // Prints nothing if tree is empty
    else if (helpRoot->left){
        helperInorder(helpRoot->left);
        std::cout << ", ";
    }
    std::cout << helpRoot->name; // Prints name
    if (helpRoot->right){
        std::cout << ", ";
        helperInorder(helpRoot->right);
    }
}
void AVL::helperPreorder(TreeNode* helpRoot, bool first = true){
    // Adapted from slide 55 of Trees presentation, adjusted to include commas and change order type
    if (!helpRoot){ return; } // Prints nothing if tree is empty
    if (!first){ std::cout << ", "; } // Prints comma before entry if it's the first node
    std::cout << helpRoot->name;
    helperPreorder(helpRoot->left, false);
    helperPreorder(helpRoot->right, false);
}
void AVL::IDInorder(TreeNode* helpRoot, std::vector<std::string>& inorder){
    // Adapted from slide 55 of Trees presentation, adjusted for vector instead of cout
    if (!helpRoot){ return; } // Ends if tree is empty
    IDInorder(helpRoot->left, inorder);
    inorder.push_back(helpRoot->ID);
    IDInorder(helpRoot->right, inorder);
}
void AVL::helperPostorder(TreeNode* helpRoot, bool first = true){
    // Adapted from slide 55 of Trees presentation, adjusted to include commas and change order type
    if (!helpRoot){ return; } // Prints nothing if tree is empty
    helperPostorder(helpRoot->left, false);
    helperPostorder(helpRoot->right, false);
    std::cout << helpRoot->name;
    if (!first){ std::cout << ", "; } // Prints comma before entry is printed if it's not the first
}
void AVL::helperSearchID(AVL::TreeNode* helpRoot, const std::string& ID){
    if (!helpRoot){ std::cout << "unsuccessful" << std::endl; return; } // ID doesn't exist within tree
    if (helpRoot->ID == ID){ // ID found
        std::cout << helpRoot->name << std::endl;
        return;
    }
    if (ID < helpRoot->ID){ helperSearchID(helpRoot->left, ID);
    }else if (ID > helpRoot->ID){ helperSearchID(helpRoot->right, ID); }
}
void AVL::helperSearchName(AVL::TreeNode* helpRoot, const std::string& name, unsigned int& success){
    if (!helpRoot){ return; }
    if (helpRoot->name == name){ // ID found
        std::cout << helpRoot->ID << std::endl;
        success++;
    }
    helperSearchName(helpRoot->left, name, success);
    helperSearchName(helpRoot->right, name, success);
}
int AVL::helperHeight(AVL::TreeNode *helpRoot){
    if (!helpRoot) { return 0; }
    return helpRoot->height;
}
int AVL::getBalance(AVL::TreeNode *helpRoot){
    return helperHeight(helpRoot->left) - helperHeight(helpRoot->right);
}
void AVL::searchName(const std::string& name){
    unsigned int success = 0;
    helperSearchName(this->root, name, success);
    if (success == 0){ std::cout << "unsuccessful" << std::endl; }
}
// All the below functions simply call their respective helper
void AVL::printInorder(){ helperInorder(this->root); }
void AVL::printPreorder(){ helperPreorder(this->root); }
void AVL::printPostorder(){ helperPostorder(this->root); }
void AVL::insert(const std::string& ID, const std::string& name){ this->root = helperInsert(this->root, ID, name); }
void AVL::remove(const std::string& ID){ this->root = helperRemove(this->root, ID); }
void AVL::searchID(const std::string& ID){ helperSearchID(this->root, ID); }
void AVL::printLevelCount(){ std::cout << helperHeight(this->root); }
void AVL::removeInorder(int n){ this->root = helperRemoveInorder(this->root, n); }
// Memory management
void AVL::deleteTree(){
    helperDelete(this->root);
    this->root = nullptr;
}
void AVL::helperDelete(TreeNode* helpRoot){
    if (!helpRoot){ return; }
    helperDelete(helpRoot->left);
    helperDelete(helpRoot->right);
    delete(helpRoot);
}
// The below functions were only written to simplify the Catch2 testcases and have no impact on the project
void AVL::helpCatchPreorder(TreeNode* helpRoot, std::vector<std::string>& preorder){
    // Adapted from slide 55 of Trees presentation
    if (!helpRoot){ return; }
    preorder.push_back(helpRoot->name);
    helpCatchPreorder(helpRoot->left, preorder);
    helpCatchPreorder(helpRoot->right, preorder);
}
void AVL::catchPreorder(std::vector<std::string>& inorder){ helpCatchPreorder(this->root, inorder); }
void AVL::helpCatchInorder(TreeNode* helpRoot, std::vector<std::string>& inorder){
    // Adapted from slide 55 of Trees presentation
    if (!helpRoot){ return; }
    helpCatchInorder(helpRoot->left, inorder);
    inorder.push_back(helpRoot->name);
    helpCatchInorder(helpRoot->right, inorder);
}
void AVL::catchInorder(std::vector<std::string>& inorder){ helpCatchInorder(this->root, inorder); }
