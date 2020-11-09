/*******************************************
 ***Problema: Binary Tree Tilt
 ***ID: Week1.7
 ***Juez: LeetCode
 ***Tipo: Binary Tree Traversal
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
    
    int solve(TreeNode* root, int &res){
        if( root == NULL ) return 0;
        if( !root -> left && !root -> right ) return root -> val;
        int left = solve(root -> left, res);
        int right = solve(root -> right, res);
        res += abs(left - right);
        return left + right + root -> val;
    }
    int findTilt(TreeNode* root) {
        int res = 0;
        solve(root, res);
        return res;
    }
};
