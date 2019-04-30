/****************************************************
 ***Problema: Capacity To Ship Packages Within D Days
 ***ID: 1011
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 ***************************************************/

class Solution {
public:
    
    bool possible(vector<int>& weights, int c, int D){
        int n = weights.size();
        int sum = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( weights[i] > c ) return false;
            sum += weights[i];
            if( sum > c ){
                sum = weights[i];
                D--;
            }
        }
        if( sum > 0 ) D--;
        return D >= 0;
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int sum = 0;
        int n = weights.size();
        for( int i = 0 ; i < n ; ++i ) sum += weights[i];
        int left = 0, right = sum + 1;
        while( left < right){
            int mid = (left + right)/2;
            if( possible(weights, mid, D) ){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return right;
    }
};
