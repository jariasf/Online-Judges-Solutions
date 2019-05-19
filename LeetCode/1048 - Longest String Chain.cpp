/*******************************************
 ***Problema: Longest String Chain
 ***ID: 1048
 ***Juez: LeetCode
 ***Tipo: Sorting, Hashing, DP
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pis pair<int, string>
    #define mp make_pair
    #define MAX 1005
    vector<int> adj[MAX];

    bool possible(string a, string b ){

        if( abs( (int)a.size() - (int)b.size()) != 1 ) return false;

        if( a.size() < b.size() ){
            string tmp = b;
            b = a;
            a = tmp;
        }

        vector<int> cnt(26);
        for( int i = 0 ; i < a.size(); ++i ){
            cnt[ a[i] - 'a']++;
        }

        for( int j = 0 ; j < b.size(); ++j ){
            if( cnt[ b[j] - 'a' ] > 0 ){
                cnt[ b[j] - 'a' ]--;
            }else
                return false;
        }

        int aux = 0;
        for( int i = 0 ; i < a.size(); ++i ){
            if( cnt[i] > 1 ) return false;
            if( cnt[i] == 1 ) aux++;
        }

        return aux <= 1;
    }

    void create_graph(vector<string> &words){
        int n = words.size();
        for( int i = 0 ; i < MAX ; ++i ){
            adj[i].clear();
        }
        vector<int> hash[18];
        for( int i = 0 ; i < n ; ++i ){
            hash[ words[i].size() ].push_back(i);
        }

        for( int k = 1 ; k <= 16 ; ++k ){
            for( int i = 0 ; i < hash[k].size(); ++i ){
                int ii = hash[k][i];
                for( int j = 0 ; j < hash[k + 1].size(); ++j ){
                    int jj = hash[k + 1][j];
                    if( possible( words[ii], words[jj])){
                        adj[ii].push_back(jj);
                    }
                }
            }
        }
    }

    int dp[MAX];
    int solve(int u){

        if( adj[u].size() == 0 ){
            return 1;
        }

        if( dp[u] != -1){
            return dp[u];
        }
        int res = 0;
        for( int i = 0 ; i < adj[u].size(); ++i ){
            int v = adj[u][i];
            res = max( res, 1 + solve(v));
        }

        return dp[u] = res;
    }

    int longestStrChain(vector<string>& words) {
        create_graph(words);
        int n = words.size();
        memset(dp, -1,sizeof(dp));
        int res = 0;
        for( int i = 0 ; i < n ; ++i ){
            res = max( res, solve(i));
        }
        return res;
    }
};
