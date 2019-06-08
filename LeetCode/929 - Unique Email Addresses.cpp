/*******************************************
 ***Problema: Unique Email Addresses
 ***ID: 929
 ***Juez: LeetCode
 ***Tipo: Strings + Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> hash;
        int n = emails.size();
        for( int i = 0 ; i < n; ++i ){
            string localname = "";
            string s = emails[i];
            int j = 0;
            bool cut = false;
            for( ; j < s.size(); ++j ){
                if( s[j] == '@' ){
                    break;
                }
                if( s[j] == '.') continue;
                else if( s[j] == '+' ) cut = true;
                else if( !cut )
                    localname += s[j];
            }
            
            while( j < s.size() ){
                localname += s[j++];
            }
            hash.insert(localname);
        }
        return hash.size();
    }
};
