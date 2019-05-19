/*******************************************
 ***Problema: Last Stone Weight
 ***ID: 1046
 ***Juez: LeetCode
 ***Tipo: Sorting | Priority Queue
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if( n == 1 ) return stones[0];
        priority_queue<int> Q;
        for( int i = 0 ; i < n ; ++i ){
            Q.push(stones[i]);
        }
        while( !Q.empty() && Q.size() > 1 ){
            int y = Q.top(); Q.pop();
            int x = Q.top(); Q.pop();
            if( x == y ) continue;
            Q.push(y - x);
        }
        if( Q.size() == 0 ) return 0;
        return Q.top();
    }
};
