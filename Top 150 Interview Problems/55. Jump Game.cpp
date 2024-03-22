#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {


        int size = nums.size();
        int lastPos = size-1;
        if(size == 1) return true;
        int biggestStep = INT_MIN;
        int biggestStepInd = -1;

        for(int i = 0; i < lastPos;){

            if (nums[i] >= lastPos-i){
                return true;
            } 
            for (int k = i+1; k <= nums[i]+i; k++){
                
                if (nums[k] != 0 && nums[k]+k > biggestStep){
                    biggestStep = nums[k]+k;
                    biggestStepInd = k;
                } 
            }
            if (biggestStep == INT_MIN) return false;
            i = biggestStepInd;
            biggestStep = INT_MIN;
        } 
        return false;
    }
};  

int main() {
    Solution s;
    vector<int> vec {5,9,3,2,1,0,2,3,3,1,0,0};

    int result = s.canJump(vec);
    
    return 0;
}