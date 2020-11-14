/*******************************************
 ***Problema: Populating Next Right Pointers in Each Node
 ***ID: Week2.6
 ***Juez: LeetCode
 ***Tipo: Binary Tree + Pointer Manipulation
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

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

#define NONE 0
#define LEFT 1
#define RIGHT 2
class Solution {
public:
    Node* connect(Node* root) {
        Node* current = root;
        Node* leftmost, *last;
        leftmost = root; last= NULL;
        while( root ){
            leftmost = last = NULL;
            int flag = NONE;
            while( root ){
                if( flag == NONE && root -> left ){
                    if( leftmost == NULL )
                        last = leftmost = root -> left;
                    else{
                        last -> next = root -> left;
                        last = root -> left;
                    }
                    flag = LEFT;
                }else if( flag != RIGHT && root -> right ){
                    if( leftmost == NULL )
                        last = leftmost = root -> right;
                    else{
                        last -> next = root -> right;
                        last = root -> right;
                    }
                    flag = RIGHT;
                }else{
                    root = root -> next;
                    flag = NONE;
                }        
            }
            root = leftmost;
        }
        return current;
    }
};
