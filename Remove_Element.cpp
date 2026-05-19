#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0, j=0;
        while( i<nums.size() && j<nums.size() ){
            if( nums[j] == val && nums[i] != val ) i=j;
            if(nums[j] != val && nums[i] == val){
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
        int count = 0;
        for(int t = 0; t < nums.size(); t++){
            if(nums[t] != val) count++;
        }
        return count;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    int k = obj.removeElement(nums, val);

    cout << "Count after removing: " << k << endl;

    cout << "Modified array: ";
    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}