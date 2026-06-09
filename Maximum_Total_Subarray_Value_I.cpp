#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        // int ma = *max_element(nums.begin(), nums.end());
        // int mi = *min_element(nums.begin(), nums.end());

        // return 1LL * k*(ma-mi);

        int ma = INT_MIN;
        int mi = INT_MAX;

        for (int x : nums) {
            ma = max(ma, x);
            mi = min(mi, x);
        }

        return 1LL * k * (ma - mi);

    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 3, 7, 2, 5};
    int k = 4;

    cout << sol.maxTotalValue(nums, k) << endl;

    return 0;
}