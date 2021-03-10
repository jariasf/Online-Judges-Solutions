/*******************************************
 ***Problema: Add One Row to Tree
 ***ID: Week2.2
 ***Juez: LeetCode
 ***Tipo: BFS
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        
        if( d == 1 ){
            TreeNode* new_root = new TreeNode(v);
            new_root -> left = root;
            return new_root;
        }
        
        queue<TreeNode*> Q;
        Q.push(root);
        while( !Q.empty() && d > 1){
            int sz = Q.size();
            d--;
            for( int i = 0 ; i < sz ; ++i ){
                TreeNode* cur = Q.front(); Q.pop();
                if( d == 1 ){
                    TreeNode *new_left = new TreeNode(v);
                    TreeNode *new_right = new TreeNode(v);
                    TreeNode *left = cur -> left, *right = cur -> right;
                    cur -> left = new_left;
                    cur -> right = new_right;
                    new_left -> left = left;
                    new_right -> right = right;
                }
                if( cur -> left)
                    Q.push(cur -> left);
                if( cur -> right)
                    Q.push(cur -> right);
            }
        }
        
        return root;
    }
};
