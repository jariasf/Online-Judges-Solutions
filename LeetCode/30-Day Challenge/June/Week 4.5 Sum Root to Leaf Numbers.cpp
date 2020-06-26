/*******************************************
 ***Problema: Sum Root to Leaf Numbers
 ***ID: Week4.4
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
    int traverse(TreeNode* root, int number){
        if( root == NULL )
            return 0;
        
        if( root -> left == NULL && root -> right == NULL )
            return number * 10 + root -> val;
        
        int sum = 0;
        sum += traverse(root -> left , number * 10 + root -> val);
        sum += traverse(root -> right, number * 10 + root -> val);
        return sum;
    }
    
    int sumNumbers(TreeNode* root) {
        return traverse(root, 0);
    }
};

