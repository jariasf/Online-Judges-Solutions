/*******************************************
 ***Problema: Flatten a Multilevel Doubly Linked List
 ***ID: Week2.3
 ***Juez: LeetCode
 ***Tipo: Double Linked Lists
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten2(Node* head) {        
        if( head == NULL ) return head;
        // Return last node of current level
        if( head -> next == NULL && head -> child == NULL) return head;
        if( head -> child ){
            // Use last node of next level and reassign pointers
            Node *last = flatten2(head -> child);
            Node* tmp = head -> next;
            head -> next = head -> child;
            head -> child -> prev = head;        
            if( tmp ){
                tmp -> prev = last;
                last -> next = tmp;
            }
            head -> child = NULL;
            return flatten2(tmp);
        }else
            return flatten2(head -> next);    
    }
    
    Node* flatten(Node* head){
        Node* _ = flatten2(head);
        return head;
    }
};
