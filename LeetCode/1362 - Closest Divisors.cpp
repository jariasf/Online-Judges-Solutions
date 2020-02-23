/*******************************************
 ***Problem: Closest Divisors
 ***ID: 1362
 ***Judge: LeetCode
 ***Type: Number Theory - Factors
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    vector<int> closestDivisors(int num) {
        int n1 = num + 1, n2 = num + 2;
        int l = sqrt(n2);
        int dif = 1<<30;
        vector<int> res(2);

        for( int i = 1; i <= l ; ++i ){
            if( n1 % i == 0 ){
                int a = i, b = n1/i;
                int c = abs( a - b );
                if( dif > c ){
                    dif = c;
                    res[0] = a; res[1] = b;
                }
            }            
            
            if( n2 % i == 0 ){
                int a = i, b = n2/i;
                int c = abs( a - b );
                if( dif > c ){
                    dif = c;
                    res[0] = a; res[1] = b;
                }
            }
        }        
        return res;
    }
};
