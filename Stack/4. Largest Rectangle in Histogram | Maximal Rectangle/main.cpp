// Largest Rectangle in Histogram (https://leetcode.com/problems/largest-rectangle-in-histogram/)

#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    vector<int> Right(n);
    vector<int> Left(n);

    stack<int> st;

    for(int i = 0; i < n; i++) {
        while(!st.empty() && heights[st.top()] > heights[i]) {
            Right[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    while(!st.empty()) {
        Right[st.top()] = n;
        st.pop();
    }

    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && heights[st.top()] > heights[i]) {
            Left[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    while(!st.empty()) {
        Left[st.top()] = -1;
        st.pop();
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans = max(ans, heights[i] * (Right[i] - Left[i] - 1));
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of bars in histogram: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights of bars: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int maxArea = largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << maxArea << endl;
}

// input:
// Enter number of bars in histogram: 6
// Enter the heights of bars: 2 1 5 6 2 3

// output:
// Largest Rectangle Area: 10
// ............................................................................................
// Optimized Version (Single Stack)

#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights) {
    int ans = 0;
    int index;
    stack<int>st;
    int n = heights.size();

    for(int i = 0; i < n; i++) {
        while(!st.empty() && heights[st.top()]>heights[i]) {
            index = st.top();
            st.pop();
            if(!st.empty()) {
                ans = max(ans, heights[index] * (i-st.top()-1));
            } else {
                ans = max(ans, heights[index]*i);
            }
        }

        st.push(i);
    }

    while(!st.empty()) {
        index = st.top();
        st.pop();
        if(!st.empty()) {
            ans = max(ans, heights[index] * (n-st.top()-1));
        } else {
            ans = max(ans, heights[index]*n);
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of bars in histogram: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights of bars: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int maxArea = largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << maxArea << endl;
}

// input:
// Enter number of bars in histogram: 6
// Enter the heights of bars: 2 1 5 6 2 3

// output:
// Largest Rectangle Area: 10
// ............................................................................................
// Maximal Rectangle (https://leetcode.com/problems/maximal-rectangle/description/)

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights) {
    int ans = 0;
    int index;
    stack<int>st;
    int n = heights.size();

    for(int i = 0; i < n; i++) {
        while(!st.empty() && heights[st.top()]>heights[i]) {
            index = st.top();
            st.pop();
            if(!st.empty()) {
                ans = max(ans, heights[index] * (i-st.top()-1));
            } else {
                ans = max(ans, heights[index]*i);
            }
        }

        st.push(i);
    }

    while(!st.empty()) {
        index = st.top();
        st.pop();
        if(!st.empty()) {
            ans = max(ans, heights[index] * (n-st.top()-1));
        } else {
            ans = max(ans, heights[index]*n);
        }
    }

    return ans;
}

int maximalRectangle(vector<vector<char> > &matrix) {
    int ans = 0;
    int row = matrix.size();
    int col = matrix[0].size();

    vector<int>heights(col, 0);

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(matrix[i][j] == '0') {
                heights[j] = 0;
            } else {
                heights[j]++;
            }
        }

        ans = max(ans, largestRectangleArea(heights));
    }

    return ans;
}

int main() {
    int r, c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;

    vector<vector<char> > matrix(r, vector<char>(c));

    cout << "Enter the matrix (0/1 characters):" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = maximalRectangle(matrix);
    cout << "Maximal Rectangle Area: " << result << endl;
}

// input:
// Enter number of rows: 4
// Enter number of columns: 5
// Enter the matrix (0/1 characters):
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0

// output:
// Maximal Rectangle Area: 6