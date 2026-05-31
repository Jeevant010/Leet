#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long k = mass;

        for (int i = 0; i < asteroids.size(); i++) {
            if (k < asteroids[i])
                return false;
            k += asteroids[i];
        }

        return true;
    }
};

int main() {
    int mass, n;

    cin >> mass;   
    cin >> n;      
    
    vector<int> asteroids(n);
    for (int i = 0; i < n; i++) {
        cin >> asteroids[i];
    }

    Solution obj;
    bool ans = obj.asteroidsDestroyed(mass, asteroids);

    cout << (ans ? "true" : "false") << endl;

    return 0;
}