#include <stack>
#include "binary_tree.h"

/*
 * To be done iteratively
 * NO RECURSION ALLOWED
 */
template<class T>
std::vector<T> *BinaryTree<T>::dfs_in_order() {
    auto *result = new std::vector<T>();
    /*
     * TODO: homework
    */
    std::stack<TreeNode<T>*> s;
    TreeNode<T> *curr = root;

    while(curr || !s.empty()){
       if(curr){ //if curr not null, continue traverse to the left most of
                    //left or right subtree
           s.push(curr);
           curr = curr->left;//if curr->left is null, pop the new added node
                            //and check the right child
       }else{//reach the last left most node
           curr = s.top(); //pop the value and save it to the vector
           s.pop();
           result->push_back(curr->val);
           curr = curr->right;//check if the current node has any right child.
           //if yes, start a new while loop, push the right child to the stack
           //if right child is null, pop the rest of the stack
       }
    }

    return result;
}

/*
 * To be done iteratively
 * NO RECURSION ALLOWED
 */
template<class T>
std::vector<T> *BinaryTree<T>::dfs_pre_order() {
    auto *result = new std::vector<T>();
    /*
     * TODO: homework
     */
    if (root == NULL)
        return result;
    std::stack<TreeNode<T>*> s;
    //preorder - push the root into the stack first
    if(root){
        s.push(root);
    }
    while(!s.empty()){//while stack is not empty, we pop value fromt he stack
                        //and save it into the vector
       auto curr = s.top();
       s.pop();
       result->push_back(curr->val);
       //check whether the current node has the right child first
       // then check the left child. If any of the condition is true, push
       //it into the stack
       if(curr->right){
           s.push(curr->right);
       }
       if(curr->left){
           s.push(curr->left);
       }
    }

    return result;
}

template<class T>
TreeNode<T> *BinaryTree<T>::lca(TreeNode<T> *node_start, TreeNode<T> *node_1, TreeNode<T> *node_2) {
    /*
     * TODO: homework
     * This helper function is OPTIONAL.
     * Use this or change it to your like.
     * If you do, remember to change the same in the .h file.
     */

    //if node1 or 2 equal to the root, simply return the root
    if(node_start->val == node_1->val || node_start->val == node_2->val){
        return node_start;
    }
    TreeNode<T> *left = NULL, *right = NULL;
    //traverse on the left side, if found, assign the value to left node
    if(node_start->left){
        left = lca(node_start->left, node_1, node_2);
    }
    //traverse on the right side, if found, assign the value to right node
    if(node_start->right){
        right = lca(node_start->right, node_1, node_2);
    }
    //if both left and right is found, which mean the node1 and 2 are at the
    //opposite site their root
    if(left and right){
        return node_start;
    }
    //if 1 side is not found then return which ever node that is found first
    //in the left or right subtree
    if(left){
        return left;
    }else{
        return right;
    }
}

template<class T>
TreeNode<T> *BinaryTree<T>::lca(TreeNode<T> *node_1, TreeNode<T> *node_2) {
    /*
     * TODO: homework
     */

    return lca(root, node_1, node_2);
}

template<class T>
BinaryTree<T>::~BinaryTree() {
    delete_tree(root);
}

template<class T>
void BinaryTree<T>::delete_tree(TreeNode<T> *node) {
    if (node == nullptr) {
        return;
    }
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree &another_tree) {
    if (another_tree.root == nullptr) {
        root = nullptr;
        return;
    }

    root = new TreeNode(another_tree.root->val);

    copy_node(root, another_tree.root);
}

template<class T>
void BinaryTree<T>::copy_node(TreeNode<T> *tree_node_1, TreeNode<T> *tree_node_2) {

    if (tree_node_2->left) {
        tree_node_1->left = new TreeNode(tree_node_2->left->val);
        copy_node(tree_node_1->left, tree_node_2->left);
    }

    if (tree_node_2->right) {
        tree_node_1->right = new TreeNode(tree_node_2->right->val);
        copy_node(tree_node_1->right, tree_node_2->right);
    }
}

template<class T>
bool BinaryTree<T>::operator==(const BinaryTree &another_tree) const {
    return check_equal(root, another_tree.root);
}

template<class T>
bool BinaryTree<T>::check_equal(TreeNode<T> *tree_node_1, TreeNode<T> *tree_node_2) const {
    if (tree_node_1 == nullptr && tree_node_2 == nullptr) {
        return true;
    }
    if (tree_node_1 == nullptr && tree_node_2 != nullptr) {
        return false;
    }
    if (tree_node_1 != nullptr && tree_node_2 == nullptr) {
        return false;
    }
    if (tree_node_1->val != tree_node_2->val) {
        return false;
    }

    return check_equal(tree_node_1->left, tree_node_2->left) &&
           check_equal(tree_node_1->right, tree_node_2->right);
}


template<class T>
bool BinaryTree<T>::operator!=(const BinaryTree &another_tree) const {
    return !(another_tree == *this);
}

template<class T>
TreeNode<T> *BinaryTree<T>::get_root() const {
    return root;
}