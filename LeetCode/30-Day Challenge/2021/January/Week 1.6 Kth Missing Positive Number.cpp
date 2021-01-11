/*******************************************
 ***Problema: Kth Missing Positive Number
 ***ID: Week1.6
 ***Juez: LeetCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
        int val = 1, pos = 0, n = v.size();
        while(k > 0){
            while(pos < n && v[pos] == val ){
                pos++;
                val++;
            }
            val++;
            k--;
        }
        return val - 1;
    }
};
