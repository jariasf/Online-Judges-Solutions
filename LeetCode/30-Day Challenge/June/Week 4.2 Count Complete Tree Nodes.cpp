/*******************************************
 ***Problema: Count Complete Tree Nodes
 ***ID: Week4.2
 ***Juez: LeetCode
 ***Tipo: Tree Height Comparison
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
    
    int height(TreeNode* root){
        return root == NULL? -1: 1 + height(root -> left);
    }
    
    int countNodes(TreeNode* root) {
        int h = height(root);
        if( h < 0 ) return 0;
        int h_right = height(root -> right);
        if( h_right == h - 1 )
            return (1<<h) + countNodes(root -> right);
        else
           return (1<<h-1) + countNodes(root -> left);
    }
};
