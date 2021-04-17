/*******************************************
 ***Problema: Product of Array Except Self
 ***ID: 1310
 ***Juez: LintCode
 ***Tipo: Prefix and Suffix products
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the product of all the elements of nums except nums[i].
     */
	//O(1) memory
	vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> products(n, 1);        
        for( int i = n - 2 ; i >= 0 ; --i )
            products[i] = products[i + 1] * nums[i + 1];

        int left = 1;        
        for( int i = 0 ; i < n ; ++i ){
            products[i] *= left;
            left *= nums[i];
        }
        return products;
    }

    //O(n) memory
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> right(n + 1, 1);
        for( int i = n - 1 ; i >= 0 ; --i )
            right[i] = right[i + 1] * nums[i];

        int left = 1;
        vector<int> products(n);
        for( int i = 0 ; i < n ; ++i ){
            products[i] = left * right[i + 1];
            left *= nums[i];
        }
        return products;
    }
};
