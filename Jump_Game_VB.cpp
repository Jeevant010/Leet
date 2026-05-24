#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        vector<int> dp(n, 1);

        vector<pair<int,int>> sor;

        for(int i = 0; i < n; i++) {
            sor.push_back({arr[i], i});
        }

        sort(sor.begin(), sor.end());

        for(auto &[height, i] : sor) {


            for(int j = i - 1; j >= max(0, i - d); j--) {

                if(arr[j] >= arr[i])
                    break;

                dp[i] = max(dp[i], 1 + dp[j]);
            }


            for(int j = i + 1; j <= min(n - 1, i + d); j++) {

                if(arr[j] >= arr[i])
                    break;

                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main() {

    Solution obj;

    vector<int> arr = {6,4,14,6,8,13,9,7,10,6,12};

    int d = 2;

    cout << obj.maxJumps(arr, d) << endl;

    return 0;
}