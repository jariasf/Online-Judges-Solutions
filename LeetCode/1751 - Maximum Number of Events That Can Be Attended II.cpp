/*******************************************
 ***Problema: Maximum Number of Events That Can Be Attended II
 ***ID: 1751
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define pii pair<int ,int>
#define mp make_pair

class Solution {
public:
    vector<int> next;
    void pre_cal(vector<vector<int> > &v){
        vector<pii> s, e;
        for(int i = 0 ; i < v.size(); ++i ){
            vector<int> cur = v[i];
            s.push_back(mp(cur[0], i));
            e.push_back(mp(cur[1], i));
        }
        sort(e.begin(), e.end());
        next = vector<int>(e.size() + 1, -1);
        int i = 0 , j = 0;
        while(i < s.size() && j < e.size() ){
            if( e[j].first < s[i].first ){
                next[e[j].second] = s[i].second;
                j++;
            }else{
                i++;
            }
        }
        
        for(int i = 0 ; i < e.size(); ++i ){
            if( next[e[i].second] == -1 ){
                next[e[i].second] = e.size();
            }
        }
    }
    
    vector<vector<int> > dp;
    int N;
    vector<vector<int> > v;
    int solve(int pos, int k){
        if(k < 0) return -(1<<30);
        if(pos == N ){
            return 0;
        }
        if( dp[pos][k] != -1 ) return dp[pos][k];
        int res = solve(pos + 1, k);
        res = max(res, v[pos][2] + solve(next[pos], k - 1));
        return dp[pos][k] = res;
    }    
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        pre_cal(events);
        N = events.size();
        v = events;
        dp = vector<vector<int> >(N + 1, vector<int>(k + 1, -1));
        return solve(0, k);
    }
};
