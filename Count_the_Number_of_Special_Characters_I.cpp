#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<int> upper(26, 0);
        vector<int> lower(26, 0);

        for(char ch : word) {

            if(ch >= 'a' && ch <= 'z')
                lower[ch - 'a']++;

            else if(ch >= 'A' && ch <= 'Z')
                upper[ch - 'A']++;
        }

        int cnt = 0;

        for(int i = 0; i < 26; i++) {
            if(lower[i] > 0 && upper[i] > 0)
                cnt++;
        }

        return cnt;
    }
};

int main() {

    Solution obj;

    string word;

    cin >> word;

    cout << obj.numberOfSpecialChars(word);

    return 0;
}