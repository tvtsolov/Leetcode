#include <vector>
#include <algorithm>

using namespace std;

  
class Solution {
public:
    int jump(vector<int>& nums) {

        int lastPos = nums.size()-1;
        int biggestStep = INT_MIN;
        int biggestStepInd = -1;
        int jumps = 0;

        if (nums.size() == 1){
            return 0;
        }

        for(int i = 0; i < lastPos;){

            if (nums[i]+i >= lastPos){
                return ++jumps;
            } 
            for (int k = i+1; k <= nums[i]+i; k++){
                if (nums[k] != 0 && nums[k]+k > biggestStep){
                    biggestStep = nums[k]+k;
                    biggestStepInd = k;
                } 
            }
            i = biggestStepInd;
            jumps++;
            biggestStep = INT_MIN;
        } 
        return jumps;
    }
};  

int main() {
    Solution s;
    vector<int> vec {1,2,1,1,1};

    int result = s.jump(vec);
    
    return 0;
}