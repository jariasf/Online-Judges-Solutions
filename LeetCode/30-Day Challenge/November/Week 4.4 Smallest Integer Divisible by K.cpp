/*******************************************
 ***Problema: Smallest Integer Divisible by K
 ***ID: Week4.4
 ***Juez: LeetCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    int smallestRepunitDivByK(int K) {
        if( K % 2 == 0 ) return -1;
        if( K == 1 ) return 1;
        vector<int> v(100000, 0);
        LL val = 1;
        v[0] = 1;
        for( int i = 1; i < 100000 ; ++i  ){
            val = val * 10;
            val %= K;
            v[i] = val;
        }
        
        int result = 0;
        LL sum = 0;
        for( int i = 0 ; i < 100000 ; ++i ){
            sum = sum + v[i];
            sum %= K;
            result++;
            if( sum == 0 ) return result;
        }
        return -1;
    }
};
