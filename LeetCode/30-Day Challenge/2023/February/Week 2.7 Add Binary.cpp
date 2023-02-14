/*******************************************
 ***Problema: Add Binary
 ***ID: Week 2.7
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size(), n2 = b.size();
        int i = n1 - 1, j = n2 - 1, carry = 0;
        string res = "";
        while( i >= 0 || j >= 0 || carry){
            int val = carry;
            if( i >= 0 ) val += a[i] - '0'; 
            if( j >= 0 ) val += b[j] - '0';
            res += (val % 2) + '0';
            if( val > 1 ) carry = 1;
            else carry = 0;
            i--; j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
