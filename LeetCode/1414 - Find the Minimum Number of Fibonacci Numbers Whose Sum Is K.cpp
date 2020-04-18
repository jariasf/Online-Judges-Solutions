/*******************************************
 ***Problem: Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
 ***ID: 1414
 ***Judge: LeetCode
 ***Type: Ad hoc
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    int findMinFibonacciNumbers(int k) {
        vector<LL> fib;
        fib.push_back(1); fib.push_back(1);
        for( int i = 2 ; ; ++i ){
            LL next = fib[i - 1] + fib[i - 2];
            if( next > k ) break;
            fib.push_back(next);
        }
        
        int res = 0;
        for( int i = fib.size() - 1; i >= 0 ; --i ){
            while( k >= fib[i] ){
                k -= fib[i];
                res++;
            }
        }
        return res;
    }
};
