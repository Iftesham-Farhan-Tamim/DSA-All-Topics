// Count number of hops using Recursive approach (https://www.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1?page=1&difficulty%5B%5D=0&category%5B%5D=Dynamic%2520Programming&sortBy=submissions)

#include<bits/stdc++.h>
using namespace std;

long long ways(int n) {
    if(n <= 1) {
        return 1;
    }

    if(n == 2) {
        return 2;
    }

    return ways(n - 1) + ways(n - 2) + ways(n - 3);
}

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output: " << ways(n) << endl;
}

// output:
// Input: 4
// Output: 7
// ............................................................................................
// Count number of hops Top-Down (Memoization) approach

#include<bits/stdc++.h>
using namespace std;

int hopes(int n, vector<int>&dp) {
	if (n <= 1) {
		return 1;
	}

	if (n == 2) {
		return 2;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	return dp[n] = hopes(n - 1, dp) + hopes(n - 2, dp) + hopes(n - 3, dp);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> dp(n + 1, -1);

	int ans = hopes(n, dp);
	cout << ans << endl;
}

// output:
// Input: 4
// Output: 7
// ............................................................................................
// Count number of hops (Bottom-Up -> Tabulation)

#include<bits/stdc++.h>
using namespace std;

long long countWays(int n) {  
    vector<long long> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1]+dp[i - 2]+dp[i - 3]);
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
// Count number of hops (Bottom-Up Approach)

#include<bits/stdc++.h>
using namespace std;

long long countWays(int n) {  
    if(n <= 1) {
        return 1;
    }
    
    if(n == 2) {
        return 2;
    }
    
    long long curr, prev = 2, prev1 = 1, prev2 = 1;
    
    for(int i = 3; i <= n; i++) {
        curr = (prev + prev1 +prev2);
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
// Min Cost Climbing Stairs Recursion (Top-Down without Memoization) Approach (https://leetcode.com/problems/min-cost-climbing-stairs/description/)

#include<bits/stdc++.h>
using namespace std;

int ways(int n, vector<int>&cost) {
    if(n <= 1) {
        return 0;
    }

    return min(cost[n - 1] + ways(n - 1, cost), 
               cost[n - 2] + ways(n - 2, cost));
}

int main() {
    vector<int> cost;
    cost.push_back(10);
    cost.push_back(15);
    cost.push_back(20);

    int n = cost.size();
    int ans = ways(n, cost);
    cout << ans << endl;
}

// output:
// 15
// ............................................................................................
// Recursion with Memoization Top-Down

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

// output:
// 15
// ............................................................................................
// Min Cost Climbing Stairs Dynamic Programming Bottom-Up Tabulation Approach

#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>&cost) {
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 0;

    for(int i = 2; i <= n; i++) {
        dp[i] = min(cost[i - 1] + dp[i - 1], 
                    cost[i - 2] + dp[i - 2]);
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





// int solve(int idx) {
//     if(idx >= cost.size()) {
//         return 0;
//     }
    
//     int a = cost[idx] + solve(idx+1);
//     int b = cost[idx] + solve(idx+2);
    
//     return min(a, b);
// }