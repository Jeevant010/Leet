#include <bits/stdc++.h>
using namespace std;

class Solution {

    private:
        int digitSum(int x) {
            int sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            return sum;
        }

    public:
        int minElement(vector<int>& nums) {
            int ans = INT_MAX;

            for (int x : nums) {
                ans = min(ans, digitSum(x));
            }

            return ans;





            // for(int i=0; i<nums.size(); i++){
            //     int k = 0;
            //     while(nums[i] != 0){
            //         k += nums[i] % 10;
            //         nums[i] = nums[i] / 10;
            //     }
            //     nums[i] = k;
            // }
            // return *min_element(nums.begin(), nums.end());
        }   
};

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    int result = obj.minElement(nums);

    cout << "Minimum digit sum element: " << result << endl;

    return 0;
}