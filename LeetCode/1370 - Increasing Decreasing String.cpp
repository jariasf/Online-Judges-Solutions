/*******************************************
 ***Problem: Increasing Decreasing String
 ***ID: 1370
 ***Judge: LeetCode
 ***Type: Hashing + Simulation
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string sortString(string s) {
        vector<int> cnt(26);
        for( int i = 0 ; i < s.size(); ++i ) cnt[ s[i] - 'a']++;
        string res = "";
        bool flag = true;
        while(res.size() < s.size() ){
            if( flag ){
                for( int i = 0 ; i < 26 ; ++i ){
                    if( cnt[i] > 0 ){
                        res += (char)(i + 'a');
                        cnt[i]--;
                    }
                }
            }else{
                for( int i = 25 ; i >= 0 ; --i ){
                    if( cnt[i] > 0 ){
                        res += (char)(i + 'a');
                        cnt[i]--;
                    }
                }
            }
            flag = !flag;
        }
        return res;
    }
};
