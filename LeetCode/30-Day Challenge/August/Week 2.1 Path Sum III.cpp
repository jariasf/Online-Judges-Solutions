/*******************************************
 ***Problema: Path Sum III
 ***ID: Week2.1
 ***Juez: LeetCode
 ***Tipo: Hashing + Prefix Sums + Binary Tree Traversal
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
    unordered_map<int, int> hash;
    int traverse(TreeNode* root, int sum, int target){
        if( root == NULL ) return 0;
        int new_sum = sum + root -> val;  
        int res = 0;
        if( hash.find( new_sum - target ) != hash.end() )
            res += hash[ new_sum - target];
        hash[new_sum]++;              
        res += traverse(root -> left, new_sum, target);
        res += traverse(root -> right, new_sum, target);
        hash[new_sum]--;
        return res;
    }
    
    int pathSum(TreeNode* root, int sum) {
        hash.clear();
        hash[0] = 1;
        return traverse(root, 0, sum);
    }
};
