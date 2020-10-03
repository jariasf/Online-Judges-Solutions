/*******************************************
 ***Problema: Alert Using Same Key-Card Three or More Times in a One Hour Period
 ***ID: 1604
 ***Juez: LeetCode
 ***Tipo: Hashing + Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int, string>
    #define mp make_pair
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<int> > hash;
        for(int i = 0 ; i < keyName.size(); ++i ){
            int h = ((keyTime[i][0] - '0')*10 + (keyTime[i][1]-'0'))*60;
            int m = (keyTime[i][3] - '0')*10 + (keyTime[i][4] - '0');
            hash[keyName[i]].push_back(h + m);
        }
        vector<string> res;
        for(auto it:hash ){
            vector<int> v = it.second;
            sort(v.begin(), v.end());
            for( int i = 2 ; i < v.size(); ++i ){
                if( v[i] - v[i - 2] <= 60 ){
                    res.push_back(it.first);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
