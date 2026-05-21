#include <bits/stdc++.h>

using namespace std;

class Solution {

private:
    
    void sub(int i, int s, vector<int>& m, set<vector<int>>& r, vector<int> t) {
        
        r.insert(t);

        if (i >= s)
            return;

        sub(i + 1, s, m, r, t);

        t.push_back(m[i]);
        sub(i + 1, s, m, r, t);
    }

public:
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        set<vector<int>> r;
        vector<int> temp;

        sub(0, nums.size(), nums, r, temp);

        vector<vector<int>> ans(r.begin(), r.end());

        return ans;
    }
};

int main() {

    vector<int> nums = {1, 2, 2};

    Solution obj;

    vector<vector<int>> result = obj.subsetsWithDup(nums);

    cout << "Subsets are:\n";

    for (auto subset : result) {

        cout << "[ ";

        for (int x : subset) {
            cout << x << " ";
        }

        cout << "]\n";
    }

    return 0;
}