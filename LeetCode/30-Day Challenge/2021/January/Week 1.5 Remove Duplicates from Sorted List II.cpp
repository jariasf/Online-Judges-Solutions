/*******************************************
 ***Problema: Remove Duplicates from Sorted List II
 ***ID: Week1.5
 ***Juez: LeetCode
 ***Tipo: Linked List Manipulation
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = head, *last = dummy;
        dummy -> next = head;
        while(cur){
            while(cur -> next && cur -> next -> val == cur -> val ){
                cur = cur -> next;
            }
            if( last -> next == cur ){
                last = last -> next;
            }else{
                last -> next = cur -> next;
            }
            cur = cur -> next;
        }
        return dummy -> next;
    }
};
