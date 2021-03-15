/*******************************************
 ***Problema: Swapping Nodes in a Linked List
 ***ID: Week2.7
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* last = head;
        for( int i = 0 ; i < k - 1; ++i ){
            last = last -> next;
        }
        ListNode* left = last;
        last = last -> next;
        ListNode* start = head;
        while(last){
            start = start -> next;
            last = last -> next;
        }
        ListNode* right = start;
        swap(left -> val, right -> val);
        return head;
    }
};
