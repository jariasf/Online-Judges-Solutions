/*******************************************
 ***Problema: Merge In Between Linked Lists
 ***ID: 1669
 ***Juez: LeetCode
 ***Tipo: Linked Lists
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode();
        dummy -> next = list1;
        ListNode* cur = list1, *prev = dummy;
        int cnt = 0;
        while( cnt < a ){
            cur = cur -> next;
            prev = prev -> next;
            cnt++;
        }
        
        prev -> next = list2;
        while(list2 -> next){
            list2 = list2 -> next;
        }
        while(cnt < b){
            cur = cur -> next;
            cnt++;
        }
        
        list2 -> next = cur -> next;
        return dummy -> next;
    }
};
