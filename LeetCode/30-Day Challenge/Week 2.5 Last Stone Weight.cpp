/*******************************************
 ***Problema: Last Stone Weight
 ***ID: Week2.5
 ***Juez: LeetCode
 ***Tipo: Priority Queue
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> Q;
        int n = stones.size();
        for( int i = 0 ; i < n ; ++i ) Q.push(stones[i]);
        while( Q.size() > 1 ){
            int y = Q.top(); Q.pop();
            int x = Q.top(); Q.pop();
            if( x != y ) Q.push(y - x);
        }
        return Q.size() == 1 ? Q.top() : 0;
    }
};
