// Smallest Range Covering Elements from K Lists (https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/)

#include<bits/stdc++.h>
using namespace std;

vector<int> smallestRange(vector<vector<int> > &nums) {
    priority_queue<
        pair<int, pair<int, int> >,
        vector<pair<int, pair<int, int> > >,
        greater<pair<int, pair<int, int> > >
    > p;

    int minimum, maximum = INT_MIN;

    for(int i = 0; i < nums.size(); i++) {
        p.push(make_pair(nums[i][0], make_pair(i, 0)));
        maximum = max(maximum, nums[i][0]);
    }

    minimum = p.top().first;
    vector<int> ans(2);
    ans[0] = minimum;
    ans[1] = maximum;
    pair<int, pair<int, int> > temp;
    int row, col, elem;

    while(p.size() == nums.size()) {
        temp = p.top();
        p.pop();

        elem = temp.first;
        row = temp.second.first;
        col = temp.second.second;

        if(col + 1 < nums[row].size()) {
            col++;
            p.push(make_pair(nums[row][col], make_pair(row, col)));
            maximum = max(maximum, nums[row][col]);
            minimum = p.top().first;

            if(maximum - minimum < ans[1] - ans[0]) {
                ans[0] = minimum;
                ans[1] = maximum;
            }
        }
    }

    return ans;
}

int main() {
    int k;
    cin >> k;  

    vector<vector<int> > nums(k);
    for(int i = 0; i < k; i++) {
        int n;
        cin >> n;  

        nums[i].resize(n);
        for(int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }

    vector<int> result = smallestRange(nums);
    cout << result[0] << " " << result[1] << endl;
}

// input:
// 3
// 5 4 10 15 24 26
// 4 0 9 12 20
// 4 5 18 22 30

// output:
// 20 24
// ............................................................................................
// Construct Target Array With Multiple Sums (https://leetcode.com/problems/construct-target-array-with-multiple-sums/description/)

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &target) {
    priority_queue<long long> p;
    long long sum = 0;

    for(int i = 0; i < target.size(); i++) {
        p.push(target[i]);
        sum += target[i];
    }

    long long MaxEle, RemSum, Element;

    while(p.top() != 1) { 
        MaxEle = p.top();
        p.pop();
        RemSum = sum - MaxEle;

        if(RemSum <= 0 || RemSum >= MaxEle) {
            return 0;
        }

        Element = MaxEle % RemSum;
        if(Element == 0) {
            if(RemSum != 1) {
                return 0;
            } else {
                return 1;
            }
        }
        sum = RemSum + Element;
        p.push(Element);
    }

    return 1;
}

int main() {
    vector<int> target = {9,3,5};

    if(isPossible(target)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

// output:
// true