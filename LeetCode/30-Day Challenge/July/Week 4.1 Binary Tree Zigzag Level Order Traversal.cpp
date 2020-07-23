/*******************************************
 ***Problema: Binary Tree Zigzag Level Order Traversal
 ***ID: Week4.1
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if( root == NULL ) return ans;
        queue<TreeNode*> Q;
        Q.push(root);
        bool left_to_right = true;        
        while(!Q.empty()){
            int sz = Q.size();
            vector<int> v(sz);          
            for( int i = 0 ; i < sz; ++i ){
                TreeNode* cur = Q.front(); Q.pop();
                if( left_to_right )
                    v[i] = cur -> val;
                else
                    v[sz - i - 1] = cur -> val;
                if( cur -> left )
                    Q.push(cur -> left);
                if( cur -> right )
                    Q.push(cur -> right);
            }
            ans.push_back(v);
            left_to_right = !left_to_right;
        }
        
        return ans;
    }
};
