/*******************************************
 ***Problema: Shortest Common Supersequence
 ***ID: 1092
 ***Juez: LeetCode
 ***Tipo: Dynamic Programing - LCS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define MAX 1005
    int dp[MAX][MAX];
    int lcs(string &s1, string &s2, int posA, int posB){
        if( posA == s1.size() || posB == s2.size() )
            return dp[posA][posB] = 0;
        
        if( dp[posA][posB] != -1 ) return dp[posA][posB];
        
        int result = 0;
        if( s1[posA] == s2[posB] ){
            result = 1 + lcs(s1, s2, posA + 1, posB + 1);
        }else{
            result =  max( lcs(s1, s2, posA + 1, posB ), lcs(s1, s2, posA, posB + 1));
        }
        
        return dp[posA][posB] = result;
    }
    
    void get_lcs(string &s1, string &s2, int posA, int posB, int maxi, string &res ){
        if( posA == s1.size() || posB == s2.size() ){
            return;
        }
        if( s1[posA] == s2[posB] && 1 + dp[posA + 1][posB + 1] == maxi ){
            res += s1[posA];
            get_lcs(s1, s2, posA + 1, posB + 1, maxi - 1, res );
        }else if( dp[posA + 1][posB] == maxi ){
            get_lcs(s1, s2, posA + 1, posB, maxi, res);
        }else{
            get_lcs(s1, s2, posA, posB + 1, maxi, res);
        }
    }
    
    
    string shortestCommonSupersequence(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        int maxi = lcs(s1, s2, 0, 0);
        string LCS = "";
        get_lcs(s1, s2, 0, 0, maxi, LCS);
        int lcs_index = 0, posA =0, posB = 0;
        string result = "";
        while( posA < s1.size() && posB < s2.size() && lcs_index < LCS.size() ){
            if( s1[posA] == LCS[lcs_index] ){
                while( posB < s2.size() && s2[posB] != LCS[lcs_index] ){
                    result += s2[posB++];
                }
                result += s1[posA];
                posA++; posB++; lcs_index++;
            }else{
                result += s1[posA++];
            }
        }

        while( posA < s1.size() ) result += s1[posA++];
        while( posB < s2.size() ) result += s2[posB++];
        
        return result;
    }
};
