/*******************************************
 ***Problema: Add to Array-Form of Integer
 ***ID: Week 3.1
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = num.size() - 1, carry = 0, val;
        vector<int> res;
        while( k > 0 || i >= 0 || carry ){
            val = carry;
            if( k > 0 )  val += k % 10, k /= 10;
            if( i >= 0 ) val += num[i--];
            res.push_back(val % 10);
            carry = val > 9 ? 1: 0;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
