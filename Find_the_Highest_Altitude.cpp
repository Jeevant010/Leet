#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ni = 0, mn = 0;
        for( auto &i : gain ){
            ni += i;
            mn = max( mn, ni );
        }
            return mn;
    }
};

int main() {
    Solution sol;

    vector<int> gain = {-5, 1, 5, 0, -7};

    cout << sol.largestAltitude(gain) << endl;

    return 0;
}