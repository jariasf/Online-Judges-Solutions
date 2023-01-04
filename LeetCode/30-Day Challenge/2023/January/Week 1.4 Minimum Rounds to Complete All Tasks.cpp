/*******************************************
 ***Problema: Minimum Rounds to Complete All Tasks
 ***ID: Week 1.4
 ***Juez: LeetCode
 ***Tipo: Hashing - frequencies
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> hash;
        for(int num:tasks){
            hash[num]++;
        }
        int res = 0;
        for(auto it:hash){
            int cnt = it.second;
            if( cnt == 1 ) return -1;
            else 
                res += cnt/3 + (cnt % 3 > 0);
        }
        return res;
    }
};
