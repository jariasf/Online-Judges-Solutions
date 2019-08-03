/*******************************************
 ***Problema: Two Sum
 ***ID: 56
 ***Juez: LintCode
 ***Tipo: Hashing | Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n = numbers.size();
        unordered_map<int, int> hash;
        vector<int> res(2);
        for( int i = 0 ; i < n ; ++i ){
            if( hash.find(target - numbers[i]) != hash.end() ){
                res[0] = hash[target-numbers[i]];
                res[1] = i;
            }
            hash[numbers[i]] = i;
        }
        return res;
    }
};
