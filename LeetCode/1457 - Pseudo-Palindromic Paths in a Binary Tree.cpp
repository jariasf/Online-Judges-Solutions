/*******************************************
 ***Problema: Pseudo-Palindromic Paths in a Binary Tree
 ***ID: 1457
 ***Juez: LeetCode
 ***Tipo: Hashing + Tree Traversal
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
    int cnt;
    void solve(TreeNode* root, vector<int> &hash){
        if( root == NULL ) return;
        
        hash[ root -> val ]++;
        if( root -> left == NULL && root -> right == NULL ){
            int odd = 0;
            for( int i = 0 ; i < hash.size(); ++i )
                odd += hash[i] & 1;
            if( odd <= 1 ) cnt++;
        }
        
        solve(root -> left, hash);
        solve(root -> right, hash);
        hash[ root -> val ]--;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> hash = vector<int>(10, 0);
        cnt = 0;
        solve(root, hash);
        return cnt;
    }
};
