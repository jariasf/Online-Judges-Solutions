/*******************************************
 ***Problema: Sum of Subarray Minimums
 ***ID: 907
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define pii pair<int,int>
#define mp make_pair
#define MOD 1000000007

typedef long long LL;
class Solution {
public:
    vector<LL> min_count;
    vector<LL> dp;
    vector<int> a;
    
    LL solve(int pos){
        if( pos == a.size() ) return 0;
        if( dp[pos] != -1 ) return dp[pos];
        LL total = (a[pos] * min_count[pos] % MOD + solve( pos + min_count[pos]) % MOD ) % MOD;
        return dp[pos] = total;
    }
    
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        stack<pii> S;
        S.push( mp(0, n) );
        min_count = vector<LL>(n);
        for( int i = n - 1 ; i >= 0 ; --i ){
            while( !S.empty() && S.top().first >= A[i] ){
                S.pop();
            }
            min_count[i] = S.top().second - i;
            S.push(mp(A[i], i));
        }
        
        LL result = 0;
        a = A;
        dp = vector<LL>(n + 5 , -1);
        for( int i = 0 ; i < n ; ++i ){
            result = (result + solve(i) % MOD ) % MOD;
        }
        return result;
    }
};
