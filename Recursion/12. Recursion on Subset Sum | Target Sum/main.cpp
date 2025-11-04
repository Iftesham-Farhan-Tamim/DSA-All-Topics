#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int idx, int n, int sum) {
    if(idx == n) {
        cout << sum << " ";
        return;
    }

    // not included
    print(arr, idx + 1, n, sum);
    // included
    print(arr, idx + 1, n, sum + arr[idx]);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int arr[] = {1, 2, 3, 4};
    print(arr, 0, 4, 0);
}

// output:
// 0 4 3 7 2 6 5 9 1 5 4 8 3 7 6 10
// ............................................................................................
#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int idx, int n, int sum, vector<int> &ans) {
    if(idx == n) {
        ans.push_back(sum);
        return;
    }

    // not included
    print(arr, idx + 1, n, sum, ans);
    // included
    print(arr, idx + 1, n, sum + arr[idx], ans);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int arr[] = {1, 2, 3, 4};
    vector<int> ans;
    print(arr, 0, 4, 0, ans); 
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

// output:
// 0 4 3 7 2 6 5 9 1 5 4 8 3 7 6 10
// ............................................................................................
#include<bits/stdc++.h>
using namespace std;

bool find(int arr[], int idx, int n, int target) {
    if(target == 0) {
        return 1;
    }

    if(idx == n || target < 0) {
        return 0;
    }

    return find(arr, idx + 1, n, target) || find(arr, idx + 1, n, target - arr[idx]);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    int arr[] = {2, 4, 1, 8, 7};
    int target = 13;
    cout << find(arr, 0, 5, target) << " ";
}

// output:
// 1