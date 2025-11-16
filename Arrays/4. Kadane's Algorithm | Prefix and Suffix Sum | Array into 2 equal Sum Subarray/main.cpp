// Divide array in 2 subarray with equal sum

#include<bits/stdc++.h>
using namespace std;

bool divide(vector<int> arr) {
    int maxi = INT_MIN, prefix = 0, total_sum = 0, n = arr.size();

    for(int i=0; i<n; i++) {
        total_sum += arr[i];
    }

    for(int i=0; i<n; i++) {
        prefix += arr[i];
        if(total_sum == 2 * prefix) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the element in array: ";

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << divide(v) << endl;
}

// input:
// Enter the size of array: 8
// Enter the element in array: 2 4 6 2 1 5 8 2

// output:
// 1
// ............................................................................................
// Largest sum contiguous subarray or Kadane’s Algorithm (https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1?utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxi = INT_MIN, prefix = 0;

    for(int i = 0; i < n; i++) {
        prefix += arr[i];
        maxi = max(prefix, maxi);
        if(prefix < 0) {
            prefix = 0;
        }
    }

    return maxi;
}

int main() {
    int arr[] = {2, 3, -8, 7, -1, 2, 3};
    cout << maxSubarraySum(arr, 7) << endl; 
}

// output:
// 11
// ............................................................................................
// Max difference between 2 element (https://www.geeksforgeeks.org/dsa/maximum-difference-between-two-elements/)

// ............................................................................................
// ............................................................................................
// ............................................................................................
// ............................................................................................
// ............................................................................................
// ............................................................................................
