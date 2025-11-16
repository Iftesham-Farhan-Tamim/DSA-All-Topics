// Subarray Sums Divisible by K (https://leetcode.com/problems/subarray-sums-divisible-by-k/description/)

#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k) {
    // unordered map
    unordered_map<int, int> m;
    m[0] = 1;

    int prefixSum = 0, rem, total = 0;

    for(int i=0; i<nums.size(); i++) {
        prefixSum += nums[i];
        rem = prefixSum % k;

        if(rem < 0) {
            rem = k + rem;
        }

        if(m.count(rem)) {
            total += m[rem];
            m[rem]++;
        } else {
            m[rem] = 1;
        }
    }

    return total;
}

int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    cout << "Number of subarrays divisible by " << k << ": " << subarraysDivByK(nums, k) << endl;
}

// output:
// Number of subarrays divisible by 5: 7
// ............................................................................................
// Subarray Product Less Than K (https://leetcode.com/problems/subarray-product-less-than-k/description/)

#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    if (k <= 1) {
        return 0;
    } 

    int product = 1, start = 0, end = 0, n = nums.size(), count = 0;

    while(end < n) {
        product *= nums[end];

        while(product >= k && start <= end) {
            product /= nums[start];
            start++;
        }

        count += 1 + (end - start);
        end++;
    }

    return count;
}

int main() {
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << "Number of subarrays with product < " << k << ": " 
         << numSubarrayProductLessThanK(nums, k) << endl;
}

// output:
// Number of subarrays with product < 100: 8
// ............................................................................................
// Count Subarrays With Score Less Than K (https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/)

#include <bits/stdc++.h>
using namespace std;

int main() {
    
}


// ............................................................................................
// Number of subarrays having sum less than K (https://www.geeksforgeeks.org/dsa/number-subarrays-sum-less-k/)

#include <bits/stdc++.h>
using namespace std;

int main() {
    
}
// ............................................................................................
// ............................................................................................
