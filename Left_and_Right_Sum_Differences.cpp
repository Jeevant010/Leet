#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int t = accumulate(nums.begin(), nums.end(), 0);
        int l = 0;

        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            int r = t - l - nums[i];
            ans[i] = abs(l - r);
            l += nums[i];
        }

        return ans;



        // int n = nums.size();
        // if(n<2) return {0};
        // vector<int> l(n), r(n);
        // vector<int> res(n);
        // l[0] = 0, l[1] = nums[0];
        // r[n-1] = 0, r[n-2] = nums[n-1];
        // for(int i=2; i<n; i++){
        //     l[i] = nums[i-1] + l[i-1];
        //     r[n-i-1] = nums[n-i] + r[n-i];
        // }
        // for(int i=0; i<n; i++){
        //     res[i] = abs(r[i] - l[i]);
        // }
        // return res;
    }
};

int main() {
    vector<int> nums = {10, 4, 8, 3};

    Solution sol;
    vector<int> result = sol.leftRightDifference(nums);

    cout << "Output: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}