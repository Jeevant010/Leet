#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    int dfs(int i, int n, int d, vector<int>& a, vector<int>& dp) {

        if (dp[i] != -1)
            return dp[i];

        int maxVisited = 1;

        
        for (int j = i + 1; j < min(i + d + 1, n); j++) {

            if (a[j] >= a[i])
                break;

            maxVisited = max(maxVisited,
                             1 + dfs(j, n, d, a, dp));
        }

        
        for (int j = i - 1; j >= max(0, i - d); j--) {

            if (a[j] >= a[i])
                break;

            maxVisited = max(maxVisited,
                             1 + dfs(j, n, d, a, dp));
        }

        return dp[i] = maxVisited;
    }

public:

    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        vector<int> dp(n, -1);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, n, d, arr, dp));
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> arr = {6,4,14,6,8,13,9,7,10,6,12};

    int d = 2;

    cout << obj.maxJumps(arr, d) << endl;

    return 0;
}