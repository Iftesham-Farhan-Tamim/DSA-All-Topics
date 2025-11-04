// Permutation of Arrays (https://leetcode.com/problems/permutations/description/)

#include <bits/stdc++.h>
using namespace std;

void permut(int arr[], vector<vector<int> > &ans, vector<int> &temp, vector<bool> &visited) {
    if (visited.size() == temp.size()) {   
        ans.push_back(temp);
        return;
    }
    
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            temp.push_back(arr[i]);
            permut(arr, ans, temp, visited);
            visited[i] = 0;
            temp.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int arr[] = {1, 2, 3};
    vector<vector<int> > ans;
    vector<int> temp;              
    vector<bool> visited(3, 0);
    permut(arr, ans, temp, visited);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;              
    }
}

// output:
// 1 2 3 
// 1 3 2 
// 2 1 3 
// 2 3 1 
// 3 1 2 
// 3 2 1 
// ............................................................................................
// Permutation of Arrays (speed and memory efficiency.)

#include <bits/stdc++.h>
using namespace std;

void permut(vector<int> &arr, vector<vector<int> > &ans, int index) {
    if (arr.size() == index) {   
        ans.push_back(arr);
        return;
    }
    
    for (int i = index; i < arr.size(); i++) {
        swap(arr[index], arr[i]);
        permut(arr, ans, index + 1);
        swap(arr[index], arr[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    vector<int> arr = {1, 2, 3};
    vector<vector<int> > ans;

    permut(arr, ans, 0);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

// output:
// 1 2 3 
// 1 3 2 
// 2 1 3 
// 2 3 1 
// 3 2 1 
// 3 1 2 
// ............................................................................................
// Permutation of Strings

#include <bits/stdc++.h>
using namespace std;

void permut(string &s, vector<string> &ans, int index) {
    if (index == s.size()) {   
        ans.push_back(s);
        return;
    }

    for (int i = index; i < s.size(); i++) {
        swap(s[index], s[i]);
        permut(s, ans, index + 1);
        swap(s[index], s[i]); 
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    string s = "ABC";
    vector<string> ans;

    permut(s, ans, 0);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}

// output:
// ABC
// ACB
// BAC
// BCA
// CBA
// CAB