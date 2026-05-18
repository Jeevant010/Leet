#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mi = 1;
        int ma = *max_element(piles.begin(), piles.end());
        while( mi<=ma ){
            int mid = mi + (ma-mi)/2;
            long long l=0;
            for(int i=0; i<piles.size(); i++){
                l += ceil((double)piles[i] / mid);
            }
            if( l > h ) mi = mid + 1;
            else ma = mid -1 ;
        }
        return mi;
    }
};

int main() {
    int n, h;

    cout << "Enter number of piles: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of piles" << endl;
        return 1;
    }

    vector<int> piles(n);

    cout << "Enter bananas in each pile: ";
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    cout << "Enter hours: ";
    cin >> h;

    Solution sol;
    int ans = sol.minEatingSpeed(piles, h);

    cout << "Minimum eating speed: " << ans << endl;

    return 0;
}