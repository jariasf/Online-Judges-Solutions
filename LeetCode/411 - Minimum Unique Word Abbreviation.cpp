/*******************************************
 ***Problema: Minimum Unique Word Abbreviation
 ***ID: 411
 ***Juez: LeetCode
 ***Tipo: Bitmaks|DFS + Priority Queue
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param target: a target string 
     * @param dictionary: a set of strings in a dictionary
     * @return: an abbreviation of the target string with the smallest possible length
     */
    #define pii pair<int, string>
    string minAbbreviation(string &target, vector<string> &dictionary) {
        priority_queue<pii, vector<pii>, greater<pii> > Q;
        generateAbbreviations(Q, target);
        string res = "";
        while( !Q.empty() ){
            pii cur = Q.top(); Q.pop();
            string abbr = cur.second;
            bool correct = true;
            for( int i = 0 ; i < dictionary.size(); ++i ){
                if( validWordAbbreviation(dictionary[i], abbr) ){
                    correct = false;
                    break;
                }
            }
            if( correct ){
                res = abbr;
                break;
            }
        }
        return res;
    }
    
    void generateAbbreviations(priority_queue<pii, vector<pii>, greater<pii>> &Q, string &word) {
        int n = word.size();
        for( int i = 0 ; i < (1<<n) ; ++i ){
            string cur = "";
            int cnt = 0;
            for( int j = 0 ; j < n ; ++j ){
                if( i & (1<<j) ){
                    if( cnt > 0 ) cur += to_string(cnt);
                    cnt = 0;
                    cur += word[j];
                }else{
                    cnt++;
                }
            }
            if( cnt > 0 ) cur += to_string(cnt);
            Q.push(make_pair(cur.size(), cur));
        }
    }    
    
    bool validWordAbbreviation(string &word, string &abbr) {
        int i = 0, j = 0;
        while(i < abbr.size() && j < word.size() ){
            int val = 0;
            if( abbr[i] == '0') return false;
            while(i < abbr.size() && isdigit(abbr[i]) ){
                val = val * 10 + (abbr[i] - '0');
                i++;
            }
            if( val > 0 ){
                j += val;
            }else if( abbr[i++] != word[j++] )
                return false;
        }
        return i == abbr.size() && j == word.size();
    }    
};
