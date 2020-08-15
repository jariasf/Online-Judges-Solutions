/*******************************************
 ***Problema: Iterator for Combination
 ***ID: Week2.6
 ***Juez: LeetCode
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Brute force
class CombinationIterator {
public:
    
    int bitcount(int x){
        int ones = 0;
        while(x > 0){
            ones++;
            x = x & (x - 1);
        }
        return ones;
    }
    
    string s;
    vector<string> v;
    int pos;
    CombinationIterator(string characters, int combinationLength) {
        v.clear();
        s = characters;
        int n = s.size();
        for( int i = 1 ; i < 1<<n ; ++i ){
            if( bitcount(i) == combinationLength ){
                string tmp = "";
                for( int j = 0 ; j < n ; ++j )
                    if( i & (1<<j))
                        tmp += s[j];
                v.push_back(tmp);
            }
        }
        pos = 0;
        sort(v.begin(), v.end());
    }
    
    string next(){
        return v[pos++];
    }
    
    bool hasNext() {
        return pos < v.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
