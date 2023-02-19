/*******************************************
 ***Problema: Binary Tree Zigzag Level Order Traversal
 ***ID: Week 3.5
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if( root == nullptr ) return res;
        queue<TreeNode*> Q;
        Q.push(root);
        bool left_to_right = true;
        while( !Q.empty() ){
            int sz = Q.size();
            vector<int> values(sz);
            for(int i = 0 ; i < sz ; ++i){
                TreeNode* cur = Q.front(); Q.pop();
                if( left_to_right)
                    values[i] = cur->val;
                else
                    values[sz - i - 1] = cur -> val;
                if(cur -> left) Q.push(cur -> left);
                if(cur -> right) Q.push(cur -> right);                
            }
            res.push_back(values);
            left_to_right = !left_to_right;
        }

        return res;
    }
};
