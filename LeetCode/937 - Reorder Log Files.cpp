/*******************************************
 ***Problema: Reorder Log Files
 ***ID: 937
 ***Juez: LeetCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define pii pair<string,string>
#define mp make_pair
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pii> words;
        vector<string> digits;
        
        int n = logs.size();
        for( int i = 0 ; i < n ; ++i ){
            string s = logs[i];
            string id = "", value = "";
            int j = 0;
            for( ; j < s.size(); ++j ){
                if( s[j] == ' '){
                    j++;
                    break;
                }
                id += s[j];
            }
            
            if( isdigit(s[j]) ){
                digits.push_back(s);
                continue;
            }
            for(; j < s.size(); ++j ){
                value += s[j];
            }
            words.push_back(mp(value, id));
            
        }

        sort(words.begin(), words.end());
        vector<string> res;
        for( int i = 0 ;i < words.size(); ++i ){
            res.push_back( words[i].second + " " + words[i].first );
        }
        
        for( int i = 0 ; i < digits.size(); ++i ){
            res.push_back(digits[i]);
        }
        return res;
    }
};
