/*******************************************
 ***Problema: H-Index
 ***ID: Week2.4
 ***Juez: LeetCode
 ***Tipo: Hashing | Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

//O(n)
class Solution {
public:
    int hIndex(vector<int>& citations){
        int n = citations.size();
        vector<int> hash(n + 1);
        for(int val:citations){
            if( val > n ) val = n;
            hash[val]++;
        }
        int cnt = 0;
        for(int i = n ; i >= 0 ; --i ){
            cnt += hash[i];
            if( cnt >= i )        
                return i;
        }
        return 0;
    }
};

//O(nlogn)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int h_index = 0;
        for(int val:citations){
            if( val >= h_index + 1 )
                h_index++;
            else
                break;
        }
        return h_index;
    }
};
