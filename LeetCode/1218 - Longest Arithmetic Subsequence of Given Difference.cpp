/*******************************************
 ***Problema: Longest Arithmetic Subsequence of Given Difference
 ***ID: 1218
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        int longest = 1;
        unordered_map<int, int> cnt;
        for( int i = 0 ; i < n ; ++i ){
            cnt[arr[i]] = 1 + cnt[arr[i] - difference];
            longest = max(longest, cnt[arr[i]]);
        }
        return longest;
    }
};
