// Peak Index in a Mountain Array (https://leetcode.com/problems/peak-index-in-a-mountain-array/description/)

#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
	int str = 1, end = arr.size() - 2;

	while (str <= end) {
		int mid = str + (end - str) / 2;

		if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
			return mid;
		} else if (arr[mid - 1] < arr[mid]) {
			str = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> arr = {0, 10, 5, 2};

	int peak = peakIndexInMountainArray(arr);

	cout << "Peak index is: " << peak << endl;
}

// output:
// Peak index is: 1
// ............................................................................................
// Find Minimum in Rotated Sorted Array (https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/)

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr) {
	int str = 0, end = arr.size() - 1, ans = arr[0];

	while (str <= end) {
		int mid = str + (end - str) / 2;

		if (arr[0] <= arr[mid]) {
			str = mid + 1;
		} else {
			end = mid - 1;
			ans = arr[mid];
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int minimum = findMin(arr);
	cout << minimum << endl;
}

// input1:
// 4
// 11 13 15 17

// output1:
// 11

// input2:
// 7
// 4 5 6 7 0 1 2

// output:
// 0
// ............................................................................................
// Search in Rotated Sorted Array (https://leetcode.com/problems/search-in-rotated-sorted-array/description/)

#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
	int str = 0, end = nums.size() - 1;

	while (str <= end) {
		int mid = str + (end - str) / 2;

		if (nums[mid] == target) {
			return mid;
		}

		if (nums[str] <= nums[mid]) {
			if (nums[str] <= target && target < nums[mid]) {
				end = mid - 1;
			} else {
				str = mid + 1;
			}
		} else {
			if (nums[mid] < target && target <= nums[end]) {
				str = mid + 1;
			} else {
				end = mid - 1;
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, target;
	cin >> n;  
	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cin >> target;  

	int index = search(nums, target);
	cout << index << endl;
}

// input1:
// 7
// 4 5 6 7 0 1 2

// output1:
// 0

// input2:
// 7
// 4 5 6 7 0 1 2
// 3

// output2:
// -1
// ............................................................................................
// Kth Missing Positive Number (https://leetcode.com/problems/kth-missing-positive-number/description/)

#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
	int str = 0, end = arr.size() - 1;

	while (str <= end) {
		int mid = str + (end - str) / 2;

		if ((arr[mid] - (mid + 1)) < k) {
			str = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	return str + k;
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

	int result = findKthPositive(arr, k);
	cout << result << endl;
}

// input1:
// 5 5
// 2 3 4 7 11

// output1:
// 9

// input2:
// 4 2
// 1 2 3 4

// output:
// 6