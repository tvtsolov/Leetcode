#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <map>

using namespace std;


class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++){
            if (prices[i] < buy) {
                buy = prices[i];
            }
            else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }
        }


        return profit;
    }
};

int main() {

    Solution s;

    vector<int> vec = {1,2};
    int result = s.maxProfit(vec);

    return 0;
}