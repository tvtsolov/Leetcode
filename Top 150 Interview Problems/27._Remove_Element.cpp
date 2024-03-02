#include <vector>
#include <algorithm>

// https://leetcode.com/tvtsolov/
// Beats 100.00% of users with C++

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int size = 0;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == val){
                nums[i] = INT_MIN;
            } else {
                size++;
            }
        }
        std::sort(nums.begin(), nums.end(), greater<int>());
        return size;
    }
};