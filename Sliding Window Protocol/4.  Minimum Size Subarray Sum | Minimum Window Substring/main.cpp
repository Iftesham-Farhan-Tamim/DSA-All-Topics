// Minimum Size Subarray Sum (https://leetcode.com/problems/minimum-size-subarray-sum/description/)

#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums) {
    int total = INT_MAX, start = 0, end = 0;
    int sum = 0, n = nums.size();

    while(end < n) {
        sum += nums[end];

        while(sum >= target) {
            total = min(total, end - start + 1);
            sum -= nums[start++];
        }

        end++;
    }

    return total == INT_MAX ? 0 : total;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << "Minimum size of subarray with sum ≥ " << target << ": "
         << minSubArrayLen(target, nums) << endl;
}

// output:
// Minimum size of subarray with sum ≥ 7: 2
// ............................................................................................
// Minimum Window Substring (https://leetcode.com/problems/minimum-window-substring/description/)

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    int total = t.size();

    unordered_map<char, int> m;
    for(int i = 0; i < t.size(); i++) {
        m[t[i]]++;
    }

    int start = 0, end = 0, ans = INT_MAX, index = -1;

    while(end < s.size()) {
        m[s[end]]--;
        if(m[s[end]] >= 0) {
            total--;
        }

        while(!total && start <= end) {
            if(ans > end - start + 1) {
                ans = end - start + 1;
                index = start;
            }

            m[s[start]]++;
            if(m[s[start]] > 0) {
                total++;
            }

            start++;
        }

        end++;
    }

    if(index == -1) {
        return "";
    }

    string str = "";

    for(int i = index; i < index + ans; i++) {
        str += s[i];
    }

    return str;
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Minimum window substring: " << minWindow(s, t) << endl;
}

// output:
// Minimum window substring: BANC