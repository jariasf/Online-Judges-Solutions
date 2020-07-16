/*******************************************
 ***Problema: Reverse Words in a String
 ***ID: Week2.8
 ***Juez: LeetCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Space: O(1)
class Solution {
public:
    string reverseWords(string s){
        reverse(s.begin(), s.end());
        int n = s.size();
        for(int left = 0, right = 0; right < n; ++right ){
            while( right < n && s[right] == ' ')
                right++;
            int word_size = 0;
            while( right < n && s[right] != ' '){
                right++;
                word_size++;
            }
            reverse(s.begin() + left, s.begin() + right);
            left += word_size + 1;
        }
        
        for( int i = n - 1 ; i >= 0 && s[i] == ' ' ; --i )
            s.pop_back();
        
        return s;
    }
};


// Space: O(n)
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> v;
        while(ss>>s){
            v.push_back(s);
        }
        
        reverse(v.begin(), v.end());
        s = "";
        
        for( int i = 0 ; i < v.size(); ++i ){
            if(i)
                s += " ";
            s += v[i];
        }
        
        return s;
    }
};
