/*******************************************
 ***Problema: Check If It Is a Good Array
 ***ID: 1250
 ***Juez: LeetCode
 ***Tipo: GCD - Coprimes
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    long long gcd( long long a , long long b ){
        if( b == 0 )return a;
        return gcd( b , a % b );
    }    
    
    bool isGoodArray(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 ) return nums[0] == 1;
        long long aux = gcd(nums[0], nums[1]);
        if( aux == 1 ) return true;
        for( int i = 2 ; i < n ; ++i ){
            aux = gcd(aux, nums[i]);
            if( aux == 1 ) return true;
        }
        return false;
    }
};
