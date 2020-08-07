/*
Determine if a binary tree is a binary search tree
    Given a Binary Tree, figure out whether it’s a Binary Search Tree. In a binary search tree, each node’s key value is smaller than the key value of all nodes in the right subtree, and is greater than the key values of all nodes in the left subtree. 
Author: Dannah Gersh
Techinques used:
    - In order traversal (Left, root, right)
    - recursion
*/
typedef struct node{
    int value;
    BinaryTreeNode * left;
    BinaryTreeNode * right;
    BinaryTreeNode * parent;
} BinaryTreeNode;

bool is_bst_rec(BinaryTreeNode* root, int max, int min) {
    //base case 1:
    // you are at leaf node or null node return true
    if(root == nullptr){
        return true;
    }
    
    if(root->data < min || root->data > max)
        return false;
    
    return is_bst_rec(root->left, min, root->data) && is_bst_rec(root->right, root->data, max);
}

bool is_bst(BinaryTreeNode* root) {
  return 
    is_bts_rec(
      root,
      numeric_limits<int>::min(), 
      numeric_limits<int>::max());
}