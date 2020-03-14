/*******************************************
 ***Problem: Repeated DNA Sequences
 ***ID: 187
 ***Judge: LeetCode
 ***Typr: Hashing + Sorting
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int n = s.size();
        if(n < 10) return res;

        unordered_map<string, int> hash;
        string cur = "";
        for( int i = 0 ; i < 10; ++i)
            cur += s[i];

        hash[cur]++;
        for( int i = 10 ; i < n; ++i ){
            cur += s[i];
            cur.erase(0, 1);
            hash[cur]++;
        }
        for(auto it: hash){
            if( it.second > 1 ) 
                res.push_back(it.first);
        }

        sort(res.begin(), res.end());
        return res;
    }
};



class Solution {
public:
    typedef long long LL;
    #define LEN 10
    
    int getValue(char c){
        if( c == 'A') return 1;
        if( c == 'G') return 2;
        if( c == 'C') return 3;
        return 4;
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<LL,int> hash;
        vector<string> result;
        int n = s.size();
        if( n < 10 ) return result;
        
        LL hash_value = 0, p = 1;
        for( int i = n - LEN ; i < n; ++i ){
            hash_value = hash_value * 10 + getValue(s[i]);
            p *= 10;
        }
        p /= 10;
        hash[hash_value]++;
        for( int i = n - LEN - 1 ; i >= 0 ; --i ){
            hash_value /= 10;
            hash_value = hash_value + getValue(s[i]) * p;
            hash[ hash_value]++;
            if( hash[hash_value] == 2 ){
                result.push_back(s.substr(i, LEN));
            }
        }
        return result;
    }
};
