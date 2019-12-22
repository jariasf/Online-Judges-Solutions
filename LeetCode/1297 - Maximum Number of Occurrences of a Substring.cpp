/*******************************************
 ***Problema: Maximum Number of Occurrences of a Substring
 ***ID: 1297
 ***Juez: LeetCode
 ***Tipo: Sliding Window + Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool correctLetters(vector<int> &cnt, int maxLetters){
        int dif = 0;
        for( int i = 0 ; i < cnt.size(); ++i ){
            if( cnt[i] > 0 ) dif++;
        }
        return dif <= maxLetters;
    }
    
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> hash;
        vector<int> cnt(26, 0);
        int n = s.size();
        for(int left = 0, right = 0; right < n ; ++right){
            cnt[ s[right] - 'a']++;
            while(right - left + 1 > minSize || (left <= right && !correctLetters(cnt, maxLetters) ) ){
                cnt[s[left] - 'a']--;
                left++;
            }
            if( right - left + 1 >= minSize ){
                hash[s.substr(left, right - left + 1)]++;
            }
        }
        int maxi = 0;
        for( auto it:hash ){
            maxi = max( maxi, it.second);
        }
        return maxi;
    }
};
