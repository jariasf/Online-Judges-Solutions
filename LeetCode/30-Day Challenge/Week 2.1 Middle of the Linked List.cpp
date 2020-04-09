/*******************************************
 ***Problema: Middle of the Linked List
 ***ID: Week2.1
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
    ListNode* middleNode(ListNode* head) {
        if( head == NULL || head -> next == NULL ) return head;
        ListNode* first, *second;
        first = head;
        second = head -> next;
        while( second && second -> next ){
            first = first -> next;
            second = second -> next -> next;
        }
        if( second ) first = first -> next;
        return first;
    }
};
