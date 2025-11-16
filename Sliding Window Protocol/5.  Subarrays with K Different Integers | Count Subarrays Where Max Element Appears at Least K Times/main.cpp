// Length of Longest Subarray With at Most K Frequency (https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/)

#include <bits/stdc++.h>
using namespace std;

int maxSubarrayLength(vector<int> &nums, int k) {
    int len = 0;
    unordered_map<int, int> count;

    int start = 0, end = 0, n = nums.size();

    while(end < n) {
        count[nums[end]]++;

        while(count[nums[end]] > k) {
            count[nums[start]]--;
            start++;
        }

        len = max(len, end - start + 1);
        end++;
    }

    return len;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 2, 2, 3};
    int k = 2;
    cout << maxSubarrayLength(nums, k) << endl;
}

// output:
// 5
// ............................................................................................
// Count Subarrays Where Max Element Appears at Least K Times (https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/)

#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int> &nums, int k) {
    int maxEle = 0, n = nums.size();

    for(int i = 0; i < n; i++) {
        maxEle = max(maxEle, nums[i]);
    }    

    long long total = 0;
    int count = 0, start = 0, end = 0;

    while(end < n) {
        if(nums[end] == maxEle) {
            count++;
        }

        while(count == k) {
            total += n - end;
            if(nums[start] == maxEle) {
                count--;
            }

            start++;
        }
        end++;
    }

    return total;
}

int main() {
    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;
    cout << countSubarrays(nums, k) << endl;  
}

// output:
// 6
// ............................................................................................
// Subarrays with K Different Integers (https://leetcode.com/problems/subarrays-with-k-different-integers/description/)

#include <bits/stdc++.h>
using namespace std;

int subarraysWithKDistinct(vector<int> &nums, int k) {
    int total = 0;

    unordered_map<int, int> freq;

    int start = 0, end = 0, n = nums.size(), count = 0;

    while(end < n) {
        freq[nums[end]]++;

        if(freq[nums[end]] == 1) {
            count++;
        }

        while(count == k) {
            total += n - end;
            freq[nums[start]]--;
            if(freq[nums[start]] == 0) {
                count--;
            }
            start++;
        }

        end++;
    }

    start = 0, end = 0, count = 0;
    freq.clear();
    k++;

    while(end < n) {
        freq[nums[end]]++;

        if(freq[nums[end]] == 1) {
            count++;
        }

        while(count == k) {
            total -= n - end;
            freq[nums[start]]--;
            if(freq[nums[start]] == 0) {
                count--;
            }

            start++;
        }
        end++;
    }
    return total;
}

int main() {
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << subarraysWithKDistinct(nums, k) << endl; 
}

// output:
// 7