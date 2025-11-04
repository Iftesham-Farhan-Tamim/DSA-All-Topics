// Aggressive Cows (https://www.geeksforgeeks.org/problems/aggressive-cows/0)

#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k, vector<int> &stalls) {
	int start = 1, end, mid, ans;

	sort(stalls.begin(), stalls.end());

	end = stalls[n - 1] - stalls[0];

	while (start <= end) {
		mid = start + (end - start) / 2;
		int count = 1, pos = stalls[0];

		for (int i = 1; i < n; i++) {
			if (pos + mid <= stalls[i]) {
				count++;
				pos = stalls[i];
			}
		}

		if (count < k) {
			end = mid - 1;
		} else {
			ans = mid;
			start = mid + 1;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> stalls(n);
	for (int i = 0; i < n; i++) {
		cin >> stalls[i];
	}

	cout << solve(n, k, stalls) << endl;
}

// input1:
// 5 3
// 1 2 4 8 9

// output1:
// 3

// input2:
// 5 3
// 10 1 2 7 5

// output2:
// 4
// ............................................................................................
// Koko Eating Bananas (https://leetcode.com/problems/koko-eating-bananas/description/)

#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int> &piles, int h) {
	int start = 0, end = 0, mid, ans, n = piles.size();
	long long sum = 0;

	for (int i = 0; i < n; i++) {
		sum += piles[i];
		end = max(end, piles[i]);
	}

	start = sum / h;

	if (!start) {
		start = 1;
	}

	while (start <= end) {
		mid = start + (end - start) / 2;

		int total_time = 0;

		for (int i = 0; i < n; i++) {
			total_time += piles[i] / mid;
			if (piles[i] % mid) {
				total_time++;
			}
		}

		if (total_time > h) {
			start = mid + 1;
		} else {
			ans = mid;
			end = mid - 1;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, h;
	cin >> n >> h;

	vector<int> piles(n);
	for (int i = 0; i < n; i++) {
		cin >> piles[i];
	}

	cout << minEatingSpeed(piles, h) << endl;
}

// input1:
// 4 8
// 3 6 7 11

// output1:
// 4

// input2:
// 5 5
// 30 11 23 4 20

// output2:
// 30
// ............................................................................................
// Magnetic Force Between Two Balls (https://leetcode.com/problems/magnetic-force-between-two-balls/description/)

#include <bits/stdc++.h>
using namespace std;

bool possibleToPlace(int force, vector<int>& position, int m) {
	int prev = position[0];
	int countBalls = 1;

	for (int i = 1; i < position.size(); i++) {
		int curr = position[i];

		if (curr - prev >= force) {
			countBalls++;
			prev = curr;
		}

		if (countBalls == m) {
            break;
        }
	}

	return countBalls == m;
}

int maxDistance(vector<int>& position, int m) {
	int n = position.size();
	sort(begin(position), end(position));

	int minForce = 1;
	int maxForce = position[n - 1] - position[0];
    int result = 0;

	while (minForce <= maxForce) {
		int midForce = minForce + (maxForce - minForce) / 2;

		if (possibleToPlace(midForce, position, m)) {
			result = midForce;
			minForce = midForce + 1;
		} else {
			maxForce = midForce - 1;
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> position(n);

	for (int i = 0; i < n; i++) {
		cin >> position[i];
	}

	cout << maxDistance(position, m) << endl;
}

// input1:
// 5 3
// 1 2 3 4 7

// output1:
// 3

// input2:
// 6 2
// 5 4 3 2 1 1000000000

// output2:
// 999999999