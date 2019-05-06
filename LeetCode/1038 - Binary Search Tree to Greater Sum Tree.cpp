/********************************************
 ***Problema: Binary Search Tree to Greater Sum Tree
 ***ID: 1038
 ***Juez: LeetCode
 ***Tipo: BST - Reversed inorder traversal
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
    
    void solve(TreeNode* root, int &sum){
        if( root == NULL ) return;
        solve(root -> right, sum);
        sum += root -> val;
        root -> val = sum;
        solve(root -> left, sum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return root;
    }
};
