/*******************************************
 ***Problema: Largest Values From Labels
 ***ID: 1090
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector< pair<int,int> > v(values.size());
        
        for( int i = 0 ; i < values.size(); ++i )
            v[i] = make_pair(values[i], labels[i]);
        
        sort( v.rbegin(), v.rend());
        unordered_map<int,int> hash;
        int result = 0;

        for( int i = 0 ; i < v.size() && num_wanted > 0; ++i ){
            int value = v[i].first, label = v[i].second;
            if( hash[label] < use_limit ){
                result += value;
                hash[label]++;
                num_wanted--;
            }
        }
        
        return result;
    }
};
