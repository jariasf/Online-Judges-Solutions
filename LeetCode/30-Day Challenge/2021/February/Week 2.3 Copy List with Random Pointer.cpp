/*******************************************
 ***Problema: Copy List with Random Pointer
 ***ID: Week2.3
 ***Juez: LeetCode
 ***Tipo: Linked List + Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if( head == NULL ) return head;
        unordered_map<Node *, Node *> hash;
        Node *copy = NULL;
        Node *copyHead = NULL;
        
        
        Node *A = head, *last = NULL;
        while(A){
            Node* novo = new Node(A -> val);
            hash[A] = novo;
            if( last != NULL ){
                last -> next = novo;
                copy = last -> next;
            }else{
                copy = novo;
                copyHead = copy;
            }
            last = copy;
            
            A = A -> next;
        }
        
        copy = copyHead;
        A = head;
        while(A){
            copy -> random = hash[A -> random];
            A = A -> next;
            copy = copy -> next;
        }
        
        return copyHead;
    }
};
