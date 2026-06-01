#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size(), r = 0;
        // for(int i=n-1; i>=2; i -= 3 ){
        //     r += cost[i] + cost[i-1];
        // }
        // if( n%3 == 1 ) r+= cost[0];
        // if( n%3 == 2 ) r+= (cost[0] + cost[1]);
         for (int i = n - 1; i >= 0; --i) {
            if ((n - 1 - i) % 3 != 2)
                r += cost[i];
        }
        return r;
        
    }
};

int main() {
    Solution obj;

    vector<int> cost = {6, 5, 7, 9, 2, 2};

    cout << obj.minimumCost(cost) << endl;

    return 0;
}