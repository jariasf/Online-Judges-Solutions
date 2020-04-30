/*******************************************
 ***Problema: Binary Tree Maximum Path Sum
 ***ID: Week5.1
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int solve(TreeNode* root, int &ans){
        if( root == NULL )
            return 0;
        int maxLeft = max(0, solve(root -> left, ans ));
        int maxRight = max(0, solve(root -> right, ans));
        ans = max( ans, maxLeft + maxRight + root -> val );
        return max( maxLeft, maxRight ) + root -> val;
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};
