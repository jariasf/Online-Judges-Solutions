/*******************************************
 ***Problema: Capacity To Ship Packages Within D Days
 ***ID: Week 4.1
 ***Juez: LeetCode
 ***Tipo: Binary search the answer
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool possible(vector<int>& weights, int days, int capacity){
        int sum = 0;
        for(int weight:weights){
            if( weight > capacity ) return false;
            sum += weight;
            if( sum > capacity){
                days--;
                sum = weight;
            }
        }
        if( sum > 0 ) days--;
        return days >= 0;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = std::accumulate(weights.begin(), weights.end(), 0), mid;

        while( left < right){
            mid = (left + right)/2;
            if(possible(weights, days, mid)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return right;
    }
};
