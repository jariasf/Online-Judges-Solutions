/*******************************************
 ***Problem: Minimum Number of Frogs Croaking
 ***ID: 1419
 ***Judge: LeetCode
 ***Type: Ad hoc
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    int id(char c){
        string s = "croak";
        int i = 0;
        for( ; i < 5 ; ++i )
            if( s[i] == c ) break;
        
        return i;
    }
    
    int minNumberOfFrogs(string s) {
        int n = s.size();
        int maximum = -1;
        vector<int> cnt(5);
        for( int i = 0 ; i < n ; ++i ){
            int cur = id(s[i]);
            cnt[cur]++;
            if( cur > 0 && cnt[cur - 1] <  cnt[cur] ) 
                return -1;
            maximum = max(maximum, cnt[cur]);
            if( cur == 4 ){
                for( int j = 0 ; j < 5 ; ++j ){
                    if( cnt[j]-- < 0 ) return -1;    
                }
            }
        }
        
        for( int i = 0 ; i < 4 ; ++i ) 
            if( cnt[i] > 0 ) return -1;
        return maximum;
    }
};
