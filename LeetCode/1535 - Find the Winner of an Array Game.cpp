/*******************************************
 ***Problema: Find the Winner of an Array Game
 ***ID: 1535
 ***Juez: LeetCode
 ***Tipo: Deque
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int getWinner(vector<int>&v, int k) {
        int n = v.size();
        deque<int> Q;
        int maxi = 0;
        for( int i = 0 ; i < n ; ++i ){
            maxi = max( maxi, v[i]);
            Q.push_back(v[i]);
        }
        
        int last = -1, cnt = 0;
        while(cnt < k){
            int a = Q.front(); Q.pop_front(); 
            int b = Q.front(); Q.pop_front();
            if( a == maxi || b == maxi ) return maxi;
            if( a < b ){
                Q.push_front(b);
                Q.push_back(a);
                if( b == last ){
                    cnt++;
                }else
                    cnt = 1;
                if( cnt == k ) return b;
                last = b;                
            }else if( a > b ){
                Q.push_front(a);
                Q.push_back(b);
                if( a == last ){
                    cnt++;
                }else
                    cnt = 1;                
                if( cnt == k ) return a; 
                last = a;
            }
        }
        return -1;
    }
};
