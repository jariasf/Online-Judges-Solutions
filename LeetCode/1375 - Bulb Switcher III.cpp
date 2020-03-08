/*******************************************
 ***Problem: Bulb Switcher III
 ***ID: 1375
 ***Judge: LeetCode
 ***Type: Ad hoc
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size();
        int res = 0, maxi = 0;
        for( int i = 0 ; i < n ; ++i ){
            maxi = max( maxi, light[i]);
            if( maxi == i + 1 ) res++;
        }
        return res;
    }
};
