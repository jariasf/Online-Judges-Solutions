/*******************************************
 ***Problema: Sum of Left Leaves
 ***ID: Week4.3
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL ) return 0;
        if( root -> left != NULL && root -> left -> left == NULL && root -> left -> right  == NULL )
            return root -> left -> val + sumOfLeftLeaves(root -> right);
        return sumOfLeftLeaves(root -> left) + sumOfLeftLeaves(root -> right);
    }
};
