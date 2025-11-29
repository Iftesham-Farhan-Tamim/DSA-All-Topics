// Kth element in Matrix (https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1?page=1&difficulty%5B%5D=1&category%5B%5D=Heap&sortBy=submissions)

#include <bits/stdc++.h>
using namespace std;

int KthSmallest(vector<vector<int> > &mat, int n, int k) {
    vector<pair<int, pair<int, int> > > temp;
    for(int i = 0; i < n; i++) {
        temp.push_back({mat[i][0], {i, 0}});
    }

    priority_queue<
        pair<int, pair<int, int> >,
        vector<pair<int, pair<int, int> > >,
        greater<pair<int, pair<int, int> > >
    > p(temp.begin(), temp.end());

    int ans;
    pair<int, pair<int, int> > element;
    int i, j;

    while(k--) {
        element = p.top();
        p.pop();
        ans = element.first;
        i = element.second.first;
        j = element.second.second;
        if(j + 1 < n) {
            p.push({mat[i][j + 1], {i, j + 1}});
        }
    }

    return ans;
}

int main() {
    int n = 3, k = 5;
    vector<vector<int> > mat = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };

    cout << "5th smallest element is " << KthSmallest(mat, n, k) << endl;
}

// output:
// 5th smallest element is 11
// ............................................................................................
// Find median in a stream (https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1?page=1&difficulty%5B%5D=2&category%5B%5D=Heap&sortBy=submissions)

#include <bits/stdc++.h>
using namespace std;

priority_queue<int> LeftMaxHeap;
priority_queue<int, vector<int>, greater<int> > RightMinHeap;

void balanceHeaps() {
    if(RightMinHeap.size() > LeftMaxHeap.size()) {
        LeftMaxHeap.push(RightMinHeap.top());
        RightMinHeap.pop();
    } else {
        if(RightMinHeap.size() < LeftMaxHeap.size() - 1) {
            RightMinHeap.push(LeftMaxHeap.top());
            LeftMaxHeap.pop();
        }
    }
}

void insertHeap(int &x) {
    if(LeftMaxHeap.empty()) {
        LeftMaxHeap.push(x);
        return;
    }

    if(x > LeftMaxHeap.top()) {
        RightMinHeap.push(x);
    } else {
        LeftMaxHeap.push(x);
    }

    balanceHeaps();
}

double getMedian() {
    if(LeftMaxHeap.size() > RightMinHeap.size()) {
        return LeftMaxHeap.top();
    } else {
        double ans = LeftMaxHeap.top() + RightMinHeap.top();
        ans /= 2;
        return ans;
    }
}

int main() {
    vector<int> stream = {5, 15, 1, 3};
    
    for(int i = 0; i < stream.size(); i++) {
        int x = stream[i];
        insertHeap(x);
        cout << "Median after inserting " << x << " is " << getMedian() << endl;
    }
}

// output:
// Median after inserting 5 is 5
// Median after inserting 15 is 10
// Median after inserting 1 is 5
// Median after inserting 3 is 4