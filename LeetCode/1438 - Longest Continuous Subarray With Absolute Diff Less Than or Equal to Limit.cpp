/*******************************************
 ***Problem: Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 ***ID: 1438
 ***Judge: LeetCode
 ***Type: Sliding Window + Multiset|Priority Queue
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

// Multiset
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> v;
        int left = 0, maxi = 1;
        for( int i = 0 ; i < nums.size(); ++i ){
            v.insert(nums[i]);
            while( v.size() > 0 && *v.rbegin() - *v.begin() > limit ){
                v.erase( v.find(nums[left++]));
            }
            maxi = max( maxi, i - left + 1);
        }
        return maxi;
    }
};

//Priority Queue
class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int maxi = 1;
        priority_queue<pii > maxHeap;
        priority_queue <pii, vector<pii>, greater<pii> > minHeap;
        int maxIndex = -1;
        for( int i = 0 ; i < n ; ++i ){    
            while( minHeap.size() > 0 ){
                pii cur = minHeap.top();
                if( cur.second < maxIndex ){
                    minHeap.pop();
                    continue;
                }                
                if( abs(cur.first - nums[i]) <= limit ){
                    break;
                }
                maxIndex = max( maxIndex, cur.second);
                minHeap.pop();
            }
            
            while( maxHeap.size() > 0 ){
                pii cur = maxHeap.top();
                if( cur.second < maxIndex ){
                    maxHeap.pop();
                    continue;
                }                
                if( abs(cur.first - nums[i]) <= limit ){
                    break;
                }
                maxIndex = max( maxIndex, cur.second);
                maxHeap.pop();
            }
            minHeap.push(mp(nums[i], i));
            maxHeap.push(mp(nums[i], i));
            if( minHeap.size() > 1 ){
                maxi = max( maxi, i - maxIndex);
            }
        }
        return maxi;
    }
};
