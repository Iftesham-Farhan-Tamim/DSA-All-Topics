// Next Greater Element in Circular Array (https://www.geeksforgeeks.org/problems/next-greater-element/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab)

#include<bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n, -1);

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[i]) {
                ans[i] = arr[j];
                break;
            }
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 3, 2, 4};      
    vector<int> res = nextLargerElement(arr);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}

// output:
// 3 4 4 -1 
// ............................................................................................
// optimized version

#include<bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int> &arr, int n) {
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            ans[st.top()] = arr[i];
            st.pop();
        }

        st.push(i);
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 3, 2, 4};
    int n = arr.size();                         
    vector<int> res = nextLargerElement(arr, n); 

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}

// output:
// 3 4 4 -1 
// ............................................................................................
// optimized version

#include<bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int> &arr, int n) {
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }

        if(!st.empty()) {
            ans[i] = arr[st.top()];
        }

        st.push(i);
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 3, 2, 4};
    int n = arr.size();                         
    vector<int> res = nextLargerElement(arr, n); 

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}

// output:
// 3 4 4 -1  
// ............................................................................................
// Next Smaller Element (https://www.naukri.com/code360/problems/next-smaller-element_1112581?leftPanelTabValue=PROBLEM)

#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[i] < arr[st.top()]) {
            ans[st.top()] = arr[i];
            st.pop();
        }

        st.push(i);
    }

    return ans;
}

int main() {
    vector<int> arr = {4, 8, 5, 2, 7};
    int n = arr.size();

    vector<int> res = nextSmallerElement(arr, n);

    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}

// output:
// 2 5 2 -1 -1 
// ............................................................................................
// Smaller on Left (https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab)

#include <bits/stdc++.h>
using namespace std;

vector<int> leftSmaller(int n, int a[]) {
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && a[i]<a[st.top()]) {
            ans[st.top()] = a[i];
            st.pop();
        }

        st.push(i);
    }

    return ans;
}

int main() {
    int a[] = {4, 8, 5, 2, 7};
    int n = sizeof(a)/sizeof(a[0]);

    vector<int> res = leftSmaller(n, a);

    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}

// output:
// -1 1 -1 0 3 4 
// ............................................................................................
// Stock span problem (https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab)

#include <bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(int price[], int n) {
    vector<int> ans(n);
    stack<int> st;

    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && price[i] > price[st.top()]) {
            ans[st.top()] = st.top() - i;
            st.pop();
        }

        st.push(i);
    }

    while(!st.empty()) {
        ans[st.top()] = st.top() - 1;
        st.pop();
    }

    return ans;
}

int main() {
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price)/sizeof(price[0]);

    vector<int> res = calculateSpan(price, n);

    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}

// output:
// 1 1 2 4 