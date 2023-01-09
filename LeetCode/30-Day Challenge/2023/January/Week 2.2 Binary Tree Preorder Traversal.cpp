/*******************************************
 ***Problema: Binary Tree Preorder Traversal
 ***ID: Week 2.2
 ***Juez: LeetCode
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

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
    vector<int> preorderTraversal(TreeNode* root) {
        if( root == nullptr ) return {};
        vector<int> traversal;
        stack<TreeNode*> S;
        S.push(root);
        while(!S.empty()){
            TreeNode* cur = S.top(); S.pop();
            traversal.push_back(cur->val);
            if(cur -> right) S.push(cur -> right);
            if(cur -> left) S.push(cur -> left);
        }
        return traversal;
    }
};
