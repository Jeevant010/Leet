#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

#define to_bin(x) (x == 0 ? "0" : bitset<32>(x).to_string().substr(__builtin_clz(x)))

class Solution {
public:
    int binaryGap(int n) {
        string s = to_bin(n);
        int i = 0, j = 0, m = 0;

        cout << "Binary: " << s << endl;

        while (j < s.length()) {
            if (s[j] == '1') {
                m = max(m, j - i);
                i = j;
            }
            j++;
        }
        return m;
    }
};

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    Solution sol;
    cout << "Binary Gap = " << sol.binaryGap(n) << endl;

    return 0;
}