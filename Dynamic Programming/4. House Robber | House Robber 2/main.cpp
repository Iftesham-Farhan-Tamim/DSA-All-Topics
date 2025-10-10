// House Robber Top-Down Recursive Approach (https://leetcode.com/problems/house-robber/description/)

// #include<bits/stdc++.h>
// using namespace std;

// int Robber(int index, vector<int>& nums) {
//     if(index == 0) {
//         return nums[0];
//     }

//     if(index == 1) {
//         return max(nums[0], nums[1]);
//     }

//     return max(nums[index] + Robber(index - 2, nums), Robber(index - 1, nums));
// }

// int rob(vector<int>& nums) {
//     int n = nums.size();
//     return Robber(n-1, nums);
// }

// int main() {
//     vector<int> nums;
//     nums.push_back(2);
//     nums.push_back(7);
//     nums.push_back(9);
//     nums.push_back(3);
//     nums.push_back(1);

//     int n = nums.size();
//     cout << rob(nums) << endl;
// }

// output:
// 12
// ............................................................................................
// House Robber Top-Down DP / Memoization

// #include<bits/stdc++.h>
// using namespace std;

// int Robber(int index, vector<int>& nums, vector<int>&dp) {
//     if(index == 0) {
//         return nums[0];
//     }

//     if(index == 1) {
//         return max(nums[0], nums[1]);
//     }

//     if(dp[index] != -1) {
//         return dp[index];
//     }

//     return dp[index] = max(nums[index] + Robber(index - 2, nums, dp), Robber(index - 1, nums, dp));
// }

// int rob(vector<int>& nums) {
//     int n = nums.size();
//     vector<int>dp(n, -1);
//     return Robber(n-1, nums, dp);
// }

// int main() {
//     vector<int> nums;
//     nums.push_back(2);
//     nums.push_back(7);
//     nums.push_back(9);
//     nums.push_back(3);
//     nums.push_back(1);

//     int n = nums.size();
//     cout << rob(nums) << endl;
// }

// ouput:
// 12
// ............................................................................................
// House Robber using Bottom up Approachy

#include<bits/stdc++.h>
using namespace std;

int Robber(int index, vector<int>& nums, vector<int>&dp) {
    if(index == 0) {
        return nums[0];
    }

    if(index == 1) {
        return max(nums[0], nums[1]);
    }

    if(dp[index] != -1) {
        return dp[index];
    }

    return dp[index] = max(nums[index] + Robber(index - 2, nums, dp), Robber(index - 1, nums, dp));
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n, -1);

    return Robber(n-1, nums, dp);
}

int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(9);
    nums.push_back(3);
    nums.push_back(1);

    int n = nums.size();
    cout << rob(nums) << endl;
}

// output:
// 12
// ............................................................................................
