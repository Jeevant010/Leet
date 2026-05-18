#include <bits/stdc++.h>

using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());

    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long hours = 0;

        for (int bananas : piles) {
            hours += (bananas + mid - 1) / mid;
        }

        if (hours > h) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

int main() {
    int n, h;

    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);

    cout << "Enter bananas in each pile: ";
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    cout << "Enter hours: ";
    cin >> h;

    int ans = minEatingSpeed(piles, h);

    cout << "Minimum eating speed: " << ans << endl;

    return 0;
}