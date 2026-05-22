#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while( l<=h ){
            long long m = l + (h-l)/2;
            if(nums[m] == target) return m;

            if( nums[l] <= nums[m] ){
                if( target >= nums[l] && target < nums[m]) h = m - 1;
                else l = m + 1; 
            }
            else {
                if( target > nums[m] && target <= nums[h] ) l = m + 1;
                 else h = m - 1;
            }
        }
        return -1;
        
        
        
        // for(int i=0; i<nums.size(); i++){
        //     if( nums[i] == target ) return i;
        // }
        // return -1;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    int ans = obj.search(nums, target);

    cout << "Index: " << ans << endl;

    return 0;
}