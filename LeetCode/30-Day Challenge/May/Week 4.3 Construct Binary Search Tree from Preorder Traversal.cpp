/*******************************************
 ***Problema: Construct Binary Search Tree from Preorder Traversal
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* solve(vector<int> &preorder, int left, int right){
        if( left >= right ) return NULL;
        TreeNode* root = new TreeNode(preorder[left]);
        int right_index = right;
        for( int i = left + 1; i < right ; ++i ){
            if( preorder[i] > preorder[left] ){
                right_index = i;
                break;
            }
        }
        
        root -> left = solve(preorder, left + 1, right_index );
        root -> right = solve(preorder, right_index, right);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder, 0, preorder.size());
    }
};
