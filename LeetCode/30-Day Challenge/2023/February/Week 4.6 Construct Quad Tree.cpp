/*******************************************
 ***Problema: Construct Quad Tree
 ***ID: Week 4.6
 ***Juez: LeetCode
 ***Tipo: Recursion + Quadtree
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int> > dp(n1 + 1, vector<int>(n2 + 1));

        for(int i = 0 ; i <= n1 ; ++i) dp[i][0] = i;
        for(int i = 0 ; i <= n2 ; ++i) dp[0][i] = i;        

        for(int i = 1 ; i <= n1 ; ++i){
            for(int j = 1 ; j <= n2 ; ++j){
                if( word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
            }
        }
        return dp[n1][n2];
    }
};/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    Node* create(vector<vector<int> > &grid, int x1, int y1, int x2, int y2){
        int xmid = x1 + (x2 - x1)/2, ymid = y1 + (y2 - y1)/2;
        if( x1 + 1 == x2 ){
            return new Node(grid[x1][y1], true);
        }
        Node* topLeft = create(grid, x1, y1, xmid, ymid);
        Node* topRight = create(grid, x1, ymid, xmid, y2);
        Node* bottomLeft = create(grid, xmid, y1, x2, ymid);
        Node* bottomRight = create(grid, xmid, ymid, x2, y2);
        if(topLeft -> val == topRight -> val && topRight -> val == bottomLeft -> val && bottomLeft -> val == bottomRight -> val && topLeft -> isLeaf && topRight -> isLeaf && bottomLeft -> isLeaf && bottomRight -> isLeaf){
            return new Node(topLeft ->val, true);
        }else{
            return new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
        }
    }

    Node* construct(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        return create(grid, 0, 0, h, w);
    }
};
