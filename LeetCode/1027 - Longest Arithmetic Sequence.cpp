/*******************************************
 ***Problema: Longest Arithmetic Sequence
 ***ID: 1027
 ***Juez: LeetCode
 ***Tipo: Data Structures
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        
        unordered_map<int, queue<int> > hash;
        
        for( int i = 0 ; i<  n ; ++i ){
            hash[ A[i] ].push(i);
        }
        
        vector<int> seen(n, false);
        int maxi = 0;
        for( int i = 0 ; i < n ; ++i ){
            int cnt = 1;
            seen[i] = true;
            for( int j = i + 1 ; j < n ;++j ){
                int dif = A[j] - A[i];
                cnt = 2;
                int next = A[j] + dif;
                int pos = j;
                while( hash.find(next) != hash.end() ){
                    seen[pos] = true;
                    queue<int> Q = hash[next];
                    while( !Q.empty() && Q.front() <= pos ){
                        Q.pop();
                    }
                    if( !Q.empty() ){
                        cnt++;
                        pos = Q.front();
                        next = A[pos] + dif;
                    }else 
                        break;
                }
                maxi = max( maxi, cnt );
                
            }
        }
        return maxi;
    }
};
