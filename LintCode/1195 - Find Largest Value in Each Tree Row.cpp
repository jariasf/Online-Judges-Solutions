/*******************************************
 ***Problema: Find Largest Value in Each Tree Row
 ***ID: 1195
 ***Juez: LintCode
 ***Tipo: BFS
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
     * @param root: a root of integer
     * @return: return a list of integer
     */
    vector<int> largestValues(TreeNode * root) {
        vector<int> result;
        if( root == NULL ) return result;
        queue<TreeNode*> Q;
        Q.push(root);
        while( !Q.empty() ){
            int sz = Q.size(), maximum = 0;
            for( int i = 0 ; i < sz ; ++i ){
                TreeNode* node = Q.front(); Q.pop();
                int current_value = node -> val;
                if( i == 0 ) maximum = current_value;
                else maximum = max(maximum, current_value);
                if( node -> left ) Q.push(node -> left);
                if( node -> right) Q.push(node -> right);
            }
            result.push_back(maximum);            
        }
        return result;
    }
};
