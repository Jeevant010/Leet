#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for (const string& w : words) {
            int s = 0;

            for (char c : w) {
                s = (s + weights[c - 'a']) % 26;
            }

            ans.push_back('a' + (25 - s));
        }

        return ans;
        
        
        
        // int n = words.size();
        // string p = "";
        // for(auto i=0; i<n;i++){
        //     int w = words[i].size(), s = 0;
        //     for(auto j =0; j<w; j++ ){
        //         s += weights[words[i][j] - 'a'];
        //     }
        //     s = (s % 26);
        //     p += (char)(97 + (25 - s));
        // }
        // return p;
    }
};

int main() {
    Solution sol;

    vector<string> words = {"abc", "z"};
    vector<int> weights(26);

    for (int i = 0; i < 26; i++) {
        weights[i] = i + 1;
    }

    string result = sol.mapWordWeights(words, weights);

    cout << result << "\n";

    return 0;
}