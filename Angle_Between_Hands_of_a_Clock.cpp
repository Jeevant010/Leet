#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a = (hour%12)*30 + minutes/2.0;
        double r = minutes * 6;
        a = abs( r - a );
        return min( a, 360 - a );
    }
};

int main() {
    Solution obj;

    cout << obj.angleClock(12, 30) << endl; // 165
    cout << obj.angleClock(3, 30) << endl;  // 75
    cout << obj.angleClock(3, 15) << endl;  // 7.5

    return 0;
}