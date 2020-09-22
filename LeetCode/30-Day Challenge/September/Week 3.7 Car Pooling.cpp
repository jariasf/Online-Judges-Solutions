/*******************************************
 ***Problema: Car Pooling
 ***ID: Week3.7
 ***Juez: LeetCode
 ***Tipo: Sweep Line
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define MAX 1005

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<int> v(MAX);
        for( int i = 0 ; i < n ; ++i ){
            int num = trips[i][0], start = trips[i][1], end = trips[i][2];
            v[start] += num;
            v[end] -= num;
        }
        
        int sum = 0;
        for( int i = 0 ; i < MAX ; ++i ){
            sum += v[i];
            if( sum > capacity ) return false;
        }
        return true;
    }
};
