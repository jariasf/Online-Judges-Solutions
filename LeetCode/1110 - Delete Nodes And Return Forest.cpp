/*******************************************
 ***Problema: Delete Nodes And Return Forest
 ***ID: 1110
 ***Juez: LeetCode
 ***Tipo: Binary Trees, Traversal
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
#define MAX 1005
class Solution {
public:
    
    vector<bool> del;
    vector<TreeNode*> res;
    
    
    void solve(TreeNode* root, TreeNode* parent){
        if( root == NULL ) return;
        if( del[root -> val] ){
            if( root -> left && !del[root -> left -> val ] ){
                res.push_back( root -> left );
            }
            
            if( root -> right && !del[root -> right -> val ] ){
                res.push_back( root -> right );
            }
            
            if( parent != NULL ){
                if( parent -> left != NULL && parent -> left -> val == root -> val  ) parent -> left = NULL;
                if( parent -> right != NULL && parent -> right -> val == root -> val  ) parent -> right = NULL;
            }
        }
        
        solve(root -> left, root);
        solve(root -> right, root);
        
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        del = vector<bool>(MAX);
        
        for( int i = 0 ; i < to_delete.size(); ++i ){
            del[ to_delete[i] ] = 1;
        }
        
        res.clear();
        
        if( root == NULL ){
            return res;
        }
        
        if( !del[root -> val ] ){
            res.push_back(root);
        }
        
        solve(root, NULL);
        return res;
    }
};
