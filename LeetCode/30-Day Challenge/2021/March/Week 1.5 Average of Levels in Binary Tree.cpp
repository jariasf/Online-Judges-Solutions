/*******************************************
 ***Problema: Average of Levels in Binary Tree
 ***ID: Week1.5
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avg;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){            
            double sum = 0.0;
            int n = Q.size();
            //current level
            for( int i = 0 ; i < n ; ++i ){
                TreeNode* current = Q.front(); Q.pop();
                sum += current -> val;
                if( current -> left ) Q.push(current -> left);
                if( current -> right ) Q.push(current -> right);
            }
            avg.push_back(sum/(double)n);
        }
        return avg;
    }
};
