/*******************************************
 ***Problema: Smallest Subtree with all the Deepest Nodes
 ***ID: Week2.5
 ***Juez: LeetCode
 ***Tipo: LCA
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
    #define MAX 505
    int d[MAX];
    void traverse(TreeNode* root, int depth){
        if( root == NULL ) return;
        d[root -> val] = depth;
        traverse(root -> left, depth + 1);
        traverse(root -> right, depth + 1);
    }

    bool hasAll(TreeNode* root, int maxDepth, int maxCount ){
        queue<TreeNode*> Q;
        Q.push(root);
        while( !Q.empty() ){
            TreeNode* cur = Q.front(); Q.pop();
            if( cur == NULL ) continue;
            if( d[cur -> val] == maxDepth ){
                maxCount--;
            }
            Q.push(cur -> left);
            Q.push(cur -> right);
        }
        return maxCount == 0;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        memset(d, 0, sizeof(d));
        traverse(root, 0 );
        int maxDepth = 0;
        for( int i = 0 ; i < MAX ; ++i ){
            maxDepth = max( maxDepth, d[i] );
        }

        int maxCount = 0;
        for( int i = 0; i < MAX ; ++i ){
            if( maxDepth == d[i] ){
                maxCount++;
            }
        }

        queue<TreeNode*> Q;
        Q.push(root);
        int maxDepthRes = 0;
        TreeNode* resNode = root;
        while( !Q.empty() ){
            TreeNode* cur = Q.front(); Q.pop();
            if( cur == NULL ) continue;
            if( hasAll(cur, maxDepth, maxCount) ){
                if( d[cur -> val] > maxDepthRes ){
                    maxDepthRes = d[cur->val];
                    resNode = cur;
                }
            }
            Q.push(cur -> left);
            Q.push(cur -> right);
        }
        return resNode;
    }
};
