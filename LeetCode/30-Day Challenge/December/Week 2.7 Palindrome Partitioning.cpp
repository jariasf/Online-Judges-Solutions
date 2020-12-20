/*******************************************
 ***Problema: Palindrome Partitioning
 ***ID: Week2.7
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    
    
    vector<vector<string>> partition(string s) {
        int sz = s.size();
        vector<vector<bool> > dp = vector<vector<bool> >( sz, vector<bool>(sz , false ) );
        vector<vector<vector<string> > > ans = vector<vector<vector<string> > >( sz, vector<vector<string> >() );

        for( int i = 0 ; i < sz ; ++i ) dp[i][i] = true;
        
        for( int i = 0 ; i < sz ; ++i ){
            for( int j = 0 ; j <= i ; ++j ){
                string pal;
                if(j + 1 <= i - 1){
                    if( dp[j + 1][i - 1] && s[i] == s[j] ){
                        pal = s.substr(j , i - j + 1);
                        
                        dp[j][i] = true;
                    }
                }else if( s[j] == s[i] ){
                    dp[j][i] = true;
                    pal = string(1,s[j]);
                    if( i != j )
                        pal += s[i];
                }
                
                if( dp[j][i] ){
                    vector<vector<string> > last_result;
                    if( j - 1 >= 0 ){
                        last_result = ans[j - 1];
                        for( int k = 0 ; k < last_result.size() ; ++k ){
                            vector<string> current = last_result[k];
                            current.push_back(pal);
                            ans[i].push_back( current );
                        }
                    }else{
                        ans[i].push_back(  vector<string>( 1,pal) );
                    }
                }
            }
        }
        return ans[ans.size() - 1];
    }
};
