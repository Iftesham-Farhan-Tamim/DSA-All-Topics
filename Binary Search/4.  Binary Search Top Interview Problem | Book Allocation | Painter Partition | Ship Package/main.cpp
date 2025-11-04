// Allocate Minimum Pages (https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?utm_medium=article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include <bits/stdc++.h>
using namespace std;

int findPages(vector<int> &arr, int k) {
	int start = 0, end = 0, ans;

	if (k > arr.size()) {
		return -1;
	}

	for (int i = 0; i < arr.size(); i++) {
		start = max(start, arr[i]);
		end += arr[i];
	}

	while (start <= end) {
		int mid = start + (end - start) / 2;
		int page = 0, count = 1;

		for (int i = 0; i < arr.size(); i++) {
			page += arr[i];

			if (page > mid) {
				count++;
				page = arr[i];
			}
		}

		if (count <= k) {
			ans = mid;
			end = mid - 1;
		} else {
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

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << findPages(arr, k) << endl;
}

// input1:
// 4 2
// 12 34 67 90

// output1:
// 113

// input2:
// 4 2
// 10 20 30 40

// output2:
// 60
// ............................................................................................
// The Painter's Partition Problem-II (https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1?utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include <bits/stdc++.h>
using namespace std;

long long minTime(int arr[], int n, int m) {
	int start = 0, end = 0, mid, ans;

	for (int i = 0; i < n; i++) {
		start = max(start, arr[i]);
		end += arr[i];
	}

	while (start <= end) {
		mid = start + (end - start) / 2;
		long long pages = 0, count = 1;

		for (int i = 0; i < n; i++) {
			pages += arr[i];
			if (pages > mid) {
				count++;
				pages = arr[i];
			}
		}

		if (count <= m) {
			ans = mid;
			end = mid - 1;
		} else {
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
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << minTime(a, n, k) << endl;
}

// input1:
// 5 3
// 5 10 30 20 15

// outpur1:
// 35

// input2:
// 4 2
// 10 20 30 40

// output2:
// 60
// ............................................................................................
// Capacity To Ship Packages Within D Days (https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/)

#include <bits/stdc++.h>
using namespace std;

int shipWithinDays(vector<int>& weights, int days) {
	int str = 0, end = 0, ans;

	for (int i = 0; i < weights.size(); i++) {
		str = max(str, weights[i]);
		end += weights[i];
	}

	while (str <= end) {
		int mid = str + (end - str) / 2;
		int belt = 0, count = 1;

		for (int i = 0; i < weights.size(); i++) {
			belt += weights[i];

			if (belt > mid) {
				count++;
				belt = weights[i];
			}
		}

		if (count <= days) {
			ans = mid;
			end = mid - 1;
		} else {
			str = mid + 1;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, days;
	cin >> n >> days;

	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		cin >> weights[i];
	}

	cout << shipWithinDays(weights, days) << endl;
}

// input1:
// 6 3
// 3 2 2 4 1 4

// output1:
// 6

// input2:
// 10 5
// 1 2 3 4 5 6 7 8 9 10

// output2:
// 15