/*******************************************
 ***Problema: Boats to Save People
 ***ID: Week2.6
 ***Juez: LeetCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int left = 0, right = n - 1;
        int result = 0;
        while( left <= right ){
            if( people[left] + people[right] <= limit ){
                result++;
                left++; right--;
            }else if( people[right] <= limit ){
                result++;
                right--;
            }else if( people[left]  <= limit ){
                result++;
                left++;
            }
        }
        return result;
    }
};
