/*******************************************
 ***Problema: Calculate Maximum Value
 ***ID: 719
 ***Juez: LintCode
 ***Tipo: Brute force | Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param str: the given string
     * @return: the maximum value
     */
    vector<int> memo;
    int solve(string &s, int pos){
        if( pos == -1 )
            return 0;

        if( memo[pos] != -1 )
            return memo[pos];

        return memo[pos] = max(s[pos] - '0' + solve(s, pos - 1), (s[pos] - '0') * solve(s, pos - 1) );
    }

    int calcMaxValue(string &str) {
        memo = vector<int>(str.size(), -1);
        return solve(str, str.size() - 1);
    }
};
