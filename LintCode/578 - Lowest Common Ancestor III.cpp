/*******************************************
 ***Problema: Lowest Common Ancestor III
 ***ID: 578
 ***Juez: LintCode
 ***Tipo: Tree Traversal
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
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    bool exist(TreeNode* root, TreeNode* A){
        if( root == NULL ) return NULL;
        if( root == A ) return true;
        return exist( root -> left, A) || exist( root -> right, A);
    }

    TreeNode* LCA(TreeNode* root, TreeNode* A, TreeNode* B){
        if( root == NULL) return NULL;
        if( root == A ) return A;
        if( root == B ) return B;
        TreeNode* left = LCA(root -> left, A, B);
        TreeNode* right = LCA(root -> right, A, B);
        if( left == NULL )
            return right;
        else if( right == NULL )
            return left;
        return root;
    }


    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
        if( !exist(root, A) || !exist(root, B) ) return NULL;
        return LCA(root, A, B);
    }
    /*
    //Additional Memory to save the paths and requires less recursive calls
    bool searchNode(vector<TreeNode *> &pA, TreeNode *root, TreeNode *A){
        if( root == NULL ) return false;
        pA.push_back(root);        
        if( root == A )
            return true;

        if( root -> left && searchNode(pA, root -> left, A) ){
            return true;
        }else if( root ->right && searchNode(pA, root -> right, A)){
            return true;
        }
        pA.pop_back();
        return false;
    }

    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
        if( root == NULL ) return NULL;
        vector<TreeNode*> pA, pB;
        if( !searchNode(pA, root, A) || !searchNode(pB, root, B) ) return NULL;

        while( pA.size() > pB.size() )
            pA.pop_back();

        while( pB.size() > pA.size() )
            pB.pop_back();

        while( pA.size() > 0 && pB.size() > 0 && pA.back() != pB.back()){
            pA.pop_back(); pB.pop_back();
        }

        if( pA.size() > 0 ) return pA.back();
        return NULL;
    }*/
};
