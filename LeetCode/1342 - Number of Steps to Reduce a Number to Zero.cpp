/*******************************************
 ***Problema: Number of Steps to Reduce a Number to Zero
 ***ID: 1342
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int numberOfSteps (int num) {
        int cnt = 0;
        while( num > 0 ){
            if( num & 1 ) num--;
            else num /= 2;
            cnt++;
        }
        return cnt;
    }
};
