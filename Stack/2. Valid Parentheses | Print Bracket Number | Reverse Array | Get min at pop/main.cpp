// Reverse String (https://leetcode.com/problems/reverse-string/description/)

#include<bits/stdc++.h>
using namespace std;

void reverseString(vector<char> &s) {
    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
        st.push(s[i]);
    }

    int i = 0;
    while(!st.empty()) {
        s[i] = st.top();
        st.pop();
        i++;
    }
}

int main() {
    vector<char> s = {'h','e','l','l','o'};
    reverseString(s);

    for(int i = 0; i < s.size(); i++) { 
        cout << s[i];
    }
    cout << endl; 
}

// output:
// olleh
// ............................................................................................
// Insert an Element at the Bottom of a Stack (https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1?page=2&category=Stack&difficulty=Easy&sortBy=submissions)

#include<bits/stdc++.h> 
using namespace std;

stack<int> insertAtBottom(stack<int> st, int x) {
    stack<int> temp;

    while(!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    st.push(x);

    while(!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }

    return st;
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3); 

    st = insertAtBottom(st, 0); 

    while(!st.empty()) {
        cout << st.top() << " "; 
        st.pop();
    }
}

// output:
// 3 2 1 0
// ............................................................................................
// Make the array beautiful (https://www.geeksforgeeks.org/problems/make-the-array-beautiful--170647/1)

#include<bits/stdc++.h>
using namespace std;

vector<int> makeBeautiful(vector<int> arr) {
    stack<int>s;

    for(int i = 0; i < arr.size(); i++) {
        if(s.empty()) {
            s.push(arr[i]);
        } else if(arr[i] >= 0) {
            if(s.top() >= 0) {
                s.push(arr[i]);
            } else {
                s.pop();
            }
        } else {
            if(s.top() < 0) {
                s.push(arr[i]);
            } else {
                s.pop();
            }
        }
    }

    vector<int> ans(s.size());
    int i = s.size() - 1;
    while(!s.empty()) {
        ans[i] = s.top();
        i--;
        s.pop();
    }

    return ans;
}

int main() {
    vector<int> arr = {1, -1, -2, 2, 3};
    vector<int> result = makeBeautiful(arr);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}

// output:
// 4 1 
// ............................................................................................
// String Manupulation (https://www.geeksforgeeks.org/problems/string-manipulation3706/1?page=1&difficulty%5B%5D=0&category%5B%5D=Stack&sortBy=submissions)

#include<bits/stdc++.h>
using namespace std;

int removeConsecutiveSame(vector<string> v) {
    stack<string> s;
    for(int i = 0; i < v.size(); i++) {
        if(s.empty()) {
            s.push(v[i]);
        } else if(s.top() == v[i]) {
            s.pop();
        } else {
            s.push(v[i]);
        }
    }

    return s.size();
}

int main() {
    vector<string> v = {"ab", "aa", "aa", "bcd", "ab"};
    cout << removeConsecutiveSame(v) << endl;
}

// output:
// 3
// ............................................................................................
// Parenthesis is Valid or not ? 

#include<bits/stdc++.h>
using namespace std;

bool check(string str) {
    stack<char> s;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(') {  // opening
            s.push(str[i]);
        } else {  // closing
            if(s.empty()) {
                return 0;
            } else {
                s.pop();
            }
        }
    }

    return s.empty();
}

int main() {
    string str = "((()))";
    cout << check(str) << endl;
}

// output:
// 1
// ............................................................................................

// ............................................................................................
// Minimum Add to Make Parentheses Valid (https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/)

#include<bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s) {
    stack<char> st;
    int count = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {  // opening
            st.push(s[i]);
        } else {  // closing
            if(st.empty()) {
                count++;
            } else {
                st.pop();
            }
        }
    }

    return count + st.size();
}

int main() {
    string s = "()))((";
    cout << minAddToMakeValid(s) << endl;
}

// output:
// 4
// ............................................................................................
// Valid Parentheses (https://leetcode.com/problems/valid-parentheses/description/)

#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else {
            if(st.empty()) {
                return false;
            } else if(s[i] == ')') {      
                if(st.top() != '(') {   
                    return false;
                } else {
                    st.pop();
                }
            } else if(s[i] == '}') {
                if(st.top() != '{') {
                    return false;
                } else {
                    st.pop();
                }
            } else if(s[i] == ']') {     
                if(st.top() != '[') {
                    return false;
                } else {
                    st.pop();
                }
            }
        } 
    } 

    return st.empty();
}

int main() {
    string s = "{[()]}";
    cout << isValid(s) << endl;
}

// output:
// 1
// ............................................................................................
// Print Bracket Number (https://www.geeksforgeeks.org/problems/print-bracket-number4058/1?page=1&difficulty%5B%5D=0&category%5B%5D=Stack&sortBy=submissions)

#include<bits/stdc++.h>
using namespace std;

vector<int> bracketNumbers(string S) {
    int count = 0;
    stack<int> st;
    vector<int> ans;

    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '(') {
            count++;
            st.push(count);
            ans.push_back(count);
        } else if(S[i] == ')') {
            ans.push_back(st.top());
            st.pop();
        }
    }

    return ans;
}

int main() {
    string S = "(aa(bdc))p(dee)";
    vector<int> result = bracketNumbers(S);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}

// output:
// 1 2 2 1 3 3
// ............................................................................................
// Get min at pop (https://www.geeksforgeeks.org/problems/get-min-at-pop/1?page=1&category=Stack&difficulty=Easy&sortBy=submissions)

#include<bits/stdc++.h>
using namespace std;

stack<int> _push(int arr[], int n) {
    stack<int>st;
    for(int i=0; i<n; i++) {
        if(i==0) {
            st.push(arr[i]);
        } else {
            st.push(min(arr[i], st.top()));
        }
    }

    return st;
}

void _getMinAtPop(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    int arr[] = {1, 6, 43, 1, 2, 0, 5};
    int n = 7;

    stack<int> s = _push(arr, n);
    _getMinAtPop(s);
}

// output:
// 0 0 1 1 1 1 1
// ............................................................................................
// Backspace String Compare (https://leetcode.com/problems/backspace-string-compare/description/)

#include<bits/stdc++.h>
using namespace std;

int main() {

}