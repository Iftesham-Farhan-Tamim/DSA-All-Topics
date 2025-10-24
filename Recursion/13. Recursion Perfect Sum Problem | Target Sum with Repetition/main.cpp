// Perfect Sum Problem (https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include<bits/stdc++.h>
using namespace std;

int subSet(int arr[], int idx, int sum, int n) {
    if(idx == n) {
        return sum == 0;
    }

    return subSet(arr, idx + 1, sum, n) + subSet(arr, idx + 1, sum - arr[idx], n);
}

int main() {
    int arr[] = {2, 5, 6, 1, 3};
    int sum = 8;
    cout << subSet(arr, 0, sum, 5) << endl;
}

// output:
// 3
// ............................................................................................
// Target Sum with Repetition

#include<bits/stdc++.h>
using namespace std;

int subSum(int arr[], int idx, int n, int sum) {
    if(sum == 0) {
        return 1;
    }

    if(idx == n || sum < 0) {
        return 0;
    }

    return subSum(arr, idx + 1, n, sum) + subSum(arr, idx, n, sum - arr[idx]);
}

int main() {
    int arr[] = {2, 3, 4};
    int sum = 6;
    cout << subSum(arr, 0, 3, sum) << endl;
}

// output:
// 3