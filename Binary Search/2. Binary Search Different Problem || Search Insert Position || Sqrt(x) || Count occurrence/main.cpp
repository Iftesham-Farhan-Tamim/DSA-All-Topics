// Find First and Last Position of Element in Sorted Array (https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/)

#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	int first = -1, last = -1, mid;
	// first
	int str = 0, end = nums.size() - 1;
	while (str <= end) {
		mid = str + (end - str) / 2;
		if (nums[mid] == target) {
			first = mid;
			end = mid - 1;
		} else if (nums[mid] < target) {
			str = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	// last
	str = 0, end = nums.size() - 1;
	while (str <= end) {
		mid = str + (end - str) / 2;
		if (nums[mid] == target) {
			last = mid;
			str = mid + 1;
		} else if (nums[mid] > target) {
			end = mid - 1;
		} else {
			str = mid + 1;
		}
	}

	vector<int> a(2);
	a[0] = first;
	a[1] = last;
	return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	vector<int> nums = {1, 2, 3, 3, 3, 4, 5};
	int target = 3;
	vector<int> res = searchRange(nums, target);

	cout << "[" << res[0] << ", " << res[1] << "]" << endl;
}

// output:
// [2, 4]
// ............................................................................................
// Search Insert Position (https://leetcode.com/problems/search-insert-position/description/)

#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
	int str = 0, end = nums.size() - 1, ans = nums.size();

	while (str <= end) {
		int mid = str + (end - str) / 2;

		if (nums[mid] == target) {
			ans = mid;
			break;
		} else if (nums[mid] > target) {
			end = mid - 1;
			ans = mid;
		} else {
			str = mid + 1;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> nums = {1, 3, 5, 6};
	int target = 2;
	cout << searchInsert(nums, target) << endl;
}

// output:
// 1
// ............................................................................................
// Sqrt(x) (https://leetcode.com/problems/sqrtx/description/)

#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
	int str = 0, end = x, ans = 0;

	while (str <= end) {
		if (x < 2) {
			return x;
		}

		int mid = str + (end - str) / 2;

		if (mid == x / mid) {
			ans = mid;
			break;
		} else if (mid < x / mid) {
			ans = mid;
			str = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x;
	cin >> x;
	cout << mySqrt(x);
}

// input:
// 4

// output:
// 2

// input:
// 8

// output:
// 2





// 5: Count the Zeros: https://practice.geeksforgeeks.org/pr...[]=0&category[]=Searching&sortBy=submissions
// 6: Number of occurrence: https://practice.geeksforgeeks.org/pr...
// 7: Cube root of a number: https://practice.geeksforgeeks.org/pr...
