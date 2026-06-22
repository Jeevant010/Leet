#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> bal(5);
        for( auto &i : text){
            if(i == 'b') bal[0]++;
            else if( i == 'a' ) bal[1]++;
            else if( i == 'l' ) bal[2]++;
            else if( i == 'o' ) bal[3]++;
            else if( i == 'n' ) bal[4]++;
        }
        bal[2] = bal[2]/2;
        bal[3] = bal[3]/2;
        int ma = INT_MAX;
        // for(int i=0; i<5; i++){
        //     ma = min( ma, bal[i] );
        // }
        // return ma;
        return *min_element(bal.begin(), bal.end());
    }
};

int main() {
    Solution sol;

    string text;
    cin >> text;   // Example: loonbalxballpoon

    cout << sol.maxNumberOfBalloons(text) << endl;

    return 0;
}