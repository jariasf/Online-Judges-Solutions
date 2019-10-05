/*******************************************
 ***Problema: Positions of Large Groups
 ***ID: 830
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
    	int n = S.size();
        vector<vector<int> > res;
        vector<int> aux(2,0);
        for( int i = 0 ; i < n ; ++i ){
            int j = i + 1;
            int cnt = 1;
            while( j < n && S[i] == S[j] ){
                cnt++;
                j++;
            }
            if( cnt > 2 ){
                aux[0] = i; aux[1] = j - 1;
                res.push_back(aux);
            }
            i = j - 1;
            
        }
        return res;
    }
};
