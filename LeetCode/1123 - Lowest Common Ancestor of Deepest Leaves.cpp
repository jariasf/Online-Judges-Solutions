/*******************************************
 ***Problema: Lowest Common Ancestor of Deepest Leaves
 ***ID: 1123
 ***Juez: LeetCode
 ***Tipo: Binary Tree, LCA
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
    
    TreeNode* LCA(TreeNode* root, int A, int B){
        if( root == NULL ) return NULL;
        if( root -> val == A || root -> val == B ) return root;
        TreeNode* left = LCA(root -> left, A, B);
        TreeNode* right = LCA(root -> right, A, B);
        if( left && right ) return root;
        if( left ) return left;
        return right;
    }
    
    vector<TreeNode*> leaves;
    int maxDepth;
    void deepest(TreeNode* root, int depth){
        if( root == NULL ) return;
        if( root -> left == NULL && root -> right == NULL ){
            if( depth > maxDepth ){
                maxDepth = depth;
                leaves.clear();
                leaves.push_back(root);
            }else if( depth == maxDepth ){
                leaves.push_back(root);
            }
            return;
        }
        deepest(root -> left, depth + 1);
        deepest(root -> right, depth + 1);
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        leaves.clear();
        maxDepth = -1;
        deepest(root, 0);
        if( leaves.size() == 1 ) return leaves[0];
        TreeNode* res = LCA(root, leaves[0] -> val, leaves[1] -> val );
        for( int i = 2 ; i < leaves.size(); ++i ){
            res = LCA(root, res -> val, leaves[i] -> val);
        }
        return res;
    }
};
