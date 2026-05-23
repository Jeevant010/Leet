#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        while( !(st.find(n) != st.end() ) ){
            st.insert(n);
            int k = 0;
            while(n != 0){
                int t = n%10;
                k += pow(t, 2);
                n /= 10;
            }
            if( k == 1) return true;
            else {
                n = k;
            }
        }
        return false;
    }
};

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    Solution obj;

    if (obj.isHappy(n))
        cout << n << " is a Happy Number" << endl;
    else
        cout << n << " is NOT a Happy Number" << endl;

    return 0;
}