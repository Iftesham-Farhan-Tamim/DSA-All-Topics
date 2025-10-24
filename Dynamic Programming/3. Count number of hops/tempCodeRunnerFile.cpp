#include<bits/stdc++.h>
using namespace std;

int ways(int n, vector<int> &cost, vector<int> &dp) {
    if(n <= 1) {
        return 0;
    }
    
    if(dp[n] != -1) {
        return dp[n];
    }
    
    return dp[n] = min(cost[n - 1] + ways(n - 1, cost, dp), 
           cost[n - 2] + ways(n - 2, cost, dp));
}

int main() {
    vector<int> cost;
    cost.push_back(10);
    cost.push_back(15);
    cost.push_back(20);

    int n = cost.size();
    vector<int> dp(n + 1, -1);
    int ans = ways(n, cost, dp);
    cout << ans << endl;
}