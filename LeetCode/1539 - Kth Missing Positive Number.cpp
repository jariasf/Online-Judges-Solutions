/*******************************************
 ***Problema: Kth Missing Positive Number
 ***ID: 1539
 ***Juez: LeetCode
 ***Tipo: Two Pointers | Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
	/*
	Input: arr = [2,3,4,7,11], k = 5
	Output: 9
	Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. 
	The 5th missing positive integer is 9.

	 0,1,2,3,4 ,5
	[2,3,4,7,11,12]  original
	[1,1,1,3,6 ,6]   missing numbers smaller than number at pos
	[1,2,3,4,5 ,6]   desired positions  

	We can obtain missing by: A[pos] - pos - 1

	Find position of value with missing numbers >= k using binary search

	Result of binary search -> pos = 4

	At this point we have 6 missing values to the left

	A[pos] = 11, pos = 4
	missing to the left = A[pos] - pos - 1 = 11 - 4 - 1 = 6

	We want k=5 so we have to move 11 to the left by substracting a value

	That value will be given by  (A[pos] - pos - 1) - k + 1  = 6 - 5 + 1 = 2

	We have to substract 2 from 11 ->  11 - 2 = 9 (the result we want)

	Let's simplify the solution

	A[pos] - ((A[pos] - pos - 1) - k + 1 ) = desired
	A[pos] - (A[pos] - pos - k)
	pos + k

	So we return pos + k
	*/    
    // O(log n) time and O(1) space
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size(), mid;
        while(left < right){
            mid = (left + right)/2;
            if( arr[mid] - mid - 1 < k ){
                left = mid + 1;
            }else
                right = mid;
        }
        return left + k;
    }

	// O(n) time and space
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size(), mid;
        while(left < right){
            mid = (left + right)/2;
            if( arr[mid] - mid - 1 < k ){
                left = mid + 1;
            }else
                right = mid;
        }
        return left + k;
    }
};
