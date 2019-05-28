/*******************************************
 ***Problema: Reveal Cards In Increasing Order
 ***ID: 950
 ***Juez: LeetCode
 ***Tipo: Sorting, Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        
        vector<int> res(n);
        vector<int> idx(n);
        for( int i = 0 ; i < n ; ++i ) idx[i] = i;
        int next = 0;
        int pot = 2;
        while(n){
            for( int i = 0 ; i < n; i += 2){
                res[idx[i]] = deck[next++];
            }
            if( n == 1)break;
            if( n & 1 ){
                n /= 2;
                int next_pos = 3;
                vector<int> idx2 = vector<int>(n);
                for( int i = 0 ; i < n - 1 ; ++i ){
                    idx2[i] = idx[next_pos];
                    next_pos += 2;
                }
                idx2[n - 1] = idx[1];
                idx = idx2;
            }else{
                n /= 2;
                int pos = 1;
                vector<int> idx2 = vector<int>(n);
                for( int i = 0 ; i < n; ++i ){
                    idx2[i] = idx[pos];
                    pos += 2;
                }
                idx = idx2;
            }
        }
        
        return res;
    }
};
