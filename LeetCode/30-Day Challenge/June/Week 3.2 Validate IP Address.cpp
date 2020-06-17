/*******************************************
 ***Problema: Validate IP Address
 ***ID: Week3.2
 ***Juez: LeetCode
 ***Tipo: String Manipulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool isIPv4(string s){
        int n = s.size();
        int cnt = 0, num = 0, len = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( s[i] == '.'){
                if( len == 0 ) return false;
                cnt++; num = len = 0;
            }else if(isdigit(s[i]) ){
                int d = s[i] - '0';
                if( num == 0 && len > 0 ) return false;
                num = num * 10 + d;
                len++;
                if( num > 255 ) return false;
            }else
                return false;
        }
        return cnt == 3 && len > 0;
    }
    
    bool isIPv6( string s ){
        int n = s.size();
        int cnt = 0, len = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( s[i] == ':'){
                if( len == 0 ) return false;
                cnt++; len = 0;
            }else if(isdigit(s[i]) || isalpha(s[i]) ){
                len++;
                if( len > 4 || (s[i] > 'F' && s[i] <= 'Z') || (s[i] > 'f' && s[i] <= 'z') ) return false;
            }else
                return false;
        }
        return cnt == 7 && len > 0;        
    }
    
    string validIPAddress(string ip) {
        if( isIPv4(ip) ) return "IPv4";
        else if( isIPv6(ip) ) return "IPv6";
        return "Neither";
    }
};
