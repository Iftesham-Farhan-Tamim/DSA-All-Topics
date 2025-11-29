// Kth smallest element (https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article)

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int> p;

    for(int i = 0; i < k; i++) {
        p.push(arr[i]);
    }

    for(int i = k; i <= r; i++) {
        if(arr[i] < p.top()) {
            p.pop();
            p.push(arr[i]);
        }
    }

    return p.top();
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int l = 0, r = n - 1;
    int k = 3;

    cout << "Kth smallest element is: " << kthSmallest(arr, l, r, k) << endl;
}

// output:
// Kth smallest element is: 7
// ............................................................................................
// Kth Largest Element in an Array (https://leetcode.com/problems/kth-largest-element-in-an-array/description/)

#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int> , greater<int> > p;

    for(int i = 0; i < k; i++) {
        p.push(nums[i]);
    }

    for(int i = k; i < nums.size(); i++) {
        if(nums[i] > p.top()) {
            p.pop();
            p.push(nums[i]);
        }
    }

    return p.top();
}

int main() {
    vector<int> nums;
    int n, k, val;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        nums.push_back(val);
    }

    cout << "Enter k: ";
    cin >> k;

    int kthLargest = findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << kthLargest << endl;
}

// input:
// Enter size of array: 6
// Enter array elements: 3 2 1 5 6 4
// Enter k: 2

// output:
// The 2th largest element is: 5
// ............................................................................................
// Sum of elements between k1'th and k2'th smallest elements (https://www.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1?page=1&difficulty%5B%5D=0&category%5B%5D=Heap&sortBy=submissions)

#include<bits/stdc++.h>
using namespace std;

long long sumBetweenTwoKth(long long a[], long long n, long long k1, long long k2) {
    priority_queue<long long> p1;
    priority_queue<long long> p2;

    for(long long i = 0; i < k1; i++) {
        p1.push(a[i]);
    }

    for(long long i = 0; i < k2 - 1; i++) {
        p2.push(a[i]);
    }

    for(long long i = k1; i < n; i++) {
        if(a[i] < p1.top()) {
            p1.pop();
            p1.push(a[i]);
        }
    }

    for(long long i = k2 - 1; i < n; i++) {
        if(a[i] < p2.top()) {
            p2.pop();
            p2.push(a[i]);
        }
    }

    long long sum1 = 0, sum2 = 0;
    while(!p1.empty()) {
        sum1 += p1.top();
        p1.pop();
    }

    while(!p2.empty()) {
        sum2 += p2.top();
        p2.pop();
    }

    return sum2 - sum1;
}

int main() {
    long long n, k1, k2;
    cout << "Enter size of array: ";
    cin >> n;

    long long arr[n];
    cout << "Enter array elements: ";

    for(long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k1 and k2: ";
    cin >> k1 >> k2;

    long long result = sumBetweenTwoKth(arr, n, k1, k2);
    cout << "Sum of elements between " << k1 << "-th and " << k2 << "-th smallest elements is: " << result << endl;
}

// input:
// Enter size of array: 6
// Enter array elements: 20 8 22 4 12 10
// Enter k1 and k2: 3 6

// output:
// Sum of elements between 3-th and 6-th smallest elements is: 32