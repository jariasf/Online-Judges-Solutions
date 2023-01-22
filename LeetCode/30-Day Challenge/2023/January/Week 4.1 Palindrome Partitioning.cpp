/*******************************************
 ***Problema: Palindrome Partitioning
 ***ID: Week 4.1
 ***Juez: LeetCode
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    bool isPalindrome(string &s, int left, int right){
        while(left < right){
            if( s[left] != s[right - 1]) return false;
            left++; right--;
        }
        return true;
    }

    void backtrack(vector<vector<string>> &res, vector<string> current, string &s, int pos ){
        int n = s.size();
        if( pos == n ){
            res.push_back(current);
            return;
        }

        string pal = "";
        for(int i = pos ; i < n ; ++i ){
            pal += s[i];
            if( isPalindrome(s, pos, i + 1)){
                //current.push_back(s.substr(pos, i - pos + 1));
                current.push_back(pal);
                backtrack(res, current, s, i + 1);
                current.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> current;
        backtrack(res, current, s, 0);
        return res;
    }
};
