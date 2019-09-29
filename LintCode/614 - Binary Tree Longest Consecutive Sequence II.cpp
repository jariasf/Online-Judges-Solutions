/*******************************************
 ***Problema: Binary Tree Longest Consecutive Sequence II
 ***ID: 614
 ***Juez: LintCode
 ***Tipo: DFS
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
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    pair<int, int> solve(TreeNode* root, int &longest){
        if(root == NULL) return make_pair(0 , 0);
        pair<int,int> p_left = solve(root -> left, longest);
        pair<int,int> p_right = solve(root -> right, longest);
        
        pair<int,int> p_root = make_pair(1, 1);
        if( root -> left && root -> val + 1 == root -> left -> val ){
            p_root.first = max( p_root.first, 1 + p_left.first );
        }
        if( root -> right && root -> val + 1 == root -> right -> val ){
            p_root.first = max( p_root.first, 1 + p_right.first );                
        }
        
        if( root -> left && root -> val - 1 == root -> left -> val ){
            p_root.second = max( p_root.second, 1 + p_left.second );
        }
        if( root -> right && root -> val - 1 == root -> right -> val ){
            p_root.second = max( p_root.second, 1 + p_right.second );
        }        
        longest = max(longest, p_root.first + p_root.second - 1);
        return p_root;
    } 
     
    int longestConsecutive2(TreeNode * root) {
        // write your code here
        int longest = 0;
        solve(root, longest);
        return longest;
    }
};
