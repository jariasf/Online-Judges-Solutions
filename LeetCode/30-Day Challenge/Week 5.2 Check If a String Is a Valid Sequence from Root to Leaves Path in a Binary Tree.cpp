/*******************************************
 ***Problema: Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree
 ***ID: Week5.2
 ***Juez: LeetCode
 ***Tipo: DFS
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
    vector<int> v;
    
    bool isLeaf(TreeNode* node){
        return node && node -> left == NULL && node -> right == NULL;
    }
    
    bool isValid(TreeNode* root, int pos){        
        if( root == NULL ) return false;
        if( root -> val == v[pos] ){
            if( v.size() == pos + 1 ) return isLeaf(root);
            if( isValid(root -> left, pos + 1) || isValid(root -> right, pos + 1)) return true;
        }
        return false;
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        v = arr;
        return isValid(root, 0);
    }
};
