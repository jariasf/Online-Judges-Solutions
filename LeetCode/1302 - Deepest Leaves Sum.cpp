/*******************************************
 ***Problema: Deepest Leaves Sum
 ***ID: 1301
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int deepest(TreeNode* root){
        if( root == NULL ) return 0;
        return 1 + max( deepest(root -> left), deepest(root -> right));        
    }
    
    int solve(TreeNode* root, int depth, int cur){
        if( root == NULL ) return 0;
        if( depth == cur ){
            return root -> val;
        }
        return solve(root -> left, depth, cur + 1 ) + solve(root -> right, depth, cur + 1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int depth = deepest(root);
        return solve(root, depth, 1);
    }
};
