/**********************************************
 ***Problema: Next Greater Node In Linked List
 ***ID: 1019
 ***Juez: LeetCode
 ***Tipo: Data Structures - Lists, Stacks
 ***Autor: Jhosimar George Arias Figueroa
 **********************************************/

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        if( head == NULL ) return v;
        while( head ){
            v.push_back(head -> val);
            head = head -> next;            
        }
        
        stack<int> S;
        vector<int> res(v.size(), 0);
        for( int i = v.size() - 1; i >= 0 ; --i ){
            while( !S.empty() && S.top() <= v[i] ){
                S.pop();
            }
            
            if( !S.empty() ){
                res[i] = S.top();
            }
            S.push(v[i]);
        }
        return res;
    }
};
