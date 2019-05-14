/*******************************************
 ***Problema: Vowel Spellchecker
 ***ID: 966
 ***Juez: LeetCode
 ***Tipo: Data Structures, Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    string toLower(string s){
        for( int i = 0 ; i < s.size(); ++i ){
            s[i] = tolower(s[i]);
        }
        return s;
    }
    
    string noVowel(string s){
        for( int i = 0 ; i < s.size(); ++i ){
            if( s[i] == 'a' || s[i] =='e' || s[i] =='i' || s[i] == 'o' || s[i] == 'u'){
                s[i] = '_';
            }
        }
        return s;
    }
    
    vector<string> spellchecker(vector<string>& wordList, vector<string>& queries) {
        unordered_set<string> hash;
        unordered_map<string, string > cap, voc;
        int n = wordList.size();
        for( int i = 0 ; i < n ; ++i ){
            hash.insert(wordList[i]);
            string l = toLower(wordList[i]);
            if( cap.find(l) == cap.end() ){
                cap[l] = wordList[i];
            }
            l = noVowel(l);
            if( voc.find(l) == voc.end() ){
                voc[l] = wordList[i];
            }
        }
        
        vector<string> res(queries.size(), "");
        for( int i = 0 ; i < queries.size(); ++i ){
            string s = queries[i];
            if( hash.find(s) != hash.end() ){
                res[i] = s;
            }else{
                string l = toLower(s);
                if( cap.find(l) != cap.end() ){
                    res[i] = cap[l];
                }else{
                    l = noVowel(l);
                    if( voc.find(l) != voc.end() ){
                        res[i] = voc[l];
                    }
                }
            }
        }
        
        return res;
    }
};
