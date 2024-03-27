#include <vector>
#include <unordered_map>
#include <random>
#include <iostream>
#include <numeric> // for std::accumulate
#include <functional> // for std::multiplies

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(), left=1;
        vector<int> ans(n,1);
        
        for(int i = n-2; i >= 0; i--) {
            ans[i] = ans[i+1]*nums[i+1];
        }
        for(int i = 0; i < n; i++) {   
            ans[i] *= left;
            left *= nums[i];
        }

        return ans;
    }
};


int main() {
    vector<int> v = {2,1,3,4};
    Solution s;

    vector<int> result = s.productExceptSelf(v);

    return 0;
}

/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/