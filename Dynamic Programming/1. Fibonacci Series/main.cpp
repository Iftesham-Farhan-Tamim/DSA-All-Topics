// Fibonacci series using Top-Down / Memoization

#include<bits/stdc++.h>
using namespace std;

int fib(int n, vector<int> &dp) {
    // base case
	if (n <= 1) {
		return n;
	}

	// already calculated result (fibon number)
	if (dp[n] != -1) {
		return dp[n];
	}

	return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
    cout << "Input: ";
	cin >> n;

	vector<int> dp(n + 1, -1);
    cout << "Output: ";
	for (int i = 0; i < n; i++) {
		int ans = fib(i, dp);
		cout << ans << " ";
	}
}

// output:
// Input: 10
// Output: 0 1 1 2 3 5 8 13 21 34
// ............................................................................................
// Fibonacci series using Bottom-up approach

#include<bits/stdc++.h>
using namespace std;

int fib(int n) {
	vector<int> dp(n + 1, -1);

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
    cout << "Input: ";
	cin >> n;

    cout << "Output: ";
	for (int i = 0; i < n; i++) {
		int ans = fib(i);
		cout << ans << " ";
	}
}

// output:
// Input: 10
// Output: 0 1 1 2 3 5 8 13 21 34
// ............................................................................................
// Bottom-Up with Space Optimization 

#include<bits/stdc++.h>
using namespace std;

int fib(int n) {
	if (n <= 1) {
		return n;
	}

	int prev2 = 0;
	int prev1 = 1;
	int curr;

	for (int i = 2; i <= n; i++) {
		curr = prev1 + prev2;
		prev2 = prev1;
		prev1 = curr;
	}

	return curr;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
    cout << "Input: ";
	cin >> n;

    cout << "Output: ";
	for (int i = 0; i < n; i++) {
		int ans = fib(i);
		cout << ans << " ";
	}
}

// output:
// Input: 10
// Output: 0 1 1 2 3 5 8 13 21 34