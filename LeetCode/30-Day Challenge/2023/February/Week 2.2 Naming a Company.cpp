/*******************************************
 ***Problema: Naming a Company
 ***ID: Week 2.2
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// O(26*25/2*n'*|s|)
// n' is the number of strings for character c
class Solution {
public:
    typedef long long LL;
    LL distinctNames(vector<string>& ideas) {
        unordered_set<string> dict[26];
        for(string &s: ideas) dict[s[0]-'a'].insert(s.substr(1));
        LL res = 0;
        int intersect, cnt1, cnt2;
        for(int i = 0 ; i < 26 ; ++i){
            for(int j = i + 1 ; j < 26 ; ++j){
                if( dict[j].empty() || dict[i].empty()) continue;
                intersect = 0;
                for(string s:dict[i]){
                    if( dict[j].count(s) ) intersect++;
                }
                cnt1 = dict[i].size() - intersect;
                cnt2 = dict[j].size() - intersect;
                res += (LL) cnt1 * cnt2;
            }
        }

        return res * 2;
    }    
};


// O(n*26*|s|)
class Solution {
public:
    typedef long long LL;
    LL distinctNames(vector<string>& ideas) {
        vector<vector<int> > cnt(26, vector<int>(26));
        unordered_set<string> dict;
        for(string &s: ideas) dict.insert(s);

        for(string &s: ideas){
            char tmp = s[0];
            for(char c = 'a'; c <= 'z'; ++c){                
                s[0] = c;
                if(dict.count(s) == 0){
                    cnt[tmp - 'a'][c - 'a']++;
                }
            }
            s[0] = tmp;
        }
        LL res = 0;
        for(int i = 0 ; i < 26 ; ++i){
            for(int j = i + 1 ; j < 26 ; ++j){
                res += (LL)cnt[i][j] * cnt[j][i];
            }
        }

        return res * 2;
    }
};
