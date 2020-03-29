/*******************************************
 ***Problem: Count Number of Teams
 ***ID: 1395
 ***Judge: LeetCode
 ***Type: Brute Force | DP
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int numTeams(vector<int>& v) {
        int n = v.size();
        vector<int> g(n), s(n);
        
        for( int i = 0 ; i < n ; ++i ){
            for( int j = i + 1 ; j < n ; ++j ){
                if( v[j] > v[i] ){
                    g[i]++;
                }
                if( v[j] < v[i] ){
                    s[i]++;
                }
            }
        }

        int cnt = 0;
        for( int i = 0 ; i < n;  ++i ){
            for( int j = i + 1 ; j < n; ++j ){
                if( v[j] > v[i] ){
                    cnt += g[j];
                }
                if( v[j] < v[i] ){
                    cnt += s[j];
                }
            }    
        }
        return cnt;
    }
};
