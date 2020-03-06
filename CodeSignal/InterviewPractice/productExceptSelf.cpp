/*******************************************
 ***Problem: Product Except Self
 ***Judge: CodeSignal
 ***Type: Dynamic Programming
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

//O(n) time, O(1) space
//[a, b, c, d]
// bcd + acd + abd + abc
// abc + d(ab + ac + bc)
// abc + d(ab + c(a + b))
// p = a, total = p + b
// p = ab, total = p + c*total
// p = abc, total = p + d*total
int productExceptSelf(std::vector<int> nums, int m) {
    int n = nums.size();
    int total = 1, p = 1;
    for(int i = 0 ; i < n - 1 ; ++i ){
        p = (p * nums[i] % m);
        total = (p + nums[i + 1] * total % m)%m;
    }
    return total;
}


//O(n) time, O(n) space
int productExceptSelf(std::vector<int> nums, int m) {
    int n = nums.size();
    vector<int> left(n + 5), right(n + 5);
    left[0] = right[n + 1] = 1;
    for( int i = 1 ; i <= n ; ++i )
        left[i] = (nums[i - 1] * left[i - 1] % m);

    for( int i = n ; i >= 1 ; --i )
        right[i] = (nums[i - 1] * right[i + 1] % m);

    int total = 0;
    for( int i = 1 ; i <= n ; ++i )
        total = total + ( left[i - 1] * right[i + 1] % m);
    
    return total % m;
}

