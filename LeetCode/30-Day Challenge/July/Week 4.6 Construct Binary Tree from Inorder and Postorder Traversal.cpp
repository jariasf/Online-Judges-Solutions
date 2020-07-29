/*******************************************
 ***Problema: Construct Binary Tree from Inorder and Postorder Traversal
 ***ID: Week4.6
 ***Juez: LeetCode
 ***Tipo: Recursion
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

    TreeNode* solve(int left, int right, int pos, vector<int> &inorder, vector<int> &postorder ){
        
        if( left > right || pos < 0 ) return NULL;
        
        int root_value = postorder[pos];
        int index_root_in = 0;
        for( int i = left ; i <= right ; ++i ){
            if( inorder[i] == root_value ){
                index_root_in = i;
                break;
            }
        }
        TreeNode *root = new TreeNode(root_value);
        root -> left = solve(left, index_root_in - 1, pos - 1 - right + index_root_in, inorder, postorder );
        root -> right = solve(index_root_in + 1, right, pos - 1 , inorder, postorder );
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(0,inorder.size() - 1, postorder.size() - 1, inorder, postorder );
    }
};
