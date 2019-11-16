/*******************************************
 ***Problema: Sentence Similarity 
 ***ID: 471
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming + Prefix Table
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> prefixTable(string &s){
        int n = s.size();
        vector<int> p(n + 1, 0);
        p[0] = -1;
        int i = 1, j = 0;
        while(i < n){
            while(j >= 0 && s[j] != s[i] ) j = p[j];
            i++; j++;
            p[i] = j;
        }
        return p;
    }
    
    /**
     * @param s: a string
     * @return: return a string
     */
    string encode(string &s) {
        int n = s.size();
        vector<vector<string> > dp(n + 5, vector<string>(n + 5) );

        for( int l = 1 ; l <= n ; ++l ){
            for( int i = 0 ; i + l <= n ; ++i ){
                int cnt = 1;
                string cur = s.substr(i, l);
                int j = i + l - 1;
                dp[i][i + l - 1] = cur;
                for( int k = i ; k < j ; ++k ){
                    if( dp[i][k].size() + dp[k + 1][j].size() < dp[i][j].size() ){
                        dp[i][j] = dp[i][k] + dp[k + 1][j];
                    }
                }
                
                vector<int> p = prefixTable(cur);
                int short_pref = cur.size() - p[p.size() - 1];
                if( cur.size() % short_pref == 0 ){
                    int cnt = cur.size()/short_pref;
                    if( cnt > 1 ){
                        string abbr = to_string(cnt) + "[" + dp[i][i + short_pref-1] + "]";
                        if( abbr.size() < dp[i][j].size() )
                            dp[i][j] = abbr;
                    }
                }
            }
        }
        
        return dp[0][n - 1];
    }
};

/*
"abababaabababababcdefgabcdefgabcdefgabcdefgabcdefgabcdefgabcdefgabcdefgabcdefgabcdefgabcdefgabcdefgabcdefgabcdefgabcdefg"
"abbbabbbcabbbabbbc"
*/
