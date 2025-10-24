// climbing stairs using plain recursion approach (naive recursion)

#include<bits/stdc++.h>
using namespace std;

int climb(int i, int n) {
    if(i == n) {
        return 1;
    }

    if(i > n) {
        return 0;
    }

    return climb(i + 1, n) + climb(i + 2, n);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output: " << climb(0, n) << endl;
}

// output:
// Input: 5
// Output: 8
// ............................................................................................
// climbing stairs (Top-Down Memoization) -> Forward Recursion (0 → n)

#include<bits/stdc++.h>
using namespace std;

int climb(int i, int n, vector<int>&dp) {
    if(i == n) {
        return 1;
    }

    if(i > n) {
        return 0;
    }

    if(dp[i] != -1) {
        return dp[i];
    }

    return dp[i] = climb(i + 1, n, dp) + climb(i + 2, n, dp);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cout << "Input: ";
    cin >> n;

    vector<int> dp(n + 2, -1);
    cout << "Output: " << climb(0, n, dp) << endl;
}

// output:
// Input: 5
// Output: 8
// ............................................................................................
// climbing stairs (Top-Down Memoization) -> Backward Recursion (n → 0)

#include<bits/stdc++.h>
using namespace std;

int climb(int n, vector<int> &dp) {
	if (n <= 1) {
		return 1;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	return climb(n - 1, dp) + climb(n - 2, dp);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> dp(n + 1, -1);

	int ans = climb(n, dp);
	cout << ans << endl;
}

// output:
// Input: 5
// Output: 8
// ............................................................................................
// Tabulation / Bottom-Up 0 -> n

#include<bits/stdc++.h>
using namespace std;

int climb(int n, int i) {
	vector<int> dp(n + 2, -1);

	dp[n] = 1;
	dp[n + 1] = 0;

	for (int i = n - 1; i >= 0; i--) {
		dp[i] = dp[i + 1] + dp[i + 2];
	}

	return dp[0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
    cout << "Input: ";
	cin >> n;
	vector<int> dp(n + 2, -1);

	int ans = climb(n, 0);
	cout << "Output: " << ans << endl;
}

// output:
// Input: 5
// Output: 8
// ............................................................................................
// climbing stairs (Bottom-Up Tabulation) n -> 0

#include<bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++) {
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
    cout << "Output: " << climbStairs(n) << endl;
}

// output:
// Input: 5
// Output: 8
// ............................................................................................
// space-optimized version Tabulation / Bottom-Up

#include<bits/stdc++.h>
using namespace std;

int climb(int n) {
	if (n <= 1) {
		return 1;
	}

	int prev2 = 1;
	int prev1 = 1;
	int curr;

	for (int i = 2; i <= n; i++) {
		curr = prev2 + prev1;
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

	int ans = climb(n);
	cout << "Output: " << ans << endl;
}

// output:
// Input: 5
// Output: 8