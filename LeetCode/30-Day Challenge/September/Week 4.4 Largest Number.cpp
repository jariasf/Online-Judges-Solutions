/*******************************************
 ***Problema: Largest Number
 ***ID: Week4.4
 ***Juez: LeetCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    static bool cmp(string &s1, string &s2){
        return s1 + s2 > s2 + s1;
    }
    
    string largestNumber(vector<int>& nums) {        
        vector<string> v;
        
        for(int x : nums )
            v.push_back(to_string(x));
        sort(v.begin(), v.end(), cmp);
        
        string res = "";
        for(string s:v )
            res += s;
        
        int start_index = 0;
        while(start_index < res.size() - 1 && res[start_index] == '0')
            start_index++;
        
        return res.substr(start_index);
    }
};
