// Sliding Window Maximum (https://leetcode.com/problems/sliding-window-maximum/description/)

#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> ans;
    int n = nums.size();
    for(int i = 0; i <= n - k; i++) {
        int total = INT_MIN;
        for(int j = i; j < i + k; j++) {
            total = max(total, nums[j]);
        }
        ans.push_back(total);
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximums: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

// output:
// Sliding Window Maximums: 3 3 5 5 6 7 
// ............................................................................................
// optimized version

#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> d;
    vector<int> ans;
    int n = nums.size();

    for(int i = 0; i < k - 1; i++) {
        if(d.empty()) {
            d.push_back(i);
        } else {
            while(!d.empty() && nums[i] > nums[d.back()]) {
                d.pop_back();
            }

            d.push_back(i);
        }
    }

    for(int i = k - 1; i < n; i++) {
        while(!d.empty() && nums[i] > nums[d.back()]) {
            d.pop_back();
            d.push_back(i);
        }

        if(d.front() <= i - k) {
            d.pop_front();
        }

        ans.push_back(nums[d.front()]);
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximums: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

// output:
// Sliding Window Maximums: 3 3 5 5 6 7 
// ............................................................................................
// Minimum Number of K Consecutive Bit Flips (https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/)

#include<bits/stdc++.h>
using namespace std;

int minKBitFlips(vector<int> &nums, int k) {
    int flip = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        if(nums[i] == 0) {
            if(i + k - 1 >= n) {
                return -1;
            }

            for(int j = i; j <= i + k - 1; j++) {
                nums[j]=!nums[j];
            }

            flip++;
        }
    }

    return flip;
}

int main() {
    vector<int> nums;
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " bits (0 or 1): ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << "Enter k: ";
    cin >> k;

    int result = minKBitFlips(nums, k);

    cout << "Minimum number of flips required: " << result << endl;

    cout << "Final array after flips: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

// input1:
// Enter number of elements: 3
// Enter 3 bits (0 or 1): 1 1 0
// Enter k: 2

// output1:
// Minimum number of flips required: -1
// Final array after flips: 1 1 0 

// input2:
// Enter number of elements: 8
// Enter 8 bits (0 or 1): 0 0 0 1 0 1 1 0
// Enter k: 3

// output2:
// Minimum number of flips required: 3
// Final array after flips: 1 1 1 1 1 1 1 1 
// ............................................................................................
// optimized version

#include<bits/stdc++.h>
using namespace std;

int minKBitFlips(vector<int> &nums, int k) {
    queue<int> q;
    int flip = 0;
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        if(!q.empty() && q.front() < i) {
            q.pop();
        }

        if(q.size() % 2 == nums[i]) {
            if(i + k - 1 >= n) {
                return -1;
            }

            q.push(i + k - 1);
            flip++;
        }
    }

    return flip;
}

int main() {
    vector<int> nums;
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " bits (0 or 1): ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << "Enter k: ";
    cin >> k;

    int result = minKBitFlips(nums, k);

    cout << "Minimum number of flips required: " << result << endl;

    cout << "Final array after flips: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

// input1:
// Enter number of elements: 3
// Enter 3 bits (0 or 1): 1 1 0
// Enter k: 2

// output1:
// Minimum number of flips required: -1
// Final array after flips: 1 1 0 

// input2:
// Enter number of elements: 8
// Enter 8 bits (0 or 1): 0 0 0 1 0 1 1 0
// Enter k: 3

// output2:
// Minimum number of flips required: 3
// Final array after flips: 1 1 1 1 1 1 1 1 