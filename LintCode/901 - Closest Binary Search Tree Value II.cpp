/*******************************************
 ***Problema: Closest Binary Search Tree Value II
 ***ID: 901
 ***Juez: LintCode
 ***Tipo: Ad hoc, prefix-sums
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
     * @param root: the given BST
     * @param target: the given target
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     */
    void getNextPredecessor(TreeNode* root, stack<TreeNode*> &S){
        S.pop();
        TreeNode* cur = root -> left;
        while( cur ){
            S.push(cur);
            cur = cur -> right;
        }
    }
    
    void getNextSuccessor(TreeNode* root, stack<TreeNode*> &S){
        S.pop();
        TreeNode* cur = root -> right;
        while( cur ){
            S.push(cur);
            cur = cur -> left;
        }
    }    
    
    vector<int> closestKValues(TreeNode * root, double target, int k) {
        vector<int> values;
        stack<TreeNode*> pre, suc;
        
        while(root != NULL){
            if( root -> val >= target ){
                suc.push(root);
                root = root -> left;
            }else{
                pre.push(root);
                root = root -> right;
            }
        }
        
        while(k > 0 && (!suc.empty() || !pre.empty() )){
            TreeNode* pSuc, *pPre;
            pSuc = pPre = NULL;
            if( !suc.empty() ){
                pSuc = suc.top();
            }
            if( !pre.empty() ){
                pPre = pre.top();
            }
            
            if( pPre != NULL && pSuc != NULL ){
                if( fabs(pPre -> val - target) < fabs(pSuc -> val - target)  ){
                    values.push_back(pPre -> val);
                    getNextPredecessor(pPre, pre);
                }else{
                    values.push_back(pSuc -> val);
                    getNextSuccessor(pSuc, suc);
                }
                
            }else if( pPre == NULL ){
                values.push_back( pSuc -> val );
                getNextSuccessor(pSuc, suc);
            }else if( pSuc == NULL ){
                values.push_back( pPre -> val );
                getNextPredecessor(pPre, pre);
            }
            k--;
        }
        return values;
    }
};
/*
{4,2,5,1,3}
3.714286
3
*/
