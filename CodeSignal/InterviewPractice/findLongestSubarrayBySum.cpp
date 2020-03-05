/*******************************************
 ***Problem: Find Longest Subarray By Sum
 ***Judge: CodeSignal
 ***Type: Two Pointers
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

std::vector<int> findLongestSubarrayBySum(int s, std::vector<int> arr) {
    int n = arr.size();
    int sum = 0, maxi = 0;
    vector<int> res(2, -1);
    for( int left = 0, right = 0; right < n ; ++right ){
        sum += arr[right];
        while( left < right && sum > s ){
            sum -= arr[left++];
        }
        if( sum == s ){
            int len = right - left + 1; 
            if( len > maxi ){
                maxi = len;
                res[0] = left + 1;
                res[1] = right + 1;                
            }
        }        
    }
    if( res[0] == -1 ) res.pop_back();
    return res;
}


