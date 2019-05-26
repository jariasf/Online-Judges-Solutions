/***********************************************
 ***Problema: Previous Permutation With One Swap
 ***ID: 1053
 ***Juez: LeetCode
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 **********************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        
        stack< pii > S;
        vector<int> prev_idx(n, -1);

        for( int i = 0 ; i < n ; ++i ){
            while( !S.empty() && S.top().first <= A[i] ){
                S.pop();
            }
                
            if( !S.empty() && S.top().first > A[i] ){
                prev_idx[i] = S.top().second;
            }
            S.push(mp(A[i], i));
        }
        
        int max_index = -1, index = -1;
        for( int i = n - 1 ; i >= 0 && i >= max_index ; --i ){
            if( prev_idx[i] > -1 ){
                if( max_index < prev_idx[i] ){
                    max_index = prev_idx[i];
                    index = i;
                }
            }
            
        }
        if( index != -1 )
            swap(A[index], A[max_index]);
        return A;
    }
};
