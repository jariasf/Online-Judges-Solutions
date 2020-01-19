/*******************************************
 ***Problema: Print Words Vertically
 ***ID: 1324
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<string> printVertically(string s) {
        int n = s.size();
        stringstream ss(s);
        vector<string> v;
        int max_len = 0;
        while(ss>>s){
            v.push_back(s);
            max_len = max(max_len, (int)s.size());
        }
        vector<string> res(max_len, "");
        for( int i = 0 ; i < max_len ; ++i ){
            string space = "";
            string word = "";
            for( int j = 0 ; j < v.size(); ++j ){
                string cur = v[j];
                if( cur.size() > i ){
                    word += cur[i];
                }else{
                    word += " ";
                }
            }
            
            int j = word.size() - 1;
            for(  ; j >= 0 ; --j ){
                if( word[j] != ' ') break;
            }
            for( int k = 0 ; k <= j ; ++k ){
                res[i] += word[k];    
            }
            
        }
        return res;   
    }
};
