/*******************************************
 ***Problema: Happy Number
 ***ID: Week1.2
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n > 1 && seen.find(n) == seen.end()){
            seen.insert(n);
            int sum = 0;
            while(n){
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};
