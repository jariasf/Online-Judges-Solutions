/*******************************************
 ***Problema: Maximum Vacation Days
 ***ID: 568
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

//Bottom Up
class Solution {
public:
    /**
     * @param flights: the airline status from the city i to the city j
     * @param days: days[i][j] represents the maximum days you could take vacation in the city i in the week j
     * @return: the maximum vacation days you could take during K weeks
     */
    int maxVacationDays(vector<vector<int>> &flights, vector<vector<int>> &days) {
        int N = flights.size(), W = days[0].size();
        int dp[N+1][W+1];
        memset(dp, -1, sizeof(dp));
        
        dp[0][0] = days[0][0];
        for( int i = 1 ; i < N ; ++i ){
            if( flights[0][i]){
                dp[i][0] = days[i][0];
            }
        }
        
        for( int week = 1 ; week < W ; ++week ){
            for( int dest = 0 ; dest < N ; ++dest ){
                for( int orig = 0; orig < N ; ++orig ){
                    if( dp[orig][week - 1] != -1 ){
                        if(orig == dest){
                            dp[dest][week] = max(dp[dest][week], dp[dest][week - 1] + days[dest][week]);
                        }else if(flights[orig][dest]){
                            dp[dest][week] = max(dp[dest][week], dp[orig][week - 1] + days[dest][week]);
                        }
                    }
                }
            }
        }
        
        int result = 0;
        for( int i = 0 ; i < N ; ++i  ){
            result = max(result, dp[i][W-1]);
        }
        return result;
    }
};


//Top Down O(n^2)
class Solution {
public:

    #define MAX 102
    int dp[MAX][MAX];
    vector<vector<int> > d;
    vector<vector<int> > f;

    /**
     * @param flights: the airline status from the city i to the city j
     * @param days: days[i][j] represents the maximum days you could take vacation in the city i in the week j
     * @return: the maximum vacation days you could take during K weeks
     */
    int solve(int city, int week){
        int N = f.size();
        int W = d[0].size();
        
        if( week == W ){
            return 0;
        }
        
        if( dp[city][week] != -1 ) return dp[city][week];
        
        int result = 0;
        for( int i = 0 ; i < N ; ++i ){
            if( f[city][i] == 1 ){
                result = max(result, d[i][week] + solve(i, week + 1));    
            }
        }
        
        // do not travel
        result = max(result, d[city][week] + solve(city, week + 1));
        return dp[city][week] = result;
    }
     
    int maxVacationDays(vector<vector<int>> &flights, vector<vector<int>> &days) {
        d = days;
        f = flights;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }  
};


//Top Down O(2*n*n)
class Solution {
public:

    #define MAX 102
    int dp[MAX][MAX][2];
    vector<vector<int> > d;
    vector<vector<int> > f;

    /**
     * @param flights: the airline status from the city i to the city j
     * @param days: days[i][j] represents the maximum days you could take vacation in the city i in the week j
     * @return: the maximum vacation days you could take during K weeks
     */
    int solve(int city, int week, bool travel){
        int N = f.size();
        int W = d[0].size();
        
        if( week == W ){
            return 0;
        }
        
        if( dp[city][week][travel] != -1 ) return dp[city][week][travel];
        
        int result = 0;
        if( !travel ){
            for( int i = 0 ; i < N ; ++i ){
                if( f[city][i] == 1 ){
                    result = max(result, solve(i, week, 1));    
                }
            }
        }
        
        // do not travel
        result = max(result, d[city][week] + solve(city, week + 1, 0));
        return dp[city][week][travel] = result;
    }
     
    int maxVacationDays(vector<vector<int>> &flights, vector<vector<int>> &days) {
        d = days;
        f = flights;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};
