/*******************************************
 ***Problema: Remove Zero Sum Consecutive Nodes from Linked List
 ***ID: 1171
 ***Juez: LeetCode
 ***Tipo: Linked List + Hashing
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        unordered_map<int, ListNode*> hash;
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        
        while(true){     
            ListNode* aux = dummy;
            hash.clear();
            int sum = 0;
            bool sum_zero = false;
            while( aux ){
                sum += aux -> val;
                if( hash.find(sum) != hash.end() ){
                    sum_zero = true;
                    hash[sum] -> next = aux -> next;
                    break;
                }
                hash[sum] = aux;
                aux = aux -> next;
            }
            if( !sum_zero ) break;
        }
        return dummy -> next;
        
    }
};
