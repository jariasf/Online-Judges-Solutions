/*******************************************
 ***Problema: Insert into a Binary Search Tree
 ***ID: Week1.6
 ***Juez: LeetCode
 ***Tipo: BST
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* pNode = new TreeNode(val);
        if( root == NULL ) return pNode;
        TreeNode* current = root;
        while(true){
            if(current -> val < val ){
                if( current -> right == NULL ){
                    current -> right = pNode;
                    break;
                }
                current = current -> right;
            }else{
                if( current -> left == NULL ){
                    current -> left = pNode;
                    break;
                }
                current = current -> left;
            }
        }
        return root;
    }
};
