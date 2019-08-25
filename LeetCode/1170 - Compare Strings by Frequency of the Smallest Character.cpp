/*******************************************
 ***Problema: Compare Strings by Frequency of the Smallest Character
 ***ID: 1170
 ***Juez: LeetCode
 ***Tipo: Sorting + Binary Seach
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    vector<int> convert(vector<string> &v ){
        vector<int> res(v.size());
        for( int i = 0 ; i < v.size(); ++i ){
            string s = v[i];
            vector<int> cnt(27);
            for( int j = 0 ; j < v[i].size(); ++j ){
                cnt[ v[i][j] - 'a']++;
            }
            for( int j = 0 ; j < 27 ; ++j ){
                if( cnt[j] > 0 ){
                    res[i] = cnt[j];
                    break;
                }
            }
        }
        return res;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> q = convert(queries);
        vector<int> w = convert(words);
        sort( w.begin(), w.end() );
        vector<int> res(q.size());
        for( int i = 0 ; i < q.size(); ++i ){
            int idx = lower_bound(w.begin(), w.end(), q[i] + 1) - w.begin();
            if( idx >= 0 && idx < w.size() && w[idx] > q[i] ){
                res[i] = w.size() - idx;
            }
        }
        return res;
    }
};
