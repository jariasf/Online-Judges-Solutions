/*******************************************
 ***Problem: Four Divisors
 ***ID: 1390
 ***Judge: LeetCode
 ***Type: Number Theory
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for( int x = 0 ; x < n ; ++x ){
            int tmp = nums[x];
            int l = sqrt(tmp);
            int s = 0, cnt = 0;
            for( int i = 1 ; i <= l ; ++i ){
                if( tmp % i == 0 ){
                    s += i;
                    cnt++;
                    if( i != tmp/i ){
                        s += tmp/i;
                        cnt++;
                    }
                    if( cnt > 4 ) break;
                }
            }
            if( cnt == 4 ){
                sum += s;
            }
        }
        return sum;
    }
};
