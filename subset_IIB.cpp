#include <bits/stdc++.h>

using namespace std;

class Solution {

    private:
        void sub ( int i, int s, vector<int>& m, set<vector<int>>& r, vector<int> t ) {
            r.insert(t);
            if( i >= s ) return;
            sub( i+1, s, m, r, t );
            t.push_back(m[i]);
            sub( i+1, s, m, r, t);

        }

        void sol(int i, vector<int> &n, vector<int>& t, vector<vector<int>>& a){
            a.push_back(t);
            for(int k=i; k<n.size(); k++){
                if(k > i && n[k] == n[k-1]) continue;
                t.push_back(n[k]);
                sol(k+1, n, t, a);
                t.pop_back();
            }
        }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
// solution 1 naive approach
        
        // sort(nums.begin(), nums.end());
        // set<vector<int> > r;
        // vector<int> temp;
        // sub(0, nums.size(), nums, r, temp);

        // vector<vector<int>> ans(r.begin(), r.end());
        // return ans;


// solution 2


        // sort(nums.begin(), nums.end());

        // set<vector<int>> s;
        // int n = nums.size();
        // int total = 1 << n;

        // for( int i=0; i< total; i++){
        //     vector<int> t;
        //     for(int j=0; j<n; j++){
        //         if( i & (1 << j)) t.push_back(nums[j]);
        //     }
        //     s.insert(t);
        // }
        // vector<vector<int>> a(s.begin(), s.end());
        // return a;


// solution 3 best optimal

    sort(nums.begin(), nums.end());

    vector<vector<int>> a;
    vector<int> t;
    sol(0, nums, t, a);
    return a;
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