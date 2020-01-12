/*******************************************
 ***Problema: Convert Integer to the Sum of Two No-Zero Integers
 ***ID: 1317
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool checkZero(int x){
        while(x){
            int d = x % 10;
            x /= 10;
            if(d == 0 ) return true;
        }
        return false;
    }
    
    vector<int> getNoZeroIntegers(int n) {
        int left = 1;
        vector<int> res(2);
        while(left <= n){
            int dif = n - left;
            if(!checkZero(left) && !checkZero(dif)){
                res[0] = left;
                res[1] = dif;
                break;
            }
            left++;
        }
        return res;
    }
};
