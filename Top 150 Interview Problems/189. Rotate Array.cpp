
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <list>

using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> result(size);

        if (k == size || size == 1 || k == 0){
            return;
        }

        if (k > size){
            int actualK = k % size;
            k = actualK;
        }  
        
        int pos = size-k;
        int temp = nums[pos];

        for(int i = 0; i < size; i++){
            result[i] = temp;
            if (pos < size-1){
                temp = nums[++pos];
            }
            else if (pos == size-1)
            {
                ++pos;
                continue;
            }
            else {
                result[i] = nums[i-k];
            }
        }
        nums = result;
    }
};

int main() {

    Solution s;
    int k = 1003;

    vector<int> vec = {1,2,3};
    s.rotate(vec, k);

    vec;
    return 0;
}


/* solution using list for the rotation

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int size = nums.size();

        if (k == size || size == 1){
            return;
        }

        if (k > size){
            int actualK = k % nums.size();
            k = actualK;
        } 

        
        list <int> ls;
        ls.assign( nums.begin(), nums.end() );
    
        for (int i = 0; i<k; i++){
            int el = ls.back();
            ls.pop_back();
            ls.push_front(el);
        }

        vector<int> result (ls.begin(), ls.end());
        nums = result;
    }
};


*/






/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/