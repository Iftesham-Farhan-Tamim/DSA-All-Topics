// The Celebrity Problem (https://www.geeksforgeeks.org/problems/the-celebrity-problem/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab)

#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int> > &m) {
    int n = m.size();
    stack<int> st;
    for(int i = n - 1; i >= 0; i--) {
        st.push(i);
    }

    int first, second;

    while(st.size() > 1) {
        first = st.top();
        st.pop();
        second = st.top();
        st.pop();

        if(m[first][second] && !m[second][first]) {
            st.push(second);
        } else if(!m[first][second] && m[second][first]) {
            st.push(first);
        }
    }

    if(st.empty()) {
        return -1;
    }

    int num = st.top();
    st.pop();

    int row = 0, col = 0;

    for(int i = 0; i < n; i++) {
        row += m[num][i];
        col += m[i][num];
    }

    return row == 1 && col == n ? num : -1;
}

int main() {
    vector<vector<int> > mat = {{ 1, 1, 0 },
                                { 0, 1, 0 },
                                { 0, 1, 1 }};

    cout << celebrity(mat) << endl;
}

// output:
// 1
// ............................................................................................
// two pointer approach

#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>>& mat) {
    int n = mat.size();
    int start = 0, end = n - 1;

    while (start < end) {
        if (mat[start][end] == 1) {
            start++;
        } else {
            end--;
        }
    }

    int c = start;  

    for (int i = 0; i < n; i++) {
        if (i != c) {
            if (mat[c][i] == 1 || mat[i][c] == 0)
                return -1;  
        }
    }

    return c;  
}

int main() {
    vector<vector<int> > mat = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 1}
    };

    cout << celebrity(mat) << endl;
}

// output:
// 1