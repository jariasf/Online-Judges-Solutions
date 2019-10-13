/*******************************************
 ***Problema: Maximum Equal Frequency
 ***ID: 1224
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        unordered_map<int, int> cnt;
        int maximum = 0;
        for( int i = 0 ; i < nums.size(); ++i ){
            int last_cnt = cnt[nums[i]];
            cnt[ nums[i] ]++;
            int next_cnt = last_cnt + 1;
            //if value was already counted
            if( freq.find(last_cnt) != freq.end() ){
                freq[last_cnt]--;
                if( freq[last_cnt] == 0 )
                    freq.erase(last_cnt);    
            }
            freq[next_cnt]++;
            
            // if two keys
            if( freq.size() == 2 ){
                vector<int> keys;
                for( auto it:freq ){
                    keys.push_back(it.first);
                }
                if( keys[0] > keys[1] ) swap(keys[0], keys[1]);
                if( keys[0] == 1 ){
                    int sz0 = freq[keys[0]], sz1 = freq[keys[1]];
                    if( sz0 == 1 )
                        maximum = max( maximum, keys[1] * sz1 );
                }
                if(keys[0] + 1 == keys[1] ){
                    int sz0 = freq[keys[0]], sz1 = freq[keys[1]];
                    if( sz1 == 1 ){
                        maximum = max(maximum, keys[0] * sz0 + (keys[1] - 1) * sz1  );
                    }
                }
            }else if( freq.size() == 1 ){
                int key, value;
                for( auto it:freq ){
                    key = it.first;
                    value = it.second;
                }
                if( key == 1 ){
                    maximum = max(maximum, (key) * (value - 1) );
                }else{
                    maximum = max(maximum, key - 1 );
                }
            }
        }        
        return 1 + maximum;
        
    }
};
