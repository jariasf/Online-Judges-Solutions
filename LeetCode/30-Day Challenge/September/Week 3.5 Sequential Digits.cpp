/*******************************************
 ***Problema: Sequential Digits
 ***ID: Week3.5
 ***Juez: LeetCode
 ***Tipo: Math + Sorting | BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// BFS
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> Q;
        vector<int> res; 
        
        for( int i = 1 ; i < 10 ; ++i )
            Q.push(i);
        
        while( !Q.empty() ){
            int x = Q.front(); Q.pop();
            if( x >= low && x <= high ){
                res.push_back(x);
            }
            if(x > high ) break;
            if( x % 10 < 9 )
                Q.push(x * 10 + (x % 10) + 1 );
        }
        
        return res;
    }
};

// Math + Sorting
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res; 
        for( int i = 1 ; i < 10 ; ++i ){
            int val = i;
            while(val <= high && val % 10 < 9 ){
                val = val * 10 + (val % 10) + 1;
                if(val >= low && val <= high ){
                    res.push_back(val);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
