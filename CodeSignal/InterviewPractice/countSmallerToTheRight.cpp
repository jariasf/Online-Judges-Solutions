/*******************************************
 ***Problem: Count Smaller to the Right
 ***Judge: CodeSignal
 ***Type: Merge Sort - Count Inversions
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

typedef long long LL;

LL mergeSort(vector<int> &nums, int left, int right){
    if( left + 1 >= right) return 0;    
    int mid = (left + right)/2;
    LL total = mergeSort(nums, left, mid);
    total += mergeSort(nums, mid, right);

    vector<int> L(mid - left), R(right - mid);
    for( int i = left ; i < mid; ++i ) L[i - left] = nums[i];
    for( int i = mid ; i < right ; ++i ) R[i - mid] = nums[i];

    int p_left = 0, p_right = 0, k = left;
    while( p_left < L.size() && p_right < R.size() ){
        if( R[p_right] < L[p_left] ){
            total += L.size() - p_left;
            nums[k++] = R[p_right++];
        }else{
            nums[k++] = L[p_left++];
        }
    }
    while( p_left < L.size() ) nums[k++] = L[p_left++];
    while( p_right < R.size() ) nums[k++] = R[p_right++];

    return total;
}

LL countSmallerToTheRight(std::vector<int> nums) {
    return mergeSort(nums, 0, nums.size());
}

