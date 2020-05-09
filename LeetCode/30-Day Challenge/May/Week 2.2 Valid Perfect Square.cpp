/*******************************************
 ***Problema: Valid Perfect Square
 ***ID: Week2.2
 ***Juez: LeetCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        while( left <= right ){
            int mid = left + (right - left)/2;
            int div = num/mid, res = num % mid;
            
            if( res == 0 && div == mid ) 
                return true;
            
            if( mid <= div )
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

// Using long long
class Solution {
public:
    typedef long long LL;
    bool isPerfectSquare(int num) {
        LL left = 1, right = 1LL + num;
        while( left < right ){
            LL mid = left + (right - left)/2;
            LL p = mid * mid;
            if( p == num ) return true;
            if( p < num )
                left = mid + 1;
            else
                right = mid;
        }
        return false;
    }
};
