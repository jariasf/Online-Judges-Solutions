/*******************************************
 ***Problema: Swap Nodes in Pairs
 ***ID: Week4.3
 ***Juez: LeetCode
 ***Tipo: Linked List
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if( head == NULL || head -> next == NULL ) return head;
        ListNode* first = head;
        ListNode* second = head -> next;
        ListNode* tmp;
        head = head -> next;
        while( second && first ){
            tmp = second -> next;
            second -> next = first;
            if( tmp && tmp -> next )
                first -> next = tmp -> next;
            else    
                first -> next = tmp;
            first = tmp;
            if( first )
                second = first -> next;
        }
        return head;
    }
};
