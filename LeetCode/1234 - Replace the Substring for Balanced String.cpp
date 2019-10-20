/*******************************************
 ***Problema: Replace the Substring for Balanced String
 ***ID: 1234
 ***Juez: LeetCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    int getID(char c){
        if( c == 'Q') return 0;
        if( c == 'W') return 1;
        if( c == 'E') return 2;
        return 3;
    }

    bool correct(int req, vector<int> &cnt, int k){
        int total = 0;
        for( int i = 0 ; i < 4 ; ++i ){
            if(cnt[i] < 0 ) return false;
            if( cnt[i] < req ){
                total += req - cnt[i];
            }
        }
        return total <= k;
    }
    
    bool possible(string &s, vector<int> cnt, int k){
        int n = s.size();
        int req = n / 4;
        for( int i = 0 ; i < k ; ++i ){
            cnt[ getID(s[i]) ]--;
        }
        
        if( correct(req, cnt, k) ) return true;
        
        for( int i = k ; i < n ; ++i ){
            cnt[getID(s[i])]--;
            cnt[getID(s[i - k])]++;
            if( correct(req, cnt, k) ) return true;
        }
        return false;
    }
    
    int balancedString(string s) {
        int n = s.size();
        int req = n/4;
        
        vector<int> cnt(4);
        for( int i = 0 ; i < n ; ++i ){
            cnt[ getID(s[i])]++;
        }
        
        int total = 0;
        for( int i = 0 ; i < 4 ; ++i ){
            if( cnt[i] < req ){
                total += req - cnt[i];
            }
        }
        
        if(total == 0 ) return 0;
        
        int left = total, right = n + 1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(!possible(s, cnt, mid)){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return right;
    }
};
