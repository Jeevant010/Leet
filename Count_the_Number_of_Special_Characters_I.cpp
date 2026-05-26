#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool lower[26] = {0};
        bool upper[26] = {0};

        for(char ch : word) {

            if(ch >= 'a' && ch <= 'z')
                lower[ch - 'a'] = true;

            else if(ch >= 'A' && ch <= 'Z')
                upper[ch - 'A'] = true;
        }

        int cnt = 0;

        for(int i = 0; i < 26; i++) {
            cnt += (lower[i] && upper[i]);
        }

        return cnt;


        // vector<int> a(26), b(26);
        // for(int i=0; i<word.length();i++){
        //     if( word[i] - 'a' <= 25 && word[i] - 'a' >= 0 ) b[word[i] - 'a']++;
        //     if( word[i] - 'A' <= 25 && word[i] - 'A' >= 0 ) a[word[i] - 'A']++;
        // }
        // int c = 0;
        // for(int i=0; i<26; i++){
        //     if( a[i] > 0 && b[i] > 0 ) c++;
        // }
        // return c;
    }
};

int main() {

    Solution obj;

    string word;

    cin >> word;

    cout << obj.numberOfSpecialChars(word);

    return 0;
}