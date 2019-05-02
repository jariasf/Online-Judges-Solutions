/*******************************************
 ***Problema: Max Consecutive Ones III
 ***ID: 1004
 ***Juez: LeetCode
 ***Tipo: Deque, Maximum Window
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        deque<int> Q;
        int maxi = 0;
        if( K == 0 ){
            for( int i = 0 ; i < n ; ++i ){
                int j = i + 1;
                int cnt = 0;
                if( A[i] == 1 ){
                    cnt = 1;
                    while( j < n && A[j] == 1 ){ cnt++; j++;}
                    maxi = max( maxi, cnt );
                    i = j - 1;
                }
            }
            return maxi;
        }
        
        int k = 0;
        int right = 0;
        int i = 0;
        int left = 0;
        for( ; i < n && k < K ; ++i ){
            if( A[i] == 0 ){
                Q.push_back(i);
                k++;
            }
            right++;
        }
        for( ; i < n && A[i] == 1 ; ++i ) right++;        
        if( right > left ) maxi = right;
        while( i < n ){
            if( !Q.empty() && Q.size() == K ){
                int index = Q.front(); Q.pop_front();
                left = index + 1;
            }
            Q.push_back(i++);
            for( ;i < n && A[i] == 1; ++i );
            maxi = max( maxi, i - left);
        }
         
        return maxi;
    }
};
