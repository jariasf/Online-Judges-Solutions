/************************************************
 ***Problema: Sum of Root To Leaf Binary Numbers
 ***ID: 1022
 ***Juez: LeetCode
 ***Tipo: Data Structures - Binary Tree
 ***Autor: Jhosimar George Arias Figueroa
 ***********************************************/

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
    #define MOD 1000000007
    typedef long long LL;
    LL solve(TreeNode *root, LL val){
        if( root == NULL ) return 0;
        LL mask = (val << 1LL);
        if( root -> val == 1 ) mask = mask | 1LL;
        if( root -> left == NULL && root -> right == NULL ) return mask;
        return (solve(root -> left,  mask % MOD ) % MOD + solve(root -> right, mask % MOD) % MOD) % MOD;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
    }
};
