// Permutations II (https://leetcode.com/problems/permutations-ii/description/)

// #include<bits/stdc++.h>
// using namespace std;

// void permut(vector<int> &arr, vector<vector<int>> &ans, int idx) {
//     if(idx == arr.size()) {
//         ans.push_back(arr);
//         return;
//     }

//     vector<bool> use(21, 0);
//     for(int i = idx; i < arr.size(); i++) {
//         if(use[arr[i] + 10] == 0) {
//             swap(arr[i], arr[idx]);
//             permut(arr, ans, idx + 1);
//             swap(arr[i], arr[idx]);
//             use[arr[i] + 10] = 1;
//         }
//     }
// }

// vector<vector<int> > permuteUnique(vector<int> &nums) {
//     vector<vector<int> > ans;
//     permut(nums, ans, 0);
//     return ans;
// }

// int main() {
//     vector<int> nums = {1, 1, 2};
//     vector<vector<int>> result = permuteUnique(nums);

//     for (int i = 0; i < result.size(); i++) {
//         for (int j = 0; j < result[i].size(); j++) {
//             cout << result[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// output:
// 1 1 2 
// 1 2 1 
// 2 1 1 
// ............................................................................................
// Ways to Sum N (https://www.geeksforgeeks.org/problems/ways-to-sum-to-n5759/1?utm_medium=article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include<bits/stdc++.h>
using namespace std;

int way(int arr[], int m, int sum) {
    if(sum == 0) {
        return 1;
    }

    if(sum < 0) {
        return 0;
    }

    int ans = 0;
    for(int i = 0; i < m; i++) {
        ans += way(arr, m, sum - arr[i]);
    }

    return ans;
}

int countWays(int arr[], int m, int n) {
    return way(arr, m, n);
}

int main() {
    int arr[] = {1, 2, 3};
    int m = 3;
    int n = 4;

    cout << countWays(arr, m, n) << endl; 
}

// output:
// 7