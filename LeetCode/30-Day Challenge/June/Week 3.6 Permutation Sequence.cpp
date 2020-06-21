/*******************************************
 ***Problema: Permutation Sequence
 ***ID: Week3.6
 ***Juez: LeetCode
 ***Tipo: Brute force | Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;

    string getPermutation(int n, int k) {
        string s = "";
        for( int i = 1 ; i <= n ; ++i )
            s += to_string(i);
        
        if( k == 1 ) return s;
        LL K = k;
        int sz = s.size();
        vector<int> cnt(10, 0 );
        for( int i = 0 ; i < sz; ++i ) cnt[ s[i] - '0']++;
        string ans = "";

        vector<LL> fact(sz + 5 , 1LL);
        for( LL i = 2 ; i <= sz ; ++i )
            fact[i] = i * fact[ i - 1 ];
        
        for( int i = 0 ; i < sz ; ++i ){
            //Calculate interval for each possible value
            for( int j = 0 ; j < 10 ; ++j ){
                if( cnt[j] == 0 ) continue;
                LL range = fact[sz - i - 1];
                cnt[j]--;
                for( int w = 0 ; w < 10 ; ++w ){
                    if( cnt[w]> 0)
                        range /= fact[ cnt[w] ];    
                }  
                if( range >= K ){
                    ans += (char)( j + '0');
                    break;    
                }else{
                    K -= range;
                    cnt[j]++;
                }
            }
        }
        
        return ans;
    }
};
