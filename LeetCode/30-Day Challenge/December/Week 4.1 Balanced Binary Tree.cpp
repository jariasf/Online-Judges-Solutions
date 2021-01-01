/*******************************************
 ***Problema: Balanced Binary Tree
 ***ID: Week4.1
 ***Juez: LeetCode
 ***Tipo: Recursion - BT
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
    pair<int,bool> balanced(TreeNode* root ){
        if( root == NULL )
            return make_pair(0, true);
        
        pair<int, bool > left = balanced(root -> left);
        pair<int, bool > right = balanced(root -> right );
        
        if( abs(left.first - right.first) > 1 )
            return make_pair( -1, false );
        
        return make_pair( 1 + max(left.first, right.first), left.second&right.second );
    }

    bool isBalanced(TreeNode* root) {
        return balanced(root).second;
    }
};
