#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long r = 0;
        while( x != 0 ){
            int t = x%10;
            r = r * 10 + t;
            x /= 10;
        }
        return (r > INT_MAX || r < INT_MIN) ? 0 : (int)r;
    }
};

int main() {
    Solution sol;

    int x;
    cout << "Enter an integer: ";
    cin >> x;

    cout << "Reversed: " << sol.reverse(x) << endl;

    return 0;
}