/*******************************************
 ***Problema: Delete Node in a Linked List
 ***ID: Week1.2
 ***Juez: LeetCode
 ***Tipo: Linked List
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        while( node && node -> next ){
            node -> val = node -> next -> val;
            if( node -> next -> next == NULL ){
                node -> next = NULL;
                break;
            }
            node = node -> next;
        }
    }
};
