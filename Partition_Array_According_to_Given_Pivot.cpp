#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> a(n);
        int l = 0, r = n-1;
        for(int i=0;i<n; i++){
            if( nums[i] < pivot ) a[l++] = nums[i];
            if( nums[n-1-i] > pivot ) a[r--] = nums[n-1-i];
        }
        while(l <= r) a[l++] = pivot;
        return a;




        // vector<int> r, l;
        // int c = 0;
        // for(int i=0; i<nums.size(); i++){
        //     if( nums[i] > pivot ) r.push_back(nums[i]); 
        //     else if( nums[i] < pivot ) l.push_back(nums[i]);
        //     else c++;
        // }
        // while (c--) l.push_back(pivot);

        // for (int x : r) l.push_back(x);
        // // int t = 0;
        // // for(int i =l.size(); i<nums.size(); i++){
        // //     if( c > 0){ 
        // //         l.push_back(pivot);
        // //         c--;
        // //     }
        // //     else {
        // //     l.push_back(r[t]);
        // //     t++;
        // //     }
        // // }
        // return l;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;

    vector<int> result = sol.pivotArray(nums, pivot);

    cout << "Result: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}