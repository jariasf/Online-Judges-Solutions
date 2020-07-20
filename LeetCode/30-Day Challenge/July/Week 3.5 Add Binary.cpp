/*******************************************
 ***Problema: Add Binary
 ***ID: Week3.5
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1 , j = b.size() - 1;
        bool carry = 0;
        while( i >= 0 || j >= 0 ){
            int sum = carry;
            if( i >= 0 ) sum += a[i--] - '0';
            if( j >= 0 ) sum += b[j--] - '0';
            res += (sum & (1<<0)) > 0 ?"1":"0";
            carry = (sum & (1<<1)) > 0;
        }
        if( carry ) res += "1";
        reverse(res.begin(), res.end());
        return res;
    }
};
