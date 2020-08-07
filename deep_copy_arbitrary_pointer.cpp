/*
    Copy linked list with arbitrary pointer
        You are given a linked list where the node has two pointers. The first is the regular next pointer. The second pointer is called arbitrary_pointer and it can point to any node in the linked list. Your job is to write code to make a deep copy of the given linked list. Here, deep copy means that any operations on the original list should not affect the copied list.
    Author: Dannah Gersh
*/
#include <unordered_map>

typedef struct node
{
    int data;
    struct node *next;
    struct node *arbitrary_pointer;
} LinkedListNode;

LinkedListNode * deep_copy_arbitrary_pointer(LinkedListNode *head){
    if(head == nullptr){
        return head;
    }
    
    unordered_map<LinkedListNode*, LinkedListNode*> map;
    LinkedListNode * current = head;
    
    //initiallize deep copy list by copying list head
    LinkedListNode * new_head = new LinkedListNode(current->data);
    new_head->next = current->next;
    new_head->arbitrary_pointer = current->arbitrary_pointer;
    
    //set up iteration
    LinkedListNode * new_prev = new_head;
    current = current->next;
    
    //continue while loop as long as there is a next node
    while(current != nullptr){
        //create new node with same date as current node
        LinkedListNode * new_node = new LinkedListNode(current->data);
        new_node->arbitrary_pointer = current->arbitrary_pointer;
        
        new_prev->next = new_node;
        new_prev = new_node;
        
        map[current] = new_node;
        current = current->next;
    }
    
    LinkedListNode * new_current = new_head;
    while(new_current != nullptr){
        if(new_current->arbitrary_pointer != nullptr){
            new_current->arbitrary_pointer = map[new_current->arbitrary_pointer];
        }
        new_current = new_current->next;
    }
    return new_head;
}