#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int hIndex(vector<int>& citations) {

        sort(citations.begin(), citations.end(), greater<int>());

        int H = 0;
        int maxH = citations[0];
        int minH = 1;

        for (int i = 0; i < citations.size(); i++){
            if (citations[i] < maxH && citations[i] != 0){
                maxH = citations[i];
            }
            if (minH == maxH){
                return maxH;
            } else if (citations[i] < minH) {
                return --minH;
            }
            minH++;
        }
        return --minH;
    }
};



int main() {
    Solution s;
    vector<int> vec {0};

    int result = s.hIndex(vec);
    
    return 0;
}


/*

Given an array of integers citations where citations[i] is 
the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: 
The h-index is defined as the maximum value of h such that the given researcher has published at least h papers 
that have each been cited at least h times.

 

Example 1:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 
citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations 
each, their h-index is 3.
Example 2:

Input: citations = [1,3,1]
Output: 1
 

Constraints:

n == citations.length
1 <= n <= 5000
0 <= citations[i] <= 1000

*/