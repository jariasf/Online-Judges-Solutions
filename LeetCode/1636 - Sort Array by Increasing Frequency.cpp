/*******************************************
 ***Problema: Sort Array by Increasing Frequency
 ***ID: 1636
 ***Juez: LeetCode
 ***Tipo: Sorting + Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define pii pair<int,int>
#define mp make_pair
class Solution {
public:
    static bool comp(pii a, pii b){
        return a.second < b.second || (a.second == b.second && a.first > b.first);
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        vector<pii> v;
        unordered_map<int, int> hash;
        for(int val:nums )
            hash[val]++;
        
        for(auto it:hash )
            v.push_back(mp(it.first, it.second));
        
        sort(v.begin(), v.end(), comp);
        vector<int> res;
        for(pii p:v){
            for( int i = 0 ; i < p.second ; ++i )
                res.push_back(p.first);
        }
        return res;
    }
};
