#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {

       vector<int> small(26, -1);
        vector<int> cap(26, -1);

        for(int i = 0; i < word.size(); i++) {

            if(islower(word[i])) {
                small[word[i] - 'a'] = i;  
            }
            else {

                if(cap[word[i] - 'A'] == -1) {
                    cap[word[i] - 'A'] = i; 
                }
            }
        }

        int cnt = 0;

        for(int i = 0; i < 26; i++) {

            if(small[i] != -1 && cap[i] != -1 &&
               small[i] < cap[i]) {

                cnt++;
            }
        }

        return cnt;



        // vector<bool>s(26), b(26), r(26);
        // int c = 0;
        // for(int i=0; i<word.size(); i++){
            
        //     if( word[i] - 'a' >= 0 && word[i] - 'a' < 26 ) {
        //         if(r[word[i] - 'a']) continue;
        //         s[word[i] - 'a'] = true;
        //         if( b[word[i] - 'a'] && !r[word[i] - 'a'] ) {
        //             c--;
        //             b[word[i] - 'a'] = false;
        //             r[word[i] - 'a'] = true;
        //             }
        //         }
        //     else {
        //         if(r[word[i] - 'A']) continue;
        //         if( !s[word[i] - 'A'] && !b[word[i] - 'A']) r[word[i] - 'A'] = true;
        //         if( s[word[i] - 'A'] && !b[word[i] - 'A'] && !r[word[i] - 'A'] ) {
        //         c++;
        //         b[word[i] - 'A'] = true;
        //         cout<<word[i];
        //         }
        //     }
        // }
        // return c;
    }
};

int main() {

    Solution obj;

    vector<string> tests = {
        "aaAbcBC",
        "abc",
        "AbBCab",
        "AbcbDBdD",
        "aA",
        "aAa",
        "aAaa"
    };

    for(string s : tests) {
        cout << s << " -> "
             << obj.numberOfSpecialChars(s)
             << endl;
    }

    return 0;
}