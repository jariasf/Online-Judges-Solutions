/*******************************************
 ***Problema: Student Attendance Record II
 ***ID: 552
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    const int MOD = 1e9 + 7;
    typedef int LL;
    int checkRecord(int n) {
        int dp[2][3] = {0};
        int last_dp[2][3] = {0};
        last_dp[0][0] = last_dp[1][0] = last_dp[0][1] = 1;
        
        for( int i = 2 ; i <= n ; ++i ){
            for( int absent = 0; absent < 2; ++absent ){
                for( int late = 0; late < 3 ; ++late ){
					//present
                    dp[absent][0] += last_dp[absent][late];
                    if( dp[absent][0] >= MOD )
                        dp[absent][0] -= MOD;
                    if(late > 0 ){
						//late                        
						dp[absent][late] += last_dp[absent][late - 1]; 
                        if( dp[absent][late] >= MOD )
                            dp[absent][late] -= MOD;
                    }
                    if( absent == 1){
						//absent
                        dp[absent][0] += last_dp[absent-1][late];
                        if( dp[absent][0] >= MOD )
                            dp[absent][0] -= MOD;
                    }
                }
            }
            
            for( int absent = 0; absent < 2 ; ++absent ){
                for( int late = 0; late < 3 ; ++late ){
                    last_dp[absent][late] = dp[absent][late];
                    dp[absent][late] = 0;
                }
            }
        }
        
        LL total = 0;
        for( int absent = 0; absent < 2 ; ++absent ){
            for( int late = 0; late < 3 ; ++late ){
                total += last_dp[absent][late];
                if( total >= MOD )
                    total -= MOD;
            }
        }
        
        return total;
        
    }
};
