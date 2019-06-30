/*******************************************
 ***Problema: Filling Bookcase Shelves
 ***ID: 1105
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    vector<vector<int>> v;
    int W;
    vector<int> dp;
    int solve(int pos){
        int n = v.size();
        if( pos == n ) return 0;
        if( dp[pos] != -1 ) return dp[pos];
        
        int maxi = 0;
        int res = 1<<30;
        int width = 0;
        for( int i = pos; i < n ; ++i ){
            if( width + v[i][0] <= W ){
                maxi = max( maxi, v[i][1]);
                width += v[i][0];
                res = min( res, maxi + solve(i + 1) );
            }else{
                break;
            }
        }
        
        return dp[pos] = res;
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        v = books;
        W = shelf_width;
        dp = vector<int>(books.size(), -1);
        return solve(0);
    }
};
