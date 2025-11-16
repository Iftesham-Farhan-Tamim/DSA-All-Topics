// Print all number in every window of size k

#include<bits/stdc++.h>
using namespace std;

void display(queue<int> q) {
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
}

int main() {
    int arr[] = {2, 3, 1, 5, 6, 7, 8};
    int n = 7;
    int k = 3;

    queue<int> q;
    for(int i=0; i<k-1; i++) {
        q.push(arr[i]);
    }

    for(int i=k-1; i<n; i++) {
        q.push(arr[i]);
        display(q);
        q.pop();
    }
}

// output:
// 2 3 1 
// 3 1 5 
// 1 5 6 
// 5 6 7 
// 6 7 8 
// ............................................................................................
// First negative in every window of size k (https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1)

#include<bits/stdc++.h>
using namespace std;

long long display(queue<long long> q) {
    while(!q.empty()) {
        if(q.front() < 0) {
            return q.front();
        }

        q.pop();
    }

    return 0;
}

vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long k) {
    vector<long long> ans;
    queue<long long> q;

    for(long long int i = 0; i < k - 1; i++) {
        q.push(a[i]);
    }

    for(long long int i = k - 1; i < n; i++) {
        q.push(a[i]);
        ans.push_back(display(q));
        q.pop();
    }

    return ans;
}

int main() {
    long long int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    long long n = 8;
    long long k = 3;

    vector<long long> result = printFirstNegativeInteger(arr, n, k);

    cout << "First negative numbers in each window: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;
}

// output:
// First negative numbers in each window: -1 -1 -7 -15 -15 0 
// ............................................................................................
// optimized version

#include<bits/stdc++.h>
using namespace std;

vector<long long> printFirstElementInteger(long long int a[], long long int n, long long k) {
    vector<long long> ans;
    queue<long long int> q;

    for(long long int i = 0; i < k - 1; i++) {
        if(a[i] < 0) {
            q.push(i);
        }
    }

    for(long long int i = k - 1; i < n; i++) {
        if(a[i] < 0) {
            q.push(i);
        }

        if(q.empty()) {
            ans.push_back(0);
        } else {
            if(q.front() <= i - k) {
                q.pop();
            }

            if(q.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(a[q.front()]);
            }
        }
    }

    return ans;
}

int main() {
    long long int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    long long n = 8;
    long long k = 3;

    vector<long long> result = printFirstElementInteger(arr, n, k);

    cout << "First negative numbers in each window: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;
}

// output:
// First negative numbers in each window: -1 -1 -7 -15 -15 0 
// ............................................................................................
// First no repeating char in a stream of characters (https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/)

#include<bits/stdc++.h>
using namespace std;

string solve(string a) {
    string b = "";
    vector<int> repeated(26, 0);
    queue<char> q;

    for(int i = 0; i < a.size(); i++) {
        if(repeated[a[i] - 'a'] >= 1) {
            repeated[a[i] - 'a']++;
            while(!q.empty() && repeated[q.front() - 'a'] > 1) {
                q.pop();
            }

            if(q.empty()) {
                b += '#';
            } else {
                b += q.front();
            }
        } else {
            repeated[a[i] - 'a']++;
            q.push(a[i]);

            while(repeated[q.front() - 'a'] > 1) {
                q.pop();
            }

            b += q.front();
        }
    }

    return b;
}

int main() {
    string s = "aabc";
    cout << solve(s) << endl;
}

// output:
// a#bb