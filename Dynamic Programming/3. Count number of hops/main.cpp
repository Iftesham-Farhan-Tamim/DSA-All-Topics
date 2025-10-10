// Count number of hops using Top down Approach (https://www.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1?page=1&difficulty%5B%5D=0&category%5B%5D=Dynamic%2520Programming&sortBy=submissions)

#include<bits/stdc++.h>
using namespace std;

long long ways(int n) {
    if(n <= 1) {
        return 1;
    }

    if(n == 2) {
        return 2;
    }

    return (ways(n-1) + ways(n-2) + ways(n-3));
}

long long countWays(int n) {
    return ways(n);
}

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output: " << countWays(n) << endl;
}

// output:
// Input: 4
// Output: 7
// ............................................................................................
// Count number of hops (Bottom-Up Approach)

#include<bits/stdc++.h>
using namespace std;

long long countWays(int n) {  // Space Optimized Versio
    if(n <= 1) {
        return 1;
    }

    if(n ==2) {
        return 2;
    }
    
    long long curr, prev = 2, prev1 = 1, prev2 = 1;

    for(int i=3; i<=n; i++) {
        curr = (prev+prev1+prev2);
        prev2 = prev1;
        prev1 = prev;
        prev = curr;
    }

    return curr;
}

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output: " << countWays(n) << endl;
}

// output:
// Input: 4
// Output: 7
// ............................................................................................
// Count number of hops (Bottom-Up Approach)

#include<bits/stdc++.h>
using namespace std;

long long countWays(int n) {  // DP Array Version
    vector<long long> dp(n+1, -1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++) {
        dp[i] = (dp[i-1]+dp[i-2]+dp[i-3]);
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output: " << countWays(n) << endl;
}

// output:
// Input: 4
// Output: 7
// ............................................................................................
// Min Cost Climbing Stairs Recursive Top-Down Approach (https://leetcode.com/problems/min-cost-climbing-stairs/description/)

#include<bits/stdc++.h>
using namespace std;

int ways(int n, vector<int>&cost) {
    if(n <= 1) {
        return 0;
    }

    return min(cost[n-1] + ways(n-1, cost), cost[n-2] + ways(n-2, cost));
}

int minCostClimbingStairs(vector<int>&cost) {
    int n = cost.size();
    return ways(n, cost);
}

int main() {
    vector<int> cost;
    cost.push_back(10);
    cost.push_back(15);
    cost.push_back(20);

    cout << minCostClimbingStairs(cost) << endl;
}

// output:
// 15
// ............................................................................................
// Min Cost Climbing Stairs Dynamic Programming Bottom-Up Approach

#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>&cost) {
    int n = cost.size();
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 0;

    for(int i=2; i<=n; i++) {
        dp[i] = min(cost[i-1] + dp[i-1], cost[i-2] + dp[i-2]);
    }

    return dp[n];
}

int main() {
    vector<int> cost;
    cost.push_back(10);
    cost.push_back(15);
    cost.push_back(20);

    cout << minCostClimbingStairs(cost) << endl;
}

// output:
// 15