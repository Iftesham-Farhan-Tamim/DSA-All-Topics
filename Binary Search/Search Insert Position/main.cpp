#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &arr, int target) {
	int start = 0, end = arr.size() - 1, ans = arr.size(), mid;

	while (start <= end) {
		mid = start + (end - start) / 2;
		if (arr[mid] == target) {
			ans = mid;
			break;
		} else if (arr[mid] < target) {
			start = mid + 1;
		} else {
			ans = mid;
			end = mid - 1;
		}
	}
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << searchInsert(arr, m);
}

// input:
// 4 2
// 1 3 5 6

// output:
// 1

// input:
// 4 3
// 1 3 5 6

// output:
// 1