
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        
        int e;

        for (int i = 0, c = 0 ; i < nums.size() ; i++) {
            if (c == 0)
                e = nums[i];
            if (e == nums[i])
                c++;
            else {
                c--;
            }
        }
        return e;
        
    }
};


int main() {
    Solution s;
    vector<int> vec {0,2,1,1,1,3,1};

    int res = s.majorityElement(vec);
    cout << res;

}