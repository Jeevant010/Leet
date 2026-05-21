#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mp;
        vector<int> v(A.size());
        int c = 0;
        
        // for(int i =0; i<A.size(); i++){
        //     mp[A[i]] == 0 ? mp[A[i]] = 1 : mp[A[i]]++;
        //     mp[B[i]] == 0 ? mp[B[i]] = 1 : mp[B[i]]++;
        //     int count = 0;
        //     for (const auto& pair : mp) {
        //         if (pair.second == 2) {
        //             count++;
        //         }
        //     }
        //     v[i] = count;
        // }
        // return v;
        
        for(int i=0; i<A.size(); i++){

            mp[A[i]]++;
            if(mp[A[i]] == 2 ) c++;

            mp[B[i]]++;
            if( mp[B[i]] == 2 ) c++;

            v[i] = c;
        }
        return v;
    }
};

int main() {

    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};

    Solution obj;

    vector<int> result = obj.findThePrefixCommonArray(A, B);

    cout << "Prefix Common Array: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}