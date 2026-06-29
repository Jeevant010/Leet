#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text, string target) {
        

        unordered_map<char,int> mp;
        for( auto &i : target){
            mp[i]++;
        }
        unordered_map<char,int> mp2;
        for( auto &i : text){
            if(mp.find(i) != mp.end()){
                mp2[i]++;
            }
        }
        int ma = INT_MAX;
        for( auto &i : mp){
            ma = min( ma, mp2[i.first]/i.second );
        }

        return ma;

    }
};

int main() {
    Solution sol;

    string text;
    cin >> text;   // Example: loonbalxballpoon

    string target;
    cin >> target;  // Example: balloon

    cout << sol.maxNumberOfBalloons(text, target) << endl;

    return 0;
}