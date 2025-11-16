// Zero Sum Subarrays (https://www.geeksforgeeks.org/problems/zero-sum-subarrays1825/1)

#include <bits/stdc++.h>
using namespace std;

long long int findSubarray(vector<long long int> &arr) {
    long long int total = 0;

    unordered_map<long long int, long long int > m;
    long long int prefixSum = 0;

    int n = arr.size();

    m[0] = 1;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];
        if(m.count(prefixSum)) {
            total += m[prefixSum];
            m[prefixSum]++;
        } else {
            m[prefixSum] = 1;
        }
    }

    return total;
}

int main() {
    vector<long long int> arr = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};
 
    cout << "Number of subarrays with sum 0: " << findSubarray(arr) << endl;
}

// Output: 4
// Explanation: The 4 subarrays are [-1, -3, 4], [-2, 2], [2, 4, 6, -12], 
// and [-1, -3, 4, -2, 2]
// ............................................................................................
// Subarray Sum Equals K (https://leetcode.com/problems/subarray-sum-equals-k/description/)

#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    m[0] = 1;
    int prefixSum = 0;
    int total = 0;

    for(int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];
        if(m.count(prefixSum - k)) {
            total += m[prefixSum - k];
            m[prefixSum]++;
        } else {
            m[prefixSum]++;
        }
    }

    return total;
}

int main() {
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << "Number of subarrays with sum " << k << ": " << subarraySum(nums, k) << endl;
}

// output:
// Number of subarrays with sum 3: 2