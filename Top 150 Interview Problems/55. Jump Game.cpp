#include <vector>
#include <algorithm>

// optimal

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx = nums[0];

        for (int i = 0; i < nums.size(); ++i) {
            if (maxIdx >= nums.size() - 1) return true;

            if (nums[i] == 0 && maxIdx == i) return false;

            if (i + nums[i] > maxIdx) maxIdx = i + nums[i];
        }

        return true;
    }
};

int main() {
    Solution s;
    vector<int> vec {1,1,1,1,0};

    int result = s.canJump(vec);
    
    return 0;
}