/*******************************************
 ***Problema: Distribute Coins in Binary Tree
 ***ID: 979
 ***Juez: LeetCode
 ***Tipo: Binary Tree, DFS
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
    
    int dfs(TreeNode* root, unordered_map<TreeNode*, int> &count) {
        if(count.find(root) == count.end() ) {
            count[root] = root -> val;
        }
        
        int coins_num = count[root];
        int result = 0;
        if( root -> left ){
            result += dfs(root -> left, count);
            coins_num += count[ root -> left];
            result += abs(count[root -> left]);
        }
        if( root -> right ){
            result += dfs(root -> right, count);
            coins_num += count[ root -> right];
            result += abs(count[root -> right]);
        }
        count[root] = coins_num - 1;
        return result;
    }
    
    int distributeCoins(TreeNode* root) {
        if( root == NULL ) return 0;
        unordered_map<TreeNode*, int> count;
        return dfs(root, count);
    }
};
