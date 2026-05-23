#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int t= 0;
        for(int i=0;i<nums.size(); i++){
            if( nums[i] > nums[(i+1)%nums.size()]) t++;
        }
        return t<=1;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2,1,3,4};

    if(sol.check(nums))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}