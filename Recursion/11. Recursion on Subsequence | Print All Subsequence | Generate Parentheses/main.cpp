//  Recursion on Subsequence (https://leetcode.com/problems/subsets/description/)

#include<bits/stdc++.h>
using namespace std;

void subsequence(int arr[], int idx, int n, vector<vector<int> >&ans, vector<int>temp) {
    if(idx == n) {
        ans.push_back(temp);
        return;
    }

    // not included
    subsequence(arr, idx + 1, n, ans, temp);

    // included
    temp.push_back(arr[idx]);
    subsequence(arr, idx + 1, n, ans, temp);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int arr[] = {1, 2, 3};
    vector<vector<int> > ans;
    vector<int>temp;
    subsequence(arr, 0, 3, ans, temp);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

// output:
// (empty line)  
// 3 
// 2 
// 2 3 
// 1 
// 1 3 
// 1 2 
// 1 2 3 
// ............................................................................................
// Print All Subsequences / Generate All Subsets of a String/Array

#include<bits/stdc++.h>
using namespace std;

void subset(string &s, int idx, int n, vector<string>&ans, string temp) {
    if(idx == n) {
        ans.push_back(temp);
        return;
    }

    // not included
    subset(s, idx + 1, n, ans, temp);
    // included
    temp.push_back(s[idx]);
    subset(s, idx + 1, n, ans, temp);
    temp.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    string s = "abc";
    vector<string>ans;
    string temp;
    subset(s, 0, s.size(), ans, temp);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << endl;
    }
}

// output:
// (empty line)  
// c
// b
// bc
// a
// ac
// ab
// abc
// ............................................................................................
// Generate Parentheses (https://leetcode.com/problems/generate-parentheses/description/)

#include<bits/stdc++.h>
using namespace std;

void parenth(int n, int left, int right, vector<string> &ans, string &temp) {
    if(left + right == 2 * n) {
        ans.push_back(temp);
        return;
    }

    // left parenth
    if(left < n) {
        temp.push_back('(');
        parenth(n, left + 1, right, ans, temp);
        temp.pop_back();
    }

    // right parenth
    if(right < left) {
        temp.push_back(')');
        parenth(n, left, right + 1, ans, temp);
        temp.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string temp;
    parenth(n, 0, 0, ans, temp);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    int n;
    cin >> n;

    vector<string> res = generateParenthesis(n);

    for(int i=0; i<res.size(); i++) {
        cout << res[i] << endl;
    }
}

// input:
// 3

// output:
// ((()))
// (()())
// (())()
// ()(())
// ()()()