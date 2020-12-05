/*******************************************
 ***Problema: Linked List Random Node
 ***ID: Week1.2
 ***Juez: LeetCode
 ***Tipo: Linked List - Random
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* head;
    Solution(ListNode* _head) {
        head = _head;
        srand(time(NULL));
    }
    
    /** Returns a random node's value. */
    int getRandom(){
        ListNode* tmp = head;
        int result = tmp -> val, len = 1;
        while( tmp ){
            int index = rand() % len;
            if( index == 0 ) result = tmp -> val;
            len++;
            tmp = tmp -> next;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
