/*******************************************
 ***Problema: Maximum Difference Between Node and Ancestor
 ***ID: Week2.2
 ***Juez: LeetCode
 ***Tipo: Binary Tree Traversal
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
    #define pii pair<int,int>
    #define mp make_pair
    
    pii solve(TreeNode* root, int &sol){
        if( root == NULL ) return mp(-1, 1<<30);
        pii pLeft = solve(root -> left, sol);
        pii pRight = solve(root -> right, sol);
        int maxi = max(pLeft.first, pRight.first);
        int mini = min(pLeft.second, pRight.second);
        if( maxi >= 0 ) sol = max( sol, abs(root -> val - maxi) );
        if( mini != 1<<30 ) sol = max(sol, abs(root -> val - mini));
        return mp( max(maxi, root -> val) , min(mini, root->val) );
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int sol = 0;
        solve(root, sol);
        return sol;
    }
};
