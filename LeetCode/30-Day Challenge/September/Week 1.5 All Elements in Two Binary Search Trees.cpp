/*******************************************
 ***Problema: All Elements in Two Binary Search Trees
 ***ID: Week1.5
 ***Juez: LeetCode
 ***Tipo: Inorder traversal
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Iterative -> one pass

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> inorder;
        stack<TreeNode*> S1, S2;
        
        while( !S1.empty() || root1 || !S2.empty() || root2 ){
            while( root1 ){
                S1.push(root1);
                root1 = root1 -> left;
            }
            
            while( root2 ){
                S2.push(root2);
                root2 = root2 -> left;
            }
            
            TreeNode* node1 = NULL, *node2 = NULL;
            int val1 = 1<<30, val2 = 1<<30;
            if( !S1.empty() ){
                node1 = S1.top(); 
                val1 = node1 -> val;
            }
            
            if( !S2.empty() ){
                node2 = S2.top();
                val2 = node2 -> val;
            }
            
            if( val1 < val2 ){
                inorder.push_back( val1 );
                S1.pop();
                root1 = node1 -> right;
            }else if( val2 != 1<<30 ){
                inorder.push_back( val2 );
                S2.pop();
                root2 = node2 -> right;
            }
        }
        return inorder;  
    }
};



// Recursive inorder traversal for each tree + Merge -> two passes

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
    
    void inorder(TreeNode* root, vector<int> &v ){
        if( root == NULL ) return;
        inorder(root -> left, v);
        v.push_back(root -> val);       
        inorder(root -> right, v);
    }
    
    vector<int> mergeSorted(vector<int> &A, vector<int> &B){
        int n = A.size(), m = B.size();
        vector<int> res;
        int i = 0, j = 0;
        while( i < n && j < m ){
            if( A[i] < B[j] )
                res.push_back(A[i++]);
            else
                res.push_back(B[j++]);
        }
        
        while( i < n ) res.push_back(A[i++]);
        while( j < m ) res.push_back(B[j++]);        
        return res;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> A, B;
        inorder(root1, A);
        inorder(root2, B);
        return mergeSorted(A, B);  
    }
};

/*
[2,1,4]
[1,0,3]
[0,-10,10]
[5,1,7,0,2]
[]
[5,1,7,0,2]
[0,-10,10]
[]
*/
