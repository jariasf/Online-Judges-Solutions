/*******************************************
 ***Problema: Check Completeness of a Binary Tree
 ***ID: 958
 ***Juez: LeetCode
 ***Tipo: Binary Tree
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
    bool isCompleteTree(TreeNode* root) {
        if( root == NULL ) return true;
        queue<TreeNode*> Q;
        Q.push(root);
        int level = 0;
        while( !Q.empty() ){
            int sz = Q.size();
            if( sz == 1<<level ){
                bool last = false;
                for( int i = 0 ; i < sz ; ++i ){
                    TreeNode* cur = Q.front(); Q.pop();
                    if( cur -> left == NULL && cur -> right != NULL ) return false;
                    if( cur -> left != NULL && cur -> right != NULL ){
                        if( last == true ) return false;
                        Q.push(cur -> left);
                        Q.push(cur -> right);
                    }else if( cur -> left != NULL && cur -> right == NULL ){
                        if( last == true ) return false;
                        Q.push(cur -> left);
                        last = true;
                    }else if( cur -> left == NULL && cur -> right == NULL )
                        last = true;
                }
            }else{
                for( int i = 0 ; i < sz ; ++i ){
                    TreeNode* cur = Q.front(); Q.pop();
                    if( cur -> left != NULL || cur -> right != NULL ) return false;
                }
            }
            level++;
        }
        return true;        
    }
};
