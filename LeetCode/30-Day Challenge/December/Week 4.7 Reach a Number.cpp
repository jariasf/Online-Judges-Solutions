/*******************************************
 ***Problema: Reach a Number
 ***ID: Week4.7
 ***Juez: LeetCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define INF 1<<30
    #define pii pair<int,int>
    #define mp make_pair
    int reachNumber(int target) {
        target = abs(target);
        int res = 0, sum = 0;
        while( sum < target ){
            res++;
            sum += res;
        }
        
        while( ( sum - target ) % 2 != 0 ) {
            res++;
            sum += res;
        }
        return res;
    }
};
