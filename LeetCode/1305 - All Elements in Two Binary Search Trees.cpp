/*******************************************
 ***Problema: All Elements in Two Binary Search Trees
 ***ID: 1305
 ***Juez: LeetCode
 ***Tipo: Inorder | Tree Traversal + Sorting
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

//O(n): Inorder + Merge
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
            if( A[i] < B[j] ){
                res.push_back(A[i++]);
            }else{
                res.push_back(B[j++]);
            }
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


//O(nlogn): Tree traversal + Sort
class Solution {
public:
    
    void traverse(TreeNode* root, vector<int> &v ){
        if( root == NULL ) return;
        v.push_back(root -> val);
        traverse(root -> left, v);
        traverse(root -> right, v);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        traverse(root1, res);
        traverse(root2, res);
        sort(res.begin(), res.end());
        return res;
    }
};
