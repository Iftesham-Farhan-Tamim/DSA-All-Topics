// Get Min from Stack (Two-stack method) (https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab)
 
#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
    int minEle;
    stack<int> st1;   
    stack<int> st2;   

public:

    int getMin() {
        if (st2.empty()) {
            return -1;
        }
        return st2.top();
    }

    int pop() {
        if (st1.empty()) {
            return -1;
        }
        int element = st1.top();
        st1.pop();
        st2.pop();
        return element;
    }

    void push(int x) {
        if (st1.empty()) {
            st1.push(x);
            st2.push(x);
        } else {
            st1.push(x);
            st2.push(min(st2.top(), x));
        }
    }
};

int main() {
    SpecialStack s;

    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);

    cout << s.getMin() << endl;  
    s.pop();
    cout << s.getMin() << endl; 
}

// output:
// 2
// 3
// ............................................................................................
// Single-stack encoding method using %101 and /101

#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
    stack<int> st1;   

public:

    int getMin() {
        if(st1.empty()) {
            return -1;
        } else {
            return st1.top() % 101;
        }
    }

    int pop() {
        if(st1.empty()) {
            return -1;
        }

        int element = st1.top() / 101;
        st1.pop();
        return element;
    }

    void push(int x) {
        if (st1.empty()) {
            st1.push(x * 101 + x);
        } else {
            st1.push(x * 101 + min((st1.top() % 101), x));
        }
    }
};

int main() {
    SpecialStack s;

    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);

    cout << s.getMin() << endl;  
    s.pop();
    cout << s.getMin() << endl; 
}

// output:
// 2
// 3
// ............................................................................................
// Max of min for every window size (https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1?page=1&difficulty%5B%5D=2&category%5B%5D=Stack&sortBy=submissions)

#include <bits/stdc++.h>
using namespace std;

vector<int>maxOfMin(int arr[], int n) {
    vector<int>ans(n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            int num = INT_MAX;
            for(int k = j; k < i + 1 + j; k++) {
                num = min(num, arr[k]);
            }

            ans[i] = max(ans[i], num);
        }
    }

    return ans;
}

int main() {
    int arr[] = {10, 20, 30, 50, 10, 70, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> ans = maxOfMin(arr, n);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

// output:
// 70 30 20 10 10 10 10
// ............................................................................................
// Stack-Optimized Code

#include<bits/stdc++.h>
using namespace std;

vector<int>maxOfMin(int arr[], int n) {
    vector<int>ans(n, 0);
    stack<int>st;

    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] > arr[i]) {
            int index = st.top();
            st.pop();

            if(st.empty()) {
                int range = i;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            } else {
                int range = i - st.top() - 1;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
        }
        st.push(i);
    }

    while(!st.empty()) {
        int index = st.top();
        st.pop();

        if(st.empty()) {
            int range = n;
            ans[range - 1] = max(ans[range - 1], arr[index]);
        } else {
            int range = n - st.top() - 1;
            ans[range - 1] = max(ans[range - 1], arr[index]);
        }
    }

    for(int i = n - 2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
}

int main() {
     int arr[] = {10, 20, 30, 50, 10, 70, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> ans = maxOfMin(arr, n);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;
}

// output:
// 70 30 20 10 10 10 10 