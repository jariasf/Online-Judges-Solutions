/*******************************************
 ***Problema: Sum of Root To Leaf Binary Numbers
 ***ID: Week2.1
 ***Juez: LeetCode
 ***Tipo: Tree Traversal
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
    int solve(TreeNode* root, int num){
        if( root == NULL ) return 0;
        num = (num<<1) + root -> val;
        return (!root -> right && !root -> left)? num
                :solve(root -> left, num) + solve(root -> right, num);       
    }
        
    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
    }
};
