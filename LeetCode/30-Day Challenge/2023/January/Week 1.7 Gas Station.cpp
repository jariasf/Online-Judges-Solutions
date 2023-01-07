/*******************************************
 ***Problema: Gas Station
 ***ID: Week 1.7
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sz = gas.size();
        int sum = 0, index = 0, tot = 0;
        for( int i = 0 ; i < sz ; ++i ){
            sum += gas[i] - cost[i];
            tot += gas[i] - cost[i];
            if( sum < 0 ){
                index = i + 1;
                sum = 0;
            }
        }
        if( tot < 0 ) return -1;
        return index;
    }
};
