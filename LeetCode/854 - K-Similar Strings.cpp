/*******************************************
 ***Problema: K-Similar Strings
 ***ID: 854
 ***Juez: LeetCode
 ***Tipo: BFS + Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param A: a string
     * @param B: a string
     * @return: the smallest K for which A and B are K-similar
     */
     
    int kSimilarity(string &A, string &B) {
        int n = A.size();
        queue<string> Q;
        Q.push(A);
        unordered_map<string, int> dist;
        dist[A] = 0;
        while( !Q.empty() ){
            A = Q.front(); Q.pop();
            int d = dist[A];
            if( A == B) return d; 
            int pos = 0;
            while(pos < n && A[pos] == B[pos]) pos++;
            for( int i = pos ; i < n ; ++i ){
                if( A[i] == B[pos] ){
                    swap(A[i], A[pos]);
                    if( A == B) return d + 1;
                    if( dist.find(A) == dist.end() ){
                        dist[A] = d + 1;
                        Q.push(A);
                    }
                    swap(A[i], A[pos]);
                }
            }
        }
        return 0;
    } 
};
