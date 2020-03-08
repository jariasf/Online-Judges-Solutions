/*******************************************
 ***Problem: Time Needed to Inform All Employees
 ***ID: 1376
 ***Judge: LeetCode
 ***Type: DFS
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    vector<vector<int> > adj;
    vector<int> cost;
    int solve(int root){
        int maxi = 0;
        for( int i = 0 ; i < adj[root].size(); ++i ){
            int v = adj[root][i];
            maxi = max( maxi, cost[v] + solve(v));
        }
        return maxi;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        adj = vector<vector<int> >(n);
        cost = informTime;
        for( int i = 0 ; i < manager.size(); ++i ){
            if( headID == i ) continue;
            adj[manager[i]].push_back(i);
        }
        
        return cost[headID] + solve(headID);
        
    }
};
