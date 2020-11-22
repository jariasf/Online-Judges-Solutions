/*******************************************
 ***Problema: Smallest String With A Given Numeric Value
 ***ID: 1663
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        for( int i = 0 ; i < n ; ++i ) res += "a";
        k -= n;
        int i = n - 1;
        while(k > 0 ){
            k++;
            int mini = min(k, 26);
            res[i] = (char)(mini - 1 + 'a');
            k -= mini;
            i--;
        }
        return res;
    }
};
