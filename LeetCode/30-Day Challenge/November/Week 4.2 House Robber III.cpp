/*******************************************
 ***Problema: House Robber III
 ***ID: Week4.2
 ***Juez: LeetCode
 ***Tipo: Binary tree Traversal
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
#define pii pair<int,int>
#define mp make_pair
class Solution {
public:
    pii solve(TreeNode* root){
        if( root == NULL )
            return mp(0,0);
        pii pLeft = solve(root -> left);
        pii pRight = solve(root -> right);
        int taken = root -> val + pLeft.second + pRight.second;
        int notaken = max(pLeft.first, pLeft.second) + max(pRight.first,pRight.second);
        return mp(taken, notaken );
    }
    
    int rob( TreeNode* root ){
        pii res = solve(root);
        return max(res.first,res.second);
    }
};
