/*******************************************
 ***Problema: Rearrange Words in a Sentence
 ***ID: 1451
 ***Juez: LeetCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int, int>
    #define mp make_pair
    string arrangeWords(string text) {
        stringstream ss(text);
        string s;
        vector<pii> v;
        vector<string> val;
        int idx = 0;
        while(ss>>s){
            if( isupper(s[0]) ) s[0] = tolower(s[0]); 
            v.push_back( mp((int)s.size(), idx++ ));
            val.push_back(s);
        }
        sort(v.begin(), v.end());
        string res = "";
        for( int i = 0 ; i < v.size(); ++i ){
            s = val[v[i].second];
            if( i == 0){
                s[0] = toupper(s[0]);
            }
            if(i) res += " ";
            res += s;
        }
        return res;
    }
};
