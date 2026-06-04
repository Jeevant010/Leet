#include <iostream>
#include <vector>
#include <climits>
using namespace std;


class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if(num2 < 99) return 0;
        int c=0;
                
        for(int i = num1; i<= num2; i++){
            int t = i;
            vector<int> dp;
            
            while(t){
                dp.push_back(t%10);
                t /= 10;
            }

            for(int j=1; j<dp.size()-1; j++){
                if(( dp[j] > dp[j-1] && dp[j] > dp[j+1] ) || ( dp[j] < dp[j-1] && dp[j] < dp[j+1] )) c++;
            }
            
        }
        return c;
        
        // if( num2 < 99) return 0;
        // int c = 0;
        // for(int i = num1; i<= num2; i++){
        //     string s = to_string(i);
        //     for(int j=1; j<s.length()-1; j++){
        //         if( s[j] > s[j-1] && s[j] > s[j+1] ) c++;
        //         if( s[j] < s[j-1] && s[j] < s[j+1] ) c++;
        //     }
        // }
        // return c;
    }
};


int main() {
    Solution sol;

    int n1 = 120, n2 = 130;

    cout << sol.totalWaviness(
            n1 ,n2    )
         << endl;

    return 0;
}