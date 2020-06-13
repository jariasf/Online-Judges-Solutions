/*******************************************
 ***Problema: Allocate Mailboxes
 ***ID: 1478
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    #define INF 1<<30;
    vector<vector<int> > cost;
    vector<vector<int> > dp;
    int n;
    int solve(int pos, int k){
        if( pos == n){
            if( k == 0 ) return 0;
            return INF;
        }
        if( k <= 0 ) return INF;
        
        if( dp[pos][k] != -1 ) return dp[pos][k];
        int res = INF;
        for( int i = pos ; i < n; ++i ){
            res = min( res, cost[pos][i] + solve(i + 1, k - 1));
        }
        return dp[pos][k] = res;
    }
    
    int minDistance(vector<int>& houses, int K) {
        n = houses.size();
        sort(houses.begin(), houses.end());
        
        // cost from house i -> j, considering a mailbox in the middle pos
        cost = vector<vector<int> >(n + 1, vector<int>(n + 1));
        
        for( int i = 0 ; i < n ; ++i ){
            for( int j = i ; j < n ; ++j ){
                int mid = (i + j)/2;
                for( int k = i ; k <= j ; ++k ){
                    cost[i][j] += abs(houses[k] - houses[mid]);
                }
            }
        }
        dp = vector<vector<int> >(n + 1, vector<int>(K + 1 , -1));
        return solve(0, K);       
    }    
};
