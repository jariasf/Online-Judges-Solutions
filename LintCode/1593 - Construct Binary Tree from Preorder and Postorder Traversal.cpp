/*******************************************
 ***Problema: Construct Binary Tree from Preorder and Postorder Traversal
 ***ID: 1593
 ***Juez: LintCode
 ***Tipo: Binary Tree Traversal
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    TreeNode* construct(vector<int> &pre, vector<int> &post, int left, int right, int post_index){
        if( left  + 1 == right ) return new TreeNode(pre[left]);
        if( left >= right ) return NULL;
        int root_pos = left, left_pre = left + 1;
        int left_post = left;
        for( int i = post_index ; i < right ; ++i ){
            if( post[i] == pre[left_pre] ){
                left_post = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(pre[root_pos]);
        root -> left = construct(pre, post, left_pre, left_pre + left_post - post_index + 1, post_index);
        root -> right = construct(pre, post, left_pre + left_post - post_index + 1, right, left_post + 1);
        return root;
    }

    TreeNode * constructFromPrePost(vector<int> &pre, vector<int> &post) {
        return construct(pre, post, 0, pre.size(), 0);
    }  
};

