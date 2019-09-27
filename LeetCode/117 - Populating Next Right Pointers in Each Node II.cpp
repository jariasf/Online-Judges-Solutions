/*******************************************
 ***Problema: Populating Next Right Pointers in Each Node II
 ***ID: 117
 ***Juez: LeetCode
 ***Tipo: Lists, Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node* current = root;
        while(current){
            Node* last = NULL;
            Node* leftmost = NULL;
            while( current){
                if( current -> left ){
                    if( last != NULL ) 
                        last -> next = current -> left;
                    if( leftmost == NULL ) leftmost = current -> left;
                    if( current -> right ){
                        current -> left -> next = current -> right;
                        last = current -> right;
                    }else{
                        last = current -> left;
                    }
                }else if(current -> right ){
                    if( leftmost == NULL ) leftmost = current -> right;                    
                    if( last != NULL ) 
                        last -> next = current -> right;
                    last = current -> right;
                }
                current = current -> next;
            }
            current = leftmost;
        }
        return root;
    }
};
