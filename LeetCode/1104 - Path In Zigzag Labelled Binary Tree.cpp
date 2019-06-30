/*******************************************
 ***Problema: Path In Zigzag Labelled Binary Tree
 ***ID: 1104
 ***Juez: LeetCode
 ***Tipo: Binary Tree, Ancestor
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        
        int aux = label;
        int height = 0;
        while( aux > 0 ){
            height++;
            aux /= 2;
        }

        if( height % 2 == 0 ){
            int ini = 1<<(height - 1);
            int last = ini * 2 - 1;
            int dif = label - ini;
            label = last - dif;
        }
        
        vector<int> res;
        while( label > 0 ){
            res.push_back(label);
            label /= 2;
        }
        
        reverse(res.begin(), res.end());
        
        for( int i = 0 ; i < res.size(); ++i ){
            if( i & 1 ){
                int ini = 1<<i;
                int last = ini * 2 - 1;
                int dif = res[i] - ini;
                res[i] = last - dif;
            }
        }
        
        
        return res;
    }
};
