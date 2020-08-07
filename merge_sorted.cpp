/*
    Merge two sorted linked lists
        Given two sorted linked lists, merge them so that the resulting linked list is also sorted.
    Author: Dannah Gersh
*/
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <unordered_set>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef Node* NodePtr;

NodePtr merge_sorted(NodePtr head1, NodePtr head2){
    if (head1 == nullptr) {
        return head2;
    } else if (head2 == nullptr) {
        return head1;
    }
    NodePtr new_head = nullptr;
    //setup head of new linked list to be lower start value of two lists to merge
    if(head1->data > head2->data){
        new_head = head1;
        head1 = head1->next;
    }
    else{
        new_head = head2;
        head2 = head2->next;
    }
    //while neither head pointer is null execute loop iterating over lists keep track of last item of new list via iter pointer
    NodePtr iter = new_head;
    while(head1 && head2){
        //if list 1 item 1 is greater than list 2 item 1, add l1 i1 to the new list, then incrememt pointeres
        if(head1->data > head2->data){
            iter->next = head1;
            head1 = head1->next;
            iter = iter->next;
        }
        //if list 2 item 1 is greater or equal to than list 1 item 1, add l1 i1 to the new list, then incrememt pointeres
        else{
            iter->next = head2;
            head2 = head2->next;
            iter = iter->next;
        }
    }
    //if list 1 or list 2 has items left over, add all of them to end of list
    if(head1 != nullptr){
        iter->next = head1;
    }
    if(head2 != nullptr){
        iter->next = head2;
    }
    return new_head;
}