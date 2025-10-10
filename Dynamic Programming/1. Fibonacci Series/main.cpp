// Fibonacci series using recursion

#include<bits/stdc++.h>
using namespace std;

int fibon(int n, vector<int>&dp) {
    // base case
    if(n <= 1) {
        return n;
    }

    // already calculated result (fibon number)
    if(dp[n] != -1) {
        return dp[n];
    }

    return dp[n] = fibon(n-1, dp) + fibon(n-2, dp);
}

int fib(int n) {
    vector<int>dp(n+1, -1);
    return fibon(n, dp);
}

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output: " << fib(n);
}

// output:
// Input: 10
// Output: 55
// ............................................................................................
// Fibonacci series using bottom-up approach

#include<bits/stdc++.h>
using namespace std;

int fib(int n) {
    vector<int>dp(n+1, -1);
    dp[0] = 0;
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
    cout << "Output: " << fib(n);
}

// output:
// Input: 10
// Output: 55
// ............................................................................................
// space-optimized Fibonacci 

#include<bits/stdc++.h>
using namespace std;

int fib(int n) {
    if(n <= 1) {
        return n;
    }

    int curr, prev = 1, prev2 = 0;

    for(int i=2; i<=n; i++) {
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }

    return curr;
}

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output: " << fib(n);
}

// output:
// Input: 10
// Output: 55