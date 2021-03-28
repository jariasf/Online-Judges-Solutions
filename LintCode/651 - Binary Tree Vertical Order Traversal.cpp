/*******************************************
 ***Problema: Binary Tree Vertical Order Traversal
 ***ID: 651
 ***Juez: LintCode
 ***Tipo: BFS | DFS + Hashing
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
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    vector<vector<int>> verticalOrder(TreeNode * root) {
        vector<vector<int> > res;
        if( root == NULL ) return res;
        unordered_map<int, vector<int> > hash;
        queue<pair<TreeNode*,int>> Q;
        Q.push(make_pair(root, 0));
        int minimum = 0, maximum = 0;
        while( !Q.empty() ){
            pair<TreeNode*,int> p = Q.front(); Q.pop();
            TreeNode* cur = p.first;
            int id = p.second;
            minimum = min(minimum, id);
            maximum = max(maximum, id);
            hash[id].push_back(cur -> val);
            if( cur -> left ){
                Q.push(make_pair(cur -> left, id - 1));
            }

            if( cur -> right ){
                Q.push(make_pair(cur -> right, id + 1));
            }
        }

        while(minimum <= maximum){
            res.push_back(hash[minimum]);
            minimum++;
        }
        return res;
    }
};
//{1,2,3,4,5,6,7,#,8,10,9,#,11,#,#,#,12}
