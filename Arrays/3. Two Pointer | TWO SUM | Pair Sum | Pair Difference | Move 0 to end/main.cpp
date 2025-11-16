// Segregate 0s and 1s (https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1?utm_medium=article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include<bits/stdc++.h>
using namespace std;

void segregate0and1(int arr[], int n) {
    int start = 0, end = n - 1;

    while(start <= end) {
        if(arr[start] == 0) {
            start++;
        } else {
            if(arr[end] == 0) {
                swap(arr[start], arr[end]);
                start++;
                end--;
            } else {
                end--;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    segregate0and1(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// input:
// 6
// 0 1 0 1 1 0

// output:
// 0 0 0 1 1 1 
// ............................................................................................
// Two Sum II - Input Array Is Sorted (https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/)

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> ans;
    int start = 0, end = numbers.size() - 1;

    while(start <= end) {
        if(numbers[start] + numbers[end] == target) {
            ans.push_back(start + 1);
            ans.push_back(end + 1);
            return ans;
        } else if(numbers[start] + numbers[end] < target) {
            start++;
        } else {
            end--;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(arr, target);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;
}

// output:
// 1 2
// ............................................................................................
// Pair With Given Difference (https://www.interviewbit.com/problems/pair-with-given-difference/)

#include <bits/stdc++.h>
using namespace std;

int pairWith(vector<int> &a, int b) {
    sort(a.begin(), a.end());
    int start = 0, end = 1, n = a.size();

    while(end < n) {
        if(a[end] - a[start] == b) {
            return 1;
        } else if(a[end] - a[start]) {
            end++;
        } else {
            start++;
        }
    }

    if(start == end) {
        end++;
    }

    return 0;
}

int main() {
    vector<int> arr = {5, 10, 3, 2, 50, 80};
    int B = 78;
    cout << pairWith(arr, B) << endl;
}

// output:
// 1