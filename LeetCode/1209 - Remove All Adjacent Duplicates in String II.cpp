/*******************************************
 ***Problema: Remove All Adjacent Duplicates in String II
 ***ID: 1209
 ***Juez: LeetCode
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    string removeDuplicates(string s, int k) {
        int n = s.size();
        vector<pii> S;
        for( int i = 0 ; i < n ; ++i ){
            if( S.size() > 0 ){
                int c = S[S.size() - 1].first;
                if( s[i] == c ){
                    int cnt = S[S.size() - 1].second + 1; 
                    S[S.size() - 1].second = cnt;
                    if( cnt == k ){
                        S.pop_back();
                    }
                }else{
                    S.push_back(mp(s[i], 1));
                }
            }else{
                S.push_back(mp(s[i], 1));
            }
        }
        string res = "";
        for( int i = 0 ; i < S.size(); ++i ){
            for( int j = 0 ; j  < S[i].second ; ++j )
                res += (char)S[i].first;
        }
        return res;
    }
};
