// climbing stairs using plain recursion approach (naive recursion)

#include<bits/stdc++.h>
using namespace std;

int count(int i, int n) {
    if(i == n) {
        return 1;
    }

    if(i > n) {
        return 0;
    }

    return count(i + 1, n) + count(i+2, n);
}

int climbStairs(int n) {
    return count(0, n);
}

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output: " << climbStairs(n) << endl;
}

// output:
// Input: 5
// Output: 8
// ............................................................................................
// climbing stairs (Top-Down Memoization) -> Forward Recursion (0 → n)

#include<bits/stdc++.h>
using namespace std;

int count(int i, int n, vector<int>&dp) {
    if(i == n) {
        return 1;
    }

    if(i > n) {
        return 0;
    }

    if(dp[i] != -1) {
        return dp[i];
    }

    return dp[i] = count(i + 1, n, dp) + count(i+2, n, dp);
}

int climbStairs(int n) {
    vector<int> dp(n+2, -1);

    // bottom up
    return count(0, n, dp);
}

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output: " << climbStairs(n) << endl;
}

// output:
// Input: 5
// Output: 8
// ............................................................................................
// climbing stairs (Top-Down Memoization) -> Backward Recursion (n → 0)

#include<bits/stdc++.h>
using namespace std;

int count(int i, vector<int>&dp) {
    if(i <= 1) {
        return 1;
    }

    if(dp[i] != -1) {
        return dp[i];
    }

    return dp[i] = count(i-1, dp) + count(i-2, dp);
}

int climbStairs(int n) {
    vector<int> dp(n+1, -1);

    // bottom up
    return count(n, dp);
}

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output: " << climbStairs(n) << endl;
}

// output:
// Input: 5
// Output: 8
// ............................................................................................
// climbing stairs (Bottom-Up Tabulation)

#include<bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    vector<int> dp(n+1, -1);

    // bottom up
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output: " << climbStairs(n) << endl;
}

// output:
// Input: 5
// Output: 8