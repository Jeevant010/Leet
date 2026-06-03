#include <iostream>
#include <vector>
#include <climits>
using namespace std;


class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size(), minR = INT_MAX, minr = INT_MAX, w = INT_MAX, l = INT_MAX ;
        for(int i =0; i<n; i++){
            minR = min(minR, landStartTime[i] + landDuration[i]);
        }

        for(int i =0; i<m; i++){
            minr = min(minr, waterStartTime[i] + waterDuration[i]);
            w = min(max(minR, waterStartTime[i]) + waterDuration[i], w); 
        }
        
        for( int i =0; i<n; i++){
            l = min(max(minr, landStartTime[i]) + landDuration[i], l);
        }
        return min(l, w);


        // int ans = INT_MAX;

        // int n = landStartTime.size();
        // int m = waterStartTime.size();

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {

        
        //         int landFinish = landStartTime[i] + landDuration[i];
        //         int waterStart = max(landFinish, waterStartTime[j]);
        //         ans = min(ans, waterStart + waterDuration[j]);

        
        //         int waterFinish = waterStartTime[j] + waterDuration[j];
        //         int landStart = max(waterFinish, landStartTime[i]);
        //         ans = min(ans, landStart + landDuration[i]);
        //     }
        // }

        // return ans;
    }
};


int main() {
    Solution sol;

    vector<int> landStartTime = {2, 8};
    vector<int> landDuration = {4, 1};

    vector<int> waterStartTime = {6};
    vector<int> waterDuration = {3};

    cout << sol.earliestFinishTime(
                landStartTime,
                landDuration,
                waterStartTime,
                waterDuration)
         << endl;

    return 0;
}