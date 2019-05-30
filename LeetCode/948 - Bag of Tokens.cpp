/*******************************************
 ***Problema: Bag of Tokens
 ***ID: 948
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int n = tokens.size();
        if( n == 0 ) return 0;
        sort(tokens.begin(), tokens.end());
        int result = 0;
        if( P < tokens[0] ) return 0;
        int i = 0, j = n - 1;
        int cnt = 0;
        while( i <= j ){
            while( i <= j && tokens[i] <= P ){
                P -= tokens[i];
                cnt++;
                i++;
            }
            result = max( result, cnt );
            if( cnt > 0 ){
                P += tokens[j--];
                cnt--;
            }
        }
        return result;
    }
};
