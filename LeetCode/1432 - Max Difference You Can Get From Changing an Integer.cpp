/*******************************************
 ***Problem: Max Difference You Can Get From Changing an Integer
 ***ID: 1432
 ***Judge: LeetCode
 ***Type: Greedy
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string s2 = s;
        
        for( int i = 0 ; i < s.size(); ++i ){
            if( s[i] != '9'){
                char tmp = s[i];
                for( int j = i; j < s.size(); ++j ){
                    if( s[j] == tmp ){
                        s[j] = '9';
                    }
                }
                break;
            }
        }
        
        if( s2[0] == '1'){
            for( int i = 1 ; i < s2.size(); ++i ){
                if( s2[i] != '1' && s2[i] != '0' ){
                    char tmp = s2[i];
                    for( int j = i; j < s2.size(); ++j ){
                        if( s2[j] == tmp ){
                            s2[j] = '0';
                        }
                    }
                    break;
                }
            }        
        }else{
            char tmp = s2[0];
            for( int i = 0 ; i < s2.size(); ++i ){
                if( s2[i] == tmp ) s2[i] = '1';
            }
        }

        int a = stoi(s), b = stoi(s2);
        return a - b;
    }
};
