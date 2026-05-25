#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.length();
        vector<int> dp(n), p(n);
        dp[0] = 1;

        for(int i =0; i<minJump; i++){
            p[i] = 1;
        }
        for(int i = minJump; i<n; i++){
            int l = i - maxJump, r = i - minJump;
            if(s[i] == '0'){
                int t = p[r] - (l <=0 ? 0 : p[l-1]);
                dp[i] = (t != 0);
            }
            p[i] = p[i-1] + dp[i];
        }
        return dp[n-1];
        // int n = s.length();
        // if(s[n-1] == '1') return false;

        // vector<int>dp( n + maxJump + 1);
        // dp[minJump]++;
        // dp[maxJump + 1]--;

        // for(int i=1; i<n; i++){
        //     dp[i] += dp[i-1];
        //     if(s[i] == '1') continue;
        //     if(dp[i] == 0) continue;

        //     dp[i + minJump]++;
        //     dp[i + maxJump + 1]--;
        // } 
        // return dp[n-1]>0;
    }
};

int main() {

    Solution sol;

    string s;
    int minJump, maxJump;

    // Example input
    // 011010
    // 2 3

    cin >> s;
    cin >> minJump >> maxJump;

    bool ans = sol.canReach(s, minJump, maxJump);

    cout << (ans ? "true" : "false") << endl;

    return 0;
}