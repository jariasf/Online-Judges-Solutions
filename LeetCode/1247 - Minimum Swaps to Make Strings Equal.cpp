/*******************************************
 ***Problema: Minimum Swaps to Make Strings Equal
 ***ID: 1247
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if( n1 != n2 ) return -1;
        vector<int> cnt(2), cnt2(2);
        for( int i = 0 ; i < n1 ; ++i ){
            if( s1[i] != s2[i] ){
                cnt[s1[i] - 'x']++;
                cnt2[s2[i] - 'x']++;
            }
        }
        if( (cnt[0] != cnt2[1]) || (cnt[1] != cnt2[0]) ) return -1;
        if( (cnt[0] + cnt[1]) & 1 ) return -1;
        int result = cnt[0]/2 + cnt[1]/2 + cnt[0] % 2 + cnt[1] % 2;
        return result;
    }
};
