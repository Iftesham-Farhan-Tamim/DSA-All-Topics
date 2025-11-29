// Height of Heap (https://www.geeksforgeeks.org/problems/height-of-heap5025/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Heap&sortBy=submissions)

#include <bits/stdc++.h>
using namespace std;

int heapHeight(int n, int arr[]) {
    if(n == 1) {
        return 1;
    }

    int height = 0;
    while(n > 1) {
        height++;
        n /= 2;
    }

    return height;
}

// int heapHeight(int n, int arr[]) {
//     return floor(log2(n));
// }

int main() {
    int n = 10;
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    cout << heapHeight(n, arr) << endl;
}


// output:
// 3
// ............................................................................................
// Minimum Cost of ropes (https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1?page=1&difficulty)

#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n) {
    priority_queue<long long, vector<long long>, greater<long long> > p;

    for(int long long i = 0; i < n; i++) {
        p.push(arr[i]);
    }

    long long cost = 0;

    while(p.size() > 1) {
        long long rope = p.top();
        p.pop();
        rope += p.top();
        p.pop();
        cost += rope;
        p.push(rope);
    }

    return cost;
}

int main() {
    long long n;
    cin >> n;

    long long arr[n];
    for(long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << minCost(arr, n) << endl;
}

// input:
// 4
// 4 3 2 6

// output:
// 29
// ............................................................................................
// Magician and Chocolates (https://www.interviewbit.com/problems/magician-and-chocolates/)

#include <bits/stdc++.h>
using namespace std;

int nRopes(int a, vector<int> &b) {
    priority_queue<int> p;
    for(int i = 0; i < b.size(); i++) {
        p.push(b[i]);
    }

    long long MaxChoc = 0;

    while(a && (!p.empty())) {
        MaxChoc += p.top();

        if(p.top() / 2) {
            p.push(p.top() / 2);

            p.pop();
            a--;
        }
    }

    return MaxChoc % 1000000007;
}

int main() {
    int a, n;
    cin >> a >> n;

    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    cout << nRopes(a, b) << endl;
}

// input:
// 5 5
// 2 4 6 8 10

// output:
// 33
// ............................................................................................
// Last Stone Weight (https://leetcode.com/problems/last-stone-weight/description/)

#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> p;

    for(int i = 0; i < stones.size(); i++) {
        p.push(stones[i]);
    }

    while(p.size() > 1) {
        int weight = p.top();
        p.pop();
        weight -= p.top();
        p.pop();
        if(weight) {
            p.push(weight);
        }
    }

    return p.empty() ? 0 : p.top();
}

int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << lastStoneWeight(stones) << endl;
}

// output:
// 1
// ............................................................................................
// Profit Maximisation (https://www.interviewbit.com/problems/profit-maximisation/)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, int b) {
    int sum = 0;
    priority_queue<int> p;

    for(int i = 0; i < a.size(); i++) {
        p.push(a[i]);
    }

    while(b && !p.empty()) {
        sum += p.top();

        if(p.top() - 1) {
            p.push(p.top() - 1);
        }

        p.pop();
        b--;
    }

    return sum;
}

int main() {
    vector<int> a = {5, 3, 4};
    int b = 5;

    cout << solve(a, b) << endl;
}

// output:
// 19