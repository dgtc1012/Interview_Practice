/*
Level Order Traversal of Binary Tree
    Given the root of a binary tree, display the node values at each level. Node values for all levels should be displayed on separate lines. Let’s take a look at the below binary tree.
Author: Dannah Gersh
*/
#include <queue>
typedef struct node{
    int value;
    BinaryTreeNode * left;
    BinaryTreeNode * right;
    BinaryTreeNode * parent;
} BinaryTreeNode;

/*
level order traversal requires Breadth First Search
    Breadth First Search requires a queue. check all children of the node, adding each to the queue and then pop the next item off the qeueue and check all those children.
    We want to be able to track each level independently, so we want to create two queues, one for current level, another for the children of that level. 
*/
string level_order_traversal(BinaryTreeNode* root){
    string result = "";
    
    string result = "";
    
    queue<BinaryTreeNode *>* current_queue = new queue<BinaryTreeNode *>();
    queue<BinaryTreeNode *>* next_queue = new queue<BinaryTreeNode *>();
    
    current_queue->push(root);
    
    while(!current_queue->empty() || !next_queue->empty())
    {
        if(!current_queue->empty()){
            BinaryTreeNode* node = current_queue->front();
            current_queue->pop();
            if(node->left != nullptr){
                next_queue->push(node->left);
            }
            if(node->right != nullptr){
                next_queue->push(node->right);
            }
            
            result += to_string(node->value) + ", ";
        }
        else{
            result += "\n";
            queue<BinaryTreeNode*> * temp = next_queue;
            next_queue = current_queue;
            current_queue = temp;
        }
    }
    
    return result;
}