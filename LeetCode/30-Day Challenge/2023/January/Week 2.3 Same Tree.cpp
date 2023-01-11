/*******************************************
 ***Problema: Same Tree
 ***ID: Week 2.3
 ***Juez: LeetCode
 ***Tipo: Recurion | BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Recursion
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((!p && q) || (p && !q) ) return false;
        if(!p && !q) return true;
        if(p-> val != q -> val) return false;
        return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
    }
};


// Iterative
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> Q1, Q2;
        Q1.push(p); Q2.push(q);
        while(!Q1.empty() && !Q2.empty()){
            p = Q1.front(); Q1.pop();
            q = Q2.front(); Q2.pop();
            if((!p && q) || (p && !q) ) return false;
            if(!p && !q) continue;
            if(p-> val != q -> val) return false;
            Q1.push(p->left); Q2.push(q->left);
            Q1.push(p->right); Q2.push(q->right);
        }
        return true;
    }
};
