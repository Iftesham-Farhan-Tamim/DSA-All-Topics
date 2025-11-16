// Missing And Repeating (https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?utm_medium=article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include <bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int> arr, int n) {
    for(int i = 0; i < n; i++) {
        arr[i]--;
    }

    for(int i = 0; i < n; i++) {
        arr[arr[i] % n] += n;
    }

    vector<int> ans(2);

    for(int i = 0; i < n; i++) {
        if(arr[i] / n == 2) {
            ans[0] = i + 1;
        } else if(arr[i] / n == 0) {
            ans[1] = i + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 3, 3};
    int n = arr.size();

    vector<int> result = findTwoElement(arr, n);

    cout << "Repeating: " << result[0] << endl;
    cout << "Missing: " << result[1] << endl;
}

// output:
// Repeating: 3
// Missing: 2
// ............................................................................................
// Majority Element (https://leetcode.com/problems/majority-element/description/)

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums) {
    int candidate, count = 0, n = nums.size();

    for(int i = 0; i < n; i++) {
        if(count == 0) {
            count = 1;
            candidate = nums[i];
        } else {
            if(candidate == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
    }

    return candidate;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int result = majorityElement(nums);

    if (result != -1) {
        cout << "Majority Element: " << result << endl;
    } else {
        cout << "No majority element found." << endl;
    }
}

// output:
// Majority Element: 2
// ............................................................................................
// Frequencies in a Limited Array (https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1?utm_medium=article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include <bits/stdc++.h>
using namespace std;

vector<int> frequencyCount(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, 0); 
    for (int i = 0; i < n; i++) {
        if (arr[i] <= n) { 
            result[arr[i] - 1]++;
        }
    }

    return result;
}

int main() {
    vector<int> arr = {2, 3, 2, 3, 5};

    vector<int> ans = frequencyCount(arr); 

    for (int i = 0; i < ans.size(); i++) {
        cout << "Number " << i + 1 << " appears " << ans[i] << " times" << endl;
    }
}

// output:
// Number 1 appears 0 times
// Number 2 appears 2 times
// Number 3 appears 2 times
// Number 4 appears 0 times
// Number 5 appears 1 times