/*******************************************
 ***Problem: HTML Entity Parser
 ***ID: 1410
 ***Judge: LeetCode
 ***Type: Ad hoc
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<string> key = {"&quot;" , "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;"};
    vector<string> val = {"\"", "'", "&", ">", "<", "/"}; 
    string entityParser(string text) {
        int n = text.size();
        string res = "";
        for( int i = 0 ; i < n ; ++i ){
            if( text[i] == '&'){
                int j = i;
                int k = 0 ;
                bool found = false;
                for( ; k < 6 ; ++k ){
                    string cur = key[k];
                    int ii = 0;
                    for( ; ii < cur.size() && j + ii < n ; ++ii ){
                        if( text[j + ii] != cur[ii] ){
                            break;
                        }
                    }
                    if( ii == cur.size() ){
                        res += val[k];
                        i = j + cur.size() - 1;
                        found = true;
                        break;
                    }
                }
                if( !found )
                    res += text[i];
            }else
                res += text[i];
        }
        return res;
    }
};
