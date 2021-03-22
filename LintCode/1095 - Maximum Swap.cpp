/*******************************************
 ***Problema: Maximum Swap
 ***ID: 1095
 ***Juez: LintCode
 ***Tipo: Two pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size(), res = num, maxi = -1, left = -1, right = -1, max_index= -1;
        for( int i = n - 1 ; i >= 0 ; --i ){
            if( s[i] < maxi ){
                left = i; right = max_index;
            }else if( maxi < s[i]){
                maxi = s[i];     
                max_index = i;
            }
        }
        if( left != -1 ) swap(s[left], s[right]);
        res = stoi(s);
        return res;
    }
};
